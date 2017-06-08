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
#include "cece/math/VectorIo.hpp"
#include "cece/math/Vector.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;

/* ************************************************************************ */

TEST(VectorIo, read)
{
    {
        io::InStringStream iss("200 100");

        Vector2<int> vec;
        iss >> vec;

        EXPECT_EQ(200, vec.x);
        EXPECT_EQ(100, vec.y);
    }

    {
        io::InStringStream iss("200 100");

        Vector2<float> vec;
        iss >> vec;

        EXPECT_FLOAT_EQ(200.f, vec.x);
        EXPECT_FLOAT_EQ(100.f, vec.y);
    }

    {
        io::InStringStream iss("2.3 100.15");

        Vector2<float> vec;
        iss >> vec;

        EXPECT_FLOAT_EQ(2.3f, vec.x);
        EXPECT_FLOAT_EQ(100.15f, vec.y);
    }
}

/* ************************************************************************ */

TEST(VectorIo, readFail)
{
    {
        io::InStringStream iss("200");

        Vector2<int> vec;
        iss >> vec;
        EXPECT_FALSE(iss);
    }

    {
        io::InStringStream iss("23.3");

        Vector2<float> vec;
        iss >> vec;
        EXPECT_FALSE(iss);
    }
}

/* ************************************************************************ */

TEST(VectorIo, write)
{
    {
        io::OutStringStream oss;

        Vector2<int> vec{200, 100};
        EXPECT_EQ(200, vec.x);
        EXPECT_EQ(100, vec.y);

        oss << vec;

        EXPECT_EQ("200 100", oss.str());
    }

    {
        io::OutStringStream oss;

        Vector2<float> vec{200.f, 100.f};
        EXPECT_FLOAT_EQ(200.f, vec.x);
        EXPECT_FLOAT_EQ(100.f, vec.y);

        oss << vec;

        EXPECT_EQ("200 100", oss.str());
    }

    {
        io::OutStringStream oss;

        Vector2<float> vec{2.3f, 100.15f};
        EXPECT_FLOAT_EQ(2.3f, vec.x);
        EXPECT_FLOAT_EQ(100.15f, vec.y);

        oss << vec;

        EXPECT_EQ("2.3 100.15", oss.str());
    }
}

/* ************************************************************************ */
