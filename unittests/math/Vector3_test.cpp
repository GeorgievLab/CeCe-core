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

TEST(Vector3, ctorDefault)
{
    {
        Vector3<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        constexpr Vector3<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<unsigned int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        constexpr Vector3<unsigned int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<float> vec;

        EXPECT_FLOAT_EQ(0.0f, vec.getX());
        EXPECT_FLOAT_EQ(0.0f, vec.getY());
        EXPECT_FLOAT_EQ(0.0f, vec.getZ());
        EXPECT_FLOAT_EQ(0.0f, vec[0]);
        EXPECT_FLOAT_EQ(0.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
    }

    {
        Vector3<double> vec;

        EXPECT_DOUBLE_EQ(0.0, vec.getX());
        EXPECT_DOUBLE_EQ(0.0, vec.getY());
        EXPECT_DOUBLE_EQ(0.0, vec.getZ());
        EXPECT_DOUBLE_EQ(0.0, vec[0]);
        EXPECT_DOUBLE_EQ(0.0, vec[1]);
        EXPECT_DOUBLE_EQ(0.0, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, ctorZero)
{
    {
        Vector3<int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        constexpr Vector3<int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<unsigned int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<float> vec(Zero);

        EXPECT_FLOAT_EQ(0.0f, vec.getX());
        EXPECT_FLOAT_EQ(0.0f, vec.getY());
        EXPECT_FLOAT_EQ(0.0f, vec.getZ());
        EXPECT_FLOAT_EQ(0.0f, vec[0]);
        EXPECT_FLOAT_EQ(0.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
    }

    {
        Vector3<double> vec(Zero);

        EXPECT_DOUBLE_EQ(0.0, vec.getX());
        EXPECT_DOUBLE_EQ(0.0, vec.getY());
        EXPECT_DOUBLE_EQ(0.0, vec.getZ());
        EXPECT_DOUBLE_EQ(0.0, vec[0]);
        EXPECT_DOUBLE_EQ(0.0, vec[1]);
        EXPECT_DOUBLE_EQ(0.0, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, ctorSingle)
{
    {
        Vector3<int> vec{1};

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(1, vec.getY());
        EXPECT_EQ(1, vec.getZ());
        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);
        EXPECT_EQ(1, vec[2]);
    }

    {
        constexpr Vector3<int> vec{1};

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(1, vec.getY());
        EXPECT_EQ(1, vec.getZ());
        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);
        EXPECT_EQ(1, vec[2]);
    }

    {
        Vector3<unsigned int> vec{3};

        EXPECT_EQ(3, vec.getX());
        EXPECT_EQ(3, vec.getY());
        EXPECT_EQ(3, vec.getZ());
        EXPECT_EQ(3, vec[0]);
        EXPECT_EQ(3, vec[1]);
        EXPECT_EQ(3, vec[2]);
    }

    {
        Vector3<float> vec{1.2f};

        EXPECT_FLOAT_EQ(1.2f, vec.getX());
        EXPECT_FLOAT_EQ(1.2f, vec.getY());
        EXPECT_FLOAT_EQ(1.2f, vec.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(1.2f, vec[1]);
        EXPECT_FLOAT_EQ(1.2f, vec[2]);
    }

    {
        Vector3<double> vec{1.2};

        EXPECT_DOUBLE_EQ(1.2, vec.getX());
        EXPECT_DOUBLE_EQ(1.2, vec.getY());
        EXPECT_DOUBLE_EQ(1.2, vec.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec[0]);
        EXPECT_DOUBLE_EQ(1.2, vec[1]);
        EXPECT_DOUBLE_EQ(1.2, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, ctorElements)
{
    {
        Vector3<int> vec = {1, 3, -8};

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(3, vec.getY());
        EXPECT_EQ(-8, vec.getZ());
        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(3, vec[1]);
        EXPECT_EQ(-8, vec[2]);
    }

    {
        Vector3<unsigned int> vec = {1, 3, 8};

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(3, vec.getY());
        EXPECT_EQ(8, vec.getZ());
        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(3, vec[1]);
        EXPECT_EQ(8, vec[2]);
    }

    {
        Vector3<float> vec = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec.getX());
        EXPECT_FLOAT_EQ(3.0f, vec.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec[2]);
    }

    {
        Vector3<double> vec = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec.getX());
        EXPECT_DOUBLE_EQ(3.0, vec.getY());
        EXPECT_DOUBLE_EQ(-8.1, vec.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec[0]);
        EXPECT_DOUBLE_EQ(3.0, vec[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, ctorCopy)
{
    {
        const Vector3<int> vec1 = {1, 3, -8};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(-8, vec1.getZ());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.0f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(-8.0f, vec2.getZ());
        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.0f, vec2[2]);
    }

    {
        const Vector3<unsigned int> vec1 = {1, 3, 8};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(8, vec1.getZ());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<int> vec2(vec1);

        EXPECT_EQ(1, vec2.getX());
        EXPECT_EQ(3, vec2.getY());
        EXPECT_EQ(8, vec2.getZ());
        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        const Vector3<float> vec1 = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec2.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec2[2]);
    }

    {
        const Vector3<double> vec1 = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec1.getX());
        EXPECT_DOUBLE_EQ(3.0, vec1.getY());
        EXPECT_DOUBLE_EQ(-8.1, vec1.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec1[0]);
        EXPECT_DOUBLE_EQ(3.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2(vec1);

        EXPECT_DOUBLE_EQ(1.2, vec2.getX());
        EXPECT_DOUBLE_EQ(3.0, vec2.getY());
        EXPECT_DOUBLE_EQ(-8.1, vec2.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec2[0]);
        EXPECT_DOUBLE_EQ(3.0, vec2[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec2[2]);
    }

}

/* ************************************************************************ */

TEST(Vector3, ctorMove)
{
    {
        Vector3<int> vec1 = {1, 3, -8};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(-8, vec1.getZ());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2(std::move(vec1));

        EXPECT_EQ(1, vec2.getX());
        EXPECT_EQ(3, vec2.getY());
        EXPECT_EQ(-8, vec2.getZ());
        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(-8, vec2[2]);
    }

    {
        Vector3<unsigned int> vec1 = {1, 3, 8};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(8, vec1.getZ());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2(std::move(vec1));

        EXPECT_EQ(1, vec2.getX());
        EXPECT_EQ(3, vec2.getY());
        EXPECT_EQ(8, vec2.getZ());
        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        Vector3<float> vec1 = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2(std::move(vec1));

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec2.getZ());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec2[2]);
    }

    {
        Vector3<double> vec1 = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec1.getX());
        EXPECT_DOUBLE_EQ(3.0, vec1.getY());
        EXPECT_DOUBLE_EQ(-8.1, vec1.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec1[0]);
        EXPECT_DOUBLE_EQ(3.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2(std::move(vec1));

        EXPECT_DOUBLE_EQ(1.2, vec2.getX());
        EXPECT_DOUBLE_EQ(3.0, vec2.getY());
        EXPECT_DOUBLE_EQ(-8.1, vec2.getZ());
        EXPECT_DOUBLE_EQ(1.2, vec2[0]);
        EXPECT_DOUBLE_EQ(3.0, vec2[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec2[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, assignmentZero)
{
    {
        Vector3<int> vec{1, 1, 1};

        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);
        EXPECT_EQ(1, vec[2]);

        vec = Zero;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<unsigned int> vec{1, 1, 1};

        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);
        EXPECT_EQ(1, vec[2]);

        vec = Zero;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);
    }

    {
        Vector3<float> vec{1.0f, 1.0f, 1.0f};

        EXPECT_FLOAT_EQ(1.0f, vec[0]);
        EXPECT_FLOAT_EQ(1.0f, vec[1]);
        EXPECT_FLOAT_EQ(1.0f, vec[2]);

        vec = Zero;

        EXPECT_FLOAT_EQ(0.0f, vec[0]);
        EXPECT_FLOAT_EQ(0.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);
    }

    {
        Vector3<double> vec{1.0, 1.0, 1.0};

        EXPECT_DOUBLE_EQ(1.0, vec[0]);
        EXPECT_DOUBLE_EQ(1.0, vec[1]);
        EXPECT_DOUBLE_EQ(1.0, vec[2]);

        vec = Zero;

        EXPECT_DOUBLE_EQ(0.0, vec[0]);
        EXPECT_DOUBLE_EQ(0.0, vec[1]);
        EXPECT_DOUBLE_EQ(0.0, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, assignmentElements)
{
    {
        Vector3<int> vec;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);

        vec = {1, 3, -8};

        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(3, vec[1]);
        EXPECT_EQ(-8, vec[2]);
    }

    {
        Vector3<unsigned int> vec;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
        EXPECT_EQ(0, vec[2]);

        vec = {1, 3, 8};

        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(3, vec[1]);
        EXPECT_EQ(8, vec[2]);
    }

    {
        Vector3<float> vec;

        EXPECT_FLOAT_EQ(0.0f, vec[0]);
        EXPECT_FLOAT_EQ(0.0f, vec[1]);
        EXPECT_FLOAT_EQ(0.0f, vec[2]);

        vec = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec[2]);
    }

    {
        Vector3<double> vec;

        EXPECT_DOUBLE_EQ(0.0, vec[0]);
        EXPECT_DOUBLE_EQ(0.0, vec[1]);
        EXPECT_DOUBLE_EQ(0.0, vec[2]);

        vec = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec[0]);
        EXPECT_DOUBLE_EQ(3.0, vec[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, assignmentCopy)
{
    {
        const Vector3<int> vec1 = {1, 3, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<float> vec2;

        vec2 = vec1;

        EXPECT_FLOAT_EQ(1.0, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.0f, vec2[2]);
    }

    {
        const Vector3<unsigned int> vec1 = {1, 3, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<int> vec2;

        vec2 = vec1;

        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        const Vector3<float> vec1 = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2;

        vec2 = vec1;

        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec2[2]);
    }

    {
        const Vector3<double> vec1 = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec1[0]);
        EXPECT_DOUBLE_EQ(3.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2;

        vec2 = vec1;

        EXPECT_DOUBLE_EQ(1.2, vec2[0]);
        EXPECT_DOUBLE_EQ(3.0, vec2[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec2[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, assignmentMove)
{
    {
        Vector3<int> vec1 = {1, 3, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2;

        vec2 = std::move(vec1);

        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(-8, vec2[2]);
    }

    {
        Vector3<unsigned int> vec1 = {1, 3, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2;

        vec2 = std::move(vec1);

        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(3, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        Vector3<float> vec1 = {1.2f, 3.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2;

        vec2 = std::move(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec2[2]);
    }

    {
        Vector3<double> vec1 = {1.2, 3.0, -8.1};

        EXPECT_DOUBLE_EQ(1.2, vec1[0]);
        EXPECT_DOUBLE_EQ(3.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2;

        vec2 = std::move(vec1);

        EXPECT_DOUBLE_EQ(1.2, vec2[0]);
        EXPECT_DOUBLE_EQ(3.0, vec2[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec2[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorUnaryPlus)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2 = +vec1;

        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(2, vec2[1]);
        EXPECT_EQ(-8, vec2[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2 = +vec1;

        EXPECT_EQ(1, vec2[0]);
        EXPECT_EQ(2, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2 = +vec1;

        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(2.0f, vec2[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec2[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2 = +vec1;

        EXPECT_DOUBLE_EQ(1.0, vec2[0]);
        EXPECT_DOUBLE_EQ(2.0, vec2[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec2[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorUnaryMinus)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2 = -vec1;

        EXPECT_EQ(-1, vec2[0]);
        EXPECT_EQ(-2, vec2[1]);
        EXPECT_EQ(8, vec2[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2 = -vec1;

        EXPECT_EQ(-1, vec2[0]);
        EXPECT_EQ(-2, vec2[1]);
        EXPECT_EQ(-8, vec2[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2 = -vec1;

        EXPECT_FLOAT_EQ(-1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(-2.0f, vec2[1]);
        EXPECT_FLOAT_EQ(8.1f, vec2[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2 = -vec1;

        EXPECT_DOUBLE_EQ(-1.0, vec2[0]);
        EXPECT_DOUBLE_EQ(-2.0, vec2[1]);
        EXPECT_DOUBLE_EQ(8.1, vec2[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorPlus)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2{1, 2, -8};
        vec1 += vec2;

        EXPECT_EQ(2, vec1[0]);
        EXPECT_EQ(4, vec1[1]);
        EXPECT_EQ(-16, vec1[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2{1, 2, 8};
        vec1 += vec2;

        EXPECT_EQ(2, vec1[0]);
        EXPECT_EQ(4, vec1[1]);
        EXPECT_EQ(16, vec1[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2{1.0f, 2.0f, -8.1f};
        vec1 += vec2;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-16.2f, vec1[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2{1.0, 2.0, -8.1};
        vec1 += vec2;

        EXPECT_DOUBLE_EQ(2.0, vec1[0]);
        EXPECT_DOUBLE_EQ(4.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-16.2, vec1[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorMinus)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        Vector3<int> vec2{1, 2, -8};
        vec1 -= vec2;

        EXPECT_EQ(0, vec1[0]);
        EXPECT_EQ(0, vec1[1]);
        EXPECT_EQ(0, vec1[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        Vector3<unsigned int> vec2{1, 2, 8};
        vec1 -= vec2;

        EXPECT_EQ(0, vec1[0]);
        EXPECT_EQ(0, vec1[1]);
        EXPECT_EQ(0, vec1[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        Vector3<float> vec2{1.0f, 2.0f, -8.1f};
        vec1 -= vec2;

        EXPECT_FLOAT_EQ(0.0f, vec1[0]);
        EXPECT_FLOAT_EQ(0.0f, vec1[1]);
        EXPECT_FLOAT_EQ(0.0f, vec1[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        Vector3<double> vec2{1.0, 2.0, -8.1};
        vec1 -= vec2;

        EXPECT_DOUBLE_EQ(0.0, vec1[0]);
        EXPECT_DOUBLE_EQ(0.0, vec1[1]);
        EXPECT_DOUBLE_EQ(0.0, vec1[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorMult)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        vec1 *= 2.0;

        EXPECT_EQ(2, vec1[0]);
        EXPECT_EQ(4, vec1[1]);
        EXPECT_EQ(-16, vec1[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        vec1 *= 2.0;

        EXPECT_EQ(2, vec1[0]);
        EXPECT_EQ(4, vec1[1]);
        EXPECT_EQ(16, vec1[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        vec1 *= 2.0;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-16.2f, vec1[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        vec1 *= 2.0;

        EXPECT_DOUBLE_EQ(2.0, vec1[0]);
        EXPECT_DOUBLE_EQ(4.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-16.2, vec1[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, operatorDiv)
{
    {
        Vector3<int> vec1{1, 2, -8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(-8, vec1[2]);

        vec1 /= 2.0;

        EXPECT_EQ(0, vec1[0]);
        EXPECT_EQ(1, vec1[1]);
        EXPECT_EQ(-4, vec1[2]);
    }

    {
        Vector3<unsigned int> vec1{1, 2, 8};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(2, vec1[1]);
        EXPECT_EQ(8, vec1[2]);

        vec1 /= 2.0;

        EXPECT_EQ(0, vec1[0]);
        EXPECT_EQ(1, vec1[1]);
        EXPECT_EQ(4, vec1[2]);
    }

    {
        Vector3<float> vec1{1.0f, 2.0f, -8.1f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-8.1f, vec1[2]);

        vec1 /= 2.0;

        EXPECT_FLOAT_EQ(0.5f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
        EXPECT_FLOAT_EQ(-4.05f, vec1[2]);
    }

    {
        Vector3<double> vec1{1.0, 2.0, -8.1};

        EXPECT_DOUBLE_EQ(1.0, vec1[0]);
        EXPECT_DOUBLE_EQ(2.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-8.1, vec1[2]);

        vec1 /= 2.0;

        EXPECT_DOUBLE_EQ(0.5, vec1[0]);
        EXPECT_DOUBLE_EQ(1.0, vec1[1]);
        EXPECT_DOUBLE_EQ(-4.05, vec1[2]);
    }
}

/* ************************************************************************ */

TEST(Vector3, memberFunctions)
{
    {
        const Vector3<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLength());
    }

    {
        const Vector3<float> vec{1.0f, 2.0f, 3.0f};

        EXPECT_FLOAT_EQ(3.7416574f, vec.getLength());
    }

    {
        const Vector3<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLengthSquared());
    }

    {
        const Vector3<float> vec{1.0f, 2.0f, 3.0f};

        EXPECT_FLOAT_EQ(14, vec.getLengthSquared());
    }
}

/* ************************************************************************ */

TEST(Vector3, mutators)
{
    {
        Vector3<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setX(100);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setY(50);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(50, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setZ(10);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(50, vec.getY());
        EXPECT_EQ(10, vec.getZ());
    }

    {
        Vector3<int> vec;

        EXPECT_EQ(0, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.x = 100;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.y = 50;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.z = 10;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
        EXPECT_EQ(10, vec.z);
    }

    {
        Vector3<unsigned int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setX(100);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setY(50);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(50, vec.getY());
        EXPECT_EQ(0, vec.getZ());

        vec.setZ(10);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(50, vec.getY());
        EXPECT_EQ(10, vec.getZ());
    }

    {
        Vector3<unsigned int> vec;

        EXPECT_EQ(0, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.x = 100;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.y = 50;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
        EXPECT_EQ(0, vec.z);

        vec.z = 10;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
        EXPECT_EQ(10, vec.z);
    }

    {
        Vector3<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getX());
        EXPECT_FLOAT_EQ(0, vec.getY());
        EXPECT_FLOAT_EQ(0, vec.getZ());

        vec.setX(100.3f);

        EXPECT_FLOAT_EQ(100.3f, vec.getX());
        EXPECT_FLOAT_EQ(0, vec.getY());
        EXPECT_FLOAT_EQ(0, vec.getZ());

        vec.setY(50);

        EXPECT_FLOAT_EQ(100.3f, vec.getX());
        EXPECT_FLOAT_EQ(50, vec.getY());
        EXPECT_FLOAT_EQ(0, vec.getZ());

        vec.setZ(10);

        EXPECT_FLOAT_EQ(100.3f, vec.getX());
        EXPECT_FLOAT_EQ(50, vec.getY());
        EXPECT_FLOAT_EQ(10, vec.getZ());
    }

    {
        Vector3<float> vec;

        EXPECT_FLOAT_EQ(0, vec.x);
        EXPECT_FLOAT_EQ(0, vec.y);
        EXPECT_FLOAT_EQ(0, vec.z);

        vec.x = 100.3f;

        EXPECT_FLOAT_EQ(100.3f, vec.x);
        EXPECT_FLOAT_EQ(0, vec.y);
        EXPECT_FLOAT_EQ(0, vec.z);

        vec.y = 50;

        EXPECT_FLOAT_EQ(100.3f, vec.x);
        EXPECT_FLOAT_EQ(50, vec.y);
        EXPECT_FLOAT_EQ(0, vec.z);

        vec.z = 10;

        EXPECT_FLOAT_EQ(100.3f, vec.x);
        EXPECT_FLOAT_EQ(50, vec.y);
        EXPECT_FLOAT_EQ(10, vec.z);
    }

    {
        Vector3<double> vec;

        EXPECT_DOUBLE_EQ(0, vec.getX());
        EXPECT_DOUBLE_EQ(0, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setX(100.3);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(0, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setY(50);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(50, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setZ(10);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(50, vec.getY());
        EXPECT_DOUBLE_EQ(10, vec.getZ());
    }

    {
        Vector3<double> vec;

        EXPECT_DOUBLE_EQ(0, vec.getX());
        EXPECT_DOUBLE_EQ(0, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setWidth(100.3);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(0, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setHeight(50);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(50, vec.getY());
        EXPECT_DOUBLE_EQ(0, vec.getZ());

        vec.setDepth(10);

        EXPECT_DOUBLE_EQ(100.3, vec.getX());
        EXPECT_DOUBLE_EQ(50, vec.getY());
        EXPECT_DOUBLE_EQ(10, vec.getZ());
        EXPECT_DOUBLE_EQ(100.3, vec.getWidth());
        EXPECT_DOUBLE_EQ(50, vec.getHeight());
        EXPECT_DOUBLE_EQ(10, vec.getDepth());
    }

    {
        Vector3<double> vec;

        EXPECT_DOUBLE_EQ(0, vec.x);
        EXPECT_DOUBLE_EQ(0, vec.y);
        EXPECT_DOUBLE_EQ(0, vec.z);

        vec.x = 100.3;

        EXPECT_DOUBLE_EQ(100.3, vec.x);
        EXPECT_DOUBLE_EQ(0, vec.y);
        EXPECT_DOUBLE_EQ(0, vec.z);

        vec.y = 50;

        EXPECT_DOUBLE_EQ(100.3, vec.x);
        EXPECT_DOUBLE_EQ(50, vec.y);
        EXPECT_DOUBLE_EQ(0, vec.z);

        vec.z = 10;

        EXPECT_DOUBLE_EQ(100.3, vec.x);
        EXPECT_DOUBLE_EQ(50, vec.y);
        EXPECT_DOUBLE_EQ(10, vec.z);
    }
}

/* ************************************************************************ */

TEST(Vector3, functions)
{
    {
        Vector3<float> vec1(0.94333f, 0.73733f, 0.92636f);
        Vector3<float> vec2(0.16110f, 0.61872f, 0.21556f);

        EXPECT_FLOAT_EQ(0.94333f, vec1.getX());
        EXPECT_FLOAT_EQ(0.73733f, vec1.getY());
        EXPECT_FLOAT_EQ(0.92636f, vec1.getZ());

        EXPECT_FLOAT_EQ(0.16110f, vec2.getX());
        EXPECT_FLOAT_EQ(0.61872f, vec2.getY());
        EXPECT_FLOAT_EQ(0.21556f, vec2.getZ());

        auto vec3 = cross(vec1, vec2);

        EXPECT_FLOAT_EQ(0.73733f * 0.21556f - 0.92636f * 0.61872f, vec3.getX());
        EXPECT_FLOAT_EQ(0.92636f * 0.16110f - 0.94333f * 0.21556f, vec3.getY());
        EXPECT_FLOAT_EQ(0.94333f * 0.61872f - 0.73733f * 0.16110f, vec3.getZ());
    }

    {
        Vector3<float> vec1(0.94333f, 0.73733f, 0.92636f);
        Vector3<float> vec2(0.16110f, 0.61872f, 0.21556f);

        EXPECT_FLOAT_EQ(0.94333f, vec1.getX());
        EXPECT_FLOAT_EQ(0.73733f, vec1.getY());
        EXPECT_FLOAT_EQ(0.92636f, vec1.getZ());

        EXPECT_FLOAT_EQ(0.16110f, vec2.getX());
        EXPECT_FLOAT_EQ(0.61872f, vec2.getY());
        EXPECT_FLOAT_EQ(0.21556f, vec2.getZ());

        auto res = dot(vec1, vec2);

        EXPECT_FLOAT_EQ(
            0.94333f * 0.16110f +
            0.73733f * 0.61872f +
            0.92636f * 0.21556f,
            res
        );
    }

    {
        const Vector3<float> vec;

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector3<float> vec{1.0f, 2.0f, 3.0f};

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector3<float> vec1{1.0f, 2.0f, 3.0f};
        const Vector3<float> vec2{5.0f, 4.0f, 3.0f};

        EXPECT_FLOAT_EQ(20.0f, distanceSquared(vec1, vec2));
    }

    {
        const Vector3<float> vec1{1.0f, 2.0f, 3.0f};
        const Vector3<float> vec2{5.0f, 4.0f, 3.0f};

        EXPECT_FLOAT_EQ(4.4721360f, distance(vec1, vec2));
    }
}

/* ************************************************************************ */

TEST(Vector3, freeOperators)
{
    {
        const Vector3<float> vec1(5.3f, 8.9f, -8.1f);
        const Vector3<float> vec2(3.3f, 1.2f, 2.5f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());
        EXPECT_FLOAT_EQ(2.5f, vec2.getZ());

        const auto vec3 = vec1 + vec2;
        const auto vec4 = vec2 + vec1;

        EXPECT_FLOAT_EQ(5.3f + 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f + 1.2f, vec3.getY());
        EXPECT_FLOAT_EQ(-8.1f + 2.5f, vec3.getZ());

        EXPECT_FLOAT_EQ(3.3f + 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f + 8.9f, vec4.getY());
        EXPECT_FLOAT_EQ(2.5f + -8.1f, vec4.getZ());
    }

    {
        const Vector3<float> vec1(5.3f, 8.9f, -8.1f);
        const Vector3<float> vec2(3.3f, 1.2f, 2.5f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());
        EXPECT_FLOAT_EQ(2.5f, vec2.getZ());

        const auto vec3 = vec1 - vec2;
        const auto vec4 = vec2 - vec1;

        EXPECT_FLOAT_EQ(5.3f - 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f - 1.2f, vec3.getY());
        EXPECT_FLOAT_EQ(-8.1f - 2.5f, vec3.getZ());

        EXPECT_FLOAT_EQ(3.3f - 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f - 8.9f, vec4.getY());
        EXPECT_FLOAT_EQ(2.5f - -8.1f, vec4.getZ());
    }

    {
        const Vector3<float> vec1(5.3f, 8.9f, -8.1f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());

        const auto vec3 = vec1 * 3.2f;
        const auto vec4 = 3.2f * vec1;

        EXPECT_FLOAT_EQ(5.3f * 3.2f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f * 3.2f, vec3.getY());
        EXPECT_FLOAT_EQ(-8.1f * 3.2f, vec3.getZ());

        EXPECT_FLOAT_EQ(3.2f * 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.2f * 8.9f, vec4.getY());
        EXPECT_FLOAT_EQ(3.2f * -8.1f, vec4.getZ());
    }

    {
        const Vector3<float> vec1(5.3f, 8.9f, -8.1f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());
        EXPECT_FLOAT_EQ(-8.1f, vec1.getZ());

        const auto vec3 = vec1 / 3.2f;
        const auto vec4 = 3.2f / vec1;

        EXPECT_FLOAT_EQ(5.3f / 3.2f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f / 3.2f, vec3.getY());
        EXPECT_FLOAT_EQ(-8.1f / 3.2f, vec3.getZ());

        EXPECT_FLOAT_EQ(3.2f / 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.2f / 8.9f, vec4.getY());
        EXPECT_FLOAT_EQ(3.2f / -8.1f, vec4.getZ());
    }

    {
        const Vector3<float> vec1(5.3f, 8.9f, -8.1f);
        const Vector3<float> vec2(5.3f, 8.9f, -8.1f);
        const Vector3<float> vec3(1.3f, 8.9f, -3.1f);
        const Vector3<float> vec4(5.3f, 0.9f, -1.1f);

        EXPECT_EQ(vec1, vec1);
        EXPECT_EQ(vec1, vec2);
        EXPECT_NE(vec1, vec3);
        EXPECT_NE(vec1, vec4);

        EXPECT_EQ(vec2, vec1);
        EXPECT_EQ(vec2, vec2);
        EXPECT_NE(vec2, vec3);
        EXPECT_NE(vec2, vec4);

        EXPECT_NE(vec3, vec1);
        EXPECT_NE(vec3, vec2);
        EXPECT_EQ(vec3, vec3);
        EXPECT_NE(vec3, vec4);

        EXPECT_NE(vec4, vec1);
        EXPECT_NE(vec4, vec2);
        EXPECT_NE(vec4, vec3);
        EXPECT_EQ(vec4, vec4);
    }

}

/* ************************************************************************ */
