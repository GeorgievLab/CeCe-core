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
#include "cece/Exception.hpp"
#include "cece/PtrStringMap.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

TEST(PtrStringMapTest, ctors)
{
    {
        PtrStringMap<int> data;
        EXPECT_EQ(0u, data.size());
        EXPECT_TRUE(data.empty());
    }

    {
        PtrStringMap<int> data;
        data.create("one", 1);
        data.create("two", 2);
        EXPECT_EQ(2u, data.size());
        EXPECT_FALSE(data.empty());
    }
}

/* ************************************************************************ */

TEST(PtrStringMapTest, add)
{
    PtrStringMap<int> data;
    data.add("one", makeUnique<int>(1));
    data.add("two", makeUnique<int>(2));
    EXPECT_EQ(2u, data.size());

    EXPECT_TRUE(data.exists("one"));
    EXPECT_TRUE(data.exists("two"));
    EXPECT_FALSE(data.exists("three"));

    // Replace
    data.add("one", makeUnique<int>(3));
    EXPECT_EQ(2u, data.size());
    EXPECT_TRUE(data.exists("one"));
}

/* ************************************************************************ */

TEST(PtrStringMapTest, exists)
{
    PtrStringMap<int> data;
    data.create("one", 1);
    data.create("two", 2);
    EXPECT_EQ(2u, data.size());

    EXPECT_TRUE(data.exists("one"));
    EXPECT_TRUE(data.exists("two"));
    EXPECT_FALSE(data.exists("three"));
}

/* ************************************************************************ */

TEST(PtrStringMapTest, at)
{
    PtrStringMap<int> data;
    data.create("one", 1);
    data.create("two", 2);
    EXPECT_EQ(2u, data.size());

    EXPECT_EQ(1, *data.at("one"));
    EXPECT_EQ(2, *data.at("two"));
    EXPECT_THROW(data.at("three"), OutOfRangeException);
}

/* ************************************************************************ */

TEST(PtrStringMapTest, get)
{
    PtrStringMap<int> data;
    data.create("one", 1);
    data.create("two", 2);
    EXPECT_EQ(2u, data.size());

    ASSERT_NE(nullptr, data.get("one"));
    EXPECT_EQ(1, *data.get("one"));
    ASSERT_NE(nullptr, data.get("two"));
    EXPECT_EQ(2, *data.get("two"));
    EXPECT_EQ(nullptr, data.get("three"));
}

/* ************************************************************************ */

TEST(PtrStringMapTest, remove)
{
    PtrStringMap<int> data;
    data.add("one", makeUnique<int>(1));
    data.add("two", makeUnique<int>(2));
    EXPECT_EQ(2u, data.size());

    data.remove("one");

    EXPECT_EQ(1u, data.size());
}

/* ************************************************************************ */
