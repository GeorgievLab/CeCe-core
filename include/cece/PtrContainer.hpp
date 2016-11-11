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
#include <type_traits>
#include <algorithm>

// CeCe
#include "cece/UniquePtr.hpp"
#include "cece/ViewPtr.hpp"
#include "cece/DynamicArray.hpp"

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

/**
 * @brief      Container for pointers.
 *
 * @tparam     T     Stored element type.
 */
template<typename T>
class PtrDynamicArray : public DynamicArray<UniquePtr<T>>
{
    using Parent = DynamicArray<UniquePtr<T>>;

// Public Ctors & Dtors
public:


    using Parent::Parent;


// Public Accessors & Mutators
public:


    using Parent::operator[];
    using Parent::at;
    using Parent::back;
    using Parent::front;
    using Parent::data;
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
    using Parent::reserve;
    using Parent::capacity;
    using Parent::shrink_to_fit;
    using Parent::clear;
    using Parent::insert;
    using Parent::emplace;
    using Parent::erase;
    using Parent::push_back;
    using Parent::emplace_back;
    using Parent::pop_back;
    using Parent::resize;


    /**
     * @brief      Store a value.
     *
     * @param      val   The value to store.
     *
     * @return     View pointer to stored value.
     */
    ViewPtr<T> add(UniquePtr<T> val)
    {
        push_back(std::move(val));
        return back();
    }


    /**
     * @brief      Create and store an object.
     *
     * @param[in]  args       Construction arguments.
     *
     * @tparam     U          Type of constructed object.
     * @tparam     Args       Construction argument types.
     *
     * @return     View pointer to stored object.
     */
    template<typename U = T, typename... Args>
    ViewPtr<U> create(Args&&... args)
    {
        return ViewPtr<U>(add(makeUnique<U>(std::forward<Args>(args)...)));
    }


    /**
     * @brief      Remove value from container.
     *
     * @param      val   The value to remove.
     */
    void remove(ViewPtr<T> val)
    {
        erase(std::remove_if(begin(), end(), [&val](const UniquePtr<T>& ptr) {
            return ptr.get() == val;
        }), end());
    }


// Protected Operations
protected:


    /**
     * @brief      Invoke a member function for all stored objects.
     *
     * @param[in]  fn         The member function.
     *
     * @tparam     Fn         { description }
     * @tparam     Args       A list of member function arguments.
     */
    template<typename Fn, typename... Args>
    void invoke(Fn fn, Args&&... args) const
    {
        static_assert(std::is_member_function_pointer<Fn>::value, "Fn is not a member function.");

        // Foreach all object
        for (const auto& object : *this)
        {
            // Call member function with given arguments
            (object.get()->*fn)(std::forward<Args>(args)...);
        }
    }
};

/* ************************************************************************ */

/**
 * @brief PtrDynamicArray alias
 */
template<typename T>
using PtrContainer = PtrDynamicArray<T>;

/* ************************************************************************ */

}

/* ************************************************************************ */
