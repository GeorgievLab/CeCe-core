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
#include "cece/PtrDynamicArray.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

class NotFoundException;

/* ************************************************************************ */

/**
 * @brief      An interface for configuration implementation.
 */
class Implementation
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Destructor.
     */
    virtual ~Implementation() = 0;


// Public Accessors & Mutators
public:


    /**
     * @brief      Check if there is a value stored under given name.
     *
     * @param      name  The name.
     *
     * @return     `true` if value is stored, `false` otherwise.
     */
    virtual bool has(StringView name) const = 0;


    /**
     * @brief      Returns stored value.
     *
     * @param      name  The name.
     *
     * @return     The stored value.
     *
     * @throws     NotFoundException  When no value is stored.
     */
    virtual String get(StringView name) const = 0;


    /**
     * @brief      Store a value.
     *
     * @param      name   The name.
     * @param      value  The value to store.
     */
    virtual void set(StringView name, String value) = 0;


    /**
     * @brief      Returns list of names under which values are stored.
     *
     * @return     A list of names.
     */
    virtual DynamicArray<String> getNames() const = 0;


    /**
     * @brief      Checks if the configuration contains a content.
     *
     * @return     If content is present.
     */
    virtual bool hasContent() const = 0;


    /**
     * @brief      Returns the configuration content.
     *
     * @return     The content with replaced parameters.
     */
    virtual String getContent() const = 0;


    /**
     * @brief      Change configuration content.
     *
     * @param      content  The new content.
     */
    virtual void setContent(String value) = 0;


    /**
     * @brief      Check if at least one child configuration exists.
     *
     * @param      name  The child configuration name.
     *
     * @return     `true` if exists, `false` otherwise.
     */
    virtual bool hasChild(StringView name) const = 0;


    /**
     * @brief      Returns child configurations with given name.
     *
     * @param      name  The child configuration name.
     *
     * @return     List of child configurations.
     */
    virtual PtrDynamicArray<Implementation> getChilds(StringView name) const = 0;


    /**
     * @brief      Returns list of available child configuration names.
     *
     * @return     A list of names.
     */
    virtual DynamicArray<String> getChildNames() const = 0;


    /**
     * @brief      Create new child configuration.
     *
     * @param      name  The child configuration name.
     *
     * @return     New child configuration.
     */
    virtual UniquePtr<Implementation> createChild(StringView name) = 0;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */