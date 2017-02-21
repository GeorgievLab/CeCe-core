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
     * @brief Create from single value.
     *
     * @param val
     *
     * @return
     */
    static BasicVector createSingle(T val) noexcept;


// Private Data Members
private:

    /// BasicVector data.
    StaticArray<T, N> m_data;

};

/* ************************************************************************ */

/**
 * @brief Two dimensional vector.
 */
template<typename T>
class BasicVector<T, 2>
{

// Public Types
public:


    /// BasicVector value type.
    using ValueType = T;


// Public Contants
public:


    /// Number of elements
    static constexpr int SIZE = 2;


// Public Ctors
public:


    /**
     * @brief Default constructor.
     */
    BasicVector() noexcept
        : m_x{}
        , m_y{}
    {
        // Nothing to do
    }


    /**
     * @brief Constructor.
     *
     * @param x
     * @param y
     */
    BasicVector(T x, T y) noexcept
        : m_x(x)
        , m_y(y)
    {
        // Nothing to do
    }


    /**
     * @brief Zero value constructor.
     */
    BasicVector(Zero_t) noexcept
        : m_x{}
        , m_y{}
    {
        // Nothing to do
    }


    /**
     * @brief Copy constructor.
     *
     * @param rhs Source vector.
     */
    template<typename T2>
    explicit BasicVector(const BasicVector<T2, SIZE>& rhs) noexcept
        : m_x(static_cast<T>(rhs.getX()))
        , m_y(static_cast<T>(rhs.getY()))
    {
        // Nothing to do
    }


// Public Operators
public:


    /**
     * @brief Access operator.
     *
     * @param pos
     *
     * @return
     */
    T& operator[](int pos) noexcept
    {
        CECE_ASSERT(pos < SIZE);
        return (&m_x)[pos];
    }


    /**
     * @brief Access operator.
     *
     * @param pos
     *
     * @return
     */
    const T& operator[](int pos) const noexcept
    {
        CECE_ASSERT(pos < SIZE);
        return (&m_x)[pos];
    }


    /**
     * @brief Unary plus operator.
     *
     * @return
     */
    BasicVector operator+() const noexcept
    {
        return *this;
    }


    /**
     * @brief Unary minus operator.
     *
     * @return
     */
    BasicVector operator-() const noexcept
    {
        return BasicVector{-getX(), -getY()};
    }


    /**
     * @brief Addition operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator+=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x += rhs.getX();
        m_y += rhs.getY();
        return *this;
    }


    /**
     * @brief Subtraction operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator-=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x -= rhs.getX();
        m_y -= rhs.getY();
        return *this;
    }


    /**
     * @brief Multiplication operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator*=(T1 rhs) noexcept
    {
        m_x *= rhs;
        m_y *= rhs;
        return *this;
    }


    /**
     * @brief Multiplication operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator*=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x *= rhs.getX();
        m_y *= rhs.getY();
        return *this;
    }


    /**
     * @brief Division operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator/=(T1 rhs) noexcept
    {
        m_x /= rhs;
        m_y /= rhs;
        return *this;
    }


    /**
     * @brief Division operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1>
    BasicVector& operator/=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x /= rhs.getX();
        m_y /= rhs.getY();
        return *this;
    }


// Public Accessors
public:


    /**
     * @brief Returns vector size.
     *
     * @return
     */
    int getSize() const noexcept
    {
        return SIZE;
    }


    /**
     * @brief Returns X coordinate.
     *
     * @return
     */
    T& x() noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns X coordinate.
     *
     * @return
     */
    const T& getX() const noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns Y coordinate.
     *
     * @return
     */
    T& y() noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns Y coordinate.
     *
     * @return
     */
    const T& getY() const noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns width.
     *
     * @return
     */
    T& width() noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns width.
     *
     * @return
     */
    const T& getWidth() const noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns height.
     *
     * @return
     */
    T& height() noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns height.
     *
     * @return
     */
    const T& getHeight() const noexcept
    {
        return m_y;
    }


// Public Mutators
public:


