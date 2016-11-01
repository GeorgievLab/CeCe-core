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

// C++
#include <utility>

// CeCe
#include "cece/core/String.hpp"
#include "cece/core/StringView.hpp"
#include "cece/loader/FactoryManager.hpp"
#include "cece/init/FactoryManager.hpp"
#include "cece/object/FactoryManager.hpp"
#include "cece/module/FactoryManager.hpp"
#include "cece/program/FactoryManager.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief       Record for repository.
 *
 * @details     Each record has own name and list of factory
 *              managers for each extension type. In most cases the plugin
 *              populate created record by offered objects.
 *
 *              @code{.cpp}
record
   .registerModule<MyModule>("my-module")
   .registerProgram<MyProgram>("my-program")
;

auto module = record.createModule("my-module");
auto program = record.createProgram("my-program");
@endcode
 */
class RepositoryRecord final
{

// Public Accessors & Mutators
public:


    /**
     * @brief      Checks if a loader is registered under given name.
     *
     * @param[in]  name  Registration name.
     *
     * @return     Is a loader with given name registered?
     */
    bool isRegisteredLoader(StringView name) const noexcept
    {
        return m_loaderFactoryManager.exists(name);
    }


    /**
     * @brief      Checks if an initializer is registered under given name.
     *
     * @param[in]  name  Registration name.
     *
     * @return     Is an initializer with given name registered?
     */
    bool isRegisteredInitializer(StringView name) const noexcept
    {
        return m_initFactoryManager.exists(name);
    }


    /**
     * @brief      Checks if a module is registered under given name.
     *
     * @param[in]  name  Registration name.
     *
     * @return     Is an initializer with given name registered?
     */
    bool isRegisteredModule(StringView name) const noexcept
    {
        return m_moduleFactoryManager.exists(name);
    }


    /**
     * @brief      Checks if an object is registered under given name.
     *
     * @param[in]  name  Registration name.
     *
     * @return     Is an object with given name registered?
     */
    bool isRegisteredObject(StringView name) const noexcept
    {
        return m_objectFactoryManager.exists(name);
    }


    /**
     * @brief      Checks if a program is registered under given name.
     *
     * @param[in]  name  Registration name.
     *
     * @return     Is a program with given name registered?
     */
    bool isRegisteredProgram(StringView name) const noexcept
    {
        return m_programFactoryManager.exists(name);
    }


// Public Mutators
public:


    /**
     * @brief      Register a new loader type.
     *
     * @param[in]  name        Loader registration name.
     *
     * @tparam     LoaderType  Type of a loader registered under given name.
     *
     * @return     *this.
     * @throws     Exception  If another loader is already registered under given name.
     */
    template<typename LoaderType>
    RepositoryRecord& registerLoader(String name)
    {
        m_loaderFactoryManager.createFor<LoaderType>(std::move(name));
        return *this;
    }


    /**
     * @brief      Register a new initializer type.
     *
     * @param[in]  name             Initializer registration name.
     *
     * @tparam     InitializerType  Type of an initializer registered under
     *                              given name.
     *
     * @return     *this.
     * @throws     Exception  If another initializer is already registered under given
     *                        name.
     */
    template<typename InitializerType>
    RepositoryRecord& registerInitializer(String name)
    {
        m_initFactoryManager.createFor<InitializerType>(std::move(name));
        return *this;
    }


    /**
     * @brief      Register a new module type.
     *
     * @param[in]  name        Module registration name.
     *
     * @tparam     ModuleType  Type of a module registered under given name.
     *
     * @return     *this.
     * @throws     Exception  If another module is already registered under given name.
     */
    template<typename ModuleType>
    RepositoryRecord& registerModule(String name)
    {
        m_moduleFactoryManager.createFor<ModuleType>(std::move(name));
        return *this;
    }


    /**
     * @brief      Register a new object type.
     *
     * @param[in]  name        Object registration name.
     *
     * @tparam     ObjectType  Type of an object registered under given name.
     *
     * @return     *this.
     * @throws     Exception  If another object is already registered under given name.
     */
    template<typename ObjectType>
    RepositoryRecord& registerObject(String name)
    {
        m_objectFactoryManager.createFor<ObjectType>(std::move(name));
        return *this;
    }


