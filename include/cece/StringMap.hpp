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
#include "cece/Map.hpp"
#include "cece/String.hpp"
#include "cece/StringView.hpp"

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

/**
 * @brief      Container for mapping string to value.
 *
 * @tparam     T     Value type.
 */
template<typename T>
class StringMap : protected Map<String, T>
{
    using Parent = Map<String, T>;


// Public Ctors & Dtors
public:


    using Parent::Parent;


// Public Accessors & Mutators
public:


    using Parent::operator[];
    using Parent::operator=;
    using Parent::at;
    using Parent::begin;
    using Parent::cbegin;
    using Parent::end;
    using Parent::cend;
    using Parent::rbegin;
    using Parent::crbegin;
    using Parent::rend;
    using Parent::crend;
    using Parent::empty;
    using Parent::size;
    using Parent::max_size;
    using Parent::clear;
    using Parent::insert;
    using Parent::emplace;
    using Parent::erase;
    using Parent::count;
    using Parent::find;


    /**
     * @brief      Returns if an object with given name exists.
     *
     * @param      name  Object name.
     *
     * @return     If a value exists.
     */
    bool exists(StringView name) const noexcept
    {
#if __cplusplus >= 201402L
        return count(name) == 1;
#else
        return count(String(name)) == 1;
#endif
    }

};

/* ************************************************************************ */

}

/* ************************************************************************ */