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
#include "cece/StringView.hpp"
#include "cece/ViewPtr.hpp"
#include "cece/Set.hpp"
#include "cece/Parameters.hpp"
#include "cece/io/FilePath.hpp"
#include "cece/plugin/Manager.hpp"

/// @deprecated
#include "cece/object/Object.hpp"

/* ************************************************************************ */

namespace cece {
    namespace loader    { class Loader; }
    namespace init      { class Initializer; }
    namespace module    { class Module; }
    //namespace object    { class Object; }
    namespace object    { class Type; }
    namespace program   { class Program; }
    namespace simulator { class Simulation; }
}

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

class Api;
class Repository;

/* ************************************************************************ */

/**
 * @brief      Plugins context for simulation.
 */
class Context
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param      manager  Plugins manager.
     */
    explicit Context(const Manager& manager) noexcept
        : m_manager(manager)
    {
        // Nothing to do
    }


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns plugin repository.
     *
     * @return     The repository.
     */
    const Repository& getRepository() const noexcept
    {
        return m_manager.getRepository();
    }


    /**
     * @brief      Returns a set of imported plugin names.
     *
     * @return     A set of imported plugin names.
     */
    const Set<StringView>& getImportedPlugins() const noexcept
    {
        return m_importedPlugins;
    }


    /**
     * @brief      Returns if plugin is already imported.
     *
     * @param      name  Plugin name.
     *
     * @return     True if a plugin with given name is imported, False otherwise.
     */
    bool isImported(StringView name) const noexcept
    {
        return m_importedPlugins.find(name) != m_importedPlugins.end();
    }


// Public Operations
public:


    /**
     * @brief      Import plugin.
     *
     * @param      name  Plugin name.
     *
     * @return     Imported plugin API.
     * @throws     PluginNotFoundException  When plugin with given name is not loaded.
     */
    ViewPtr<Api> importPlugin(StringView name);


    /**
     * @brief      Remove imported plugin.
     *
     * @param      name  Plugin name.
     *
     * @return     Plugin API.
     */
    ViewPtr<Api> removePlugin(StringView name);


    /**
     * @brief      Create a loader.
     *
     * @param      name  Loader registration name.
     *
     * @return     Pointer to the created loader.
     * @throws     cece::Exception             When a loader cannot be created.
     * @throws     ExtensionNotFoundException  When a loader is not found.
     */
    UniquePtr<loader::Loader> createLoader(StringView name) const;


    /**
     * @brief      Create an initializer.
     *
     * @param      name  Initializer registration name.
     *
     * @return     Pointer to the created initializer.
     * @throws     cece::Exception              When an initializer cannot be created.
     * @throws     ExtensionNotFoundException   When an initializer is not found in
     *                                          imported plugins.
     * @throws     MultipleExtensionsException  When an initializer with same name is
     *                                          found in multiple plugins.
     */
    UniquePtr<init::Initializer> createInitializer(StringView name) const;


    /**
     * @brief      Create a module.
     *
     * @param      name        Module registration name.
     * @param      simulation  Simulation object.
     *
     * @return     Pointer to created module.
     * @throws     cece::Exception              When a module cannot be created.
     * @throws     ExtensionNotFoundException   When a module is not found in imported
     *                                          plugins.
     * @throws     MultipleExtensionsException  When a module with same name is found
     *                                          in multiple plugins.
     */
    UniquePtr<module::Module> createModule(StringView name, simulator::Simulation& simulation) const;


    /**
     * @brief      Create an object.
     *
     * @param      name        Object registration name.
     * @param      simulation  Simulation object.
     * @param      type        Type of created object.
     *
     * @return     Pointer to created object.
     * @throws     cece::Exception              When an object cannot be created.
     * @throws     ExtensionNotFoundException   When an object is not found in imported
     *                                          plugins.
     * @throws     MultipleExtensionsException  When an object with same name is found
     *                                          in multiple plugins.
     */
    UniquePtr<object::Object> createObject(StringView name, simulator::Simulation& simulation, object::Object::Type type) const;


    /**
     * @brief      Create a program
     *
     * @param[in]  name  Program registration name.
     *
     * @return     Pointer to created program.
     * @throws     cece::Exception              When a program cannot be created.
     * @throws     ExtensionNotFoundException   When a program is not found in imported
     *                                          plugins.
     * @throws     MultipleExtensionsException  When a program with same name is found
     *                                          in multiple plugins.
     */
    UniquePtr<program::Program> createProgram(StringView name) const;


// Private Data Members
private:

    /// Plugins manager.
    const Manager& m_manager;

    /// Imported plugins.
    Set<StringView> m_importedPlugins;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
