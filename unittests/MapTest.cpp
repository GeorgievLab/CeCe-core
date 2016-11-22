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
#include "cece/Map.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

TEST(MapTest, ctors)
{
    {
        Map<int, int> data;
        EXPECT_EQ(0u, data.size());
        EXPECT_TRUE(data.empty());
    }

    {
        Map<int, int> data{{1, 2}, {2, 3}};
        EXPECT_EQ(2u, data.size());
        EXPECT_FALSE(data.empty());
    }
}

/* ************************************************************************ */

TEST(MapTest, at)
{
    Map<int, int> data;
    data.emplace(0, 0);
    data.emplace(1, 3);
    EXPECT_EQ(2u, data.size());

    EXPECT_EQ(0, data.at(0));
    EXPECT_EQ(3, data.at(1));
    EXPECT_THROW(data.at(2), OutOfRangeException);
}

/* ************************************************************************ */