    /**
     * @brief Set X coordinate.
     *
     * @param x
     */
    void setX(T x) noexcept
    {
        m_x = x;
    }


    /**
     * @brief Set Y coordinate.
     *
     * @param y
     */
    void setY(T y) noexcept
    {
        m_y = y;
    }


    /**
     * @brief Check if given value is in given range.
     *
     * @param value Given value.
     * @param low   Minimum value (>=).
     * @param high  Maximum value (<).
     *
     * @return
     */
    static bool inRange(T value, T low, T high) noexcept
    {
        return value >= low && value < high;
    }


    /**
     * @brief Check if current vector is in given range.
     *
     * @param low  Minimum coordinates (>=).
     * @param high Maximum coordinates (<).
     *
     * @return
     */
    bool inRange(const BasicVector& low, const BasicVector& high) const noexcept
    {
        return (
            inRange(getX(), low.getX(), high.getX()) &&
            inRange(getY(), low.getY(), high.getY())
        );
    }


// Public Operations
public:


    /**
     * @brief Calculate vector length.
     *
     * @return
     */
    T getLength() const noexcept
    {
        using std::sqrt;
        return static_cast<T>(sqrt(getLengthSquared()));
    }


    /**
     * @brief Calculate vector length - squared.
     *
     * @return
     */
    decltype(T{} * T{}) getLengthSquared() const noexcept
    {
        return dot(*this);
    }


    /**
     * @brief Calculate dot of two vectors.
     *
     * @param rhs Second vector.
     *
     * @return Dot product.
     */
    decltype(T{} * T{}) dot(const BasicVector& rhs) const noexcept
    {
        return {getX() * rhs.getX() + getY() * rhs.getY()};
    }


    /**
     * @brief Calculate vectors squared distance.
     *
     * @param rhs Second vector.
     *
     * @return Distance.
     */
    decltype(std::declval<T>() * std::declval<T>()) distanceSquared(const BasicVector& rhs) const noexcept
    {
        return (*this - rhs).getLengthSquared();
    }


    /**
     * @brief Calculate vectors distance.
     *
     * @param rhs Second vector.
     *
     * @return Distance.
     */
    T distance(const BasicVector& rhs) const noexcept
    {
        return (*this - rhs).getLength();
    }


    /**
     * @brief Inverse current vector (1 / *this).
     *
     * @return
     */
    template<typename T2>
    BasicVector<T2, SIZE> inversed() const noexcept
    {
        return BasicVector<T2, SIZE>{T2(1) / getX(), T2(1) / getY()};
    }


    /**
     * @brief Rotate current vector and return rotated version.
     *
     * @param angle Rotation angle.
     *
     * @return
     */
    BasicVector rotated(unit::Angle angle) const noexcept
    {
        return BasicVector(
            static_cast<T>(getX() * cos(static_cast<RealType>(angle)) - getY() * sin(static_cast<RealType>(angle))),
            static_cast<T>(getX() * sin(static_cast<RealType>(angle)) + getY() * cos(static_cast<RealType>(angle)))
        );
    }


    /**
     * @brief Create from single value.
     *
     * @param val
     *
     * @return
     */
    static BasicVector createSingle(T val) noexcept
    {
        return BasicVector{val, val};
    }


// Private Data Members
private:

    /// X coordinate.
    T m_x{};

    /// Y coordinate.
    T m_y{};

};

/* ************************************************************************ */

/**
 * @brief Three dimensional vector.
 */
template<typename T>
class BasicVector<T, 3>
{

// Public Types
public:


    /// BasicVector value type.
    using ValueType = T;


// Public Contants
public:


    /// Number of elements
    static constexpr int SIZE = 3;


// Public Ctors
public:


    /**
     * @brief Default constructor.
     */
    BasicVector() noexcept
        : m_x{}
        , m_y{}
        , m_z{}
    {
        // Nothing to do
    }


    /**
     * @brief Constructor.
     *
     * @param x
     * @param y
     * @param z
     */
    BasicVector(T x, T y, T z) noexcept
        : m_x(x)
        , m_y(y)
        , m_z(z)
    {
        // Nothing to do
    }


