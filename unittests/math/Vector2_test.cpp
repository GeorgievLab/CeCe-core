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
#include "cece/unit/math.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;

/* ************************************************************************ */

TEST(Vector2, ctor)
{
    {
        Vector2<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getWidth());
        EXPECT_EQ(0, vec.getHeight());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        constexpr Vector2<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getWidth());
        EXPECT_EQ(0, vec.getHeight());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        Vector2<int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getWidth());
        EXPECT_EQ(0, vec.getHeight());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        constexpr Vector2<int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec.getWidth());
        EXPECT_EQ(0, vec.getHeight());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        Vector2<float> vec(12.3f);

        EXPECT_FLOAT_EQ(12.3f, vec.getX());
        EXPECT_FLOAT_EQ(12.3f, vec.getY());
        EXPECT_FLOAT_EQ(12.3f, vec.getWidth());
        EXPECT_FLOAT_EQ(12.3f, vec.getHeight());
        EXPECT_FLOAT_EQ(12.3f, vec[0]);
        EXPECT_FLOAT_EQ(12.3f, vec[1]);
    }

    {
        constexpr Vector2<float> vec(12.3f);

        EXPECT_FLOAT_EQ(12.3f, vec.getX());
        EXPECT_FLOAT_EQ(12.3f, vec.getY());
        EXPECT_FLOAT_EQ(12.3f, vec.getWidth());
        EXPECT_FLOAT_EQ(12.3f, vec.getHeight());
        EXPECT_FLOAT_EQ(12.3f, vec[0]);
        EXPECT_FLOAT_EQ(12.3f, vec[1]);
    }

    {
        Vector2<float> vec = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec.getX());
        EXPECT_FLOAT_EQ(3.0f, vec.getY());
        EXPECT_FLOAT_EQ(1.2f, vec.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
    }

    {
        constexpr Vector2<float> vec = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec.getX());
        EXPECT_FLOAT_EQ(3.0f, vec.getY());
        EXPECT_FLOAT_EQ(1.2f, vec.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
    }

    {
        const Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec1.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        constexpr const Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec1.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        constexpr Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec1.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2(std::move(vec1));

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        constexpr Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec1.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        constexpr Vector2<float> vec2(std::move(vec1));

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        const Vector2<int> vec1 = {1, 3};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(1, vec1.getWidth());
        EXPECT_EQ(3, vec1.getHeight());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);

        Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.0f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.0f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        constexpr const Vector2<int> vec1 = {1, 3};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(1, vec1.getWidth());
        EXPECT_EQ(3, vec1.getHeight());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);

        constexpr Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.0f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.0f, vec2.getWidth());
        EXPECT_FLOAT_EQ(3.0f, vec2.getHeight());
        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }
}

/* ************************************************************************ */

TEST(Vector2, assignment)
{
    {
        Vector2<int> vec{1, 1};

        EXPECT_EQ(1, vec[0]);
        EXPECT_EQ(1, vec[1]);

        vec = Zero;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        Vector2<float> vec;

        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);

        vec = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
    }

    {
        const Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2;

        vec2 = vec1;

        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2;

        vec2 = std::move(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        const Vector2<int> vec1 = {1, 3};

        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);

        Vector2<float> vec2;

        vec2 = vec1;

        EXPECT_FLOAT_EQ(1.0, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }
}

/* ************************************************************************ */

TEST(Vector2, operators)
{
    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vector2<float> vec2 = +vec1;

        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(2.0f, vec2[1]);
    }

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vector2<float> vec2 = -vec1;

        EXPECT_FLOAT_EQ(-1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(-2.0f, vec2[1]);
    }

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vector2<float> vec2{1.0f, 2.0f};
        vec1 += vec2;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
    }

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vector2<float> vec2{1.0f, 2.0f};
        vec1 -= vec2;

        EXPECT_FLOAT_EQ(0.0f, vec1[0]);
        EXPECT_FLOAT_EQ(0.0f, vec1[1]);
    }

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        vec1 *= 2.0;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
    }

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        vec1 /= 2.0;

        EXPECT_FLOAT_EQ(0.5f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
    }
}

/* ************************************************************************ */

TEST(Vector2, memberFunctions)
{
    {
        const Vector2<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLength());
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(2.2360680f, vec.getLength());
    }

    {
        const Vector2<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLengthSquared());
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(5, vec.getLengthSquared());
    }
}

/* ************************************************************************ */

