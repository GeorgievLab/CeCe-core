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
#include "cece/ViewPtr.hpp"
#include "cece/Pair.hpp"
#include "cece/DynamicArray.hpp"
#include "cece/simulation/ObjectType.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

/**
 * @brief Container for object types.
 */
class ObjectTypeContainer
{


// Public Accessors
public:


    /**
     * @brief Returns if object type with given name exists.
     *
     * @param name ObjectType name.
     *
     * @return
     */
    bool exists(StringView name) const noexcept;


    /**
     * @brief Returns parameter with given value.
     *
     * @param name ObjectType name.
     *
     * @return Pointer to object type. Can be nullptr.
     */
    ViewPtr<const ObjectType> get(StringView name) const noexcept;


    /**
     * @brief Returns begin iterator.
     *
     * @return
     */
    DynamicArray<ObjectType>::const_iterator begin() const noexcept
    {
        return m_types.begin();
    }


    /**
     * @brief Returns begin iterator.
     *
     * @return
     */
    DynamicArray<ObjectType>::const_iterator cbegin() const noexcept
    {
        return m_types.cbegin();
    }


    /**
     * @brief Returns end iterator.
     *
     * @return
     */
    DynamicArray<ObjectType>::const_iterator end() const noexcept
    {
        return m_types.end();
    }


    /**
     * @brief Returns end iterator.
     *
     * @return
     */
    DynamicArray<ObjectType>::const_iterator cend() const noexcept
    {
        return m_types.cend();
    }


// Public Mutators
public:


    /**
     * @brief Store or replace object type.
     *
     * @param type Object type.
     */
    void add(ObjectType type);


// Private Data Members
private:

    /// Stored types.
    DynamicArray<ObjectType> m_types;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */