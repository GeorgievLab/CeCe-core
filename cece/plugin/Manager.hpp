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
 * @brief      Manager of simulator plugins.
 *
 * @details    The functionality is based on two things: plugin loader and
 *             plugin directory.
 *
 *             Plugin directory are path of directory where loaded plugins are
 *             stored and where loaders looks for available plugins. Loader
 *             looks into plugins directory and according to own rules it loads
 *             plugins found in plugins directory. By default, manager needs to
 *             add a plugin loader (SharedLibraryLoader is available) and
 *             specify plugins directory. No additional action is required,
 *             calling one either `addLoader` or `addDirectory` invoke plugins
 *             loading. For each loaded valid plugin the `Api::onLoad` is called
 *             and when the manager is being destroyed the `Api::onUnload` is
 *             called.
 *
 * @note       The plugin loader is responsible for proper plugin loading and
 *             the plugin code must be loaded in memory until `Loader` is
 *             destroyed.
 */
class Manager final
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     */
    Manager();


    /**
     * @brief      Destructor.
     */
    ~Manager();


// Public Accessors
public:


    /**
     * @brief      Returns mutable plugin repository.
     *
     * @return     Manager's repository.
     */
    Repository& getRepository() noexcept
    {
        return m_repository;
    }


    /**
     * @brief      Returns immutable plugin repository.
     *
     * @return     Manager's repository.
     */
    const Repository& getRepository() const noexcept
    {
        return m_repository;
    }


    /**
     * @brief      Returns plugin loaders.
     *
     * @return     A list of plugin loaders.
     */
    const DynamicArray<UniquePtr<Loader>>& getLoaders() const noexcept
    {
        return m_loaders;
    }


    /**
     * @brief      Returns plugins search directories.
     *
     * @return     A list of directories.
     */
    const DynamicArray<FilePath>& getDirectories() const noexcept
    {
        return m_directories;
    }


    /**
     * @brief      Return a list of plugins.
     *
     * @return     An array of plugin names.
     */
    DynamicArray<StringView> getNames() const noexcept;


    /**
     * @brief      Check if plugin is loaded.
     *
     * @param[in]  name  Plugin name.
     *
     * @return     True if plugin is loaded, False otherwise.
     */
    bool isLoaded(StringView name) const noexcept;


    /**
     * @brief      Returns plugin API of loaded plugin.
     *
     * @param[in]  name  Plugin name.
     *
     * @return     Pointer to API or nullptr, if plugin is not loaded.
     */
    ViewPtr<Api> getApi(StringView name) const noexcept;


// Public Mutators
public:


    /**
     * @brief      Add a plugin loader.
     *
     *             It also invoke loader's scan function for all currently
     *             stored paths.
     *
     * @param[in]  loader  Pointer to plugin loader.
     *
     * @return     *this.
     */
    Manager& addLoader(UniquePtr<Loader> loader);


    /**
     * @brief      Store additional directories.
     *
     * @param[in]  directories  List of directories.
     *
     * @return     *this.
     */
    Manager& addDirectories(DynamicArray<FilePath> directories)
    {
        for (auto&& directory : directories)
            addDirectory(std::move(directory));

        return *this;
    }


    /**
     * @brief      Add directory where the plugins are stored.
     *
     * @details    For all stored loaders, it invoke their scan function.
     *
     * @param[in]  path  Path with plugins.
     *
     * @return     *this
     */
    Manager& addDirectory(FilePath path);


    /**
     * @brief      Register a custom plugin.
     *
     * @details    The function also calls `Api::onLoad` function.
     *
     * @param[in]  plugin  The plugin.
     */
    void addPlugin(Plugin plugin);


// Private Operations
private:


    /**
     * @brief      Add plugins into inner list.
     *
     * @param[in]  plugins  Plugins to add.
     */
    void appendPlugins(DynamicArray<Plugin> plugins);


// Private Data Members
private:

    /// Plugin loaders.
    DynamicArray<UniquePtr<Loader>> m_loaders;

    /// Plugins directory paths.
    DynamicArray<FilePath> m_directories;

    /// List of loaded plugins.
    DynamicArray<Plugin> m_plugins;

    /// Plugin repository.
    Repository m_repository;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
