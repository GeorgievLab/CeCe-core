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

// CeCe
#include "cece/plugin/definition.hpp"
#include "cece/plugin/Api.hpp"

class DifferentRealPluginApi : public cece::plugin::Api { };

// Create function
CECE_PLUGIN_DEFINE_CREATE(different_real_plugin, DifferentRealPluginApi)

// Get config
CECE_PLUGIN_GET_CONFIG_PROTOTYPE(different_real_plugin)
{
    static cece::plugin::Config config = {
        cece::config::PLUGIN_API_VERSION,
        16, // 128bit float
        CECE_RENDER_VALUE,
        CECE_THREAD_SAFE_VALUE
    };
    return &config;
}

/* ************************************************************************ */
