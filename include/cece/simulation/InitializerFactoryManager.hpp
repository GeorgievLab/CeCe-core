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
#include "cece/String.hpp"
#include "cece/StringView.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/factory/FactoryManager.hpp"
#include "cece/simulation/InitializerFactory.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

class Initializer;

/* ************************************************************************ */

/**
 * @brief Initializer factory manager.
 */
class InitializerFactoryManager : public factory::FactoryManager<InitializerFactory>
{

// Public Mutators
public:


    /**
     * @brief Register a new factory for specified initializer.
     *
     * @tparam InitializerType Initializer type.
     *
     * @param name Factory name.
     */
    template<typename InitializerType>
    void createForInitializer(String name)
    {
        createFor<InitializerType>(std::move(name));
    }


// Public Operations
public:


    /**
     * @brief Create an initializer by name.
     *
     * @param name Factory name.
     *
     * @return Created initializer.
     *
     * @throw InitializerFactoryNotFoundException In case of factory with given name doesn't exists.
     */
    UniquePtr<Initializer> createInitializer(StringView name) const;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */