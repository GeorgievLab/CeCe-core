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
#include "cece/StringMap.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/ViewPtr.hpp"

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

/**
 * @brief      Container for mapping string to value.
 *
 * @tparam     T     Value type.
 */
template<typename T>
class PtrStringMap : protected StringMap<UniquePtr<T>>
{
    using Parent = StringMap<UniquePtr<T>>;


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
    using Parent::exists;


    /**
     * @brief      Returns value stored under given key.
     *
     * @param      name  Key name.
     *
     * @return     Pointer to value. Can be nullptr.
     */
    ViewPtr<T> get(StringView name) const noexcept
    {
#if __cplusplus >= 201402L
        auto it = find(name);
#else
        auto it = find(String(name));
#endif

        if (it == end())
            return nullptr;

        return it->second;
    }


    /**
     * @brief Returns object with given value.
     *
     * @tparam T2 Required type.
     *
     * @param name Object name.
     *
     * @return Pointer to object. Can be nullptr.
     */
    template<typename U>
    ViewPtr<U> get(StringView name) const noexcept
    {
#if __cplusplus >= 201402L
        auto it = find(name);
#else
        auto it = find(String(name));
#endif

        if (it == end())
            return nullptr;

        CECE_ASSERT(dynamic_cast<U*>(it->second.get()));
        return static_cast<U*>(it->second.get());
    }


    /**
     * @brief      Store a value under specified key.
     *
     * @param[in]  name   The key name.
     * @param[in]  value  The value to store.
     *
     * @return     View pointer to stored object.
     */
    ViewPtr<T> add(String name, UniquePtr<T> value)
    {
        auto it = find(name);

        if (it != end())
        {
            it->second = std::move(value);
        }
        else
        {
            std::tie(it, std::ignore) = emplace(std::move(name), std::move(value));
        }

        return it->second;
    }


    /**
     * @brief      Create and store an object.
     *
     * @param[in]  name       Key value.
     * @param[in]  args       Construction arguments.
     *
     * @tparam     U          Type of constructed object.
     * @tparam     Args       Construction argument types.
     *
     * @return     View pointer to stored object.
     */
    template<typename U = T, typename... Args>
    ViewPtr<U> create(String name, Args&&... args)
    {
        return ViewPtr<U>(add(std::move(name), makeUnique<U>(std::forward<Args>(args)...)));
    }


    /**
     * @brief      Remove value from container.
     *
     * @param      name  Key name.
     */
    void remove(StringView name)
    {
#if __cplusplus >= 201402L
        erase(name);
#else
        erase(String(name));
#endif
    }


};

/* ************************************************************************ */

}

/* ************************************************************************ */
