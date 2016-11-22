/* ************************************************************************ */
/* Georgiev Lab (c) 2015-2016                                               */
/* ************************************************************************ */
/* Department of Cybernetics                                                */
/* Faculty of Applied Sciences                                              */
/* University of West Bohemia in Pilsen                                     */
/* ************************************************************************ */
/*                                                                          */
/* This file is part of CeCe.                                               */
/*                                                                          */
/* CeCe is free software: you can redistribute it and/or modify             */
/* it under the terms of the GNU General Public License as published by     */
/* the Free Software Foundation, either version 3 of the License, or        */
/* (at your option) any later version.                                      */
/*                                                                          */
/* CeCe is distributed in the hope that it will be useful,                  */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/* GNU General Public License for more details.                             */
/*                                                                          */
/* You should have received a copy of the GNU General Public License        */
/* along with CeCe.  If not, see <http://www.gnu.org/licenses/>.            */
/*                                                                          */
/* ************************************************************************ */

// Declaration
#include "cece/simulation/Loader.hpp"

// C++
#include <fstream>
#include <sstream>

// CeCe
#include "cece/Parameters.hpp"
#include "cece/simulation/Simulation.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

UniquePtr<Simulation> Loader::fromFile(
    const plugin::Manager& manager, const io::FilePath& filename,
    ViewPtr<const Parameters> parameters) const
{
    std::ifstream file(filename.toString(), std::ios::in);
    return fromStream(manager, file, filename, parameters);
}

/* ************************************************************************ */

UniquePtr<Simulation> Loader::fromSource(
    const plugin::Manager& manager, const String& source,
    const io::FilePath& filename, ViewPtr<const Parameters> parameters) const
{
    std::istringstream is(source, std::ios::in);
    return fromStream(manager, is, filename, parameters);
}

/* ************************************************************************ */

void Loader::toFile(const Simulation& simulation, const io::FilePath& filename) const
{
    // Write code into file
    std::ofstream file(filename.toString(), std::ios::out);
    toStream(file, simulation, filename);
}

/* ************************************************************************ */

String Loader::toSource(const Simulation& simulation, const io::FilePath& filename) const
{
    std::ostringstream os(std::ios::out);
    toStream(os, simulation, filename);
    return os.str();
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */