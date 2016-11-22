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
#include <memory>

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

template<typename T>
class ViewPtr;

/* ************************************************************************ */

/**
 * @brief      Shared smart pointer class.
 *
 * @tparam     T     Type of managed object.
 */
template<typename T>
using SharedPtr = std::shared_ptr<T>;

/* ************************************************************************ */

/**
 * @brief      Weak smart pointer class.
 *
 * @tparam     T     Type of managed object.
 */
template<typename T>
using WeakPtr = std::weak_ptr<T>;

/* ************************************************************************ */

/**
 * @brief      Make unique ptr function.
 *
 * @param[in]  args       Construction arguments.
 *
 * @tparam     T          Object type.
 * @tparam     Args       Object construction argument types.
 *
 * @return     Shared pointer.
 */
template<typename T, typename... Args>
SharedPtr<T> makeShared(Args&&... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Create a view from shared pointer.
 *
 * @param[in]  ptr   The shared pointer.
 *
 * @tparam     T     Object type.
 *
 * @return     View pointer.
 */
template<typename T>
ViewPtr<T> makeView(const SharedPtr<T>& ptr) noexcept
{
    return ViewPtr<T>(ptr.get());
}

/* ************************************************************************ */

}

/* ************************************************************************ */
