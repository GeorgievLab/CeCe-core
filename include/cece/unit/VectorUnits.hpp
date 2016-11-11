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
#include "cece/common.hpp"
#include "cece/math/Vector.hpp"
#include "cece/unit/Units.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

/**
 * @brief Position vector structure.
 */
using PositionVector = math::Vector<Length>;

/* ************************************************************************ */

/**
 * @brief Velocity vector structure.
 */
using VelocityVector = math::Vector<Velocity>;

/* ************************************************************************ */

/**
 * @brief Acceleration vector structure.
 */
using AccelerationVector = math::Vector<Acceleration>;

/* ************************************************************************ */

/**
 * @brief Force vector structure.
 */
using ForceVector = math::Vector<Force>;

/* ************************************************************************ */

/**
 * @brief Impulse vector structure.
 */
using ImpulseVector = math::Vector<Impulse>;

/* ************************************************************************ */

/**
 * @brief Scale vector.
 */
using ScaleVector = math::Vector<RealType>;

/* ************************************************************************ */

/**
 * @brief Size vector.
 */
using SizeVector = math::Vector<Length>;

/* ************************************************************************ */

}

/* ************************************************************************ */

namespace math {

/* ************************************************************************ */

extern template class BasicVector<unit::Length, DIMENSION>;
extern template class BasicVector<unit::Velocity, DIMENSION>;
extern template class BasicVector<unit::Acceleration, DIMENSION>;
extern template class BasicVector<unit::Force, DIMENSION>;
extern template class BasicVector<unit::Impulse, DIMENSION>;
extern template class BasicVector<RealType, DIMENSION>;

/* ************************************************************************ */

}

/* ************************************************************************ */

}

/* ************************************************************************ */
