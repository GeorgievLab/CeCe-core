# ######################################################################### #
# Georgiev Lab (c) 2015-2016                                                #
# ######################################################################### #
# Department of Cybernetics                                                 #
# Faculty of Applied Sciences                                               #
# University of West Bohemia in Pilsen                                      #
# ######################################################################### #
#                                                                           #
# This file is part of CeCe.                                                #
#                                                                           #
# CeCe is free software: you can redistribute it and/or modify              #
# it under the terms of the GNU General Public License as published by      #
# the Free Software Foundation, either version 3 of the License, or         #
# (at your option) any later version.                                       #
#                                                                           #
# CeCe is distributed in the hope that it will be useful,                   #
# but WITHOUT ANY WARRANTY; without even the implied warranty of            #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             #
# GNU General Public License for more details.                              #
#                                                                           #
# You should have received a copy of the GNU General Public License         #
# along with CeCe.  If not, see <http://www.gnu.org/licenses/>.             #
#                                                                           #
# ######################################################################### #

# Create config file
configure_file(config.hpp.in cece/config.hpp)

# ######################################################################### #

##
## Pretend directory to source files
##
function(dir_pretend OUT DIR)
    set(FILES "")

    foreach (F ${ARGN})
        list(APPEND FILES "${DIR}${F}")
    endforeach ()

    set(${OUT} ${FILES} PARENT_SCOPE)
endfunction ()

# ######################################################################### #

# Core files
add_subdirectory(core)
add_subdirectory(config)
add_subdirectory(loader)
add_subdirectory(init)
add_subdirectory(module)
add_subdirectory(object)
add_subdirectory(program)
add_subdirectory(plugin)
add_subdirectory(os)
add_subdirectory(io)

# Renderer files
if (CECE_RENDER)
    add_subdirectory(render)
endif ()

# Simulation files
add_subdirectory(simulator)

# ######################################################################### #

# Create library
add_library(${PROJECT_NAME} SHARED ${CECE_SOURCES})

# ######################################################################### #

# Properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS Off
    CXX_STANDARD_REQUIRED On
    WINDOWS_EXPORT_ALL_SYMBOLS On # TODO: necessary?
)

# Enable time measurement
if (CECE_TIME_MEASUREMENT)
    target_compile_definitions(${PROJECT_NAME}
        PRIVATE -DCECE_TIME_MEASUREMENT
    )
endif ()

# Include directories
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../include
        ${CMAKE_CURRENT_BINARY_DIR}
)

# Generate export header (MSVC)
include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME "cece/export.hpp"
)

# Compiler warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif ()

# Export all for MINGW
if (MINGW)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--export-all-symbols")
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--export-all-symbols")
endif ()

if (CMAKE_COMPILER_IS_GNUCXX AND CECE_TESTS_BUILD AND CECE_COVERAGE)
    target_compile_options(${PROJECT_NAME} PRIVATE --coverage)
    target_link_libraries(${PROJECT_NAME} PRIVATE --coverage)
endif ()

# ######################################################################### #

# Link Box2D internally
target_link_libraries(${PROJECT_NAME} PRIVATE Box2D)

# Include OpenGL if rendering is enabled
if (CECE_RENDER)
    # OpenGL library is required
    find_package(OpenGL REQUIRED)
    target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
endif ()

if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl)
endif ()

# ######################################################################### #

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)

# ######################################################################### #
