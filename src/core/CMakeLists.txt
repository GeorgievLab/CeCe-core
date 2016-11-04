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

set(SRCS
    Unit.cpp
    UnitIo.cpp
    Units.cpp
    Vector.cpp
    VectorUnits.cpp
    Grid.cpp
    AlignedAllocator.cpp
    ExpressionParser.cpp
    Log.cpp
    TimeMeasurement.cpp
    FilePath.cpp
    CsvFile.cpp
    DataExport.cpp
    DataExportCsv.cpp
    DataExportFactory.cpp
    DataExportCsvFactory.cpp
    Parameters.cpp
    CliColor.cpp
)

# ######################################################################### #

dir_pretend(SOURCES core/ ${SRCS})

set(SOURCES_CORE ${SOURCES} PARENT_SCOPE)

# ######################################################################### #
