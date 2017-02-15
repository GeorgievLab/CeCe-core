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

// GTest
#include "gtest/gtest.h"

// CeCe
#include "cece/unit/Units.hpp"
#include "cece/math/constants.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::unit;

/* ************************************************************************ */

TEST(UnitsTest, none)
{
    None unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, length)
{
    Length unit;
    EXPECT_EQ(1, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, time)
{
    Time unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, mass)
{
    Mass unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(1, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, area)
{
    Area unit;
    EXPECT_EQ(2, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, volume)
{
    Volume unit;
    EXPECT_EQ(3, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, velocity)
{
    Velocity unit;
    EXPECT_EQ(1, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, acceleration)
{
    Acceleration unit;
    EXPECT_EQ(1, unit.getLengthExp());
    EXPECT_EQ(-2, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, force)
{
    Force unit;
    EXPECT_EQ(1, unit.getLengthExp());
    EXPECT_EQ(-2, unit.getTimeExp());
    EXPECT_EQ(1, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, impulse)
{
    Impulse unit;
    EXPECT_EQ(1, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(1, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, density)
{
    Density unit;
    EXPECT_EQ(-3, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(1, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, dynamicViscosity)
{
    DynamicViscosity unit;
    EXPECT_EQ(-1, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(1, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, kinematicViscosity)
{
    KinematicViscosity unit;
    EXPECT_EQ(2, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, amountOfSubstance)
{
    AmountOfSubstance unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(1, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, numberConcentration)
{
    NumberConcentration unit;
    EXPECT_EQ(-3, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, molarConcentration)
{
    MolarConcentration unit;
    EXPECT_EQ(-3, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(1, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, angle)
{
    Angle unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, angularVelocity)
{
    AngularVelocity unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, probability)
{
    Probability unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(0, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, volumericFlow)
{
    VolumericFlow unit;
    EXPECT_EQ(3, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, frequency)
{
    Frequency unit;
    EXPECT_EQ(0, unit.getLengthExp());
    EXPECT_EQ(-1, unit.getTimeExp());
    EXPECT_EQ(0, unit.getMassExp());
    EXPECT_EQ(0, unit.getCurrentExp());
    EXPECT_EQ(0, unit.getTemperatureExp());
    EXPECT_EQ(0, unit.getSubstanceExp());
    EXPECT_EQ(0, unit.getIntensityExp());
}

/* ************************************************************************ */

TEST(UnitsTest, multiply)
{
    Area area(5);
    Length length(10);

    Volume volume = area * length;
    EXPECT_DOUBLE_EQ(50, volume.get());
}

/* ************************************************************************ */
