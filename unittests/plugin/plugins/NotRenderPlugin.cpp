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

class NotRenderPluginApi : public cece::plugin::Api { };

// Create function
CECE_PLUGIN_DEFINE_CREATE(not_render_plugin, NotRenderPluginApi)

// Get config
CECE_PLUGIN_GET_CONFIG_PROTOTYPE(not_render_plugin)
{
    static cece::plugin::Config config = {
        cece::PLUGIN_API_VERSION,
        sizeof(cece::RealType),
        !CECE_RENDER_VALUE,
        CECE_THREAD_SAFE_VALUE
    };
    return &config;
}

/* ************************************************************************ */
