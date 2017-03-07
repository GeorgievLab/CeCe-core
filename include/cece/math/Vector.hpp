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

#pragma once

/* ************************************************************************ */

// C++
#include <cmath>
#include <initializer_list>
#include <type_traits>

// CeCe
#include "cece/common.hpp"
#include "cece/Assert.hpp"
#include "cece/StaticArray.hpp"
#include "cece/math/Zero.hpp"
#include "cece/io/InStream.hpp"
#include "cece/io/OutStream.hpp"
#include "cece/unit/math.hpp"
#include "cece/unit/Units.hpp"
#include "cece/math/Vector2.hpp"
#include "cece/math/Vector3.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      N dimensional vector.
 *
 * @tparam     T     Element type.
 * @tparam     N     Number of elements.
 */
template<typename T, int N>
class BasicVector
{
    static_assert(N > 0, "Cannot create empty vector");


// Public Types
public:


    /// BasicVector value type.
    using ValueType = T;

    /// Element type squared.
    using ValueTypeSq = decltype(std::declval<T>() * std::declval<T>());


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    BasicVector() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    BasicVector(std::initializer_list<T> data) noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit BasicVector(T (&data)[N]) noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit BasicVector(StaticArray<T, N> data) noexcept;


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    BasicVector(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector(const BasicVector& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector(BasicVector&& src) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param      v     The source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    explicit BasicVector(const BasicVector<T2, N>& src) noexcept;


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    BasicVector& operator=(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(std::initializer_list<T> data) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(T (&data)[N]) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(StaticArray<T, N> data) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector& operator=(const BasicVector& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector& operator=(BasicVector&& src) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param      v     The source vector.
     *
     * @tparam     T2    The source vector element type.
     *
     * @return     *this.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    BasicVector& operator=(const BasicVector<T2, N>& src) noexcept;


    /**
     * @brief      Unary plus operator.
     *
     * @return     Vector.
     */
    BasicVector operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     Vector.
     */
    BasicVector operator-() const noexcept;


    /**
     * @brief      Addition operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of right operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() + std::declval<T1>()),
        T
    >::value>::type* = nullptr>
    BasicVector& operator+=(const BasicVector<T1, N>& rhs) noexcept;


    /**
     * @brief      Subtraction operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() - std::declval<T1>()),
        T
    >::value>::type* = nullptr>
    BasicVector& operator-=(const BasicVector<T1, N>& rhs) noexcept;


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of right operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() * std::declval<T1>()),
        T
    >::value || std::is_constructible<
        T,
        decltype(std::declval<T>() * std::declval<T1>())
    >::value>::type* = nullptr>
    BasicVector& operator*=(T1 rhs) noexcept;


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() * std::declval<T1>()),
        T
    >::value || std::is_constructible<
        T,
        decltype(std::declval<T>() * std::declval<T1>())
    >::value>::type* = nullptr>
    BasicVector& operator*=(const BasicVector<T1, N>& rhs) noexcept;


    /**
     * @brief      Division operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of right operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() / std::declval<T1>()),
        T
    >::value || std::is_constructible<
        T,
        decltype(std::declval<T>() * std::declval<T1>())
    >::value>::type* = nullptr>
    BasicVector& operator/=(T1 rhs) noexcept;


    /**
     * @brief      Division operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() / std::declval<T1>()),
        T
    >::value || std::is_constructible<
        T,
        decltype(std::declval<T>() * std::declval<T1>())
    >::value>::type* = nullptr>
    BasicVector& operator/=(const BasicVector<T1, N>& rhs) noexcept;


    /**
     * @brief      Access operator.
     *
     * @param      pos   The position.
     *
     * @return     Reference to the element.
     */
    T& operator[](int pos) noexcept;


    /**
     * @brief      Access operator.
     *
     * @param      pos   The position.
     *
     * @return     Reference to the element.
     */
    const T& operator[](int pos) const noexcept;


// Public Accessors
public:


    /**
     * @brief      Returns vector size.
     *
     * @return     The size.
     */
    int getSize() const noexcept;


    /**
     * @brief      Check if given value is in given range.
     *
     * @param      value  Given value.
     * @param      low    Minimum value (>=).
     * @param      high   Maximum value (<).
     *
     * @return     If given value is in given range.
     */
    static bool inRange(T value, T low, T high) noexcept;


    /**
     * @brief      Check if current vector is in given range.
     *
     * @param      low   Minimum coordinates (>=).
     * @param      high  Maximum coordinates (<).
     *
     * @return     If current value is in given range.
     */
    bool inRange(const BasicVector& low, const BasicVector& high) const noexcept;


    /**
     * @brief      Check if current vector is in given range where the low range
     *             is Zero vector.
     *
     * @param      high  Maximum coordinates (<).
     *
     * @return     If current value is in given range.
     */
    bool inRange(const BasicVector& high) const noexcept;


// Public Operations
public:


    /**
     * @brief      Calculate vector length.
     *
     * @return     The length.
     */
    ValueType getLength() const noexcept;


    /**
     * @brief      Calculate vector length - squared.
     *
     * @return     The length squared.
     */
    ValueTypeSq getLengthSquared() const noexcept;


    /**
     * @brief      Calculate dot of two vectors.
     *
     * @param      rhs   Second vector.
     *
     * @return     Dot product.
     */
    ValueTypeSq dot(const BasicVector& rhs) const noexcept;


    /**
     * @brief      Calculate vectors squared distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueTypeSq distanceSquared(const BasicVector& rhs) const noexcept;


    /**
     * @brief      Calculate vectors distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueType distance(const BasicVector& rhs) const noexcept;


    /**
     * @brief      Inverse current vector (1 / *this).
     *
     * @tparam     T2    Type of result vector's element.
     *
     * @return     Inversed vector.
     */
    template<typename T2 = T>
    BasicVector<T2, N> inversed() const noexcept;


// Public Operations
public:


    /**
     * @brief      Create from single value.
     *
     * @param      val   The value.
     *
     * @return     Vector of vals.
     */
    static BasicVector createSingle(T val) noexcept;


// Private Data Members
private:

    /// BasicVector data.
    StaticArray<T, N> m_data;

};

/* ************************************************************************ */

// TODO: rework
template<typename T>
struct BasicVector<T, 2> : public BasicVector2<T>
{
    using BasicVector2<T>::BasicVector2;

    BasicVector() {};
    BasicVector(const BasicVector2<T>& src)
        : BasicVector2<T>(src)
    {
        //
    }

    const T& getWidth() const noexcept { return BasicVector2<T>::getX(); }
    const T& getHeight() const noexcept { return BasicVector2<T>::getY(); }
};

/* ************************************************************************ */

// TODO: rework
template<typename T>
struct BasicVector<T, 3> : public BasicVector3<T>
{
    using BasicVector3<T>::BasicVector3;

    BasicVector() {};
    BasicVector(const BasicVector3<T>& src)
        : BasicVector3<T>(src)
    {
        //
    }

    const T& getWidth() const noexcept { return BasicVector3<T>::getX(); }
    const T& getHeight() const noexcept { return BasicVector3<T>::getY(); }
    const T& getDepth() const noexcept { return BasicVector3<T>::getZ(); }
};

/* ************************************************************************ */

/**
 * @brief Basic vector.
 */
template<typename T>
using Vector = BasicVector<T, DIMENSION>;

/* ************************************************************************ */

/**
 * @brief Vector for integer size.
 */
using Size = Vector<unsigned int>;

/* ************************************************************************ */

/**
 * @brief Vector for coordinates.
 */
using Coordinate = Vector<unsigned int>;

/* ************************************************************************ */

/**
 * @brief Vector of int.
 */
using VectorInt = Vector<int>;

/* ************************************************************************ */

/**
 * @brief Vector of float.
 */
using VectorFloat = Vector<float>;

/* ************************************************************************ */

/**
 * @brief Vector of float.
 */
using VectorDouble = Vector<float>;

/* ************************************************************************ */

/**
 * @brief Vector of float.
 */
using VectorLongDouble = Vector<float>;

/* ************************************************************************ */

/**
 * @brief Vector of float.
 */
using VectorReal = Vector<RealType>;

/* ************************************************************************ */

/**
 * @brief Addition operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of value in second BasicVector.
 * @tparam N  BasicVector size.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} + T2{}), N> operator+(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} + T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Addition operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 * @tparam N  BasicVector size.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} + T2{}), N> operator+(const BasicVector<T1, N>& lhs, T2 rhs) noexcept
{
    BasicVector<decltype(T1{} + T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] + rhs;

    return res;
}

/* ************************************************************************ */

/**
 * @brief Addition operator.
 *
 * @tparam T1 Type of first operand.
 * @tparam T2 Type of value in second BasicVector.
 * @tparam N  BasicVector size.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} + T2{}), N> operator+(T1 lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} + T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs + rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Substract operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} - T2{}), N> operator-(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} - T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] - rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Substract operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} - T2{}), N> operator-(const BasicVector<T1, N>& lhs, T2 rhs) noexcept
{
    BasicVector<decltype(T1{} - T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] - rhs;

    return res;
}

/* ************************************************************************ */

/**
 * @brief Substract operator.
 *
 * @tparam T1 Type of first operand.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} - T2{}), N> operator-(T1 lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} - T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs - rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Multiplication operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} * T2{}), N> operator*(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} * T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Multiplication operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} * T2{}), N> operator*(const BasicVector<T1, N>& lhs, T2 rhs) noexcept
{
    BasicVector<decltype(T1{} * T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] * rhs;

    return res;
}

/* ************************************************************************ */

/**
 * @brief Multiplication operator.
 *
 * @tparam T1 Type of first operand.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} * T2{}), N> operator*(T1 lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} * T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs * rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Division operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} / T2{}), N> operator/(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} / T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] / rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Division operator.
 *
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} / T2{}), N> operator/(const BasicVector<T1, N>& lhs, T2 rhs) noexcept
{
    BasicVector<decltype(T1{} / T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] / rhs;

    return res;
}

/* ************************************************************************ */

/**
 * @brief Division operator.
 *
 * @tparam T1 Type of first operand.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2, int N>
inline BasicVector<decltype(T1{} / T2{}), N> operator/(T1 lhs, const BasicVector<T2, N>& rhs) noexcept
{
    BasicVector<decltype(T1{} / T2{}), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs / rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator==(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    bool res = true;

    for (int i = 0; i < N; ++i)
        res = res && lhs[i] == rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator==(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    return lhs == BasicVector<T1, N>(Zero);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator==(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    return BasicVector<T1, N>(Zero) == rhs;
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator!=(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator!=(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator!=(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator<(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    bool res = true;

    for (int i = 0; i < N; ++i)
        res = res && ((lhs[i] < rhs[i]) || !(rhs[i] < lhs[i]));

    return res;
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator<(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    return lhs < BasicVector<T1, N>{Zero};
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator<(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    return BasicVector<T1, N>{Zero} < rhs;
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator<=(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator<=(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator<=(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator>(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    // Reversed operands
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator>(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    // Reversed operands
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator>(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    // Reversed operands
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, typename T2, int N>
inline bool operator>=(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator>=(const BasicVector<T1, N>& lhs, Zero_t rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Compare vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return
 */
template<typename T1, int N>
inline bool operator>=(Zero_t lhs, const BasicVector<T1, N>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief Calculate dot product of two vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Dot product.
 */
template<typename T1, typename T2, int N>
inline decltype(T1{} * T2{}) dot(const BasicVector<T1, N>& lhs, const BasicVector<T2, N>& rhs) noexcept
{
    decltype(T1{} * T2{}) res{};

    for (int i = 0; i < N; ++i)
        res += lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

/**
 * @brief Input stream operator.
 *
 * @param is     Input stream.
 * @param vector Result value.
 *
 * @return is.
 */
template<typename T, int N>
io::InStream& operator>>(io::InStream& is, BasicVector<T, N>& vector)
{
    int i = 0;

    for (; i < N; ++i)
    {
        if (!(is >> std::skipws >> vector[i]))
            break;
    }

    if (i == 0)
        return is;

    // Copy missing values
    // TODO: have this feature?
    for (int j = i; j < N; ++j)
        vector[j] = vector[i - 1];

    return is;
}

/* ************************************************************************ */

/**
 * @brief Output stream operator.
 *
 * @param os     Output stream.
 * @param vector Input value.
 *
 * @return os.
 */
template<typename T, int N>
io::OutStream& operator<<(io::OutStream& os, const BasicVector<T, N>& vector) noexcept
{
    for (int i = 0; i < N; ++i)
    {
        if (i != 0)
            os << " ";

        os << vector[i];
    }

    return os;
}

/* ************************************************************************ */

extern template class BasicVector<RealType, DIMENSION>;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector() noexcept
    : m_data{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(std::initializer_list<T> data) noexcept
{
    CECE_ASSERT(data.size() == N);

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m_data[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(T (&data)[N]) noexcept
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m_data[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(StaticArray<T, N> data) noexcept
    : m_data(data)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(Zero_t zero) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = T{};
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(const BasicVector& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = src.m_data[i];
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(BasicVector&& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = std::move(src.m_data[i]);
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector<T, N>::BasicVector(const BasicVector<T2, N>& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = T(src[i]);
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(Zero_t zero) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(std::initializer_list<T> data) noexcept
{
    CECE_ASSERT(data.size() == N);

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m_data[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(T (&data)[N]) noexcept
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m_data[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(StaticArray<T, N> data) noexcept
{
    m_data = data;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(const BasicVector& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = src.m_data[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(BasicVector&& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = std::move(src.m_data[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(const BasicVector<T2, N>& src) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] = T(src[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N> BasicVector<T, N>::operator+() const noexcept
{
    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N> BasicVector<T, N>::operator-() const noexcept
{
    BasicVector res;

    for (int i = 0; i < N; ++i)
        res[i] = -m_data[i];

    return res;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() + std::declval<T1>()),
    T
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator+=(const BasicVector<T1, N>& rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] += rhs[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() - std::declval<T1>()),
    T
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator-=(const BasicVector<T1, N>& rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] -= rhs[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() * std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator*=(T1 rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] *= rhs;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() * std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator*=(const BasicVector<T1, N>& rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] *= rhs[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() / std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator/=(T1 rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] /= rhs;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() / std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator/=(const BasicVector<T1, N>& rhs) noexcept
{
    for (int i = 0; i < N; ++i)
        m_data[i] /= rhs[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline T& BasicVector<T, N>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < N);
    return m_data[pos];
}

/* ************************************************************************ */

template<typename T, int N>
inline const T& BasicVector<T, N>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < N);
    return m_data[pos];
}

/* ************************************************************************ */

template<typename T, int N>
int BasicVector<T, N>::getSize() const noexcept
{
    return N;
}

/* ************************************************************************ */

template<typename T, int N>
inline bool BasicVector<T, N>::inRange(T value, T low, T high) noexcept
{
    return value >= low && value < high;
}

/* ************************************************************************ */

template<typename T, int N>
inline bool BasicVector<T, N>::inRange(const BasicVector& low, const BasicVector& high) const noexcept
{
    bool res = true;

    for (int i = 0; i < N; ++i)
        res = res && inRange(m_data[i], low[i], high[i]);

    return res;
}

/* ************************************************************************ */

template<typename T, int N>
inline bool BasicVector<T, N>::inRange(const BasicVector& high) const noexcept
{
    return inRange(Zero, high);
}

/* ************************************************************************ */

template<typename T, int N>
inline typename BasicVector<T, N>::ValueType BasicVector<T, N>::getLength() const noexcept
{
    using std::sqrt;
    return static_cast<T>(sqrt(getLengthSquared()));
}

/* ************************************************************************ */

template<typename T, int N>
inline typename BasicVector<T, N>::ValueTypeSq BasicVector<T, N>::getLengthSquared() const noexcept
{
    return dot(*this);
}

/* ************************************************************************ */

template<typename T, int N>
inline typename BasicVector<T, N>::ValueTypeSq BasicVector<T, N>::dot(const BasicVector& rhs) const noexcept
{
    ValueTypeSq res{};

    for (int i = 0; i < N; ++i)
        res += m_data[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

template<typename T, int N>
inline typename BasicVector<T, N>::ValueTypeSq BasicVector<T, N>::distanceSquared(const BasicVector& rhs) const noexcept
{
    return (*this - rhs).getLengthSquared();
}

/* ************************************************************************ */

template<typename T, int N>
inline typename BasicVector<T, N>::ValueType BasicVector<T, N>::distance(const BasicVector& rhs) const noexcept
{
    return (*this - rhs).getLength();
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2>
inline BasicVector<T2, N> BasicVector<T, N>::inversed() const noexcept
{
    BasicVector<T2, N> res;

    for (int i = 0; i < N; ++i)
        res[i] = T2(1) / m_data[i];

    return res;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N> BasicVector<T, N>::createSingle(T val) noexcept
{
    BasicVector res;

    for (int i = 0; i < N; ++i)
        res[i] = val;

    return res;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
