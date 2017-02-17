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
#include "cece/io/StringStream.hpp"
#include "cece/unit/math.hpp"
#include "cece/unit/UnitIo.hpp"
#include "cece/unit/Units.hpp"
#include "cece/unit/UnitsCtors.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::unit;

/* ************************************************************************ */

TEST(UnitIoTest, parseLength)
{
    {
        auto unit = parse("0");
        EXPECT_DOUBLE_EQ(0, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10m");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10dm");
        EXPECT_DOUBLE_EQ(10e-1, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10cm");
        EXPECT_DOUBLE_EQ(10e-2, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10mm");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10um");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10nm");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }

    {
        auto unit = parse("10pm");
        EXPECT_DOUBLE_EQ(10e-12, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Length u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseTime)
{
    {
        auto unit = parse("0");
        EXPECT_DOUBLE_EQ(0, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("10s");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("10ms");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("10us");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("10ns");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("5min");
        EXPECT_DOUBLE_EQ(5 * 60, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }

    {
        auto unit = parse("1h");
        EXPECT_DOUBLE_EQ(1 * 3600, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Time u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseMass)
{
    {
        auto unit = parse("0.1");
        EXPECT_DOUBLE_EQ(0.1, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_THROW({ Mass u(unit); }, CastException);
    }

    {
        auto unit = parse("10.5g");
        EXPECT_DOUBLE_EQ(10.5, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Mass u(unit); });
    }

    {
        auto unit = parse("13mg");
        EXPECT_DOUBLE_EQ(13e-3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Mass u(unit); });
    }

    {
        auto unit = parse("27ug");
        EXPECT_DOUBLE_EQ(27e-6, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Mass u(unit); });
    }

    {
        auto unit = parse("10ng");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Mass u(unit); });
    }

    {
        auto unit = parse("10pg");
        EXPECT_DOUBLE_EQ(10e-12, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Mass u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseArea)
{
    {
        auto unit = parse("10m2");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Area u(unit); });
    }

    {
        auto unit = parse("10dm2");
        EXPECT_DOUBLE_EQ(10e-2, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Area u(unit); });
    }

    {
        auto unit = parse("10cm2");
        EXPECT_DOUBLE_EQ(10e-4, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Area u(unit); });
    }

    {
        auto unit = parse("10mm2");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Area u(unit); });
    }

    {
        auto unit = parse("10um2");
        EXPECT_DOUBLE_EQ(10e-12, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Area u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseVolume)
{
    {
        auto unit = parse("10m3");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Volume u(unit); });
    }

    {
        auto unit = parse("10dm3");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Volume u(unit); });
    }

    {
        auto unit = parse("10cm3");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Volume u(unit); });
    }

    {
        auto unit = parse("10mm3");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Volume u(unit); });
    }

    {
        auto unit = parse("10um3");
        EXPECT_DOUBLE_EQ(10e-18, unit.get());
        EXPECT_EQ(3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Volume u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseVelocity)
{
    {
        auto unit = parse("10m/s");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Velocity u(unit); });
    }

    {
        auto unit = parse("10mm/s");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Velocity u(unit); });
    }

    {
        auto unit = parse("10um/s");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Velocity u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseAcceleration)
{
    {
        auto unit = parse("10m/s2");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Acceleration u(unit); });
    }

    {
        auto unit = parse("10mm/s2");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Acceleration u(unit); });
    }

    {
        auto unit = parse("10um/s2");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Acceleration u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseForce)
{
    {
        auto unit = parse("10kgm/s2");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }

    {
        auto unit = parse("10gm/s2");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }

    {
        auto unit = parse("10mgm/s2");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }

    {
        auto unit = parse("10N");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }

    {
        auto unit = parse("10mN");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }

    {
        auto unit = parse("10uN");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(-2, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Force u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseDynamicViscosity)
{
    {
        auto unit = parse("10kg/ms");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(-1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ DynamicViscosity u(unit); });
    }

    {
        auto unit = parse("10g/ms");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(-1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ DynamicViscosity u(unit); });
    }

    {
        auto unit = parse("10Ns/m2");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(-1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ DynamicViscosity u(unit); });
    }

    {
        auto unit = parse("10Pas");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(-1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ DynamicViscosity u(unit); });
    }

    {
        auto unit = parse("10mPas");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(-1, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(1, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ DynamicViscosity u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseKinematicViscosity)
{
    {
        auto unit = parse("10m2/s");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ KinematicViscosity u(unit); });
    }

    {
        auto unit = parse("10mm2/s");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ KinematicViscosity u(unit); });
    }

    {
        auto unit = parse("10um2/s");
        EXPECT_DOUBLE_EQ(10e-12, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ KinematicViscosity u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseAmountOfSubstance)
{
    {
        auto unit = parse("10mol");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ AmountOfSubstance u(unit); });
    }

    {
        auto unit = parse("10mmol");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ AmountOfSubstance u(unit); });
    }

    {
        auto unit = parse("10umol");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ AmountOfSubstance u(unit); });
    }

    {
        auto unit = parse("10nmol");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ AmountOfSubstance u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseMolarConcentration)
{
    {
        auto unit = parse("10mol/m3");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10mmol/m3");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10umol/m3");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10nmol/m3");
        EXPECT_DOUBLE_EQ(10e-9, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10mM");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10uM");
        EXPECT_DOUBLE_EQ(10e-3, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }

    {
        auto unit = parse("10nM");
        EXPECT_DOUBLE_EQ(10e-6, unit.get());
        EXPECT_EQ(-3, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(1, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ MolarConcentration u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseAngle)
{
    {
        auto unit = parse("10rad");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Angle u(unit); });
    }

    {
        auto unit = parse("10deg");
        EXPECT_DOUBLE_EQ(deg2rad(10), unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Angle u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseFrequency)
{
    {
        auto unit = parse("10/s");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }

    {
        auto unit = parse("10Hz");
        EXPECT_DOUBLE_EQ(10, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }

    {
        auto unit = parse("10kHz");
        EXPECT_DOUBLE_EQ(10e3, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }

    {
        auto unit = parse("10MHz");
        EXPECT_DOUBLE_EQ(10e6, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }

    {
        auto unit = parse("10GHz");
        EXPECT_DOUBLE_EQ(10e9, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }

    {
        auto unit = parse("10THz");
        EXPECT_DOUBLE_EQ(10e12, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(-1, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Frequency u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, parseProbability)
{
    {
        auto unit = parse("0.1");
        EXPECT_DOUBLE_EQ(0.1, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Probability u(unit); });
    }

    {
        auto unit = parse("10%");
        EXPECT_DOUBLE_EQ(0.1, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
        EXPECT_NO_THROW({ Probability u(unit); });
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, stream)
{
    {
        io::InStringStream iss("0.34um");

        auto unit = parse(iss);
        EXPECT_DOUBLE_EQ(0.34e-6, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        io::InStringStream iss("0.34um");

        Unit unit;
        iss >> unit;

        EXPECT_DOUBLE_EQ(0.34e-6, unit.get());
        EXPECT_EQ(1, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());
    }

    {
        io::OutStringStream oss;
        Length unit(10); // 10m

        oss << unit;

        // TODO suffix.
        EXPECT_EQ("10", oss.str());
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, invalid)
{
    {
        EXPECT_THROW(parse("m"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(parse(".um"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(parse("1GM"), InvalidArgumentException);
    }
}

/* ************************************************************************ */

TEST(UnitIoTest, userSymbols)
{
    {
        EXPECT_THROW(parse("15ll"), InvalidArgumentException);
        registerSymbol("ll", [](double value) { return Unit(value); });

        Unit unit;
        EXPECT_NO_THROW({ unit = parse("15ll"); });

        EXPECT_DOUBLE_EQ(15, unit.get());
        EXPECT_EQ(0, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        unregisterSymbol("ll");
        EXPECT_THROW(parse("15ll"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(parse("15a"), InvalidArgumentException);
        registerSymbol("a", [](double value) -> Unit { return value * m2(100); });

        Unit unit;
        EXPECT_NO_THROW({ unit = parse("15a"); });

        EXPECT_DOUBLE_EQ(15 * 100, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        unregisterSymbol("a");
        EXPECT_THROW(parse("15a"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(parse("15akr"), InvalidArgumentException);
        registerSymbol("akr", [](double value) { return Unit(4046873 * value, length(2)); });

        Unit unit;
        EXPECT_NO_THROW({ unit = parse("15akr"); });

        EXPECT_DOUBLE_EQ(15 * 4046873, unit.get());
        EXPECT_EQ(2, unit.getLengthExp());
        EXPECT_EQ(0, unit.getTimeExp());
        EXPECT_EQ(0, unit.getMassExp());
        EXPECT_EQ(0, unit.getCurrentExp());
        EXPECT_EQ(0, unit.getTemperatureExp());
        EXPECT_EQ(0, unit.getSubstanceExp());
        EXPECT_EQ(0, unit.getIntensityExp());

        unregisterSymbol("akr");
        EXPECT_THROW(parse("15akr"), InvalidArgumentException);
    }
}

/* ************************************************************************ */
