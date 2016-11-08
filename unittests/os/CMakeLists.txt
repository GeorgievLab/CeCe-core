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

cece_add_test(os
    SOURCES
        SharedLibraryTest.cpp
)

# ######################################################################### #

##
## Helper function which build a test plugin.
##
function (add_test_library NAME SOURCE)
    if (CECE_BUILD_TESTS)
        return ()
    endif ()

    set(FULLNAME ${NAME})

    # Test plugin
    add_library(${FULLNAME} SHARED
        libraries/${SOURCE}
    )

    # Properties
    set_target_properties(${FULLNAME} PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS Off
        CXX_STANDARD_REQUIRED On
    )
endfunction ()

# ######################################################################### #

# Test libraries
add_test_library(library1 Library1.cpp)

# ######################################################################### #
