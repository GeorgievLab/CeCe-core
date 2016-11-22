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
#include "cece/StringMap.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

TEST(StringMapTest, ctors)
{
    {
        StringMap<int> data;
        EXPECT_EQ(0u, data.size());
        EXPECT_TRUE(data.empty());
    }

    {
        StringMap<int> data{{"one", 1}, {"two", 2}};
        EXPECT_EQ(2u, data.size());
        EXPECT_FALSE(data.empty());
    }
}

/* ************************************************************************ */

TEST(StringMapTest, exists)
{
    StringMap<int> data{{"one", 1}, {"two", 2}};
    EXPECT_EQ(2u, data.size());

    EXPECT_TRUE(data.exists("one"));
    EXPECT_TRUE(data.exists("two"));
    EXPECT_FALSE(data.exists("three"));
}

/* ************************************************************************ */

TEST(StringMapTest, at)
{
    StringMap<int> data;
    data.emplace("one", 1);
    data.emplace("two", 2);
    EXPECT_EQ(2u, data.size());

    EXPECT_EQ(1, data.at("one"));
    EXPECT_EQ(2, data.at("two"));
    EXPECT_THROW(data.at("three"), OutOfRangeException);
}

/* ************************************************************************ */
