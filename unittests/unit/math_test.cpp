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
#include "cece/unit/math.hpp"
#include "cece/unit/Units.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::unit;

/* ************************************************************************ */

TEST(UnitMathTest, sqrt)
{
    {
        Area area(100);

        auto unit = sqrt(area);
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }
}

/* ************************************************************************ */

TEST(UnitMathTest, abs)
{
    {
        Area area(100);

        auto unit = abs(area);
        EXPECT_DOUBLE_EQ(100, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        Area area(-100);

        auto unit = abs(area);
        EXPECT_DOUBLE_EQ(100, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }
}

/* ************************************************************************ */

TEST(UnitMathTest, angle)
{
    {
        auto rad = deg2rad(10);

        EXPECT_DOUBLE_EQ(10 * math::PI / 180.0, rad);
    }

    {
        auto deg = rad2deg(3);

        EXPECT_DOUBLE_EQ(3 * 180.0 / math::PI, deg);
    }
}

/* ************************************************************************ */
