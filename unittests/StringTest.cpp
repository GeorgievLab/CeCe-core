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
#include "cece/String.hpp"
#include "cece/Exception.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

TEST(String, toString)
{
    {
        auto str = toString(0);
        EXPECT_EQ("0", str);
    }

    {
        auto str = toString(4897232);
        EXPECT_EQ("4897232", str);
    }

    {
        auto str = toString(-4897232);
        EXPECT_EQ("-4897232", str);
    }

    {
        auto str = toString(48972321u);
        EXPECT_EQ("48972321", str);
    }

    {
        auto str = toString(48972321l);
        EXPECT_EQ("48972321", str);
    }

    {
        auto str = toString(48972321ul);
        EXPECT_EQ("48972321", str);
    }

    {
        auto str = toString(48972324561ll);
        EXPECT_EQ("48972324561", str);
    }

    {
        auto str = toString(48972324561ull);
        EXPECT_EQ("48972324561", str);
    }

    {
        auto str = toString(1.3f);
        EXPECT_EQ("1.300000", str);
    }

    {
        auto str = toString(1.3);
        EXPECT_EQ("1.300000", str);
    }

    {
        auto str = toString(1.3l);
        EXPECT_EQ("1.300000", str);
    }
}

/* ************************************************************************ */

TEST(String, str2i)
{
    {
        auto val = str2i("0");
        EXPECT_EQ(0, val);
    }

    {
        auto val = str2i("484321");
        EXPECT_EQ(484321, val);
    }

    {
        auto val = str2i("-484321");
        EXPECT_EQ(-484321, val);
    }

    {
        EXPECT_THROW(str2i("abc04"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2i("1.456"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2i(""), InvalidArgumentException);
    }
}

/* ************************************************************************ */

TEST(String, str2l)
{
    {
        auto val = str2l("0");
        EXPECT_EQ(0, val);
    }

    {
        auto val = str2l("484321");
        EXPECT_EQ(484321, val);
    }

    {
        auto val = str2l("-484321");
        EXPECT_EQ(-484321, val);
    }

    {
        EXPECT_THROW(str2l("abc04"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2l("1.456"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2l(""), InvalidArgumentException);
    }
}

/* ************************************************************************ */

TEST(String, str2ll)
{
    {
        auto val = str2ll("0");
        EXPECT_EQ(0, val);
    }

    {
        auto val = str2ll("484321");
        EXPECT_EQ(484321, val);
    }

    {
        auto val = str2ll("-484321");
        EXPECT_EQ(-484321, val);
    }

    {
        EXPECT_THROW(str2ll("abc04"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2ll("1.456"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2ll(""), InvalidArgumentException);
    }
}

/* ************************************************************************ */

TEST(String, str2f)
{
    {
        auto val = str2f("0");
        EXPECT_FLOAT_EQ(0, val);
    }

    {
        auto val = str2f(".41");
        EXPECT_FLOAT_EQ(.41, val);
    }

    {
        auto val = str2f("-484321");
        EXPECT_FLOAT_EQ(-484321, val);
    }

    {
        EXPECT_THROW(str2f("as45e12"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2f(""), InvalidArgumentException);
    }
}

/* ************************************************************************ */

TEST(String, str2d)
{
    {
        auto val = str2d("0");
        EXPECT_FLOAT_EQ(0, val);
    }

    {
        auto val = str2d(".41");
        EXPECT_FLOAT_EQ(.41, val);
    }

    {
        auto val = str2d("-484321");
        EXPECT_FLOAT_EQ(-484321, val);
    }

    {
        EXPECT_THROW(str2d("as45e12"), InvalidArgumentException);
    }

    {
        EXPECT_THROW(str2d(""), InvalidArgumentException);
    }
}

/* ************************************************************************ */
