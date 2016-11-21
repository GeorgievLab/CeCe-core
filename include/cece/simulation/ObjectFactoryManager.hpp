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
#include "cece/simulation/ObjectFactory.hpp"

/* ************************************************************************ */

namespace cece { namespace simulation { class Simulation; } }

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

class Object;

/* ************************************************************************ */

/**
 * @brief Object factory manager.
 */
class ObjectFactoryManager : public factory::FactoryManager<ObjectFactory>
{

// Public Operations
public:


    /**
     * @brief Create an object by name.
     *
     * @param name       Factory name.
     * @param simulation Owning simulation.
     * @param type       Object type.
     *
     * @return Created object.
     *
     * @throw ObjectFactoryNotFoundException In case of factory with given name doesn't exists.
     */
    UniquePtr<Object> createObject(StringView name, simulation::Simulation& simulation, Object::Type type) const;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
