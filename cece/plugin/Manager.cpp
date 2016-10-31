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
#include "Manager.hpp"

// C++
#include <utility>

// CeCe
#include "cece/core/Assert.hpp"
#include "cece/core/Log.hpp"
#include "cece/core/Exception.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

Manager::Manager() noexcept
{
    // Nothing to do
}

/* ************************************************************************ */

Manager::~Manager()
{
    // Unload plugins
    for (auto& plugin : m_plugins)
    {
        // Unload plugin
        plugin.getApi()->onUnload(m_repository);

        // Explicit record remove
        // It's easy to forget to remove record from repository and in most
        // cases the record have same name as the plugin
        m_repository.removeRecord(plugin.getName());
    }
}

/* ************************************************************************ */

DynamicArray<String> Manager::getNames() const noexcept
{
    DynamicArray<String> names;
    names.reserve(m_plugins.size());

    for (const auto& plugin : m_plugins)
        names.emplace_back(plugin.getName());

    return names;
}

/* ************************************************************************ */

bool Manager::isLoaded(StringView name) const noexcept
{
    for (const auto& plugin : m_plugins)
    {
        if (plugin.getName() == name)
            return true;
    }

    return false;
}

/* ************************************************************************ */

ViewPtr<Api> Manager::getApi(StringView name) const noexcept
{
    CECE_ASSERT(!name.isEmpty());

    for (const auto& plugin : m_plugins)
    {
        if (plugin.getName() == name)
            return plugin.getApi();
    }

    return nullptr;
}

/* ************************************************************************ */

StringView Manager::getName(ViewPtr<const Api> api) const noexcept
{
    CECE_ASSERT(api);

    for (const auto& plugin : m_plugins)
    {
        if (plugin.getApi() == api)
            return plugin.getName();
    }

    return {};
}

/* ************************************************************************ */

Manager& Manager::addLoader(UniquePtr<Loader> loader)
{
    CECE_ASSERT(loader);

    Log::debug("New plugins loader.");

    m_loaders.push_back(std::move(loader));

    // Scan directories
    for (const auto& dir : m_directories)
    {
        CECE_ASSERT(!m_loaders.empty());
        appendPlugins(m_loaders.back()->loadAll(dir));
    }

    return *this;
}

/* ************************************************************************ */

Manager& Manager::addDirectory(FilePath path)
{
    CECE_ASSERT(!path.isEmpty());

    Log::debug("New plugins directory: `", path, "`.");

    // Add directory
    m_directories.push_back(std::move(path));

    // Scan directory by loaders
    for (auto& loader : m_loaders)
        appendPlugins(loader->loadAll(m_directories.back()));

    return *this;
}

/* ************************************************************************ */

void Manager::appendPlugins(DynamicArray<Plugin> plugins)
{
    // Load and store plugins
    for (auto&& plugin : plugins)
    {
        plugin.getApi()->onLoad(m_repository);
        m_plugins.push_back(std::move(plugin));
    }
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
