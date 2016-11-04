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
#include "cece/plugin/Exception.hpp"

// C++
#include <utility>

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief Join strings from array.
 *
 * @param array
 *
 * @return
 */
String join(const DynamicArray<String>& array) noexcept
{
    String res;

    for (auto it = array.begin(); it != array.end(); ++it)
    {
        if (it != array.begin())
            res += ", ";

        res += *it;
    }

    return res;
}

/* ************************************************************************ */

}

/* ************************************************************************ */

InvalidPluginException::InvalidPluginException(FilePath path, String msg) noexcept
    : Exception("Plugin `" + path.toString() + "`: " + msg)
    , m_path(std::move(path))
    , m_errorMessage(std::move(msg))
{
    // Nothing to do
}

/* ************************************************************************ */

PluginNotFoundException::PluginNotFoundException(String name) noexcept
    : Exception("Plugin `" + name + "` not found.")
    , m_name(std::move(name))
{
    // Nothing to do
}

/* ************************************************************************ */

MultipleExtensionsException::MultipleExtensionsException(String kind, String name, DynamicArray<String> plugins) noexcept
    : Exception("Multiple extensions " + name + "(" + kind + ") found in imported plugins: " + join(plugins) + ".")
    , m_name(std::move(name))
    , m_pluginNames(std::move(plugins))
{
    // Nothing to do
}

/* ************************************************************************ */

ExtensionNotFoundException::ExtensionNotFoundException(String kind, String name, DynamicArray<String> plugins) noexcept
    : Exception("Extension " + name + "(" + kind + ") found in imported plugins. Found in plugins: " + join(plugins) + ".")
    , m_name(std::move(name))
    , m_pluginNames(std::move(plugins))
{
    // Nothing to do
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
