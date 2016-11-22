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
#include "cece/DynamicArray.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

struct Integer
{
    int value;

    Integer() : Integer(0) {}
    Integer(int val) : value(val) {}
};

/* ************************************************************************ */

inline bool operator==(Integer lhs, int rhs) { return lhs.value == rhs; }
inline bool operator!=(Integer lhs, int rhs) { return lhs.value != rhs; }
inline bool operator==(Integer lhs, Integer rhs) { return lhs.value == rhs.value; }
inline bool operator!=(Integer lhs, Integer rhs) { return lhs.value != rhs.value; }
inline bool operator==(int lhs, Integer rhs) { return lhs == rhs.value; }
inline bool operator!=(int lhs, Integer rhs) { return lhs != rhs.value; }

/* ************************************************************************ */

template <class T>
class DynamicArrayTest : public ::testing::Test {};

/* ************************************************************************ */

using TestTypes = ::testing::Types<char, unsigned char, int, unsigned int, Integer>;
TYPED_TEST_CASE(DynamicArrayTest, TestTypes);

/* ************************************************************************ */

TYPED_TEST(DynamicArrayTest, ctors)
{
    {
        DynamicArray<TypeParam> array;
        EXPECT_EQ(0u, array.size());
        EXPECT_TRUE(array.empty());
    }

    {
        DynamicArray<TypeParam> array(5u, TypeParam(1));
        EXPECT_EQ(5u, array.size());
        EXPECT_FALSE(array.empty());

        EXPECT_EQ(1, array[0]);
        EXPECT_EQ(1, array[1]);
        EXPECT_EQ(1, array[2]);
        EXPECT_EQ(1, array[3]);
        EXPECT_EQ(1, array[4]);
    }

    {
        DynamicArray<TypeParam> array({1, 2, 3, 4});
        EXPECT_EQ(4u, array.size());
        EXPECT_FALSE(array.empty());

        EXPECT_EQ(1, array[0]);
        EXPECT_EQ(2, array[1]);
        EXPECT_EQ(3, array[2]);
        EXPECT_EQ(4, array[3]);
    }

    {
        const TypeParam src[4] = {1, 2, 3, 4};

        DynamicArray<TypeParam> array(std::begin(src), std::end(src));
        EXPECT_EQ(4u, array.size());
        EXPECT_FALSE(array.empty());

        EXPECT_EQ(1, array[0]);
        EXPECT_EQ(2, array[1]);
        EXPECT_EQ(3, array[2]);
        EXPECT_EQ(4, array[3]);
    }
}

/* ************************************************************************ */

TYPED_TEST(DynamicArrayTest, access)
{
    {
        DynamicArray<TypeParam> array({1, 2, 3, 4});
        EXPECT_EQ(4u, array.size());
        EXPECT_FALSE(array.empty());

        EXPECT_EQ(1, array[0]);
        EXPECT_EQ(2, array[1]);
        EXPECT_EQ(3, array[2]);
        EXPECT_EQ(4, array[3]);
    }

    {
        DynamicArray<TypeParam> array({1, 2, 3, 4});
        EXPECT_EQ(4u, array.size());
        EXPECT_FALSE(array.empty());

        EXPECT_EQ(1, array.at(0));
        EXPECT_EQ(2, array.at(1));
        EXPECT_EQ(3, array.at(2));
        EXPECT_EQ(4, array.at(3));
        EXPECT_ANY_THROW(array.at(4));
    }

    {
        DynamicArray<TypeParam> a1({1, 2, 3, 4});
        EXPECT_EQ(4u, a1.size());
        EXPECT_FALSE(a1.empty());

        DynamicArray<TypeParam> a2(a1);
        EXPECT_EQ(4u, a2.size());
        EXPECT_FALSE(a2.empty());
    }

    {
        DynamicArray<TypeParam> a1({1, 2, 3, 4});
        EXPECT_EQ(4u, a1.size());
        EXPECT_FALSE(a1.empty());

        DynamicArray<TypeParam> a2(std::move(a1));
        EXPECT_EQ(4u, a2.size());
        EXPECT_FALSE(a2.empty());
    }
}

/* ************************************************************************ */

TYPED_TEST(DynamicArrayTest, assign)
{
    {
        DynamicArray<TypeParam> a1({1, 2, 3, 4});
        EXPECT_EQ(4u, a1.size());
        EXPECT_FALSE(a1.empty());

        DynamicArray<TypeParam> a2 = a1;
        EXPECT_EQ(4u, a2.size());
        EXPECT_FALSE(a2.empty());
    }

    {
        DynamicArray<TypeParam> a1({1, 2, 3, 4});
        EXPECT_EQ(4u, a1.size());
        EXPECT_FALSE(a1.empty());

        DynamicArray<TypeParam> a2 = std::move(a1);
        EXPECT_EQ(4u, a2.size());
        EXPECT_FALSE(a2.empty());
    }
}

/* ************************************************************************ */

TYPED_TEST(DynamicArrayTest, size)
{
    DynamicArray<TypeParam> array;
    EXPECT_EQ(0u, array.size());

    array.resize(10u);
    EXPECT_EQ(10u, array.size());
}

/* ************************************************************************ */
