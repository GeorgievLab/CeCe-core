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

#pragma once

/* ************************************************************************ */

namespace cece { namespace simulation { class Simulation; } }
namespace cece { namespace config { class Configuration; } }

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

/**
 * @brief Simulation initialization program.
 *
 * Initializer is invoked before simulation start and it just modify simulation
 * in a way the static description can't (e.g. create a dynamic number of objects).
 * It also doesn't make sense to store any data within initializer because it's
 * invoked only once.
 */
class Initializer
{

// Public Ctors & Dtors
public:


    /**
     * @brief Destructor.
     */
    virtual ~Initializer() = 0;


// Public Operations
public:


    /**
     * @brief Load initializer configuration.
     *
     * @param simulation Current simulation.
     * @param config     Source configuration.
     */
    virtual void loadConfig(Simulation& simulation, const config::Configuration& config);


    /**
     * @brief Store initializer configuration.
     *
     * @param simulation Current simulation.
     * @param config     Output configuration.
     */
    virtual void storeConfig(const Simulation& simulation, config::Configuration& config) const;


    /**
     * @brief Invoke initializer.
     *
     * @param simulation Simulation.
     */
    virtual void init(Simulation& simulation) const = 0;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
