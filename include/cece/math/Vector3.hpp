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
 * @brief      Three dimensional vector.
 *
 * @tparam     T     Element type.
 */
template<typename T>
class Vector3
{


// Public Types
public:


    /// Vector3 value type.
    using ValueType = T;

    /// Element type squared.
    using ValueTypeSq = decltype(std::declval<T>() * std::declval<T>());


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    Vector3() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     * @param      y     The Z coordinate.
     */
    Vector3(T x, T y, T z) noexcept;


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    Vector3(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector3(const Vector3& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector3(Vector3&& src) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    Vector3(const Vector3<T2>& rhs) noexcept;


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector3& operator=(Zero_t zero) noexcept;


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector3& operator=(const Vector3& src) noexcept;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector3& operator=(Vector3&& src) noexcept;


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
    Vector3& operator=(const Vector3<T2>& src) noexcept;


    /**
     * @brief      Unary plus operator.
     *
     * @return     Vector.
     */
    Vector3 operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     Vector.
     */
    Vector3 operator-() const noexcept;


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
    Vector3& operator+=(const Vector3<T1>& rhs) noexcept;


    /**
     * @brief      Subtraction operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in Vector3 operand.
     *
     * @return     *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<
        decltype(std::declval<T>() - std::declval<T1>()),
        T
    >::value>::type* = nullptr>
    Vector3& operator-=(const Vector3<T1>& rhs) noexcept;


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
    Vector3& operator*=(T1 rhs) noexcept;


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in Vector3 operand.
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
    Vector3& operator*=(const Vector3<T1>& rhs) noexcept;


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
    Vector3& operator/=(T1 rhs) noexcept;


    /**
     * @brief      Division operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         Type of value in Vector3 operand.
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
    Vector3& operator/=(const Vector3<T1>& rhs) noexcept;


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
     * @brief      Returns Z coordinate.
     *
     * @return     Referent co Z coordinate.
     */
    T& z() noexcept;


    /**
     * @brief      Returns Z coordinate.
     *
     * @return     The Z coordinate.
     */
    const T& getZ() const noexcept;


    /**
     * @brief      Set Z coordinate.
     *
     * @param      z     The Z coordinate.
     */
    void setZ(T z) noexcept;


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
    bool inRange(const Vector3& low, const Vector3& high) const noexcept;


    /**
     * @brief      Check if current vector is in given range where the low range
     *             is Zero vector.
     *
     * @param      high  Maximum coordinates (<).
     *
     * @return     If current value is in given range.
     */
    bool inRange(const Vector3& high) const noexcept;


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
    ValueTypeSq dot(const Vector3& rhs) const noexcept;


    /**
     * @brief      Calculate vectors squared distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueTypeSq distanceSquared(const Vector3& rhs) const noexcept;


    /**
     * @brief      Calculate vectors distance.
     *
     * @param      rhs   Second vector.
     *
     * @return     Distance.
     */
    ValueType distance(const Vector3& rhs) const noexcept;


    /**
     * @brief      Inverse current vector (1 / *this).
     *
     * @tparam     T2    Type of result vector's element.
     *
     * @return     Inversed vector.
     */
    template<typename T2 = T>
    Vector3<T2> inversed() const noexcept;


    /**
     * @brief      Rotate current vector and return rotated version.
     *
     * @param      angle  Rotation angle.
     *
     * @return     Rotated vector.
     */
    Vector3 rotated(unit::Angle angle) const noexcept;


    /**
     * @brief      Create from single value.
     *
     * @param      val   The value
     *
     * @return     Vector of {val, val}.
     */
    static Vector3 createSingle(T val) noexcept;


// Private Data Members
private:

    /// X coordinate.
    T m_x;

    /// Y coordinate.
    T m_y;

    /// Z coordinate.
    T m_z;

};

/* ************************************************************************ */

extern template class Vector3<float>;
extern template class Vector3<double>;
extern template class Vector3<unsigned int>;
extern template class Vector3<int>;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const Vector3<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(T1 lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const Vector3<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(T1 lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const Vector3<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(T1 lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first Vector3.
 * @tparam     T2    Type of second operand.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const Vector3<T1>& lhs, T2 rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of first operand.
 * @tparam     T2    Type of value in second Vector3.
 *
 * @return     Result vector.
 */
template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(T1 lhs, const Vector3<T2>& rhs) noexcept;

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
inline bool operator==(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

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
Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept;

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
inline Vector3<T>::Vector3() noexcept
    : m_x{}
    , m_y{}
    , m_z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(T x, T y, T z) noexcept
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(Zero_t zero) noexcept
    : m_x{}
    , m_y{}
    , m_z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(const Vector3& src) noexcept
    : m_x{src.getX()}
    , m_y{src.getY()}
    , m_z{src.getZ()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(Vector3&& src) noexcept
    : m_x{std::move(src.m_x)}
    , m_y{std::move(src.m_y)}
    , m_z{std::move(src.m_z)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector3<T>::Vector3(const Vector3<T2>& rhs) noexcept
    : m_x(rhs.getX())
    , m_y(rhs.getY())
    , m_z(rhs.getZ())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(Zero_t zero) noexcept
{
    m_x = T{};
    m_y = T{};
    m_z = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(const Vector3& src) noexcept
{
    m_x = src.m_x;
    m_y = src.m_y;
    m_z = src.m_z;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(Vector3&& src) noexcept
{
    m_x = std::move(src.m_x);
    m_y = std::move(src.m_y);
    m_z = std::move(src.m_z);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector3<T>& Vector3<T>::operator=(const Vector3<T2>& src) noexcept
{
    m_x = T(src.getX());
    m_y = T(src.getY());
    m_z = T(src.getZ());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T> Vector3<T>::operator+() const noexcept
{
    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T> Vector3<T>::operator-() const noexcept
{
    return {-m_x, -m_y, -m_z};
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() + std::declval<T1>()),
    T
>::value>::type*>
inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T1>& rhs) noexcept
{
    m_x += rhs.getX();
    m_y += rhs.getY();
    m_z += rhs.getZ();

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T1, typename std::enable_if<std::is_same<
    decltype(std::declval<T>() - std::declval<T1>()),
    T
>::value>::type*>
inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T1>& rhs) noexcept
{
    m_x -= rhs.getX();
    m_y -= rhs.getY();
    m_z -= rhs.getZ();

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
inline Vector3<T>& Vector3<T>::operator*=(T1 rhs) noexcept
{
    m_x *= rhs;
    m_y *= rhs;
    m_z *= rhs;

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
inline Vector3<T>& Vector3<T>::operator*=(const Vector3<T1>& rhs) noexcept
{
    m_x *= rhs.getX();
    m_y *= rhs.getY();
    m_z *= rhs.getZ();

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
inline Vector3<T>& Vector3<T>::operator/=(T1 rhs) noexcept
{
    m_x /= rhs;
    m_y /= rhs;
    m_z /= rhs;

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
inline Vector3<T>& Vector3<T>::operator/=(const Vector3<T1>& rhs) noexcept
{
    m_x /= rhs.getX();
    m_y /= rhs.getY();
    m_z /= rhs.getZ();

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline T& Vector3<T>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 3);
    return (&m_x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 3);
    return (&m_x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline T& Vector3<T>::x() noexcept
{
    return m_x;
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getX() const noexcept
{
    return m_x;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setX(T x) noexcept
{
    m_x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline T& Vector3<T>::y() noexcept
{
    return m_y;
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getY() const noexcept
{
    return m_y;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setY(T y) noexcept
{
    m_y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline T& Vector3<T>::z() noexcept
{
    return m_z;
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getZ() const noexcept
{
    return m_z;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setZ(T z) noexcept
{
    m_z = std::move(z);
}

/* ************************************************************************ */

template<typename T>
inline bool Vector3<T>::inRange(T value, T low, T high) noexcept
{
    return value >= low && value < high;
}

/* ************************************************************************ */

template<typename T>
inline bool Vector3<T>::inRange(const Vector3& low, const Vector3& high) const noexcept
{
    bool res = true;

    res = res && inRange(getX(), low.getX(), high.getX());
    res = res && inRange(getY(), low.getY(), high.getY());
    res = res && inRange(getZ(), low.getZ(), high.getZ());

    return res;
}

/* ************************************************************************ */

template<typename T>
inline bool Vector3<T>::inRange(const Vector3& high) const noexcept
{
    return inRange(Zero, high);
}

/* ************************************************************************ */

template<typename T>
inline typename Vector3<T>::ValueType Vector3<T>::getLength() const noexcept
{
    using std::sqrt;
    return static_cast<T>(sqrt(getLengthSquared()));
}

/* ************************************************************************ */

template<typename T>
inline typename Vector3<T>::ValueTypeSq Vector3<T>::getLengthSquared() const noexcept
{
    return dot(*this);
}

/* ************************************************************************ */

template<typename T>
inline typename Vector3<T>::ValueTypeSq Vector3<T>::dot(const Vector3& rhs) const noexcept
{
    return
        getX() * rhs.getX() +
        getY() * rhs.getY() +
        getZ() * rhs.getZ()
    ;
}

/* ************************************************************************ */

template<typename T>
inline typename Vector3<T>::ValueTypeSq Vector3<T>::distanceSquared(const Vector3& rhs) const noexcept
{
    return (*this - rhs).getLengthSquared();
}

/* ************************************************************************ */

template<typename T>
inline typename Vector3<T>::ValueType Vector3<T>::distance(const Vector3& rhs) const noexcept
{
    return (*this - rhs).getLength();
}

/* ************************************************************************ */

template<typename T>
template<typename T2>
inline Vector3<T2> Vector3<T>::inversed() const noexcept
{
    return {
        T2(1) / getX(),
        T2(1) / getY(),
        T2(1) / getZ()
    };
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T> Vector3<T>::createSingle(T val) noexcept
{
    return {val, val, val};
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs.getX() + rhs.getX(),
        lhs.getY() + rhs.getY(),
        lhs.getZ() + rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(const Vector3<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() + rhs,
        lhs.getY() + rhs,
        lhs.getZ() + rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() + std::declval<T2>())>
operator+(T1 lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs + rhs.getX(),
        lhs + rhs.getY(),
        lhs + rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs.getX() - rhs.getX(),
        lhs.getY() - rhs.getY(),
        lhs.getZ() - rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(const Vector3<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() - rhs,
        lhs.getY() - rhs,
        lhs.getZ() - rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() - std::declval<T2>())>
operator-(T1 lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs - rhs.getX(),
        lhs - rhs.getY(),
        lhs - rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs.getX() * rhs.getX(),
        lhs.getY() * rhs.getY(),
        lhs.getZ() * rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(const Vector3<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() * rhs,
        lhs.getY() * rhs,
        lhs.getZ() * rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
operator*(T1 lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs * rhs.getX(),
        lhs * rhs.getY(),
        lhs * rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs.getX() / rhs.getX(),
        lhs.getY() / rhs.getY(),
        lhs.getZ() / rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(const Vector3<T1>& lhs, T2 rhs) noexcept
{
    return {
        lhs.getX() / rhs,
        lhs.getY() / rhs,
        lhs.getZ() / rhs
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() / std::declval<T2>())>
operator/(T1 lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs / rhs.getX(),
        lhs / rhs.getY(),
        lhs / rhs.getZ()
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline bool operator==(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return
        lhs.getX() == rhs.getX() &&
        lhs.getY() == rhs.getY() &&
        lhs.getZ() == rhs.getZ()
    ;
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline
Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const Vector3<T1>& lhs, const Vector3<T2>& rhs) noexcept
{
    return {
        lhs.getY() * rhs.getZ() - lhs.getZ() * rhs.getY(),
        lhs.getZ() * rhs.getX() - lhs.getX() * rhs.getZ(),
        lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX()
    };
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
