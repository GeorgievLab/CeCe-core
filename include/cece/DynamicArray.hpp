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
#include <vector>

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

/**
 * @brief      An array with dynamic allocation.
 *
 * @tparam     T          Element type.
 * @tparam     Allocator  Array allocator type.
 */
template<typename T, class Allocator = std::allocator<T>>
class DynamicArray : protected std::vector<T, Allocator>
{
    using Parent = std::vector<T, Allocator>;

// Public Types
public:


    using value_type = typename Parent::value_type;
    using allocator_type = typename Parent::allocator_type;
    using size_type = typename Parent::size_type;
    using difference_type = typename Parent::difference_type;
    using reference = typename Parent::reference;
    using const_reference = typename Parent::const_reference;
    using pointer = typename Parent::pointer;
    using const_pointer = typename Parent::const_pointer;
    using iterator = typename Parent::iterator;
    using const_iterator = typename Parent::const_iterator;
    using reverse_iterator = typename Parent::reverse_iterator;
    using const_reverse_iterator = typename Parent::const_reverse_iterator;


// Public Ctors & Dtors
public:


    using Parent::Parent;


// Public Accessors & Mutators
public:


    using Parent::operator=;
    using Parent::operator[];
    using Parent::assign;
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

};

/* ************************************************************************ */

}

/* ************************************************************************ */