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

# Sources
set(SRCS
    Config.hpp
    definition.hpp
    Api.hpp
    Api.cpp
    Plugin.hpp
    Plugin.cpp
    Manager.hpp
    Manager.cpp
    RepositoryRecord.hpp
    Repository.hpp
    Repository.cpp
    Context.hpp
    Context.cpp
    Loader.hpp
    Loader.cpp
    SharedLibrary.hpp
    SharedLibrary.cpp
    SharedLibraryLoader.hpp
    SharedLibraryLoader.cpp
)

set(SRCS_TEST
    ManagerTest.cpp
)

# ######################################################################### #

dir_pretend(SOURCES plugin/ ${SRCS})
dir_pretend(SOURCES_TEST plugin/test/ ${SRCS_TEST})

set(SOURCES_PLUGIN ${SOURCES} PARENT_SCOPE)
set(SOURCES_PLUGIN_TEST ${SOURCES_TEST} PARENT_SCOPE)

# ######################################################################### #

# Test plugin
add_library(cece-test-plugin SHARED
    test/TestPlugin.cpp
)

# Properties
set_target_properties(cece-test-plugin PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS Off
    CXX_STANDARD_REQUIRED On
)

target_include_directories(cece-test-plugin
    PRIVATE ${CMAKE_SOURCE_DIR}
    PRIVATE ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET cece-test-plugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cece-test-plugin> ${CMAKE_BINARY_DIR}/cece
)

# ######################################################################### #
