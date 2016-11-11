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

namespace cece {
    namespace config    { class Configuration; }
    namespace simulation { class Simulation; }
}

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

class RepositoryRecord;

/* ************************************************************************ */

/**
 * @brief      Plugin API abstract class.
 *
 * @details    Custom plugins implements this class' functions to provide
 *             additional functionality to the simulator.
 *
 *             Each valid plugin must export a function which create an instance
 *             of own Api class implementation. Api have several optional member
 *             functions which are called in different times.
 *
 * - `onLoad` - When the plugin is loaded into a Manager. Main purpose of this
 *   function is initialize plugin for global use and in most cases register
 *   offered extensions into repository.
 * - `onUnload` - Opposite of the `onLoad` function. It's called when the plugin
 *   is being unloaded from the Manager.
 * - `onImport` - When the plugin is being imported/used by the simulation.
 * - `onRemove` - When the plugin is being de-imported by the simulation.
 * - `storeConfig` - Support function used only when the memory representation
 *   needs to be stored.
 */
class Api
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Destructor.
     */
    virtual ~Api() = 0;


// Public Operations
public:


    /**
     * @brief      When the plugin is loaded by plugin manager.
     *
     * @param      repository  Repository record for the plugin.
     */
    virtual void onLoad(RepositoryRecord& repository)
    {
        // Nothing to do
    }


    /**
     * @brief      When the plugin is unloaded from plugin manager.
     *
     * @param      repository  Repository record for the plugin.
     */
    virtual void onUnload(RepositoryRecord& repository)
    {
        // Nothing to do
    }


    /**
     * @brief      When the plugin is imported into simulation.
     *
     * @param      simulation  The simulation which imports the plugin.
     * @param[in]  config      Plugin import configuration.
     */
    virtual void onImport(simulation::Simulation& simulation, const config::Configuration& config)
    {
        // Nothing to do
    }


    /**
     * @brief      When the plugin is being removed from the simulation.
     *
     * @param      simulation  The simulation.
     */
    virtual void onRemove(simulation::Simulation& simulation)
    {
        // Nothing to do
    }


    /**
     * @brief      Store plugin configuration.
     *
     * @param[in]  simulation  Current simulation.
     * @param      config      Output plugin configuration.
     */
    virtual void storeConfig(const simulation::Simulation& simulation, config::Configuration& config) const
    {
        // Nothing to do
    }

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
