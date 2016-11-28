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
#include "cece/config/Converter.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for boolean values.
 */
template<>
struct Converter<bool>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static bool fromString(const String& value) noexcept
    {
        return value == "true";
    }


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(bool value) noexcept
    {
        return value ? "true" : "false";
    }

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
