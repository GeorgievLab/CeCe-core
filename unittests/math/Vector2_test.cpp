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
#include "cece/math/Vector2.hpp"

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
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        Vector2<int> vec(Zero);

        EXPECT_EQ(0, vec.getX());
        EXPECT_EQ(0, vec.getY());
        EXPECT_EQ(0, vec[0]);
        EXPECT_EQ(0, vec[1]);
    }

    {
        Vector2<float> vec = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec.getX());
        EXPECT_FLOAT_EQ(3.0f, vec.getY());
        EXPECT_FLOAT_EQ(1.2f, vec[0]);
        EXPECT_FLOAT_EQ(3.0f, vec[1]);
    }

    {
        const Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        Vector2<float> vec1 = {1.2f, 3.0f};

        EXPECT_FLOAT_EQ(1.2f, vec1.getX());
        EXPECT_FLOAT_EQ(3.0f, vec1.getY());
        EXPECT_FLOAT_EQ(1.2f, vec1[0]);
        EXPECT_FLOAT_EQ(3.0f, vec1[1]);

        Vector2<float> vec2(std::move(vec1));

        EXPECT_FLOAT_EQ(1.2f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
        EXPECT_FLOAT_EQ(1.2f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);
    }

    {
        const Vector2<int> vec1 = {1, 3};

        EXPECT_EQ(1, vec1.getX());
        EXPECT_EQ(3, vec1.getY());
        EXPECT_EQ(1, vec1[0]);
        EXPECT_EQ(3, vec1[1]);

        Vector2<float> vec2(vec1);

        EXPECT_FLOAT_EQ(1.0f, vec2.getX());
        EXPECT_FLOAT_EQ(3.0f, vec2.getY());
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

        Vector2<float> vec2{1.0f, 2.0f};
        vec1 *= vec2;

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
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

    {
        Vector2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vector2<float> vec2{1.0f, 2.0f};
        vec1 /= vec2;

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
    }
}

/* ************************************************************************ */

TEST(Vector2, inRange)
{
    {
        const Vector2<float> vecMin{-10.0f, -5.0f};
        const Vector2<float> vecMax{10.0f, 20.0f};

        Vector2<float> vec1;
        Vector2<float> vec2{-15.0f, 0.0f};
        Vector2<float> vec3{5.0f, 0.0f};

        EXPECT_TRUE(vec1.inRange(vecMin, vecMax));
        EXPECT_FALSE(vec2.inRange(vecMin, vecMax));
        EXPECT_TRUE(vec3.inRange(vecMin, vecMax));
    }

    {
        const Vector2<float> vecMax{10.0f, 20.0f};

        Vector2<float> vec1;
        Vector2<float> vec2{-15.0f, 0.0f};
        Vector2<float> vec3{5.0f, 0.0f};

        EXPECT_TRUE(vec1.inRange(vecMax));
        EXPECT_FALSE(vec2.inRange(vecMax));
        EXPECT_TRUE(vec3.inRange(vecMax));
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

    {
        const Vector2<float> vec;

        EXPECT_FLOAT_EQ(vec.getLengthSquared(), vec.dot(vec));
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(vec.getLengthSquared(), vec.dot(vec));
    }

    {
        const Vector2<float> vec1;
        const Vector2<float> vec2;

        EXPECT_FLOAT_EQ(0, vec1.dot(vec2));
    }

    {
        const Vector2<float> vec1{1.0f, 2.0f};
        const Vector2<float> vec2{5.0f, 4.0f};

        EXPECT_FLOAT_EQ(13, vec1.dot(vec2));
    }

    {
        const Vector2<float> vec;

        EXPECT_FLOAT_EQ(0.0f, vec.distanceSquared(vec));
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(0.0f, vec.distanceSquared(vec));
    }

    {
        const Vector2<float> vec1{1.0f, 2.0f};
        const Vector2<float> vec2{5.0f, 4.0f};

        EXPECT_FLOAT_EQ(20.0f, vec1.distanceSquared(vec2));
    }

    {
        const Vector2<float> vec1{1.0f, 2.0f};
        const Vector2<float> vec2{5.0f, 4.0f};

        EXPECT_FLOAT_EQ(4.4721360f, vec1.distance(vec2));
    }

    {
        const Vector2<float> vec{1.0f, 2.0f};

        auto inv = vec.inversed();

        EXPECT_FLOAT_EQ(1.0f, inv[0]);
        EXPECT_FLOAT_EQ(0.5f, inv[1]);
    }

    {
        auto vec = Vector2<float>::createSingle(1);

        EXPECT_FLOAT_EQ(1.0f, vec[0]);
        EXPECT_FLOAT_EQ(1.0f, vec[1]);
    }

    {
        auto vec = Vector2<float>::createSingle(375.1721f);

        EXPECT_FLOAT_EQ(375.1721f, vec[0]);
        EXPECT_FLOAT_EQ(375.1721f, vec[1]);
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
}

/* ************************************************************************ */

TEST(Vector2, functions)
{
    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = vec.rotated(unit::deg2rad(90));

        EXPECT_EQ(0, rot.getX());
        EXPECT_EQ(1, rot.getY());
    }

    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = vec.rotated(unit::deg2rad(-90));

        EXPECT_EQ(0, rot.getX());
        EXPECT_EQ(-1, rot.getY());
    }

    {
        Vector2<int> vec(1, 0);

        EXPECT_EQ(1, vec.getX());
        EXPECT_EQ(0, vec.getY());

        auto rot = vec.rotated(unit::deg2rad(180));

        EXPECT_EQ(-1, rot.getX());
        EXPECT_EQ(0, rot.getY());
    }


    // TODO: cross, dot
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
        const Vector2<float> vec2(3.3f, 1.2f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());

        const auto vec3 = vec1 * vec2;
        const auto vec4 = vec2 * vec1;

        EXPECT_FLOAT_EQ(5.3f * 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f * 1.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.3f * 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f * 8.9f, vec4.getY());
    }

    {
        const Vector2<float> vec1(5.3f, 8.9f);
        const Vector2<float> vec2(3.3f, 1.2f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(3.3f, vec2.getX());
        EXPECT_FLOAT_EQ(1.2f, vec2.getY());

        const auto vec3 = vec1 / vec2;
        const auto vec4 = vec2 / vec1;

        EXPECT_FLOAT_EQ(5.3f / 3.3f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f / 1.2f, vec3.getY());

        EXPECT_FLOAT_EQ(3.3f / 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(1.2f / 8.9f, vec4.getY());
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
