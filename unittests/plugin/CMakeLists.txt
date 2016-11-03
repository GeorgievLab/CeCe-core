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

cece_add_test(plugin
    SOURCES
        ApiTest.cpp
        PluginTest.cpp
        RepositoryRecordTest.cpp
        RepositoryTest.cpp
        ManagerTest.cpp
        ContextTest.cpp
)

# ######################################################################### #

##
## Helper function which build a test plugin.
##
function (add_test_plugin NAME SOURCE)
    if (CECE_BUILD_TESTS)
        return ()
    endif ()

    set(FULLNAME cece-${NAME})

    # Test plugin
    add_library(${FULLNAME} SHARED
        plugins/${SOURCE}
    )

    # Link dependency
    target_link_libraries(${FULLNAME}
        cece
    )

    # Properties
    set_target_properties(${FULLNAME} PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS Off
        CXX_STANDARD_REQUIRED On
    )

    target_include_directories(${FULLNAME}
        PRIVATE ${CMAKE_SOURCE_DIR}
        PRIVATE ${CMAKE_BINARY_DIR}
    )
endfunction ()

# ######################################################################### #

# Test plugin
add_test_plugin(different-real-plugin DifferentRealPlugin.cpp)
add_test_plugin(invalid-plugin InvalidPlugin.cpp)
add_test_plugin(no-config-plugin NoConfigPlugin.cpp)
add_test_plugin(no-create-plugin NoCreatePlugin.cpp)
add_test_plugin(not-render-plugin NotRenderPlugin.cpp)
add_test_plugin(not-thread-safe-plugin NotThreadSafePlugin.cpp)
add_test_plugin(old-plugin OldPlugin.cpp)
add_test_plugin(test-plugin TestPlugin.cpp)
add_test_plugin(throw-plugin ThrowPlugin.cpp)

file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}cece-python-plugin.py"
    CONTENT "print('Hello')\n"
)

file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}cece-no-shared-plugin${CMAKE_SHARED_LIBRARY_SUFFIX}"
    CONTENT "I'm no shared library\n"
)

# ######################################################################### #
