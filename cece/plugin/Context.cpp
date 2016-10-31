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
#include "cece/plugin/Context.hpp"

// C++
#include <algorithm>

// CeCe
#include "cece/core/Log.hpp"
#include "cece/core/Exception.hpp"
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/plugin/Api.hpp"
#include "cece/loader/Loader.hpp"
#include "cece/init/Initializer.hpp"
#include "cece/module/Module.hpp"
#include "cece/object/Object.hpp"
#include "cece/program/Program.hpp"
#include "cece/simulator/Simulation.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief Find factory name in all plugins to give a hint for user.
 *
 * @param repo
 * @param fn
 *
 * @return
 */
template<typename RecordFn>
DynamicArray<String> getPluginNames(const Repository& repo, RecordFn fn)
{
    DynamicArray<String> names;

    // Foreach repository records
    for (const auto& record : repo.getRecords())
    {
        if (fn(record.second))
            names.push_back(record.first);
    }

    return names;
}

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

bool Context::isImported(StringView name) const noexcept
{
    return m_importedPlugins.find(String(name)) != m_importedPlugins.end();
}

/* ************************************************************************ */

ViewPtr<const Api> Context::importPlugin(StringView name)
{
    // Do not add duplicates
    auto it = m_importedPlugins.find(String(name));

    // Already imported
    if (it != m_importedPlugins.end())
        return m_manager.getApi(*it);

    Log::info("Importing plugin '", name, "'...");

    // Load plugin
    auto api = m_manager.getApi(name);

    // Plugin not found
    if (!api)
        throw RuntimeException("Cannot import plugin: " + String(name));

    // Check conflict plugins
    for (const auto& pluginName : api->conflictPlugins())
    {
        if (isImported(pluginName))
            throw RuntimeException("Cannot import plugin: " + String(name) + ". Confliction with plugin: " + pluginName);
    }

    // Import required plugins
    for (const auto& pluginName : api->requiredPlugins())
        importPlugin(pluginName);

    // Store API
    m_importedPlugins.insert(String(name));

    return api;
}

/* ************************************************************************ */

ViewPtr<const Api> Context::removePlugin(StringView name)
{
    // Find plugin
    auto it = m_importedPlugins.find(String(name));

    // Nothing to unload
    if (it == m_importedPlugins.end())
        return nullptr;

    // Remove plugin
    m_importedPlugins.erase(it);

    return m_manager.getApi(name);
}

/* ************************************************************************ */

UniquePtr<init::Initializer> Context::createInitializer(StringView typeName) const
{
    ViewPtr<const RepositoryRecord> resultRecord;
    DynamicArray<String> importedNames;

    // Foreach loaded APIs and find factory
    for (const auto& plugin : m_importedPlugins)
    {
        // Get record
        auto rec = getRepository().get(plugin);

        // Exists factory
        if (rec && rec->isRegisteredInitializer(typeName))
        {
            resultRecord = rec;
            importedNames.push_back(plugin);
        }
    }

    // Multiple imports
    if (importedNames.size() > 1)
    {
        throw RuntimeException(
            "Multiple definition of module: " + String(typeName) + ". Module found in imported plugin(s): " + join(importedNames)
        );
    }

    // Factory manager selected
    if (resultRecord)
        return resultRecord->createInitializer(typeName);

    // Find in other APIs to give a hint to user
    auto names = getPluginNames(getRepository(), [typeName](const RepositoryRecord& rec) {
        return rec.isRegisteredInitializer(typeName);
    });

    throw RuntimeException(
        "Cannot create initializer: " + String(typeName) + ". Initializer found in plugin(s): " + join(names)
    );
}

/* ************************************************************************ */

UniquePtr<module::Module> Context::createModule(StringView typeName, simulator::Simulation& simulation) const
{
    ViewPtr<const RepositoryRecord> resultRecord;
    DynamicArray<String> importedNames;

    // Foreach loaded APIs and find factory
    for (const auto& plugin : m_importedPlugins)
    {
        // Get record
        auto rec = getRepository().get(plugin);

        // Exists factory
        if (rec && rec->isRegisteredModule(typeName))
        {
            resultRecord = rec;
            importedNames.push_back(plugin);
        }
    }

    // Multiple imports
    if (importedNames.size() > 1)
    {
        throw RuntimeException(
            "Multiple definition of module: " + String(typeName) + ". Module found in imported plugin(s): " + join(importedNames)
        );
    }

    // Factory manager selected
    if (resultRecord)
        return resultRecord->createModule(typeName, simulation);

    // Find in other APIs to give a hint to user
    auto names = getPluginNames(getRepository(), [typeName](const RepositoryRecord& rec) {
        return rec.isRegisteredModule(typeName);
    });

    throw RuntimeException(
        "Cannot create module: " + String(typeName) + ". Module found in plugin(s): " + join(names)
    );
}

/* ************************************************************************ */

UniquePtr<object::Object> Context::createObject(StringView typeName, simulator::Simulation& simulation, object::Object::Type type) const
{
    ViewPtr<const RepositoryRecord> resultRecord;
    DynamicArray<String> importedNames;

    // Foreach loaded APIs and find factory
    for (const auto& plugin : m_importedPlugins)
    {
        // Get record
        auto rec = getRepository().get(plugin);

        // Exists factory
        if (rec && rec->isRegisteredObject(typeName))
        {
            resultRecord = rec;
            importedNames.push_back(plugin);
        }
    }

    // Multiple imports
    if (importedNames.size() > 1)
    {
        throw RuntimeException(
            "Multiple definition of object: " + String(typeName) + ". Object found in imported plugin(s): " + join(importedNames)
        );
    }

    // Factory manager selected
    if (resultRecord)
        return resultRecord->createObject(typeName, simulation, type);

    // Find in other APIs to give a hint to user
    auto names = getPluginNames(getRepository(), [typeName](const RepositoryRecord& rec) {
        return rec.isRegisteredObject(typeName);
    });

    throw RuntimeException(
        "Cannot create object: " + String(typeName) + ". Object found in plugin(s): " + join(names)
    );
}

/* ************************************************************************ */

UniquePtr<program::Program> Context::createProgram(StringView typeName) const
{
    ViewPtr<const RepositoryRecord> resultRecord;
    DynamicArray<String> importedNames;

    // Foreach loaded APIs and find factory
    for (const auto& plugin : m_importedPlugins)
    {
        // Get record
        auto rec = getRepository().get(plugin);

        // Exists factory
        if (rec && rec->isRegisteredProgram(typeName))
        {
            resultRecord = rec;
            importedNames.push_back(plugin);
        }
    }

    // Multiple imports
    if (importedNames.size() > 1)
    {
        throw RuntimeException(
            "Multiple definition of program: " + String(typeName) + ". Program found in imported plugin(s): " + join(importedNames)
        );
    }

    // Factory manager selected
    if (resultRecord)
        return resultRecord->createProgram(typeName);

    // Find in other APIs to give a hint to user
    auto names = getPluginNames(getRepository(), [typeName](const RepositoryRecord& rec) {
        return rec.isRegisteredProgram(typeName);
    });

    throw RuntimeException(
        "Cannot create program: " + String(typeName) + ". Program found in plugin(s): " + join(names)
    );
}

/* ************************************************************************ */

UniquePtr<loader::Loader> Context::createLoader(StringView name) const
{
    // Foreach repository records and find loader with given name
    for (const auto& item : getRepository().getRecords())
    {
        const auto& record = item.second;

        // Exists factory
        if (record.isRegisteredLoader(name))
            return record.createLoader(name);
    }

    throw RuntimeException("Unable to find loader '" + String(name) + "'");
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
