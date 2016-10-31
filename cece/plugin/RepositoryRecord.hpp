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
 * @brief Record for repository. Each record has own name and list of
 * factory managers for each extension type.
 * In most cases the plugin populate created record by offered objects.
 *
 * @code{.cpp}
   record
       .registerModule<MyModule>("my-module")
       .registerProgram<MyProgram>("my-program")
   ;

   record.createModule("my-module");
   record.createProgram("my-program");
   @endcode
 */
class RepositoryRecord final
{


// Public Accessors & Mutators
public:


    /**
     * Returns if loader with given name is registered.
     *
     * @param  name Loader name.
     *
     * @return
     */
    bool isRegisteredLoader(StringView name) const noexcept
    {
        return m_loaderFactoryManager.exists(name);
    }


    /**
     * Returns if initializer with given name is registered.
     *
     * @param  name Initializer name.
     *
     * @return
     */
    bool isRegisteredInitializer(StringView name) const noexcept
    {
        return m_initFactoryManager.exists(name);
    }


    /**
     * Returns if module with given name is registered.
     *
     * @param  name Module name.
     *
     * @return
     */
    bool isRegisteredModule(StringView name) const noexcept
    {
        return m_moduleFactoryManager.exists(name);
    }


    /**
     * Returns if object with given name is registered.
     *
     * @param  name Object name.
     *
     * @return
     */
    bool isRegisteredObject(StringView name) const noexcept
    {
        return m_objectFactoryManager.exists(name);
    }


    /**
     * Returns if program with given name is registered.
     *
     * @param  name Program name.
     *
     * @return
     */
    bool isRegisteredProgram(StringView name) const noexcept
    {
        return m_programFactoryManager.exists(name);
    }


// Public Mutators
public:


    /**
     * @brief Register new loader type and create factory for it.
     *
     * @tparam LoaderType Type of loader that is created by factory.
     *
     * @param name Factory name.
     *
     * @return *this.
     */
    template<typename LoaderType>
    RepositoryRecord& registerLoader(String name) noexcept
    {
        m_loaderFactoryManager.createFor<LoaderType>(std::move(name));
        return *this;
    }


    /**
     * @brief Register new initializer type and create factory for it.
     *
     * @tparam InitializerType Type of initializer that is created by factory.
     *
     * @param name Initializer name.
     *
     * @return *this.
     */
    template<typename InitializerType>
    RepositoryRecord& registerInitializer(String name) noexcept
    {
        m_initFactoryManager.createFor<InitializerType>(std::move(name));
        return *this;
    }


    /**
     * @brief Register new module type and create factory for it.
     *
     * @tparam ModuleType Type of module that is created by factory.
     *
     * @param name Factory name.
     *
     * @return *this.
     */
    template<typename ModuleType>
    RepositoryRecord& registerModule(String name) noexcept
    {
        m_moduleFactoryManager.createFor<ModuleType>(std::move(name));
        return *this;
    }


    /**
     * @brief Register new object type and create factory for it.
     *
     * @tparam ObjectType Type of object that is created by factory.
     *
     * @param name Factory name.
     *
     * @return *this.
     */
    template<typename ObjectType>
    RepositoryRecord& registerObject(String name) noexcept
    {
        m_objectFactoryManager.createFor<ObjectType>(std::move(name));
        return *this;
    }


    /**
     * @brief Register new program type and create factory for it.
     *
     * @tparam ObjectType Type of program that is created by factory.
     *
     * @param name Factory name.
     *
     * @return *this.
     */
    template<typename ProgramType>
    RepositoryRecord& registerProgram(String name) noexcept
    {
        m_programFactoryManager.createFor<ProgramType>(std::move(name));
        return *this;
    }


    /**
     * @brief Unregister loader type.
     *
     * @param name Loader type name.
     */
    void unregisterLoader(StringView name) noexcept
    {
        m_loaderFactoryManager.remove(name);
    }


    /**
     * @brief Unregister initializer type.
     *
     * @param name Initializer type name.
     */
    void unregisterInitializer(StringView name) noexcept
    {
        m_initFactoryManager.remove(name);
    }


    /**
     * @brief Unregister module type.
     *
     * @param name Module type name.
     */
    void unregisterModule(StringView name) noexcept
    {
        m_moduleFactoryManager.remove(name);
    }


    /**
     * @brief Unregister object type.
     *
     * @param name Object type name.
     */
    void unregisterObject(StringView name) noexcept
    {
        m_objectFactoryManager.remove(name);
    }


    /**
     * @brief Unregister program type.
     *
     * @param name Program type name.
     */
    void unregisterProgram(StringView name) noexcept
    {
        m_programFactoryManager.remove(name);
    }


// Public Operations
public:


    /**
     * @brief Create a loader.
     *
     * @return A loader.
     */
    UniquePtr<loader::Loader> createLoader(StringView name) const;


    /**
     * @brief Create an initializer of given type name.
     *
     * @param name Type of required initializer.
     *
     * @return Pointer to created initializer.
     */
    UniquePtr<init::Initializer> createInitializer(StringView name) const;


    /**
     * @brief Create a module of given type name.
     *
     * @param name       Type of required module.
     * @param simulation Simulation object.
     *
     * @return Pointer to created module.
     */
    UniquePtr<module::Module> createModule(StringView name, simulator::Simulation& simulation) const;


    /**
     * @brief Create an object of given type name.
     *
     * @param name       Type of required object.
     * @param simulation Simulation object.
     * @param type       Type of created object.
     *
     * @return Pointer to created object.
     */
    UniquePtr<object::Object> createObject(StringView name, simulator::Simulation& simulation, object::Object::Type type) const;


    /**
     * @brief Create a program of given type name.
     *
     * @param name Type of required program.
     *
     * @return Pointer to created program.
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