    /**
     * @brief Zero value constructor.
     */
    BasicVector(Zero_t) noexcept
        : m_x{}
        , m_y{}
        , m_z{}
    {
        // Nothing to do
    }


    /**
     * @brief Copy constructor.
     *
     * @param rhs Source vector.
     */
    template<typename T2>
    explicit BasicVector(const BasicVector<T2, SIZE>& rhs) noexcept
        : m_x(static_cast<T>(rhs.getX()))
        , m_y(static_cast<T>(rhs.getY()))
        , m_z(static_cast<T>(rhs.getZ()))
    {
        // Nothing to do
    }


// Public Operators
public:


    /**
     * @brief Access operator.
     *
     * @param pos
     *
     * @return
     */
    T& operator[](int pos) noexcept
    {
        CECE_ASSERT(pos < SIZE);
        return (&m_x)[pos];
    }


    /**
     * @brief Access operator.
     *
     * @param pos
     *
     * @return
     */
    const T& operator[](int pos) const noexcept
    {
        CECE_ASSERT(pos < SIZE);
        return (&m_x)[pos];
    }


    /**
     * @brief Unary plus operator.
     *
     * @return
     */
    BasicVector operator+() const noexcept
    {
        return *this;
    }


    /**
     * @brief Unary minus operator.
     *
     * @return
     */
    BasicVector operator-() const noexcept
    {
        return BasicVector{-getX(), -getY(), -getZ()};
    }


    /**
     * @brief Addition operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} + T1{}), T>::value>::type* = nullptr>
    BasicVector& operator+=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x += rhs.getX();
        m_y += rhs.getY();
        m_z += rhs.getZ();
        return *this;
    }


    /**
     * @brief Subtraction operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} - T1{}), T>::value>::type* = nullptr>
    BasicVector& operator-=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x -= rhs.getX();
        m_y -= rhs.getY();
        m_z -= rhs.getZ();
        return *this;
    }


    /**
     * @brief Multiplication operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} * T1{}), T>::value>::type* = nullptr>
    BasicVector& operator*=(T1 rhs) noexcept
    {
        m_x *= rhs;
        m_y *= rhs;
        m_z *= rhs;
        return *this;
    }


    /**
     * @brief Multiplication operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} * T1{}), T>::value>::type* = nullptr>
    BasicVector& operator*=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x *= rhs.getX();
        m_y *= rhs.getY();
        m_z *= rhs.getZ();
        return *this;
    }


    /**
     * @brief Division operator.
     *
     * @tparam T1 Type of right operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} / T1{}), T>::value>::type* = nullptr>
    BasicVector& operator/=(T1 rhs) noexcept
    {
        m_x /= rhs;
        m_y /= rhs;
        m_z /= rhs;
        return *this;
    }


    /**
     * @brief Division operator.
     *
     * @tparam T1 Type of value in BasicVector operand.
     *
     * @param rhs Right operand.
     *
     * @return *this.
     */
    template<typename T1, typename std::enable_if<std::is_same<decltype(T{} / T1{}), T>::value>::type* = nullptr>
    BasicVector& operator/=(const BasicVector<T1, SIZE>& rhs) noexcept
    {
        m_x /= rhs.getX();
        m_y /= rhs.getY();
        m_z /= rhs.getZ();
        return *this;
    }


// Public Accessors
public:


    /**
     * @brief Returns vector size.
     *
     * @return
     */
    int getSize() const noexcept
    {
        return SIZE;
    }


    /**
     * @brief Returns X coordinate.
     *
     * @return
     */
    T& x() noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns X coordinate.
     *
     * @return
     */
    const T& getX() const noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns Y coordinate.
     *
     * @return
     */
    T& y() noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns Y coordinate.
     *
     * @return
     */
    const T& getY() const noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns Z coordinate.
     *
     * @return
     */
    T& z() noexcept
    {
        return m_z;
    }


    /**
     * @brief Returns Z coordinate.
     *
     * @return
     */
    const T& getZ() const noexcept
    {
        return m_z;
    }


