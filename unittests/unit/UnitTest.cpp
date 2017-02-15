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
    using DynamicDetail = DynamicImpl::Detail;

    {
        const StaticUnit unit;
        EXPECT_DOUBLE_EQ(0, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const StaticUnit unit(Zero);
        EXPECT_EQ(Zero, unit);
        EXPECT_EQ(unit, Zero);
        EXPECT_DOUBLE_EQ(0, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const StaticUnit unit(1);
        EXPECT_DOUBLE_EQ(1, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const StaticUnit unit(0.345);
        EXPECT_DOUBLE_EQ(0.345, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const DynamicUnit unit(156.45645);
        EXPECT_DOUBLE_EQ(156.45645, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const DynamicUnit unit(156.45645, DynamicDetail{2, 1, 0, 0, 1, 0, 0});
        EXPECT_DOUBLE_EQ(156.45645, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(1, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        const StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const StaticUnit unit2(unit);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const DynamicUnit unit2(unit);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const DynamicUnit unit(45.3, DynamicDetail{1, 0, 0, 0, 0, 0, 0});
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const StaticUnit unit2(unit);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const DynamicUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const DynamicUnit unit2(unit);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(0, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    // Move
    {
        StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const StaticUnit unit2(std::move(unit));
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const DynamicUnit unit2(std::move(unit));
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        DynamicUnit unit(45.3, DynamicDetail{1, 0, 0, 0, 0, 0, 0});
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const StaticUnit unit2(std::move(unit));
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        DynamicUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        const DynamicUnit unit2(std::move(unit));
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(0, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }
}

/* ************************************************************************ */

TEST(UnitsTest, nodim)
{
    using StaticUnit  = UnitBase<StaticImpl<0, 0, 0, 0, 0, 0, 0>>;

    {
        StaticUnit unit;
        EXPECT_DOUBLE_EQ(0.0, unit);
    }

    {
        StaticUnit unit(1.5);
        EXPECT_DOUBLE_EQ(1.5, unit);
    }
}

/* ************************************************************************ */

TEST(UnitsTest, assignment)
{
    using StaticUnit  = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;
    using DynamicUnit = UnitBase<DynamicImpl>;
    using DynamicDetail = DynamicImpl::Detail;

    {
        const StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, static_cast<double>(unit));
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        StaticUnit unit2;
        unit2 = unit;
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        DynamicUnit unit2;
        unit2 = unit;

        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const DynamicUnit unit(45.3, DynamicDetail{1, 0, 0, 0, 0, 0, 0});
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        StaticUnit unit2;
        unit2 = unit;

        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        const DynamicUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        DynamicUnit unit2;
        unit2 = unit;

        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_EQ(0, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    // Move
    {
        StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        StaticUnit unit2;
        unit2 = std::move(unit);
        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        StaticUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        DynamicUnit unit2;
        unit2 = std::move(unit);

        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        DynamicUnit unit(45.3, DynamicDetail{1, 0, 0, 0, 0, 0, 0});
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        StaticUnit unit2;
        unit2 = std::move(unit);

        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }

    {
        DynamicUnit unit(45.3);
        EXPECT_DOUBLE_EQ(45.3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        DynamicUnit unit2;
        unit2 = std::move(unit);

        EXPECT_DOUBLE_EQ(45.3, unit2.get());
        EXPECT_EQ(0, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
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

    EXPECT_DOUBLE_EQ(1, unit1.get());
    EXPECT_DOUBLE_EQ(10, unit2.get());
    EXPECT_DOUBLE_EQ(0, unit3.get());
    EXPECT_DOUBLE_EQ(1, unit4.get());

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

    EXPECT_GE(unit1, unit1);
    EXPECT_LE(unit1, unit1);
    EXPECT_LT(unit1, unit2);
    EXPECT_LE(unit1, unit2);
    EXPECT_GT(unit1, unit3);
    EXPECT_GE(unit1, unit3);
    EXPECT_GE(unit1, unit4);
    EXPECT_LE(unit1, unit4);

    EXPECT_NE(Zero, unit1);
    EXPECT_NE(Zero, unit2);
    EXPECT_EQ(Zero, unit3);
    EXPECT_NE(Zero, unit4);

    EXPECT_NE(unit1, Zero);
    EXPECT_NE(unit2, Zero);
    EXPECT_EQ(unit3, Zero);
    EXPECT_NE(unit4, Zero);

    EXPECT_LE(Zero, unit1);
    EXPECT_LT(Zero, unit1);
    EXPECT_LE(Zero, unit2);
    EXPECT_LT(Zero, unit2);
    EXPECT_GE(Zero, unit3);
    EXPECT_LE(Zero, unit3);
    EXPECT_LE(Zero, unit4);
    EXPECT_LT(Zero, unit4);

    EXPECT_GE(unit1, Zero);
    EXPECT_GT(unit1, Zero);
    EXPECT_GE(unit2, Zero);
    EXPECT_GT(unit2, Zero);
    EXPECT_LE(unit3, Zero);
    EXPECT_GE(unit3, Zero);
    EXPECT_GE(unit4, Zero);
    EXPECT_GT(unit4, Zero);

}

/* ************************************************************************ */

TEST(UnitsTest, cast)
{
    using StaticUnit  = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;
    using DynamicUnit = UnitBase<DynamicImpl>;
    using DynamicDetail = DynamicImpl::Detail;

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 0, 0});

        EXPECT_NO_THROW({StaticUnit unit2(unit);});
    }

    {
        DynamicUnit unit(1, DynamicDetail{0, 0, 0, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 1, 0, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 1, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 1, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 1, 0, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 1, 0});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 0, 1});

        EXPECT_THROW({StaticUnit unit2(unit);}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 0, 0});

        EXPECT_NO_THROW({StaticUnit unit2; unit2 = unit;});
    }

    {
        DynamicUnit unit(1, DynamicDetail{0, 0, 0, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 1, 0, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 1, 0, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 1, 0, 0, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 1, 0, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 1, 0});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }

    {
        DynamicUnit unit(1, DynamicDetail{1, 0, 0, 0, 0, 0, 1});

        EXPECT_THROW({StaticUnit unit2; unit2 = unit;}, CastException);
    }
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

TEST(UnitsTest, unary)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    const Unit unit1(1);
    const Unit unit2(2);
    const Unit unit3(3);

    const Unit unit1p = +unit1;
    const Unit unit2p = +unit2;
    const Unit unit3p = +unit3;

    EXPECT_DOUBLE_EQ(1, unit1p.get());
    EXPECT_DOUBLE_EQ(2, unit2p.get());
    EXPECT_DOUBLE_EQ(3, unit3p.get());

    const Unit unit1m = -unit1;
    const Unit unit2m = -unit2;
    const Unit unit3m = -unit3;

    EXPECT_DOUBLE_EQ(-1, unit1m.get());
    EXPECT_DOUBLE_EQ(-2, unit2m.get());
    EXPECT_DOUBLE_EQ(-3, unit3m.get());
}

/* ************************************************************************ */

TEST(UnitsTest, plus)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    {
        const Unit unit1(1);
        const Unit unit2(2);
        const Unit unit3(3);

        const Unit unit4 = unit1 + unit1;
        EXPECT_DOUBLE_EQ(2, unit4.get());

        const Unit unit5 = unit1 + unit2 + unit3 + unit4;
        EXPECT_DOUBLE_EQ(8, unit5.get());
    }

    {
        Unit unit1(1);
        Unit unit2(2);
        Unit unit3(3);

        unit1 += unit2;
        unit2 += unit3;

        EXPECT_DOUBLE_EQ(3, unit1.get());
        EXPECT_DOUBLE_EQ(5, unit2.get());
    }
}

/* ************************************************************************ */

TEST(UnitsTest, minus)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    {
        const Unit unit1(1);
        const Unit unit2(2);
        const Unit unit3(3);

        const Unit unit4 = unit1 - unit1;
        EXPECT_DOUBLE_EQ(0, unit4.get());

        const Unit unit5 = unit1 - unit2 - unit3 - unit4;
        EXPECT_DOUBLE_EQ(-4, unit5.get());
    }

    {
        Unit unit1(1);
        Unit unit2(2);
        Unit unit3(3);

        unit1 -= unit2;
        unit2 -= unit3;

        EXPECT_DOUBLE_EQ(-1, unit1.get());
        EXPECT_DOUBLE_EQ(-1, unit2.get());
    }
}

/* ************************************************************************ */

TEST(UnitsTest, mult)
{
    using ::testing::StaticAssertTypeEq;

    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    {
        const Unit unit1(1);
        const Unit unit2(2);
        const Unit unit3(3);

        const auto unit4 = unit1 * unit1;
        EXPECT_DOUBLE_EQ(1, unit4.get());
        //StaticAssertTypeEq<decltype(unit4), UnitBase<StaticImpl<2, 0, 0, 0, 0, 0, 0>>>();

        const auto unit5 = unit1 * unit2 * unit3 * unit4;
        EXPECT_DOUBLE_EQ(6, unit5.get());
        //StaticAssertTypeEq<decltype(unit5), UnitBase<StaticImpl<5, 0, 0, 0, 0, 0, 0>>>();
    }

    {
        const Unit unit1(1);
        const Unit unit2(2);
        const Unit unit3(3);

        const Unit unit4 = unit1 * 10;
        const Unit unit5 = unit2 * 10;
        const Unit unit6 = unit3 * 10;

        EXPECT_DOUBLE_EQ(10, unit4.get());
        EXPECT_DOUBLE_EQ(20, unit5.get());
        EXPECT_DOUBLE_EQ(30, unit6.get());
    }

    {
        Unit unit1(1);
        Unit unit2(2);
        Unit unit3(3);

        unit1 *= 10;
        unit2 *= 10;
        unit3 *= 10;

        EXPECT_DOUBLE_EQ(10, unit1.get());
        EXPECT_DOUBLE_EQ(20, unit2.get());
        EXPECT_DOUBLE_EQ(30, unit3.get());
    }
}

/* ************************************************************************ */

TEST(UnitsTest, div)
{
    using Unit = UnitBase<StaticImpl<1, 0, 0, 0, 0, 0, 0>>;

    {
        const Unit unit1(10);
        const Unit unit2(20);
        const Unit unit3(30);

        const Unit unit4 = unit1 / 5;
        const Unit unit5 = unit2 / 5;
        const Unit unit6 = unit3 / 5;

        EXPECT_DOUBLE_EQ(2, unit4.get());
        EXPECT_DOUBLE_EQ(4, unit5.get());
        EXPECT_DOUBLE_EQ(6, unit6.get());
    }

    {
        Unit unit1(10);
        Unit unit2(20);
        Unit unit3(30);

        unit1 /= 5;
        unit2 /= 5;
        unit3 /= 5;

        EXPECT_DOUBLE_EQ(2, unit1.get());
        EXPECT_DOUBLE_EQ(4, unit2.get());
        EXPECT_DOUBLE_EQ(6, unit3.get());
    }

    {
        Unit unit1(10);
        Unit unit2(5);

        auto unit3 = unit1 / unit2;

        EXPECT_DOUBLE_EQ(2, unit3.get());
        EXPECT_EQ(0, unit3.getLengthExp());
        EXPECT_EQ(0, unit3.getTimeExp());
        EXPECT_EQ(0, unit3.getMassExp());
        EXPECT_EQ(0, unit3.getCurrentExp());
        EXPECT_EQ(0, unit3.getTemperatureExp());
        EXPECT_EQ(0, unit3.getSubstanceExp());
        EXPECT_EQ(0, unit3.getIntensityExp());
    }

    {
        Unit unit1(10);

        auto unit2 = 100 / unit1;

        EXPECT_DOUBLE_EQ(10, unit2.get());
        EXPECT_EQ(-1, unit2.getLengthExp());
        EXPECT_EQ(0, unit2.getTimeExp());
        EXPECT_EQ(0, unit2.getMassExp());
        EXPECT_EQ(0, unit2.getCurrentExp());
        EXPECT_EQ(0, unit2.getTemperatureExp());
        EXPECT_EQ(0, unit2.getSubstanceExp());
        EXPECT_EQ(0, unit2.getIntensityExp());
    }
}

/* ************************************************************************ */
