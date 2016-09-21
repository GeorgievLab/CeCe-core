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
#include "cece/core/String.hpp"
#include "cece/core/StringView.hpp"
#include "cece/core/DynamicArray.hpp"
#include "cece/core/ViewPtr.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Loader.hpp"
#include "cece/plugin/Repository.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

class Api;

/* ************************************************************************ */

/**
 * @brief Manager of simulator plugins.
 *
 * This class is responsible for loading and unloading plugins. It all begins
 * with registering plugins directory:
 * @code
    plugin::Manager m;
    m.addDirectory("plugins");
   @endcode
 * which scan given plugins directory and store paths of those plugins into internal
 * variable. Then when plugin is required, it's loaded from given path.
 * @code
    plugin::Manager m;
    auto pluginApi = m.load("myplugin");
   @endcode
 * Loading plugin also loads dependent plugins.
 */
class Manager final
{

// Public Ctors & Dtors
public:


    /**
     * @brief Constructor.
     */
    Manager() noexcept;


    /**
     * @brief Destructor.
     */
    ~Manager();


// Public Accessors
public:


    /**
     * @brief Returns plugin repository.
     *
     * @return
     */
    Repository& getRepository() noexcept
    {
        return m_repository;
    }


    /**
     * @brief Returns plugin repository.
     *
     * @return
     */
    const Repository& getRepository() const noexcept
    {
        return m_repository;
    }


    /**
     * @brief Returns plugin loaders.
     *
     * @return
     */
    const DynamicArray<UniquePtr<Loader>>& getLoaders() const noexcept
    {
        return m_loaders;
    }


    /**
     * @brief Returns plugins search directories.
     *
     * @return List of directories.
     */
    const DynamicArray<FilePath>& getDirectories() const noexcept
    {
        return m_directories;
    }


    /**
     * @brief Return a list of plugins.
     *
     * @return An array of plugin names.
     */
    DynamicArray<String> getNames() const noexcept;


    /**
     * @brief Check if plugin is loaded.
     *
     * @param name Plugin name.
     *
     * @return
     */
    bool isLoaded(StringView name) const noexcept;


    /**
     * @brief Returns plugin API of loaded plugin.
     *
     * @param name Plugin name.
     *
     * @return Pointer to API or nullptr, if plugin is not loaded.
     */
    ViewPtr<Api> getApi(StringView name) const noexcept;


    /**
     * @brief Find API name.
     *
     * @param name Plugin API.
     *
     * @return Plugin name.
     */
    StringView getName(ViewPtr<const Api> api) const noexcept;


// Public Mutators
public:


    /**
     * @brief Add a plugin loader.
     *
     * It also invoke loader's scan function for all currently stored paths.
     *
     * @param loader Pointer to plugin loader.
     *
     * @return *this.
     */
    Manager& addLoader(UniquePtr<Loader> loader);


    /**
     * @brief Store additional directories.
     *
     * @param directories List of directories.
     *
     * @return *this
     */
    Manager& addDirectories(DynamicArray<FilePath> directories)
    {
        for (auto&& directory : directories)
            addDirectory(std::move(directory));

        return *this;
    }


    /**
     * @brief Add directory where the plugins are stored.
     *
     * For all stored loaders, it invoke their scan function.
     *
     * @param path Path with plugins.
     *
     * @return *this
     */
    Manager& addDirectory(FilePath path);


// Public Operations
public:


    /**
     * @brief Returns global instance of plugin manager.
     *
     * @return
     */
    static Manager& s();


// Private Data Members
private:

    /// Plugin repository.
    Repository m_repository;

    /// Plugin loaders.
    DynamicArray<UniquePtr<Loader>> m_loaders;

    /// Plugins directory paths.
    DynamicArray<FilePath> m_directories;

    /// List of loaded plugins.
    DynamicArray<Plugin> m_plugins;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
