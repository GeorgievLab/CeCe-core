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
#include "cece/core/FilePath.hpp"
#include "cece/core/StringView.hpp"
#include "cece/core/ViewPtr.hpp"
#include "cece/core/Set.hpp"
#include "cece/core/Parameters.hpp"
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
 * @brief Plugins context for simulation.
 */
class Context
{

// Public Ctors & Dtors
public:


    /**
     * @brief Constructor.
     *
     * @param manager Plugins manager.
     */
    explicit Context(const Manager& manager) noexcept
        : m_manager(manager)
    {
        // Nothing to do
    }


// Public Accessors & Mutators
public:


    /**
     * @brief Returns plugin repository.
     *
     * @return
     */
    const Repository& getRepository() const noexcept
    {
        return m_manager.getRepository();
    }


    /**
     * @brief Returns if plugin is already imported.
     *
     * @param name Plugin name.
     *
     * @return
     */
    bool isImported(StringView name) const noexcept;


// Public Operations
public:


    /**
     * @brief Import plugin.
     *
     * @param name Plugin name.
     *
     * @return Plugin API.
     */
    ViewPtr<const Api> importPlugin(StringView name);


    /**
     * @brief Remove plugin.
     *
     * @param name Plugin name.
     *
     * @return Plugin API.
     */
    ViewPtr<const Api> removePlugin(StringView name);


    /**
     * @brief Create an initializer of given type name.
     *
     * @param typeName Type of required initializer.
     *
     * @return Pointer to created initializer.
     */
    UniquePtr<init::Initializer> createInitializer(StringView typeName) const;


    /**
     * @brief Create a module of given type name.
     *
     * @param typeName   Type of required module.
     * @param simulation Simulation object.
     *
     * @return Pointer to created module.
     */
    UniquePtr<module::Module> createModule(StringView typeName, simulator::Simulation& simulation) const;


    /**
     * @brief Create an object of given type name.
     *
     * @param typeName   Type of required object.
     * @param simulation Simulation object.
     * @param type       Type of created object.
     *
     * @return Pointer to created object.
     */
    UniquePtr<object::Object> createObject(StringView typeName, simulator::Simulation& simulation, object::Object::Type type) const;


    /**
     * @brief Create a program of given type name.
     *
     * @param typeName Type of required program.
     *
     * @return Pointer to created program.
     */
    UniquePtr<program::Program> createProgram(StringView typeName) const;


// Private Operations
private:


    /**
     * @brief Create a loader.
     *
     * @return A loader.
     */
    UniquePtr<loader::Loader> createLoader(StringView name) const;


// Private Data Members
private:

    /// Plugins manager.
    const Manager& m_manager;

    /// Imported plugins.
    Set<String> m_importedPlugins;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
