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
#include "cece/math/Zero.hpp"
#include "cece/unit/Unit.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;
using namespace cece::unit;

/* ************************************************************************ */

TEST(UnitsTest, ctor)
{
    using StaticUnit  = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;
    using DynamicUnit = UnitBase<DynamicImpl>;

    {
        const StaticUnit unit(Zero);
        EXPECT_FLOAT_EQ(0, unit.get());
    }

    {
        const StaticUnit unit(1);
        EXPECT_FLOAT_EQ(1, unit.get());
    }

    {
        const StaticUnit unit(0.345);
        EXPECT_FLOAT_EQ(0.345, unit.get());
    }

    {
        const DynamicUnit unit(156.45645);
        EXPECT_FLOAT_EQ(156.45645, unit.get());
    }
}

/* ************************************************************************ */

TEST(UnitsTest, rel)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    const Unit unit1(1);
    const Unit unit2(10);
    const Unit unit3(0);
    const Unit unit4(1);

    EXPECT_FLOAT_EQ(1, unit1.get());
    EXPECT_FLOAT_EQ(10, unit2.get());
    EXPECT_FLOAT_EQ(0, unit3.get());
    EXPECT_FLOAT_EQ(1, unit4.get());

    EXPECT_EQ(unit1, unit1);
    EXPECT_NE(unit1, unit2);
    EXPECT_NE(unit1, unit3);
    EXPECT_EQ(unit1, unit4);

    EXPECT_NE(unit2, unit1);
    EXPECT_EQ(unit2, unit2);
    EXPECT_NE(unit2, unit3);
    EXPECT_NE(unit2, unit4);

    EXPECT_NE(unit3, unit1);
    EXPECT_NE(unit3, unit2);
    EXPECT_EQ(unit3, unit3);
    EXPECT_NE(unit3, unit4);

    EXPECT_EQ(unit4, unit1);
    EXPECT_NE(unit4, unit2);
    EXPECT_NE(unit4, unit3);
    EXPECT_EQ(unit4, unit4);
}

/* ************************************************************************ */

TEST(UnitsTest, relDiff)
{
    using Unit1 = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;
    using Unit2 = UnitBase<StaticImpl<2, 0, 0, 0, 0, 0, 0>>;

    const Unit1 unit1(1);
    const Unit2 unit2(1);

    // TODO: test compile failure
}

/* ************************************************************************ */

TEST(UnitsTest, plus)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    const Unit unit1(1);
    const Unit unit2(2);
    const Unit unit3(3);

    const Unit unit4 = unit1 + unit1;
    EXPECT_FLOAT_EQ(2, unit4.get());

    const Unit unit5 = unit1 + unit2 + unit3 + unit4;
    EXPECT_FLOAT_EQ(8, unit5.get());
}

/* ************************************************************************ */
