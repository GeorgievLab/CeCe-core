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
#include "cece/core/IteratorRange.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/loader/Loader.hpp"
#include "cece/loader/FactoryManager.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

Manager::Manager() noexcept
    : m_repository(*this)
{
    // Nothing to do
}

/* ************************************************************************ */

Manager::~Manager() = default;

/* ************************************************************************ */

DynamicArray<String> Manager::getNames() const noexcept
{
    DynamicArray<String> names;
    names.reserve(m_plugins.size());

    for (const auto& p : m_plugins)
        names.emplace_back(p.getName());

    return names;
}

/* ************************************************************************ */

ViewPtr<Api> Manager::getApi(StringView name) const noexcept
{
    for (const auto& p : m_plugins)
    {
        if (p.getName() == name)
            return p.getApi();
    }

    return nullptr;
}

/* ************************************************************************ */

StringView Manager::getName(ViewPtr<const Api> api) const noexcept
{
    for (const auto& p : m_plugins)
    {
        if (p.getApi() == api)
            return p.getName();
    }

    return {};
}

/* ************************************************************************ */

Manager& Manager::addLoader(UniquePtr<Loader> loader)
{
    m_loaders.push_back(std::move(loader));
    ViewPtr<Loader> ptr = m_loaders.back();

    // Scan directories
    for (const auto& dir : m_directories)
    {
        auto plugins = ptr->scanDirectory(dir);
        m_plugins.insert(m_plugins.end(), make_move_iterator(plugins.begin()), make_move_iterator(plugins.end()));
    }

    return *this;
}

/* ************************************************************************ */

Manager& Manager::addDirectory(FilePath path)
{
    Log::debug("New plugins directory: `", path, "`");

    // Add directory
    m_directories.push_back(path);

    // Scan directory by loaders
    for (auto& loader : m_loaders)
    {
        // Scan directory
        auto plugins = loader->scanDirectory(path);

        // Add plugins
        m_plugins.insert(m_plugins.end(), make_move_iterator(plugins.begin()), make_move_iterator(plugins.end()));
    }

    return *this;
}

/* ************************************************************************ */

Manager& Manager::s()
{
    static Manager instance;
    return instance;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
