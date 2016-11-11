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

// C++
#include <sstream>

// GTest
#include "gtest/gtest.h"

// CeCe
#include "cece/unit/UnitIo.hpp"
#include "cece/unit/VectorUnits.hpp"
#include "cece/unit/UnitsCtors.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;

/* ************************************************************************ */

TEST(VectorUnitsTest, istream)
{
    {
        std::istringstream is("10 20");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(10), vec.getX());
        EXPECT_EQ(unit::um(20), vec.getY());
    }

    {
        std::istringstream is("10um 20um");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(10), vec.getX());
        EXPECT_EQ(unit::um(20), vec.getY());
    }

    {
        std::istringstream is("10um");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(10), vec.getX());
        EXPECT_EQ(unit::um(10), vec.getY());
    }

    {
        std::istringstream is("0 10um");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(0), vec.getX());
        EXPECT_EQ(unit::um(10), vec.getY());
    }

    {
        std::istringstream is("0um 10um");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(0), vec.getX());
        EXPECT_EQ(unit::um(10), vec.getY());
    }

    {
        std::istringstream is("5um 0");

        Vector<unit::Length> vec;
        is >> vec;

        EXPECT_EQ(unit::um(5), vec.getX());
        EXPECT_EQ(unit::um(0), vec.getY());
    }
}

/* ************************************************************************ */

TEST(VectorUnitsTest, ostream)
{
    //Vector
}

/* ************************************************************************ */
