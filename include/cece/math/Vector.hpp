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
#include "cece/math/VectorBase.hpp"
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
class BasicVector : public VectorBase<BasicVector, T, N>
{
    static_assert(N > 0, "Cannot create empty vector");


// Public Types
public:


    /// BasicVector value type.
    using ValueType = T;


// Public Data Members
public:


    // Member data.
    StaticArray<T, N> m;


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
    BasicVector(std::initializer_list<T> data);


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit BasicVector(T (&data)[N]);


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit BasicVector(const StaticArray<T, N>& data);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    BasicVector(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector(const BasicVector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    BasicVector(BasicVector&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      v     The source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    explicit BasicVector(const BasicVector<T2, N>& src);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    BasicVector& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(std::initializer_list<T> data);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(T (&data)[N]);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    BasicVector& operator=(const StaticArray<T, N>& data);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector& operator=(const BasicVector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    BasicVector& operator=(BasicVector&& src);


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
    BasicVector& operator=(const BasicVector<T2, N>& src);


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

};

/* ************************************************************************ */

// TODO: rework
template<typename T>
struct BasicVector<T, 2> : public Vector2<T>
{
    using Vector2<T>::Vector2;

    BasicVector() {};
    BasicVector(const Vector2<T>& src)
        : Vector2<T>(src)
    {
        //
    }

    const T& getWidth() const noexcept { return Vector2<T>::getX(); }

    const T& getHeight() const noexcept { return Vector2<T>::getY(); }

    static bool inRange(T value, T low, T high) noexcept { return value >= low && value < high; }

    bool inRange(const BasicVector& low, const BasicVector& high) const noexcept
    {
        bool res = true;

        res = res && inRange(Vector2<T>::getX(), low.getX(), high.getX());
        res = res && inRange(Vector2<T>::getY(), low.getY(), high.getY());

        return res;
    }

    bool inRange(const BasicVector& high) const noexcept
    {
        return inRange(Zero, high);
    }

    static BasicVector createSingle(T val) noexcept { return BasicVector(val, val); }

    template<typename T2 = T>
    BasicVector inversed() const noexcept
    {
        return BasicVector(
            T2(1) / Vector2<T>::getX(),
            T2(1) / Vector2<T>::getY()
        );
    }

    BasicVector rotated(unit::Angle angle) const noexcept
    {
        return rotate(*this, angle);
    }
};

/* ************************************************************************ */

// TODO: rework
template<typename T>
struct BasicVector<T, 3> : public Vector3<T>
{
    using Vector3<T>::Vector3;

    BasicVector() {};
    BasicVector(const Vector3<T>& src)
        : Vector3<T>(src)
    {
        //
    }

    const T& getWidth() const noexcept { return Vector3<T>::getX(); }
    const T& getHeight() const noexcept { return Vector3<T>::getY(); }
    const T& getDepth() const noexcept { return Vector3<T>::getZ(); }

    static bool inRange(T value, T low, T high) noexcept { return value >= low && value < high; }

    bool inRange(const BasicVector& low, const BasicVector& high) const noexcept
    {
        bool res = true;

        res = res && inRange(Vector3<T>::getX(), low.getX(), high.getX());
        res = res && inRange(Vector3<T>::getY(), low.getY(), high.getY());
        res = res && inRange(Vector3<T>::getZ(), low.getZ(), high.getZ());

        return res;
    }

    bool inRange(const BasicVector& high) const noexcept
    {
        return inRange(Zero, high);
    }

    static BasicVector createSingle(T val) noexcept { return BasicVector(val, val, val); }

    template<typename T2 = T>
    BasicVector inversed() const noexcept
    {
        return BasicVector(
            T2(1) / Vector3<T>::getX(),
            T2(1) / Vector3<T>::getY(),
            T2(1) / Vector3<T>::getZ()
        );
    }
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
    : m{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(std::initializer_list<T> data)
{
    CECE_ASSERT(data.size() == getSize());

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < getSize(); ++i, ++it)
        m[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(T (&data)[N])
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < getSize(); ++i, ++it)
        m[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(const StaticArray<T, N>& data)
    : m(data)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(Zero_t zero)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = T{};
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(const BasicVector& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = src.m[i];
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>::BasicVector(BasicVector&& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = std::move(src.m[i]);
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector<T, N>::BasicVector(const BasicVector<T2, N>& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = T(src[i]);
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(Zero_t zero)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(std::initializer_list<T> data)
{
    CECE_ASSERT(data.size() == getSize());

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < getSize(); ++i, ++it)
        m[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(T (&data)[N])
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < getSize(); ++i, ++it)
        m[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(const StaticArray<T, N>& data)
{
    m = data;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(const BasicVector& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = src.m[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(BasicVector&& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = std::move(src.m[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline BasicVector<T, N>& BasicVector<T, N>::operator=(const BasicVector<T2, N>& src)
{
    for (int i = 0; i < getSize(); ++i)
        m[i] = T(src[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline T& BasicVector<T, N>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int N>
inline const T& BasicVector<T, N>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int N>
int BasicVector<T, N>::getSize() const noexcept
{
    return N;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