TEST(Vector2, mutators)
{
    {
        Vector2<int> vec;

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());

        vec.setX(100);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(0, vec.getY());

        vec.setY(50);

        EXPECT_EQ(100, vec.getX());
        EXPECT_EQ(50, vec.getY());
    }

    {
        Vector2<int> vec;

        EXPECT_EQ(0, vec.x);
        EXPECT_EQ(0, vec.y);

        vec.x = 100;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(0, vec.y);

        vec.y = 50;

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
    }

    {
        Vector2<int> vec;

        EXPECT_EQ(0, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(0, vec.width);
        EXPECT_EQ(0, vec.height);

        vec.setWidth(100);

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(0, vec.y);
        EXPECT_EQ(100, vec.width);
        EXPECT_EQ(0, vec.height);

        vec.setHeight(50);

        EXPECT_EQ(100, vec.x);
        EXPECT_EQ(50, vec.y);
        EXPECT_EQ(100, vec.width);
        EXPECT_EQ(50, vec.height);
    }
}

/* ************************************************************************ */

TEST(Vector2, functions)
{
    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = rotate(vec, unit::deg2rad(90));

        EXPECT_EQ(0, rot.getX());
        EXPECT_EQ(1, rot.getY());
    }

    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = rotate(vec, unit::deg2rad(-90));

        EXPECT_EQ(0, rot.getX());
        EXPECT_EQ(-1, rot.getY());
    }

    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = rotate(vec, unit::deg2rad(180));

        EXPECT_EQ(-1, rot.getX());
        EXPECT_EQ(0, rot.getY());
    }

    {
        constexpr Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        /*constexpr*/ auto rot = rotate(vec, unit::deg2rad(180));

        EXPECT_EQ(-1, rot.getX());
        EXPECT_EQ(0, rot.getY());
    }

    {
        Vector2<float> vec1(0.94333f, 0.73733f);
        Vector2<float> vec2(0.16110f, 0.61872f);

        EXPECT_FLOAT_EQ(0.94333f, vec1.getX());
        EXPECT_FLOAT_EQ(0.73733f, vec1.getY());

        EXPECT_FLOAT_EQ(0.16110f, vec2.getX());
        EXPECT_FLOAT_EQ(0.61872f, vec2.getY());

        auto res = dot(vec1, vec2);

        EXPECT_FLOAT_EQ(
            0.94333f * 0.16110f +
            0.73733f * 0.61872f,
            res
        );
    }

    {
        constexpr Vector2<float> vec1(0.94333f, 0.73733f);
        constexpr Vector2<float> vec2(0.16110f, 0.61872f);

        EXPECT_FLOAT_EQ(0.94333f, vec1.getX());
        EXPECT_FLOAT_EQ(0.73733f, vec1.getY());

        EXPECT_FLOAT_EQ(0.16110f, vec2.getX());
        EXPECT_FLOAT_EQ(0.61872f, vec2.getY());

        /*constexpr*/ auto res = dot(vec1, vec2);

        EXPECT_FLOAT_EQ(
            0.94333f * 0.16110f +
            0.73733f * 0.61872f,
            res
        );
    }


    {
        const Vector2<float> vec;

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(0.0f, distanceSquared(vec, vec));
    }

    {
        const Vector2<float> vec1{1.0f, 2.0f};
        const Vector2<float> vec2{5.0f, 4.0f};

        EXPECT_FLOAT_EQ(20.0f, distanceSquared(vec1, vec2));
    }

    {
        const Vector2<float> vec1{1.0f, 2.0f};
        const Vector2<float> vec2{5.0f, 4.0f};

        EXPECT_FLOAT_EQ(4.4721360f, distance(vec1, vec2));
    }
}

/* ************************************************************************ */

TEST(Vector2, freeOperators)
{
    {
        const Vector2<float> vec1(5.3f, 8.9f);
        const Vector2<float> vec2(3.3f, 1.2f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());

        const auto vec3 = vec1 + vec2;
        const auto vec4 = vec2 + vec1;

        EXPECT_FLOAT_EQ(5.3f + 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f + 1.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.3f + 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f + 8.9f, vec4.getY());
    }

    {
        const Vector2<float> vec1(5.3f, 8.9f);
        const Vector2<float> vec2(3.3f, 1.2f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());

        const auto vec3 = vec1 - vec2;
        const auto vec4 = vec2 - vec1;

        EXPECT_FLOAT_EQ(5.3f - 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f - 1.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.3f - 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f - 8.9f, vec4.getY());
    }

    {
        const Vector2<float> vec1(5.3f, 8.9f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        const auto vec3 = vec1 * 3.2f;
        const auto vec4 = 3.2f * vec1;

        EXPECT_FLOAT_EQ(5.3f * 3.2f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f * 3.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.2f * 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.2f * 8.9f, vec4.getY());
    }

    {
        const Vector2<float> vec1(5.3f, 8.9f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        const auto vec3 = vec1 / 3.2f;
        const auto vec4 = 3.2f / vec1;

        EXPECT_FLOAT_EQ(5.3f / 3.2f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f / 3.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.2f / 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.2f / 8.9f, vec4.getY());
    }

    {
        const Vector2<float> vec1(5.3f, 8.9f);
        const Vector2<float> vec2(5.3f, 8.9f);
        const Vector2<float> vec3(1.3f, 8.9f);
        const Vector2<float> vec4(5.3f, 0.9f);

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
