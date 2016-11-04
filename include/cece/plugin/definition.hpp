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

// CeCe
#include "cece/config.hpp"
#include "cece/plugin/Config.hpp"

/* ************************************************************************ */

#ifdef _WIN32
// Required on Windows otherwise no symbols are exported
#  define CECE_PLUGIN_EXPORT __declspec(dllexport)
#else
#  define CECE_PLUGIN_EXPORT
#endif

/* ************************************************************************ */

#ifdef CECE_RENDER
#  define CECE_RENDER_VALUE 1
#else
#  define CECE_RENDER_VALUE 0
#endif

/* ************************************************************************ */

#ifdef CECE_THREAD_SAFE
#  define CECE_THREAD_SAFE_VALUE 1
#else
#  define CECE_THREAD_SAFE_VALUE 0
#endif

/* ************************************************************************ */

/**
 * @brief      Plugin function prototype name.
 *
 * @param      name    Function name.
 * @param      plugin  Plugin name.
 *
 * @return     Function prototype.
 */
#define CECE_PLUGIN_PROTOTYPE_NAME(name, plugin) name

/* ************************************************************************ */

/**
 * @brief      Prototype of function for creating plugin API object.
 *
 * @param      name  Plugin name.
 *
 * @return     Create plugin function prototype.
 */
#define CECE_PLUGIN_CREATE_PROTOTYPE(name) \
    extern "C" CECE_PLUGIN_EXPORT cece::plugin::Api* CECE_PLUGIN_PROTOTYPE_NAME(create, name)()

/* ************************************************************************ */

/**
 * @brief      Declare function for creating plugin API object.
 *
 * @param      name  Plugin name.
 *
 * @return     Create plugin function declaration.
 */
#define CECE_PLUGIN_DECLARE_CREATE(name) CECE_PLUGIN_CREATE_PROTOTYPE(name)

/* ************************************************************************ */

/**
 * @brief      Define function for creating plugin API object.
 *
 * @param      name       Plugin name.
 * @param      className  Plugin API class name.
 *
 * @return     Create plugin function definition.
 */
#define CECE_PLUGIN_DEFINE_CREATE(name, className) \
    CECE_PLUGIN_CREATE_PROTOTYPE(name)             \
    {                                              \
        return new className{};                    \
    }

/* ************************************************************************ */

/**
 * @brief      Prototype of function for returning plugin configuration.
 *
 * @param      name  Plugin name.
 *
 * @return     Plugin get config function prototype.
 */
#define CECE_PLUGIN_GET_CONFIG_PROTOTYPE(name) \
    extern "C" CECE_PLUGIN_EXPORT cece::plugin::Config* CECE_PLUGIN_PROTOTYPE_NAME(get_config, name)()

/* ************************************************************************ */

/**
 * @brief      Declare function for returning plugin configuration.
 *
 * @param      name  Plugin name.
 *
 * @return     Plugin get config function definition.
 */
#define CECE_PLUGIN_DECLARE_GET_CONFIG(name) CECE_PLUGIN_GET_CONFIG_PROTOTYPE(name)

/* ************************************************************************ */

/**
 * @brief      Define function for returning plugin configuration.
 *
 * @param      name  Plugin name.
 *
 * @return     Plugin get config function definition.
 */
#define CECE_PLUGIN_DEFINE_GET_CONFIG(name)                       \
    CECE_PLUGIN_GET_CONFIG_PROTOTYPE(name)                        \
    {                                                             \
        static cece::plugin::Config config = {                    \
            cece::config::PLUGIN_API_VERSION, /* apiVersion */    \
            sizeof(cece::config::RealType),   /* realSize */      \
            CECE_RENDER_VALUE,                /* renderEnabled */ \
            CECE_THREAD_SAFE_VALUE            /* threadSafe */    \
        };                                                        \
        return &config;                                           \
    }

/* ************************************************************************ */

/**
 * @brief      Declare plugin functions.
 *
 * @param      name  Plugin name.
 *
 * @return     Plugin functions declarations.
 */
#define CECE_PLUGIN_DECLARE(name)            \
    CECE_PLUGIN_DECLARE_PLUGIN_CREATE(name); \
    CECE_PLUGIN_DECLARE_GET_CONFIG(name)

/* ************************************************************************ */

/**
 * @brief      Define plugin functions.
 *
 * @param      name       Plugin name.
 * @param      className  Plugin API class name.
 *
 * @return     Plugin functions definitions.
 */
#define CECE_PLUGIN_DEFINE(name, className)    \
    CECE_PLUGIN_DEFINE_CREATE(name, className) \
    CECE_PLUGIN_DEFINE_GET_CONFIG(name)

/* ************************************************************************ */
