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
#include "cece/SharedPtr.hpp"
#include "cece/ViewPtr.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

TEST(SharedPtr, ctor)
{
    {
        SharedPtr<int> ptr;
        EXPECT_EQ(nullptr, ptr);
    }

    {
        SharedPtr<int> ptr(new int{5});
        ASSERT_NE(nullptr, ptr);
        EXPECT_EQ(5, *ptr);
    }
}

/* ************************************************************************ */

TEST(SharedPtr, makeShared)
{
    {
        auto ptr = makeShared<int>(5);
        ::testing::StaticAssertTypeEq<decltype(ptr), SharedPtr<int>>();
        ASSERT_NE(nullptr, ptr);
        EXPECT_EQ(5, *ptr);
    }
}

/* ************************************************************************ */

TEST(SharedPtr, makeView)
{
    {
        auto ptr = makeShared<int>(10);
        auto view = makeView(ptr);
        ASSERT_NE(nullptr, ptr);
        EXPECT_EQ(view.get(), ptr.get());
        EXPECT_EQ(10, *ptr);
        EXPECT_EQ(10, *view);
    }
}

/* ************************************************************************ */