    /**
     * @brief      Register a new program type.
     *
     * @param[in]  name         Program registration name.
     *
     * @tparam     ProgramType  Type of a program registered under given name.
     *
     * @return     *this.
     * @throws     Exception  If another program is already registered under given
     *                        name.
     */
    template<typename ProgramType>
    RepositoryRecord& registerProgram(String name)
    {
        m_programFactoryManager.createFor<ProgramType>(std::move(name));
        return *this;
    }


    /**
     * @brief      Unregister loader type.
     *
     * @param[in]  name  Loader registration name.
     */
    void unregisterLoader(StringView name) noexcept
    {
        m_loaderFactoryManager.remove(name);
    }


    /**
     * @brief      Unregister initializer type.
     *
     * @param[in]  name  Initializer registration name.
     */
    void unregisterInitializer(StringView name) noexcept
    {
        m_initFactoryManager.remove(name);
    }


    /**
     * @brief      Unregister module type.
     *
     * @param[in]  name  Module registration name.
     */
    void unregisterModule(StringView name) noexcept
    {
        m_moduleFactoryManager.remove(name);
    }


    /**
     * @brief      Unregister object type.
     *
     * @param[in]  name  Object registration name.
     */
    void unregisterObject(StringView name) noexcept
    {
        m_objectFactoryManager.remove(name);
    }


    /**
     * @brief      Unregister program type.
     *
     * @param[in]  name  Program registration name.
     */
    void unregisterProgram(StringView name) noexcept
    {
        m_programFactoryManager.remove(name);
    }


// Public Operations
public:


    /**
     * @brief      Create a loader.
     *
     * @details    Return value must be valid pointer (no `nullptr`). If a
     *             loader cannot be created an exception should be thrown.
     *
     * @param[in]  name  Loader registration name.
     *
     * @return     A pointer to created loader.
     * @throws     Exception  If loader cannot be created.
     */
    UniquePtr<loader::Loader> createLoader(StringView name) const;


    /**
     * @brief      Create an initializer.
     *
     * @details    Return value must be valid pointer (no `nullptr`). If an
     *             initializer cannot be created an exception should be thrown.
     *
     * @param[in]  name  Initializer registration name.
     *
     * @return     A pointer to created initializer.
     * @throws     Exception  If initializer cannot be created.
     */
    UniquePtr<init::Initializer> createInitializer(StringView name) const;


    /**
     * @brief      Create a module.
     *
     * @details    Return value must be valid pointer (no `nullptr`). If a
     *             module cannot be created an exception should be thrown.
     *
     * @param[in]  name        Module registration name.
     * @param      simulation  The simulation
     *
     * @return     A pointer to created module.
     * @throws     Exception  If module cannot be created.
     */
    UniquePtr<module::Module> createModule(StringView name, simulator::Simulation& simulation) const;


    /**
     * @brief      Create an object.
     *
     * @details    Return value must be valid pointer (no `nullptr`). If a
     *             module cannot be created an exception should be thrown.
     *
     * @param[in]  name        Module registration name.
     * @param      simulation  The simulation
     * @param[in]  type        The type
     *
     * @return     A pointer to created module.
     * @throws     Exception  If module cannot be created.
     */
    UniquePtr<object::Object> createObject(StringView name, simulator::Simulation& simulation, object::Object::Type type) const;


    /**
     * @brief      Create a program.
     *
     * @details    Return value must be valid pointer (no `nullptr`). If a
     *             program cannot be created an exception should be thrown.
     *
     * @param[in]  name  Program registration name.
     *
     * @return     A pointer to created program.
     * @throws     Exception  If program cannot be created.
     */
    UniquePtr<program::Program> createProgram(StringView name) const;


// Private Data Members
private:

    /// Loader factory manager.
    loader::FactoryManager m_loaderFactoryManager;

    /// Initializer factory manager.
    init::FactoryManager m_initFactoryManager;

    /// Module factory manager.
    module::FactoryManager m_moduleFactoryManager;

    /// Object factory manager.
    object::FactoryManager m_objectFactoryManager;

    /// Program factory manager.
    program::FactoryManager m_programFactoryManager;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
