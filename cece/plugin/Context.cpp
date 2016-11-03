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
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/plugin/Api.hpp"
#include "cece/plugin/Exception.hpp"
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
 * @brief      Find repository record
 *
 * @param[in]  ctx    The context.
 * @param[out] names  The names
 * @param[in]  fn     Function used to check the repository record.
 *
 * @tparam     Fn     Type of test function.
 *
 * @return     Pointer to found record. Can be nullptr.
 */
template<typename Fn>
ViewPtr<const RepositoryRecord> findRecord(const Context& ctx, DynamicArray<String>& names, Fn fn)
{
    ViewPtr<const RepositoryRecord> result = nullptr;

    // Foreach imported and find repository record
    for (const auto& plugin : ctx.getImportedPlugins())
    {
        // Get record
        const auto& rec = ctx.getRepository().get(plugin);

        // Exists factory
        if (fn(rec))
        {
            result = &rec;
            names.push_back(String(plugin));
        }
    }

    return result;
}

/* ************************************************************************ */

/**
 * @brief      Helper function for plugin extension creation.
 *
 * @param[in]  ctx      The context.
 * @param[in]  kind     The kind
 * @param[in]  name     Extension registration name.
 * @param[in]  ctor     The extension construct function.
 * @param[in]  tester   The record test function.
 *
 * @tparam     T        Type of returned object.
 * @tparam     Creator  Type of ctor function.
 * @tparam     Tester   Type of tester function.
 *
 * @return     Pointer to created object.
 */
template<typename T, typename Creator, typename Tester>
UniquePtr<T> createHelper(const Context& ctx, String kind, String name, Creator ctor, Tester tester)
{
    DynamicArray<String> plugins;

    // Try to find record
    auto record = findRecord(ctx, plugins, tester);

    // Multiple imports
    if (plugins.size() > 1)
        throw MultipleExtensionsException(std::move(kind), std::move(name), std::move(plugins));

    // Factory manager selected
    if (record)
        return ctor(*record);

    // Find in other repositories to give a hint to user
    plugins = getPluginNames(ctx.getRepository(), tester);

    throw ExtensionNotFoundException(std::move(kind), std::move(name), std::move(plugins));
}

/* ************************************************************************ */

}

/* ************************************************************************ */

ViewPtr<Api> Context::importPlugin(StringView name)
{
    // Do not add duplicates
    auto it = m_importedPlugins.find(name);

    // Already imported
    if (it != m_importedPlugins.end())
        return m_manager.getApi(*it);

    Log::info("Importing plugin '", name, "'...");

    // Check if plugin is loaded
    if (!m_manager.isLoaded(name))
        throw RuntimeException("Cannot import plugin `" + String(name) + "`: No plugin with that name is not loaded.");

    // Store name of the imported plugin
    m_importedPlugins.insert(name);

    return m_manager.getApi(name);
}

/* ************************************************************************ */

ViewPtr<Api> Context::removePlugin(StringView name)
{
    // Find plugin
    auto it = m_importedPlugins.find(name);

    // Nothing to unload
    if (it == m_importedPlugins.end())
        return nullptr;

    // Remove plugin
    m_importedPlugins.erase(it);

    return m_manager.getApi(name);
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

    // Not found in any available plugins
    throw ExtensionNotFoundException("Loader", String(name), {});
}

/* ************************************************************************ */

UniquePtr<init::Initializer> Context::createInitializer(StringView name) const
{
    return createHelper<init::Initializer>(*this, "Initializer", String(name),
        [&](const RepositoryRecord& rec) {
            return rec.createInitializer(name);
        },
        [&](const RepositoryRecord& rec) {
            return rec.isRegisteredInitializer(name);
        });
}

/* ************************************************************************ */

UniquePtr<module::Module> Context::createModule(StringView name, simulator::Simulation& simulation) const
{
    return createHelper<module::Module>(*this, "Module", String(name),
        [&](const RepositoryRecord& rec) {
            return rec.createModule(name, simulation);
        },
        [&](const RepositoryRecord& rec) {
            return rec.isRegisteredModule(name);
        });
}

/* ************************************************************************ */

UniquePtr<object::Object> Context::createObject(StringView name, simulator::Simulation& simulation, object::Object::Type type) const
{
    return createHelper<object::Object>(*this, "Object", String(name),
        [&](const RepositoryRecord& rec) {
            return rec.createObject(name, simulation, type);
        },
        [&](const RepositoryRecord& rec) {
            return rec.isRegisteredObject(name);
        });
}

/* ************************************************************************ */

UniquePtr<program::Program> Context::createProgram(StringView name) const
{
    return createHelper<program::Program>(*this, "Program", String(name),
        [&](const RepositoryRecord& rec) {
            return rec.createProgram(name);
        },
        [&](const RepositoryRecord& rec) {
            return rec.isRegisteredProgram(name);
        });
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
