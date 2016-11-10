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
#include "cece/unit/UnitIo.hpp"
#include "cece/unit/UnitSymbol.hpp"
#include "cece/unit/Units.hpp"
#include "cece/unit/UnitsCtors.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::io;

/* ************************************************************************ */

TEST(UnitsTest, exponentToCoefficient)
{
    EXPECT_FLOAT_EQ(1e0, unit::exponentToCoefficient(0));

    EXPECT_FLOAT_EQ(1e1, unit::exponentToCoefficient(1));
    EXPECT_FLOAT_EQ(1e2, unit::exponentToCoefficient(2));
    EXPECT_FLOAT_EQ(1e3, unit::exponentToCoefficient(3));
    EXPECT_FLOAT_EQ(1e4, unit::exponentToCoefficient(4));
    EXPECT_FLOAT_EQ(1e5, unit::exponentToCoefficient(5));
    EXPECT_FLOAT_EQ(1e6, unit::exponentToCoefficient(6));
    EXPECT_FLOAT_EQ(1e7, unit::exponentToCoefficient(7));
    EXPECT_FLOAT_EQ(1e8, unit::exponentToCoefficient(8));

    EXPECT_FLOAT_EQ(1e-1, unit::exponentToCoefficient(-1));
    EXPECT_FLOAT_EQ(1e-2, unit::exponentToCoefficient(-2));
    EXPECT_FLOAT_EQ(1e-3, unit::exponentToCoefficient(-3));
    EXPECT_FLOAT_EQ(1e-4, unit::exponentToCoefficient(-4));
    EXPECT_FLOAT_EQ(1e-5, unit::exponentToCoefficient(-5));
    EXPECT_FLOAT_EQ(1e-6, unit::exponentToCoefficient(-6));
    EXPECT_FLOAT_EQ(1e-7, unit::exponentToCoefficient(-7));
    EXPECT_FLOAT_EQ(1e-8, unit::exponentToCoefficient(-8));
}

/* ************************************************************************ */

TEST(UnitsTest, lengthValues)
{
    EXPECT_EQ(unit::m(1), unit::mm(1000));
    EXPECT_EQ(unit::m(0.5), unit::mm(500));
    EXPECT_EQ(unit::mm(1000), unit::m(1));
    EXPECT_EQ(unit::m(1), unit::mm(1000));
    //EXPECT_EQ(unit::mm(5), unit::um(5000)); // FIXME: float precision issue
    //EXPECT_EQ(unit::um(1), unit::mm(0.001)); // FIXME: float precision issue
}

/* ************************************************************************ */

TEST(UnitsTest, timeValues)
{
    EXPECT_EQ(unit::s(1), unit::ms(1000));
    EXPECT_EQ(unit::ms(500), unit::s(0.5));
}

/* ************************************************************************ */

TEST(UnitsTest, massValues)
{
    EXPECT_EQ(unit::kg(1), unit::g(1000));
    EXPECT_EQ(unit::g(1), unit::mg(1000));
    EXPECT_EQ(unit::mg(1), unit::ug(1000));
    EXPECT_EQ(unit::ug(1), unit::ng(1000));
    EXPECT_EQ(unit::ng(1), unit::pg(1000));
}

/* ************************************************************************ */

TEST(UnitsTest, multiplication)
{
    EXPECT_EQ(unit::m(1) * unit::m(1), unit::m2(1));
    EXPECT_EQ(unit::m(2) * unit::m(2), unit::m2(4));
    EXPECT_EQ(unit::m(3) * unit::m(4), unit::m2(12));
    EXPECT_EQ(unit::mm(2) * unit::mm(3), unit::mm2(6));
}

/* ************************************************************************ */

TEST(UnitsTest, dividion)
{
    EXPECT_FLOAT_EQ(unit::m(1) / unit::m(1), 1);
    EXPECT_FLOAT_EQ(unit::m(5) / unit::m(5), 1);
    EXPECT_FLOAT_EQ(unit::m(6) / unit::m(2), 3);
    EXPECT_EQ(unit::m(8) / unit::s(2), unit::m_s(4));
}

/* ************************************************************************ */

TEST(UnitsTest, symbol)
{
    using namespace unit;

    {
        using type = Unit<List<BaseLength>, List<>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m", symbol);
    }

    {
        using type = Unit<List<BaseLength, BaseLength>, List<>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m2", symbol);
    }

    {
        using type = Unit<List<BaseLength, BaseLength, BaseLength>, List<>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m3", symbol);
    }

    {
        using type = Unit<List<BaseLength, BaseLength, BaseLength, BaseLength>, List<>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m4", symbol);
    }

    {
        using type = Unit<List<BaseLength, BaseLength>, List<BaseTime>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m2/s", symbol);
    }

    {
        using type = Unit<List<BaseLength>, List<BaseTime, BaseTime>>;
        String symbol(Symbol<type>::type::get().data());
        EXPECT_EQ("m/s2", symbol);
    }
}

/* ************************************************************************ */

TEST(UnitsTest, istream)
{
    {
        InStringStream is("0");

        unit::Length val;
        is >> val;

        EXPECT_EQ(unit::um(0), val);
    }

    {
        InStringStream is("0um");

        unit::Length val;
        is >> val;

        EXPECT_EQ(unit::um(0), val);
    }

/*
    // FIXME: Precision issues
    {
        InStringStream is("100um");

        unit::Length val;
        is >> val;

        EXPECT_EQ(unit::um(100), val);
    }
*/

    {
        InStringStream is("  500ms    ");

        unit::Time val;
        is >> val;

        EXPECT_EQ(unit::ms(500), val);
    }

    {
        InStringStream is("2um2");

        unit::Area val;
        is >> val;

        EXPECT_EQ(unit::um2(2), val);
    }

    {
        InStringStream is("1umol/um3");

        unit::MolarConcentration val;
        is >> val;

        EXPECT_EQ(unit::umol_um3(1), val);
    }
}

/* ************************************************************************ */

TEST(UnitsTest, abbr)
{
    {
        InStringStream is("15mM"); // 1mM = 1mol/m3

        unit::MolarConcentration val;
        is >> val;

        EXPECT_EQ(unit::mol_m3(15), val);
    }
}

/* ************************************************************************ */

TEST(UnitsTest, parse)
{
    {
        InStringStream is("0");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(0, val);
    }

    {
        InStringStream is("0um");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(0, val);
    }

    {
        InStringStream is("100um");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::um(100).value(), val);
    }

    {
        InStringStream is("  500ms    ");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::ms(500).value(), val);
    }

    {
        InStringStream is("2um2");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::um2(2).value(), val);
    }

    {
        InStringStream is("1umol/um3");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::umol_um3(1).value(), val);
    }

    {
        InStringStream is("15mM");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::mM(15).value(), val);
    }

    {
        InStringStream is("50nM");

        unit::Value val = unit::parse(is);

        EXPECT_FLOAT_EQ(unit::nM(50).value(), val);
    }
}

/* ************************************************************************ */
