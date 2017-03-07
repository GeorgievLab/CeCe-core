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
#include <type_traits>

// CeCe
#include "cece/common.hpp"
#include "cece/Assert.hpp"
#include "cece/math/Zero.hpp"
#include "cece/unit/math.hpp"
#include "cece/unit/Units.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      Two dimensional vector.
 *
 * @tparam     T     Element type.
 */
template<typename T>
class BasicVector2
{


// Public Types
public:


    /// BasicVector2 value type.
    using ValueType = T;

    /// Element type squared.
    using ValueTypeSq = decltype(std::declval<T>() * std::declval<T>());


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    BasicVector2() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     */
    BasicVector2(T x, T y) noexcept;


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    BasicVector2(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector2(const BasicVector2& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector2(BasicVector2&& src) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    BasicVector2(const BasicVector2<T2>& rhs) noexcept;


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    BasicVector2& operator=(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector2& operator=(const BasicVector2& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector2& operator=(BasicVector2&& src) noexcept;


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
    BasicVector2& operator=(const BasicVector2<T2>& src) noexcept;


    /**
     * @brief      Unary plus operator.
     *
     * @return     Vector.
     */
    BasicVector2 operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     Vector.
     */
    BasicVector2 operator-() const noexcept;


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
    BasicVector2& operator+=(const BasicVector2<T1>& rhs) noexcept;


    /**
     * @brief      Subtraction operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector2 operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() - std::declval<T1>()),
        T
    >::value>::type* = nullptr>
    BasicVector2& operator-=(const BasicVector2<T1>& rhs) noexcept;


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
    BasicVector2& operator*=(T1 rhs) noexcept;


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector2 operand.
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
    BasicVector2& operator*=(const BasicVector2<T1>& rhs) noexcept;


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
    BasicVector2& operator/=(T1 rhs) noexcept;


    /**
     * @brief      Division operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in BasicVector2 operand.
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
    BasicVector2& operator/=(const BasicVector2<T1>& rhs) noexcept;


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
     * @brief      Returns X coordinate.
     *
     * @return     Reference to X coordinate.
     */
    T& x() noexcept;


    /**
     * @brief      Returns X coordinate.
     *
     * @return     The X coordinate.
     */
    const T& getX() const noexcept;


    /**
     * @brief      Set X coordinate.
     *
     * @param      x     The X coordinate.
     */
    void setX(T x) noexcept;


    /**
     * @brief      Returns Y coordinate.
     *
     * @return     Referent co Y coordinate.
     */
    T& y() noexcept;


    /**
     * @brief      Returns Y coordinate.
     *
     * @return     The Y coordinate.
     */
    const T& getY() const noexcept;


    /**
     * @brief      Set Y coordinate.
     *
     * @param      y     The Y coordinate.
     */
    void setY(T y) noexcept;


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
    bool inRange(const BasicVector2& low, const BasicVector2& high) const noexcept;


    /**
     * @brief      Check if current vector is in given range where the low range
     *             is Zero vector.
     *
     * @param      high  Maximum coordinates (<).
     *
     * @return     If current value is in given range.
     */
    bool inRange(const BasicVector2& high) const noexcept;


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
    ValueTypeSq dot(const BasicVector2& rhs) const noexcept;


    /**
     * @brief      Calculate vectors squared distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueTypeSq distanceSquared(const BasicVector2& rhs) const noexcept;


    /**
     * @brief      Calculate vectors distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueType distance(const BasicVector2& rhs) const noexcept;


    /**
     * @brief      Inverse current vector (1 / *this).
     *
     * @tparam     T2    Type of result vector's element.
     *
     * @return     Inversed vector.
     */
    template<typename T2 = T>
    BasicVector2<T2> inversed() const noexcept;


    /**
     * @brief      Rotate current vector and return rotated version.
     *
     * @param      angle  Rotation angle.
     *
     * @return     Rotated vector.
     */
    BasicVector2 rotated(unit::Angle angle) const noexcept;


    /**
     * @brief      Create from single value.
     *
     * @param      val   The value
     *
     * @return     Vector of {val, val}.
     */
    static BasicVector2 createSingle(T val) noexcept;


// Private Data Members
private:

    /// X coordinate.
    T m_x;

    /// Y coordinate.
    T m_y;

};

/* ************************************************************************ */

extern template class BasicVector2<float>;
extern template class BasicVector2<double>;
extern template class BasicVector2<unsigned int>;
extern template class BasicVector2<int>;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const BasicVector2<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(T1 lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const BasicVector2<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(T1 lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const BasicVector2<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(T1 lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first BasicVector2.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const BasicVector2<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second BasicVector2.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(T1 lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    The first type.
 * @tparam     T2    The second type.
 *
 * @return     Comparision result.
 */
template<typename T1, typename T2>
inline bool operator==(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Calculate cross product of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    The first type.
 * @tparam     T2    The second type.
 *
 * @return     Cross product.
 */
template<typename T1, typename T2>
inline
decltype(std::declval<T1>() * std::declval<T2>())
cross(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Calculate cross product of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    The first type.
 * @tparam     T2    The second type.
 *
 * @return     Cross product.
 */
template<typename T1, typename T2>
inline
BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const BasicVector2<T1>& lhs, const T2& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Calculate cross product of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    The first type.
 * @tparam     T2    The second type.
 *
 * @return     Cross product.
 */
template<typename T1, typename T2>
inline
BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const T1& lhs, const BasicVector2<T2>& rhs) noexcept;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>::BasicVector2() noexcept
    : m_x{}
    , m_y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>::BasicVector2(T x, T y) noexcept
    : m_x(x)
    , m_y(y)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>::BasicVector2(Zero_t zero) noexcept
    : m_x{}
    , m_y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>::BasicVector2(const BasicVector2& src) noexcept
    : m_x{src.getX()}
    , m_y{src.getY()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>::BasicVector2(BasicVector2&& src) noexcept
    : m_x{std::move(src.m_x)}
    , m_y{std::move(src.m_y)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector2<T>::BasicVector2(const BasicVector2<T2>& rhs) noexcept
    : m_x(rhs.getX())
    , m_y(rhs.getY())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>& BasicVector2<T>::operator=(Zero_t zero) noexcept
{
    m_x = T{};
    m_y = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>& BasicVector2<T>::operator=(const BasicVector2& src) noexcept
{
    m_x = src.m_x;
    m_y = src.m_y;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T>& BasicVector2<T>::operator=(BasicVector2&& src) noexcept
{
    m_x = std::move(src.m_x);
    m_y = std::move(src.m_y);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator=(const BasicVector2<T2>& src) noexcept
{
    m_x = T(src.getX());
    m_y = T(src.getY());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T> BasicVector2<T>::operator+() const noexcept
{
    return *this;
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T> BasicVector2<T>::operator-() const noexcept
{
    return {-m_x, -m_y};
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() + std::declval<T1>()),
    T
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator+=(const BasicVector2<T1>& rhs) noexcept
{
    m_x += rhs.getX();
    m_y += rhs.getY();

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() - std::declval<T1>()),
    T
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator-=(const BasicVector2<T1>& rhs) noexcept
{
    m_x -= rhs.getX();
    m_y -= rhs.getY();

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() * std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator*=(T1 rhs) noexcept
{
    m_x *= rhs;
    m_y *= rhs;

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() * std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator*=(const BasicVector2<T1>& rhs) noexcept
{
    m_x *= rhs.getX();
    m_y *= rhs.getY();

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() / std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator/=(T1 rhs) noexcept
{
    m_x /= rhs;
    m_y /= rhs;

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() / std::declval<T1>()),
    T
>::value || std::is_constructible<
    T,
    decltype(std::declval<T>() * std::declval<T1>())
>::value>::type*>
inline BasicVector2<T>& BasicVector2<T>::operator/=(const BasicVector2<T1>& rhs) noexcept
{
    m_x /= rhs.getX();
    m_y /= rhs.getY();

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline T& BasicVector2<T>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 2);
    return (&m_x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline const T& BasicVector2<T>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 2);
    return (&m_x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline T& BasicVector2<T>::x() noexcept
{
    return m_x;
}

/* ************************************************************************ */

template<typename T>
inline const T& BasicVector2<T>::getX() const noexcept
{
    return m_x;
}

/* ************************************************************************ */

template<typename T>
inline void BasicVector2<T>::setX(T x) noexcept
{
    m_x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline T& BasicVector2<T>::y() noexcept
{
    return m_y;
}

/* ************************************************************************ */

template<typename T>
inline const T& BasicVector2<T>::getY() const noexcept
{
    return m_y;
}

/* ************************************************************************ */

template<typename T>
inline void BasicVector2<T>::setY(T y) noexcept
{
    m_y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline bool BasicVector2<T>::inRange(T value, T low, T high) noexcept
{
    return value >= low && value < high;
}

/* ************************************************************************ */

template<typename T>
inline bool BasicVector2<T>::inRange(const BasicVector2& low, const BasicVector2& high) const noexcept
{
    bool res = true;

    res = res && inRange(getX(), low.getX(), high.getX());
    res = res && inRange(getY(), low.getY(), high.getY());

    return res;
}

/* ************************************************************************ */

template<typename T>
inline bool BasicVector2<T>::inRange(const BasicVector2& high) const noexcept
{
    return inRange(Zero, high);
}

/* ************************************************************************ */

template<typename T>
inline typename BasicVector2<T>::ValueType BasicVector2<T>::getLength() const noexcept
{
    using std::sqrt;
    return static_cast<T>(sqrt(getLengthSquared()));
}

/* ************************************************************************ */

template<typename T>
inline typename BasicVector2<T>::ValueTypeSq BasicVector2<T>::getLengthSquared() const noexcept
{
    return dot(*this);
}

/* ************************************************************************ */

template<typename T>
inline typename BasicVector2<T>::ValueTypeSq BasicVector2<T>::dot(const BasicVector2& rhs) const noexcept
{
    return getX() * rhs.getX() + getY() * rhs.getY();
}

/* ************************************************************************ */

template<typename T>
inline typename BasicVector2<T>::ValueTypeSq BasicVector2<T>::distanceSquared(const BasicVector2& rhs) const noexcept
{
    return (*this - rhs).getLengthSquared();
}

/* ************************************************************************ */

template<typename T>
inline typename BasicVector2<T>::ValueType BasicVector2<T>::distance(const BasicVector2& rhs) const noexcept
{
    return (*this - rhs).getLength();
}

/* ************************************************************************ */

template<typename T>
template<typename T2>
inline BasicVector2<T2> BasicVector2<T>::inversed() const noexcept
{
    return {T2(1) / getX(), T2(1) / getY()};
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T> BasicVector2<T>::rotated(unit::Angle angle) const noexcept
{
    return {
        static_cast<T>(getX() * cos(static_cast<RealType>(angle)) - getY() * sin(static_cast<RealType>(angle))),
        static_cast<T>(getX() * sin(static_cast<RealType>(angle)) + getY() * cos(static_cast<RealType>(angle)))
    };
}

/* ************************************************************************ */

template<typename T>
inline BasicVector2<T> BasicVector2<T>::createSingle(T val) noexcept
{
    return {val, val};
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs.getX() + rhs.getX(),
        lhs.getY() + rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const BasicVector2<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() + rhs,
        lhs.getY() + rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(T1 lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs + rhs.getX(),
        lhs + rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs.getX() - rhs.getX(),
        lhs.getY() - rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const BasicVector2<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() - rhs,
        lhs.getY() - rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(T1 lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs - rhs.getX(),
        lhs - rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs.getX() * rhs.getX(),
        lhs.getY() * rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const BasicVector2<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() * rhs,
        lhs.getY() * rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(T1 lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs * rhs.getX(),
        lhs * rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs.getX() / rhs.getX(),
        lhs.getY() / rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const BasicVector2<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() / rhs,
        lhs.getY() / rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline BasicVector2<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(T1 lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {
        lhs / rhs.getX(),
        lhs / rhs.getY()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline bool operator==(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return
        lhs.getX() == rhs.getX() &&
        lhs.getY() == rhs.getY()
    ;
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline
decltype(std::declval<T1>() * std::declval<T2>())
cross(const BasicVector2<T1>& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX()};
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline
BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const BasicVector2<T1>& lhs, const T2& rhs) noexcept
{
    return {rhs * lhs.getY(), -rhs * lhs.getX()};
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline
BasicVector2<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const T1& lhs, const BasicVector2<T2>& rhs) noexcept
{
    return {-lhs * rhs.getY(), lhs * rhs.getX()};
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
