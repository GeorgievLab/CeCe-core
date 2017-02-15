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
#include "cece/unit/math.hpp"
#include "cece/unit/Units.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

/// Base units exponents
/// @deprecated
static constexpr int LENGTH_EXPONENT = 6;
static constexpr int TIME_EXPONENT = 0;
static constexpr int MASS_EXPONENT = 6;
static constexpr int ELECTRIC_CURRENT_EXPONENT = 0;
static constexpr int THERMODYNAMIC_TEMPERATURE_EXPONENT = 0;
static constexpr int AMOUNT_OF_SUBSTANCE_EXPONENT = 6;
static constexpr int LUMINOUS_INTENSITY_EXPONENT = 0;

/* ************************************************************************ */

#define CECE_UNIT_SYMBOL_BASE(unit, name, sym)                                 \
    inline constexpr unit name(ValueType value) noexcept                       \
    {                                                                          \
        return unit(value);                                                    \
    }

#define CECE_UNIT_SYMBOL(unit, name, sym, def)                                 \
    inline constexpr unit name(ValueType value) noexcept                       \
    {                                                                          \
        return value * def;                                                    \
    }

#include "Units.def"

/* ************************************************************************ */

}
}

/* ************************************************************************ */
