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

cmake_minimum_required(VERSION 3.1)

# ######################################################################### #

project(cece
    VERSION 0.7.0
    LANGUAGES CXX
)

# ######################################################################### #

include(CMake/Functions.cmake)

# ######################################################################### #

# Options
option(CECE_RENDER                  "Enable simulation rendering (vizualization support)" On)
option(CECE_RENDER_CHECK_ERRORS     "Enable renderer errors checking." Off)
option(CECE_THREAD_SAFE             "Enable thread support" Off)
option(CECE_TESTS_BUILD             "Build simulator part tests (requires GTest)" Off)
option(CECE_TIME_MEASUREMENT        "Enable or disable time measurement" Off)
set(CECE_REAL_TYPE "double" CACHE STRING "Type used for real values")
set_property(CACHE CECE_REAL_TYPE PROPERTY STRINGS "float" "double" "long double")

# Must be defined
if (NOT CECE_REAL_TYPE)
    message(FATAL_ERROR "Missing 'CECE_REAL_TYPE' option")
endif ()

if (APPLE)
    set(MACOSX_VERSION_MIN "10.9" CACHE STRING "Minimum version of MacOS X to support")
endif ()

# Allow to enable code coverage, only for tests and GCC
if (CMAKE_COMPILER_IS_GNUCXX AND CECE_TESTS_BUILD)
    option(CECE_COVERAGE "Enable code coverage generation for tests" Off)
endif ()

# ######################################################################### #

# Build unit tests
if (CECE_TESTS_BUILD)
    enable_testing()

    # Init google test submodule
    cece_init_vendor(googletest)

    message(STATUS "Build unit tests")
    set(BUILD_GMOCK Off CACHE BOOL "" FORCE)
    set(BUILD_GTEST On CACHE BOOL "" FORCE)
    set(gtest_force_shared_crt On CACHE BOOL "" FORCE)
    mark_as_advanced(BUILD_GMOCK BUILD_GTEST gtest_build_samples gtest_build_tests gtest_disable_pthreads gtest_force_shared_crt)
    add_subdirectory(vendor/googletest)
    target_include_directories(gtest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/googletest/include)

    cece_enable_ccache(vendor/googletest)
endif ()

# Init Box2D submodule
cece_init_vendor(Box2D Box2D/CMakeLists.txt)

# Add Box2D physics library
set(BOX2D_BUILD_EXAMPLES Off CACHE BOOL "" FORCE)
set(BOX2D_BUILD_SHARED Off CACHE BOOL "" FORCE)
set(BOX2D_BUILD_STATIC On CACHE BOOL "" FORCE)
set(BOX2D_INSTALL Off CACHE BOOL "" FORCE)
set(BOX2D_INSTALL_DOC Off CACHE BOOL "" FORCE)
mark_as_advanced(FORCE BOX2D_BUILD_EXAMPLES BOX2D_BUILD_SHARED BOX2D_BUILD_STATIC BOX2D_INSTALL BOX2D_INSTALL_DOC)

add_subdirectory(vendor/Box2D/Box2D)
# It will be linked in to the shared library
set_target_properties(Box2D PROPERTIES POSITION_INDEPENDENT_CODE On)
target_include_directories(Box2D INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Box2D/Box2D)

cece_enable_ccache(vendor/Box2D/Box2D)

# ######################################################################### #

# CeCe library
add_subdirectory(src)

# ######################################################################### #

if (CECE_TESTS_BUILD)
    add_subdirectory(unittests)

    if (CMAKE_COMPILER_IS_GNUCXX AND CECE_COVERAGE)
        find_program(LCOV lcov)
        find_program(GENHTML genhtml)

        if (NOT LCOV)
            message(FATAL_ERROR "lcov not found!")
        endif ()

        if (NOT GENHTML)
            message(FATAL_ERROR "genhtml not found!")
        endif ()

        # Add custom target for gcov
        add_custom_target(cece-coverage
            # Cleanup lcov
            ${LCOV} --directory . --zerocounters

            # Run tests
            COMMAND ctest

            # Capturing lcov counters and generating report
            COMMAND ${LCOV} --directory . --capture --output-file coverage0.info
            COMMAND ${LCOV} -r coverage0.info  'vendor/*' 'unittests/*' '/usr*' --output-file coverage.info
            COMMAND ${GENHTML} --demangle-cpp -o coverage coverage.info
            COMMAND ${CMAKE_COMMAND} -E remove coverage0.info

            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
    endif ()
endif ()

# ######################################################################### #
