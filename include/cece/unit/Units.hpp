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
#include "cece/unit/Unit.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

/**
 * @brief      Type without units.
 */
using None = UnitBase<StaticImpl<0, 0, 0, 0, 0, 0, 0>>;

/* ************************************************************************ */

/**
 * @brief      Class for representing distance (meters).
 */
template<int Count>
using BaseLength = UnitBase<StaticImpl<Count, 0, 0, 0, 0, 0, 0>>;

/* ************************************************************************ */

/**
 * @brief      Class for representing distance (meters).
 */
using Length = BaseLength<1>;

/* ************************************************************************ */

/**
 * @brief      Class for representing time (seconds).
 */
template<int Count>
using BaseTime = UnitBase<StaticImpl<0, Count, 0, 0, 0, 0, 0>>;

/* ************************************************************************ */

/**
 * @brief      Class for representing time (seconds).
 */
using Time = BaseTime<1>;

// @deprecated
using Duration = Time;

/* ************************************************************************ */

/**
 * @brief      Class for representing mass (kilograms).
 */
template<int Count>
using BaseMass = UnitBase<StaticImpl<0, 0, Count, 0, 0, 0, 0>>;

/* ************************************************************************ */

/**
 * @brief      Class for representing mass (kilograms).
 */
using Mass = BaseMass<1>;

/* ************************************************************************ */

/**
 * @brief      Class for representing area.
 */
using Area = BaseLength<2>;

/* ************************************************************************ */

/**
 * @brief      Class for representing volume.
 */
using Volume = BaseLength<3>;

/* ************************************************************************ */

/**
 * @brief      Class for representing velocity (micrometers per second).
 */
using Velocity = Compose<Length, BaseTime<-1>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing acceleration (micrometers per second^2).
 */
using Acceleration = Compose<Length, BaseTime<-2>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing force (Newton).
 */
using Force = Compose<Length, Mass, BaseTime<-2>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing impulse.
 */
using Impulse = Compose<Length, Mass, BaseTime<-1>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing density.
 */
using Density = Compose<Mass, BaseLength<-3>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing dynamic viscosity.
 */
using DynamicViscosity = Compose<Mass, BaseLength<-1>, BaseTime<-1>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing kinematic viscosity.
 */
using KinematicViscosity = Compose<Area, BaseTime<-1>>::type;

/* ************************************************************************ */

/**
 * @brief      Amount of substance.
 */
template<int Count>
using BaseAmountOfSubstance = UnitBase<StaticImpl<0, 0, 0, 0, 0, Count, 0>>;

/* ************************************************************************ */

/**
 * @brief      Amount of substance.
 */
using AmountOfSubstance = BaseAmountOfSubstance<1>;

/* ************************************************************************ */

/**
 * @brief      Number concentration.
 */
using NumberConcentration = BaseLength<-3>;

/* ************************************************************************ */

/**
 * @brief      Molar concentration.
 */
using MolarConcentration = Compose<AmountOfSubstance, BaseLength<-3>>::type;

/* ************************************************************************ */

/**
 * @brief      Class for representing angle.
 */
using Angle = None;

/* ************************************************************************ */

/**
 * @brief      Class for representing angular velocity (radian per second).
 */
using AngularVelocity = BaseTime<-1>;

/* ************************************************************************ */

/**
 * @brief      Class for representing probability.
 */
using Probability = None;

/* ************************************************************************ */

/**
 * @brief      Volumeric flow rate.
 */
using VolumericFlow = Compose<Volume, BaseTime<-1>>::type;

/* ************************************************************************ */

/**
 * @brief      Frequency.
 */
using Frequency = BaseTime<-1>;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
