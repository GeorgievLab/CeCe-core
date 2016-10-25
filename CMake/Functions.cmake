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
        cece
        ${ARG_LIBRARIES}
        gtest_main
    )

    # Register test
    add_test(${FULLNAME} ${FULLNAME})
endfunction ()

# ######################################################################### #
