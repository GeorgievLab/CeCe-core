/* ************************************************************************ */
/* Georgiev Lab (c) 2015-2017                                               */
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
#include "cece/math/Vector.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;

/* ************************************************************************ */

TEST(Vector, ctor)
{
    {
        Vector<int, 5> vec;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);
    }

    {
        Vector<int, 10> vec(Zero);

        EXPECT_EQ(10, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);
        EXPECT_EQ(0, vec[5]);
        EXPECT_EQ(0, vec[6]);
        EXPECT_EQ(0, vec[7]);
        EXPECT_EQ(0, vec[8]);
        EXPECT_EQ(0, vec[9]);
    }

    {
        Vector<float, 5> vec = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        float data[5] = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        Vector<float, 5> vec(data);

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        StaticArray<float, 5> data = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        Vector<float, 5> vec(data);

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        const Vector<float, 5> vec1 = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(0.0f, vec1[2]);
        EXPECT_FLOAT_EQ(45.1f, vec1[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec1[4]);

        Vector<float, 5> vec2(vec1);

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.1f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }

    {
        Vector<float, 5> vec1 = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(0.0f, vec1[2]);
        EXPECT_FLOAT_EQ(45.1f, vec1[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec1[4]);

        Vector<float, 5> vec2(std::move(vec1));

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.1f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }

    {
        const Vector<int, 5> vec1 = {1, 3, 0, 45, -34};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(0, vec1[2]);
        EXPECT_EQ(45, vec1[3]);
        EXPECT_EQ(-34, vec1[4]);

        Vector<float, 5> vec2(vec1);

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.0, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.0f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }
}

/* ************************************************************************ */

TEST(Vector, assignment)
{
    {
        Vector<int, 10> vec{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        EXPECT_EQ(10, vec.getSize());
        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);
        EXPECT_EQ(1, vec[2]);
        EXPECT_EQ(1, vec[3]);
        EXPECT_EQ(1, vec[4]);
        EXPECT_EQ(1, vec[5]);
        EXPECT_EQ(1, vec[6]);
        EXPECT_EQ(1, vec[7]);
        EXPECT_EQ(1, vec[8]);
        EXPECT_EQ(1, vec[9]);

        vec = Zero;

        EXPECT_EQ(10, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);
        EXPECT_EQ(0, vec[5]);
        EXPECT_EQ(0, vec[6]);
        EXPECT_EQ(0, vec[7]);
        EXPECT_EQ(0, vec[8]);
        EXPECT_EQ(0, vec[9]);
    }

    {
        Vector<float, 5> vec;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);

        vec = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        Vector<float, 5> vec;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);

        float data[5] = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        vec = data;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        Vector<float, 5> vec;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
        EXPECT_EQ(0, vec[3]);
        EXPECT_EQ(0, vec[4]);

        StaticArray<float, 5> data = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        vec = data;

        EXPECT_EQ(5, vec.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
        EXPECT_FLOAT_EQ(45.1f, vec[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec[4]);
    }

    {
        const Vector<float, 5> vec1 = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(0.0f, vec1[2]);
        EXPECT_FLOAT_EQ(45.1f, vec1[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec1[4]);

        Vector<float, 5> vec2;

        vec2 = vec1;

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.1f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }

    {
        Vector<float, 5> vec1 = {1.2f, 3.0f, 0.0f, 45.1f, -34.f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(0.0f, vec1[2]);
        EXPECT_FLOAT_EQ(45.1f, vec1[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec1[4]);

        Vector<float, 5> vec2;

        vec2 = std::move(vec1);

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.1f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }

    {
        const Vector<int, 5> vec1 = {1, 3, 0, 45, -34};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(0, vec1[2]);
        EXPECT_EQ(45, vec1[3]);
        EXPECT_EQ(-34, vec1[4]);

        Vector<float, 5> vec2;

        vec2 = vec1;

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.0, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(0.0f, vec2[2]);
        EXPECT_FLOAT_EQ(45.0f, vec2[3]);
        EXPECT_FLOAT_EQ(-34.0f, vec2[4]);
    }
}

/* ************************************************************************ */

TEST(Vector, operators)
{
    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -300.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-300.8f, vec1[4]);

        Vector<float, 5> vec2 = +vec1;

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(2.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec2[2]);
        EXPECT_FLOAT_EQ(0.0f, vec2[3]);
        EXPECT_FLOAT_EQ(-300.8f, vec2[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -300.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-300.8f, vec1[4]);

        Vector<float, 5> vec2 = -vec1;

        EXPECT_EQ(5, vec2.getSize());
        EXPECT_FLOAT_EQ(-1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(-2.0f, vec2[1]);
        EXPECT_FLOAT_EQ(5.0f, vec2[2]);
        EXPECT_FLOAT_EQ(0.0f, vec2[3]);
        EXPECT_FLOAT_EQ(300.8f, vec2[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        Vector<float, 5> vec2{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        vec1 += vec2;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-2.0f, vec1[2]);
        EXPECT_FLOAT_EQ(4.0f, vec1[3]);
        EXPECT_FLOAT_EQ(1.2f, vec1[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        Vector<float, 5> vec2{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        vec1 -= vec2;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(0.0f, vec1[0]);
        EXPECT_FLOAT_EQ(0.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.0f, vec1[2]);
        EXPECT_FLOAT_EQ(-4.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-8.8f, vec1[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        vec1 *= 2.0;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-10.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-7.6f, vec1[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        Vector<float, 5> vec2{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        vec1 *= vec2;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-15.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-19.0f, vec1[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        vec1 /= 2.0;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(0.5f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-2.5f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-1.9f, vec1[4]);
    }

    {
        Vector<float, 5> vec1{1.0f, 2.0f, -5.0f, 0.0f, -3.8f};

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f, vec1[4]);

        Vector<float, 5> vec2{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        vec1 /= vec2;

        EXPECT_EQ(5, vec1.getSize());
        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-5.0f / 3.0f, vec1[2]);
        EXPECT_FLOAT_EQ(0.0f, vec1[3]);
        EXPECT_FLOAT_EQ(-3.8f / 5.0f, vec1[4]);
    }
}

/* ************************************************************************ */

TEST(Vector, memberFunctions)
{
    {
        const Vector<float, 5> vec;

        EXPECT_FLOAT_EQ(0, vec.getLength());
    }

    {
        const Vector<float, 5> vec{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

        EXPECT_FLOAT_EQ(7.4162f, vec.getLength());
    }

    {
        const Vector<float, 5> vec;

        EXPECT_FLOAT_EQ(0, vec.getLengthSquared());
    }

    {
        const Vector<float, 5> vec{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

        EXPECT_FLOAT_EQ(55, vec.getLengthSquared());
    }

    {
        const Vector<float, 5> vec;

        EXPECT_FLOAT_EQ(vec.getLengthSquared(), dot(vec, vec));
    }

    {
        const Vector<float, 5> vec{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

        EXPECT_FLOAT_EQ(vec.getLengthSquared(), dot(vec, vec));
    }

    {
        const Vector<float, 5> vec1;
        const Vector<float, 5> vec2;

        EXPECT_FLOAT_EQ(0, dot(vec1, vec2));
    }

    {
        const Vector<float, 5> vec1{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        const Vector<float, 5> vec2{5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

        EXPECT_FLOAT_EQ(35, dot(vec1, vec2));
    }

    {
        const Vector<float, 5> vec;

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector<float, 5> vec{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector<float, 5> vec1{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        const Vector<float, 5> vec2{5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

        EXPECT_FLOAT_EQ(40.0f, distanceSquared(vec1, vec2));
    }

    {
        const Vector<float, 5> vec1{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        const Vector<float, 5> vec2{5.0f, 4.0f, 3.0f, 2.0f, 1.0f};

        EXPECT_FLOAT_EQ(6.3245554f, distance(vec1, vec2));
    }
}

/* ************************************************************************ */
