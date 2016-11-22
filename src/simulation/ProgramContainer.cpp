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
#include "cece/simulation/ProgramContainer.hpp"

// CeCe
#include "cece/simulation/Program.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

void ProgramContainer::call(Simulation& simulation, Object& object, unit::Time dt)
{
    // Invoke all stored programs
    for (auto& val : *this)
        val->call(simulation, object, dt);
}

/* ************************************************************************ */

ProgramContainer ProgramContainer::clone() const
{
    ProgramContainer container;

    // Clone programs
    for (const auto& program : *this)
        container.add(program->clone());

    return container;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