    /**
     * @brief Returns width.
     *
     * @return
     */
    T& width() noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns width.
     *
     * @return
     */
    const T& getWidth() const noexcept
    {
        return m_x;
    }


    /**
     * @brief Returns height.
     *
     * @return
     */
    T& height() noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns height.
     *
     * @return
     */
    const T& getHeight() const noexcept
    {
        return m_y;
    }


    /**
     * @brief Returns depth.
     *
     * @return
     */
    T& depth() noexcept
    {
        return m_z;
    }


    /**
     * @brief Returns depth.
     *
     * @return
     */
    const T& getDepth() const noexcept
    {
        return m_z;
    }


    /**
     * @brief Check if given value is in given range.
     *
     * @param value Given value.
     * @param low   Minimum value (>=).
     * @param high  Maximum value (<).
     *
     * @return
     */
    static bool inRange(T value, T low, T high) noexcept
    {
        return value >= low && value < high;
    }


    /**
     * @brief Check if current vector is in given range.
     *
     * @param low  Minimum coordinates (>=).
     * @param high Maximum coordinates (<).
     *
     * @return
     */
    bool inRange(const BasicVector& low, const BasicVector& high) const noexcept
    {
        return (
            inRange(getX(), low.getX(), high.getX()) &&
            inRange(getY(), low.getY(), high.getY()) &&
            inRange(getZ(), low.getZ(), high.getZ())
        );
    }



// Public Mutators
public:


    /**
     * @brief Set X coordinate.
     *
     * @param x
     */
    void setX(T x) noexcept
    {
        m_x = x;
    }


    /**
     * @brief Set Y coordinate.
     *
     * @param y
     */
    void setY(T y) noexcept
    {
        m_y = y;
    }


    /**
     * @brief Set Z coordinate.
     *
     * @param z
     */
    void setZ(T z) noexcept
    {
        m_z = z;
    }


// Public Operations
public:


    /**
     * @brief Calculate vector length.
     *
     * @return
     */
    template<typename T1 = decltype(T{} * T{}), typename std::enable_if<std::is_scalar<T1>::value>::type* = nullptr>
    T getLength() const noexcept
    {
        using std::sqrt;
        return static_cast<T>(sqrt(getLengthSquared()));
    }


    /**
     * @brief Calculate vector length - squared.
     *
     * @return
     */
    decltype(T{} * T{}) getLengthSquared() const noexcept
    {
        return dot(*this);
    }


    /**
     * @brief Calculate dot of two vectors.
     *
     * @param rhs Second vector.
     *
     * @return Dot product.
     */
    decltype(T{} * T{}) dot(const BasicVector& rhs) const noexcept
    {
        return {
            getX() * rhs.getX() +
            getY() * rhs.getY() +
            getZ() * rhs.getZ()
        };
    }


    /**
     * @brief Calculate vectors squared distance.
     *
     * @param rhs Second vector.
     *
     * @return Distance.
     */
    decltype(std::declval<T>() * std::declval<T>()) distanceSquared(const BasicVector& rhs) const noexcept
    {
        return (*this - rhs).getLengthSquared();
    }


    /**
     * @brief Calculate vectors distance.
     *
     * @param rhs Second vector.
     *
     * @return Distance.
     */
    T distance(const BasicVector& rhs) const noexcept
    {
        return (*this - rhs).getLength();
    }


    /**
     * @brief Inverse current vector (1 / *this).
     *
     * @return
     */
    template<typename T2>
    BasicVector<T2, SIZE> inversed() const noexcept
    {
        return BasicVector<T2, SIZE>{
            T2(1) / getX(),
            T2(1) / getY(),
            T2(1) / getZ()
        };
    }


    /**
     * @brief Create from single value.
     *
     * @param val
     *
     * @return
     */
    static BasicVector createSingle(T val) noexcept
    {
        return {val, val, val};
    }


// Private Data Members
private:

    /// X coordinate.
    T m_x{};

    /// Y coordinate.
    T m_y{};

