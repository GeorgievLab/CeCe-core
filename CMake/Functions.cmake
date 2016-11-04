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

##
## Add CeCe test.
## NAME: Test name
##
function (cece_add_test NAME)
    if (NOT CECE_TESTS_BUILD)
        return ()
    endif ()

    set(FULLNAME "cece-${NAME}_test")

    include(CMakeParseArguments)
    cmake_parse_arguments(ARG "" "" "SOURCES;LIBRARIES" ${ARGN})

    # Create executable
    add_executable(${FULLNAME}
        ${ARG_SOURCES}
    )

    # Properties
    set_target_properties(${FULLNAME} PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS Off
        CXX_STANDARD_REQUIRED On
    )

    # Libraries
    target_link_libraries(${FULLNAME}
        PRIVATE cece
        PRIVATE ${ARG_LIBRARIES}
        PRIVATE gtest_main
    )

    if (CMAKE_COMPILER_IS_GNUCXX AND CECE_TESTS_BUILD AND CECE_COVERAGE)
        target_compile_options(${FULLNAME} PRIVATE --coverage)
        target_link_libraries(${FULLNAME} PRIVATE --coverage)
    endif ()

    # Register test
    add_test(
        NAME ${FULLNAME}
        COMMAND ${FULLNAME}
        WORKING_DIRECTORY $<TARGET_FILE_DIR:${FULLNAME}>
    )

    if (WIN32 OR MINGW)
        # Windows doen't support rpath, so we need to copy the main library to the test executable
        add_custom_command(TARGET ${FULLNAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cece> $<TARGET_FILE_DIR:${FULLNAME}>
        )
    endif ()
endfunction ()

# ######################################################################### #

##
## Initialize GIT submodule
## PATH: Submodule path
## [CHECK]: Path to tested file in submodule (default CMakeLists.txt)
##
function(cece_init_submodule PATH)
    if (ARGC GREATER 1)
        set(TEST_PATH "${PATH}/${ARGV1}")
    else ()
        set(TEST_PATH "${PATH}/CMakeLists.txt")
    endif ()

    # Check if file exists
    if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${TEST_PATH}")
        find_package(Git REQUIRED)
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive ${PATH}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif ()
endfunction ()

# ######################################################################### #

##
## Initialize vendor submodule (in `vendor` directory).
## PATH: Vendor submodule name
## [CHECK]: Path to tested file in submodule (default CMakeLists.txt)
##
function(cece_init_vendor PATH)
    cece_init_submodule(vendor/${PATH} ${ARGN})
endfunction ()

# ######################################################################### #

##
## Enable CCACHE for given directory.
## DIRECTORY: Cache directory.
##
function (cece_enable_ccache)
    find_program(CCACHE_FOUND ccache)
    if (CCACHE_FOUND)
        set_property(DIRECTORY ${DIRECTORY} PROPERTY RULE_LAUNCH_COMPILE ccache)
        set_property(DIRECTORY ${DIRECTORY} PROPERTY RULE_LAUNCH_LINK ccache)
    endif ()
endfunction ()

# ######################################################################### #
