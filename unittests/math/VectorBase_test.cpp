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
#include "cece/math/VectorBase.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::math;

/* ************************************************************************ */

template<typename T>
struct Vec2 : public VectorBase<Vec2, T>
{
    Vec2() : x{}, y{} {}
    Vec2(T x, T y) : x{x}, y{y} {}

    T& operator[](int pos) { return (&x)[pos]; }
    const T& operator[](int pos) const { return (&x)[pos]; }

    int getSize() const noexcept { return 2; }
    T getX() const noexcept { return x; }
    void setX(T x) { this->x = x; }
    T getY() const noexcept { return y; }
    void setY(T y) { this->y = y; }

    T x;
    T y;
};

/* ************************************************************************ */

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T>& vec)
{
    return os << "(x = " << vec.x << ", y = " << vec.y << ")";
}

/* ************************************************************************ */

TEST(VectorBase, operators)
{
    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vec2<float> vec2 = +vec1;

        EXPECT_FLOAT_EQ(1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(2.0f, vec2[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vec2<float> vec2 = -vec1;

        EXPECT_FLOAT_EQ(-1.0f, vec2[0]);
        EXPECT_FLOAT_EQ(-2.0f, vec2[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vec2<float> vec2{1.0f, 2.0f};
        vec1 += vec2;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        Vec2<float> vec2{1.0f, 2.0f};
        vec1 -= vec2;

        EXPECT_FLOAT_EQ(0.0f, vec1[0]);
        EXPECT_FLOAT_EQ(0.0f, vec1[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        vec1 *= 2.0;

        EXPECT_FLOAT_EQ(2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(4.0f, vec1[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};
        Vec2<float> vec2{5.0f, 3.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        EXPECT_FLOAT_EQ(5.0f, vec2[0]);
        EXPECT_FLOAT_EQ(3.0f, vec2[1]);

        vec1 *= vec2;

        EXPECT_FLOAT_EQ(1.0f * 5.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f * 3.0f, vec1[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        vec1 /= 2.0;

        EXPECT_FLOAT_EQ(0.5f, vec1[0]);
        EXPECT_FLOAT_EQ(1.0f, vec1[1]);
    }

    {
        Vec2<float> vec1{1.0f, 2.0f};
        Vec2<float> vec2{2.0f, 6.0f};

        EXPECT_FLOAT_EQ(1.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f, vec1[1]);

        EXPECT_FLOAT_EQ(2.0f, vec2[0]);
        EXPECT_FLOAT_EQ(6.0f, vec2[1]);

        vec1 /= vec2;

        EXPECT_FLOAT_EQ(1.0f / 2.0f, vec1[0]);
        EXPECT_FLOAT_EQ(2.0f / 6.0f, vec1[1]);
    }
}

/* ************************************************************************ */

TEST(VectorBase, memberFunctions)
{
    {
        const Vec2<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLength());
    }

    {
        const Vec2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(2.2360680f, vec.getLength());
    }

    {
        const Vec2<float> vec;

        EXPECT_FLOAT_EQ(0, vec.getLengthSquared());
    }

    {
        const Vec2<float> vec{1.0f, 2.0f};

        EXPECT_FLOAT_EQ(5, vec.getLengthSquared());
    }
}

/* ************************************************************************ */

TEST(VectorBase, mutators)
{
    {
        Vec2<int> vec;

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
        Vec2<int> vec;

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

TEST(VectorBase, functions)
{
    {
        Vec2<float> vec1(0.94333f, 0.73733f);
        Vec2<float> vec2(0.16110f, 0.61872f);

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
}

/* ************************************************************************ */

TEST(VectorBase, freeOperators)
{
    {
        const Vec2<float> vec1(5.3f, 8.9f);
        const Vec2<float> vec2(3.3f, 1.2f);

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
        const Vec2<float> vec1(5.3f, 8.9f);
        const Vec2<float> vec2(3.3f, 1.2f);

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
        const Vec2<float> vec1(5.3f, 8.9f);

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
        const Vec2<float> vec1(5.3f, 8.9f);
        const Vec2<float> vec2(1.8f, 3.5f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(1.8f, vec2.getX());
        EXPECT_FLOAT_EQ(3.5f, vec2.getY());

        const auto vec3 = vec1 * vec2;
        const auto vec4 = vec2 * vec1;

        EXPECT_FLOAT_EQ(5.3f * 1.8f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f * 3.5f, vec3.getY());

        EXPECT_FLOAT_EQ(1.8f * 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.5f * 8.9f, vec4.getY());
    }

    {
        const Vec2<float> vec1(5.3f, 8.9f);

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
        const Vec2<float> vec1(5.3f, 8.9f);
        const Vec2<float> vec2(1.8f, 3.5f);

        EXPECT_FLOAT_EQ(5.3f, vec1.getX());
        EXPECT_FLOAT_EQ(8.9f, vec1.getY());

        EXPECT_FLOAT_EQ(1.8f, vec2.getX());
        EXPECT_FLOAT_EQ(3.5f, vec2.getY());

        const auto vec3 = vec1 / vec2;
        const auto vec4 = vec2 / vec1;

        EXPECT_FLOAT_EQ(5.3f / 1.8f, vec3.getX());
        EXPECT_FLOAT_EQ(8.9f / 3.5f, vec3.getY());

        EXPECT_FLOAT_EQ(1.8f / 5.3f, vec4.getX());
        EXPECT_FLOAT_EQ(3.5f / 8.9f, vec4.getY());
    }

    {
        const Vec2<float> vec1(5.3f, 8.9f);
        const Vec2<float> vec2(5.3f, 8.9f);
        const Vec2<float> vec3(1.3f, 8.9f);
        const Vec2<float> vec4(5.3f, 0.9f);
        const Vec2<float> vec5(1.3f, 0.9f);

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

        EXPECT_FALSE(vec1 < vec2);

        EXPECT_GE(vec1, vec1);
        EXPECT_GE(vec1, vec2);
        EXPECT_GE(vec1, vec3);
        EXPECT_GE(vec1, vec4);

        EXPECT_GT(vec1, vec5);

        EXPECT_LE(vec1, vec1);
        EXPECT_LE(vec1, vec2);
        EXPECT_LE(vec3, vec1);
        EXPECT_LE(vec4, vec1);

        EXPECT_LT(vec5, vec1);
    }

}

/* ************************************************************************ */
