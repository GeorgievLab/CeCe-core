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
#include "cece/ViewPtr.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief Loaded plugin information.
 */
class Plugin final
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  name  Plugin name.
     * @param[in]  api   Plugin API.
     */
    explicit Plugin(String name, UniquePtr<Api> api) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns plugin name.
     *
     * @return     Plugin name.
     */
    const String& getName() const noexcept
    {
        return m_name;
    }


    /**
     * @brief      Returns plugin API.
     *
     * @return     Pointer view to plugin API.
     */
    ViewPtr<Api> getApi() const noexcept
    {
        return m_api;
    }


// Private Data Members
public:

    /// Plugin name.
    String m_name;

    /// Plugin API.
    UniquePtr<Api> m_api;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