    /// Z coordinate.
    T m_z{};

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
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} + T2{}), 2> operator+(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} + T2{}), 2>{
        lhs.getX() + rhs.getX(),
        lhs.getY() + rhs.getY()
    };
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
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} + T2{}), 2> operator+(const BasicVector<T1, 2>& lhs, T2 rhs) noexcept
{
    return BasicVector<decltype(T1{} + T2{}), 2>{
        lhs.getX() + rhs,
        lhs.getY() + rhs
    };
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
 * @brief Addition operator.
 *
 * @tparam T1 Type of first operand.
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} + T2{}), 2> operator+(T1 lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} + T2{}), 2>{
        lhs + rhs.getX(),
        lhs + rhs.getY()
    };
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
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} - T2{}), 2> operator-(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} - T2{}), 2>{
        lhs.getX() - rhs.getX(),
        lhs.getY() - rhs.getY()
    };
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
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} - T2{}), 2> operator-(const BasicVector<T1, 2>& lhs, T2 rhs) noexcept
{
    return BasicVector<decltype(T1{} - T2{}), 2>{
        lhs.getX() - rhs,
        lhs.getY() - rhs
    };
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
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} - T2{}), 2> operator-(T1 lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} - T2{}), 2>{
        lhs - rhs.getX(),
        lhs - rhs.getY()
    };
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
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} * T2{}), 2> operator*(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} * T2{}), 2>{
        lhs.getX() * rhs.getX(),
        lhs.getY() * rhs.getY()
    };
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
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} * T2{}), 2> operator*(const BasicVector<T1, 2>& lhs, T2 rhs) noexcept
{
    return BasicVector<decltype(T1{} * T2{}), 2>{
        lhs.getX() * rhs,
        lhs.getY() * rhs
    };
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
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} * T2{}), 2> operator*(T1 lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} * T2{}), 2>{
        lhs * rhs.getX(),
        lhs * rhs.getY()
    };
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
 * @tparam T2 Type of value in second BasicVector.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} / T2{}), 2> operator/(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} / T2{}), 2>{
        lhs.getX() / rhs.getX(),
        lhs.getY() / rhs.getY()
    };
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
 * @tparam T1 Type of value in first BasicVector.
 * @tparam T2 Type of second operand.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Result vector.
 */
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} / T2{}), 2> operator/(const BasicVector<T1, 2>& lhs, T2 rhs) noexcept
{
    return BasicVector<decltype(T1{} / T2{}), 2>{
        lhs.getX() / rhs,
        lhs.getY() / rhs
    };
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
template<typename T1, typename T2>
inline BasicVector<decltype(T1{} / T2{}), 2> operator/(T1 lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return BasicVector<decltype(T1{} / T2{}), 2>{
        lhs / rhs.getX(),
        lhs / rhs.getY()
    };
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
template<typename T1, typename T2>
inline bool operator==(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return
        lhs.getX() == rhs.getX() &&
        lhs.getY() == rhs.getY()
    ;
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
 * @brief Calculate cross product of two vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Cross product.
 */
template<typename T1, typename T2>
inline
decltype(std::declval<T1>() * std::declval<T2>())
cross(const BasicVector<T1, 2>& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return {lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX()};
}

/* ************************************************************************ */

/**
 * @brief Calculate cross product of two vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Cross product.
 */
template<typename T1, typename T2>
inline
BasicVector<decltype(std::declval<T1>() * std::declval<T2>()), 2>
cross(const BasicVector<T1, 2>& lhs, const T2& rhs) noexcept
{
    return {rhs * lhs.getY(), -rhs * lhs.getX()};
}

/* ************************************************************************ */

/**
 * @brief Calculate cross product of two vectors.
 *
 * @param lhs Left operand.
 * @param rhs Right operand.
 *
 * @return Cross product.
 */
template<typename T1, typename T2>
inline
BasicVector<decltype(std::declval<T1>() * std::declval<T2>()), 2>
cross(const T1& lhs, const BasicVector<T2, 2>& rhs) noexcept
{
    return {-lhs * rhs.getY(), lhs * rhs.getX()};
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
