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
#include "cece/unit/math.hpp"
#include "cece/unit/Units.hpp"
#include "cece/math/VectorBase.hpp"

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
template<typename T, int N = DIMENSION>
class Vector : public VectorBase<Vector, T, N>
{
    static_assert(N > 0, "Cannot create empty vector");


// Public Types
public:


    /// Vector value type.
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
    constexpr Vector() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    Vector(std::initializer_list<T> data);


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit Vector(T (&data)[N]);


    /**
     * @brief      Constructor.
     *
     * @param      data  The source data.
     */
    explicit Vector(const StaticArray<T, N>& data);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    Vector(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector(Vector&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      v     The source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    explicit Vector(const Vector<T2, N>& src);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    Vector& operator=(std::initializer_list<T> data);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    Vector& operator=(T (&data)[N]);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  data  The source data.
     *
     * @return     *this.
     */
    Vector& operator=(const StaticArray<T, N>& data);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(Vector&& src);


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
    Vector& operator=(const Vector<T2, N>& src);


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
    constexpr const T& operator[](int pos) const noexcept;


// Public Accessors
public:


    /**
     * @brief      Returns vector size.
     *
     * @return     The size.
     */
    constexpr int getSize() const noexcept;

};

/* ************************************************************************ */

/**
 * @brief      2D vector specialization.
 *
 * @tparam     T     Element type.
 */
template<typename T>
struct Vector<T, 2> : public VectorBase<Vector, T, 2>
{

// Public Types
public:


    /// Element type.
    using ValueType = T;


// Public Data Members
public:


    union
    {
        struct
        {
            /// X coordinate.
            T x;

            /// Y coordinate.
            T y;
        };

        struct
        {
            /// Width
            T width;

            /// Height.
            T height;
        };

        T m[2];
    };


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    constexpr Vector();


    /**
     * @brief      Constructor.
     *
     * @param      x     The X and Y coordinate.
     */
    explicit constexpr Vector(T value);


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     */
    constexpr Vector(T x, T y);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    constexpr Vector(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    constexpr Vector(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    constexpr Vector(Vector&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    constexpr Vector(const Vector<T2, 2>& rhs);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(Vector&& src);


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
    Vector& operator=(const Vector<T2, 2>& src);


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
    constexpr const T& operator[](int pos) const noexcept;


// Public Accessors
public:


    /**
     * @brief      Returns vector size.
     *
     * @return     The size.
     */
    constexpr int getSize() const noexcept;


    /**
     * @brief      Returns X coordinate.
     *
     * @return     The X coordinate.
     */
    constexpr const T& getX() const noexcept;


    /**
     * @brief      Set X coordinate.
     *
     * @param[in]  x     The X coordinate.
     */
    void setX(T x);


    /**
     * @brief      Returns Y coordinate.
     *
     * @return     The Y coordinate.
     */
    constexpr const T& getY() const noexcept;


    /**
     * @brief      Set Y coordinate.
     *
     * @param[in]  y     The Y coordinate.
     */
    void setY(T y);


    /**
     * @brief      Gets the width.
     *
     * @return     The width.
     */
    constexpr const T& getWidth() const noexcept;


    /**
     * @brief      Set the width.
     *
     * @param[in]  width  The width.
     */
    void setWidth(T width);


    /**
     * @brief      Gets the height.
     *
     * @return     The height.
     */
    constexpr const T& getHeight() const noexcept;


    /**
     * @brief      Sets the height.
     *
     * @param[in]  height  The height
     */
    void setHeight(T height);


// Public Deprecated
public:


    // @deprecated
    bool inRange(const Vector& low, const Vector& high) const noexcept
    {
        return math::inRange(*this, low, high);
    }


    // @deprecated
    bool inRange(const Vector& high) const noexcept
    {
        return math::inRange(*this, high);
    }


    // @deprecated
    static Vector createSingle(T val) noexcept
    {
        return Vector(val, val);
    }


    // @deprecated
    template<typename T2 = T>
    Vector inversed() const noexcept
    {
        return T2(1) / *this;
    }


    // @deprecated
    Vector rotated(unit::Angle angle) const noexcept
    {
        return rotate(*this, angle);
    }
};

/* ************************************************************************ */

/**
 * @brief      3D vector specialization.
 *
 * @tparam     T     Element type.
 */
template<typename T>
struct Vector<T, 3> : public VectorBase<Vector, T, 3>
{


// Public Types
public:


    /// Vector element type.
    using ValueType = T;


// Public Data Members
public:


    union
    {
        struct
        {
            /// X coordinate.
            T x;

            /// Y coordinate.
            T y;

            /// Z coordinate.
            T z;
        };

        struct
        {
            /// Width.
            T width;

            /// Height.
            T height;

            /// Depth.
            T depth;
        };

        T m[3];
    };


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    constexpr Vector() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      val   The X, Y and Z coordinate.
     */
    explicit constexpr Vector(T val);


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     * @param      y     The Z coordinate.
     */
    constexpr Vector(T x, T y, T z);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    constexpr Vector(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    constexpr Vector(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    constexpr Vector(Vector&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    constexpr Vector(const Vector<T2, 3>& rhs);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(const Vector& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector& operator=(Vector&& src);


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
    Vector& operator=(const Vector<T2, 3>& src);


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
    constexpr const T& operator[](int pos) const noexcept;


// Public Accessors
public:


    /**
     * @brief      Returns vector size.
     *
     * @return     The size.
     */
    constexpr int getSize() const noexcept;


    /**
     * @brief      Returns X coordinate.
     *
     * @return     The X coordinate.
     */
    constexpr const T& getX() const noexcept;


    /**
     * @brief      Set X coordinate.
     *
     * @param      x     The X coordinate.
     */
    void setX(T x);


    /**
     * @brief      Returns Y coordinate.
     *
     * @return     The Y coordinate.
     */
    constexpr const T& getY() const noexcept;


    /**
     * @brief      Set Y coordinate.
     *
     * @param      y     The Y coordinate.
     */
    void setY(T y);


    /**
     * @brief      Returns Z coordinate.
     *
     * @return     The Z coordinate.
     */
    constexpr const T& getZ() const noexcept;


    /**
     * @brief      Set Z coordinate.
     *
     * @param      z     The Z coordinate.
     */
    void setZ(T z);


    /**
     * @brief      Gets the width.
     *
     * @return     The width.
     */
    constexpr const T& getWidth() const noexcept;


    /**
     * @brief      Set the width.
     *
     * @param[in]  width  The width.
     */
    void setWidth(T width);


    /**
     * @brief      Gets the height.
     *
     * @return     The height.
     */
    constexpr const T& getHeight() const noexcept;


    /**
     * @brief      Sets the height.
     *
     * @param[in]  height  The height
     */
    void setHeight(T height);


    /**
     * @brief      Gets the depth.
     *
     * @return     The depth.
     */
    constexpr const T& getDepth() const noexcept;


    /**
     * @brief      Sets the depth.
     *
     * @param[in]  depth  The depth
     */
    void setDepth(T depth);


// Public Deprecated
public:


    // @deprecated
    bool inRange(const Vector& low, const Vector& high) const noexcept
    {
        return math::inRange(*this, low, high);
    }


    // @deprecated
    bool inRange(const Vector& high) const noexcept
    {
        return math::inRange(*this, high);
    }


    // @deprecated
    static Vector createSingle(T val) noexcept
    {
        return Vector(val, val, val);
    }


    // @deprecated
    template<typename T2 = T>
    Vector inversed() const noexcept
    {
        return T2(1) / *this;
    }
};

/* ************************************************************************ */

/**
 * @brief      2D vector alias.
 */
template<typename T>
using Vector2 = Vector<T, 2>;

/* ************************************************************************ */

/**
 * @brief      3D vector alias.
 */
template<typename T>
using Vector3 = Vector<T, 3>;

/* ************************************************************************ */

/**
 * @brief      Vector for integer size.
 * @deprecated
 */
using Size = Vector<unsigned int>;

/* ************************************************************************ */

/**
 * @brief      Vector for coordinates.
 * @deprecated
 */
using Coordinate = Vector<unsigned int>;

/* ************************************************************************ */

/**
 * @brief      Vector of int.
 * @deprecated
 */
using VectorInt = Vector<int>;

/* ************************************************************************ */

/**
 * @brief      Vector of float.
 * @deprecated
 */
using VectorFloat = Vector<float>;

/* ************************************************************************ */

/**
 * @brief      Vector of double.
 * @deprecated
 */
using VectorDouble = Vector<double>;

/* ************************************************************************ */

/**
 * @brief      Vector of long double.
 * @deprecated
 */
using VectorLongDouble = Vector<long double>;

/* ************************************************************************ */

/**
 * @brief      Vector of float.
 * @deprecated
 */
using VectorReal = Vector<RealType>;

/* ************************************************************************ */

/**
 * @brief      Vector of integers.
 */
using IntVector = Vector<int>;

/* ************************************************************************ */

/**
 * @brief      Vector of float.
 */
using FloatVector = Vector<float>;

/* ************************************************************************ */

/**
 * @brief      Vector of double.
 */
using DoubleVector = Vector<double>;

/* ************************************************************************ */

/**
 * @brief      Vector of long double.
 */
using LongDoubleVector = Vector<long double>;

/* ************************************************************************ */

/**
 * @brief      Vector of float.
 */
using RealVector = Vector<RealType>;

/* ************************************************************************ */

/**
 * @brief      Vector for indices.
 */
using IndexVector = Vector<unsigned long>;

/* ************************************************************************ */

/**
 * @brief      Vector for sizes.
 */
using SizeVector = Vector<unsigned long>;

/* ************************************************************************ */

/**
 * @brief      Rotate the vector counter-clockwise and return rotated version.
 *
 * @param[in]  vec    The vector.
 * @param[in]  angle  Rotation angle.
 *
 * @tparam     T      The vector element type.
 *
 * @return     Rotated vector.
 */
template<typename T>
constexpr Vector<T, 2> rotate(const Vector<T, 2>& vec, unit::Angle angle) noexcept;

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
constexpr Vector<decltype(std::declval<T1>() * std::declval<T2>()), 3>
cross(const Vector<T1, 3>& lhs, const Vector<T2, 3>& rhs);

/* ************************************************************************ */

extern template class Vector<int, 2>;
extern template class Vector<int, 3>;
extern template class Vector<unsigned int, 2>;
extern template class Vector<unsigned int, 3>;
extern template class Vector<unsigned long, 2>;
extern template class Vector<unsigned long, 3>;
extern template class Vector<float, 2>;
extern template class Vector<float, 3>;
extern template class Vector<double, 2>;
extern template class Vector<double, 3>;

/* ************************************************************************ */

/// @deprecated
template<typename T, int N>
using BasicVector = Vector<T, N>;

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
inline constexpr Vector<T, N>::Vector() noexcept
    : m{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(std::initializer_list<T> data)
{
    CECE_ASSERT(data.size() == N);

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(T (&data)[N])
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m[i] = *it;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(const StaticArray<T, N>& data)
    : m(data)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(Zero_t zero)
{
    for (int i = 0; i < N; ++i)
        m[i] = T{};
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(const Vector& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = src.m[i];
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>::Vector(Vector&& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = std::move(src.m[i]);
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector<T, N>::Vector(const Vector<T2, N>& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = T(src[i]);
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(Zero_t zero)
{
    for (int i = 0; i < N; ++i)
        m[i] = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(std::initializer_list<T> data)
{
    CECE_ASSERT(data.size() == N);

    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(T (&data)[N])
{
    using std::begin;
    auto it = begin(data);

    for (int i = 0; i < N; ++i, ++it)
        m[i] = *it;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(const StaticArray<T, N>& data)
{
    m = data;

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(const Vector& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = src.m[i];

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline Vector<T, N>& Vector<T, N>::operator=(Vector&& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = std::move(src.m[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector<T, N>& Vector<T, N>::operator=(const Vector<T2, N>& src)
{
    for (int i = 0; i < N; ++i)
        m[i] = T(src[i]);

    return *this;
}

/* ************************************************************************ */

template<typename T, int N>
inline T& Vector<T, N>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < N);
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int N>
inline constexpr const T& Vector<T, N>::operator[](int pos) const noexcept
{
#if __cplusplus >= 201402L
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < N);
#endif
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int N>
inline constexpr int Vector<T, N>::getSize() const noexcept
{
    return N;
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector()
    : x{}
    , y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector(T val)
    : x{val}
    , y{val}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector(T x, T y)
    : x{std::move(x)}
    , y{std::move(y)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector(Zero_t zero)
    : x{}
    , y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector(const Vector& src)
    : x{src.getX()}
    , y{src.getY()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2>::Vector(Vector&& src)
    : x{std::move(src.x)}
    , y{std::move(src.y)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline constexpr Vector<T, 2>::Vector(const Vector<T2, 2>& rhs)
    : x(rhs.getX())
    , y(rhs.getY())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 2>& Vector<T, 2>::operator=(Zero_t zero)
{
    x = T{};
    y = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 2>& Vector<T, 2>::operator=(const Vector& src)
{
    x = src.x;
    y = src.y;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 2>& Vector<T, 2>::operator=(Vector&& src)
{
    x = std::move(src.x);
    y = std::move(src.y);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector<T, 2>& Vector<T, 2>::operator=(const Vector<T2, 2>& src)
{
    x = T(src.getX());
    y = T(src.getY());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline T& Vector<T, 2>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 2);
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 2>::operator[](int pos) const noexcept
{
#if __cplusplus >= 201402L
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 2);
#endif
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline constexpr int Vector<T, 2>::getSize() const noexcept
{
    return 2;
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 2>::getX() const noexcept
{
    return x;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 2>::setX(T x)
{
    this->x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 2>::getY() const noexcept
{
    return y;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 2>::setY(T y)
{
    this->y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 2>::getWidth() const noexcept
{
    return width;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 2>::setWidth(T width)
{
    this->width = std::move(width);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 2>::getHeight() const noexcept
{
    return height;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 2>::setHeight(T height)
{
    this->height = std::move(height);
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector() noexcept
    : x{}
    , y{}
    , z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector(T val)
    : x{val}
    , y{val}
    , z{val}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector(T x, T y, T z)
    : x{std::move(x)}
    , y{std::move(y)}
    , z{std::move(z)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector(Zero_t zero)
    : x{}
    , y{}
    , z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector(const Vector& src)
    : x{src.getX()}
    , y{src.getY()}
    , z{src.getZ()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 3>::Vector(Vector&& src)
    : x{std::move(src.x)}
    , y{std::move(src.y)}
    , z{std::move(src.z)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline constexpr Vector<T, 3>::Vector(const Vector<T2, 3>& rhs)
    : x(rhs.getX())
    , y(rhs.getY())
    , z(rhs.getZ())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 3>& Vector<T, 3>::operator=(Zero_t zero)
{
    x = T{};
    y = T{};
    z = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 3>& Vector<T, 3>::operator=(const Vector& src)
{
    x = src.x;
    y = src.y;
    z = src.z;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector<T, 3>& Vector<T, 3>::operator=(Vector&& src)
{
    x = std::move(src.x);
    y = std::move(src.y);
    z = std::move(src.z);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector<T, 3>& Vector<T, 3>::operator=(const Vector<T2, 3>& src)
{
    x = T(src.getX());
    y = T(src.getY());
    z = T(src.getZ());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline T& Vector<T, 3>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 3);
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::operator[](int pos) const noexcept
{
#if __cplusplus >= 201402L
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < 3);
#endif
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getX() const noexcept
{
    return x;
}

/* ************************************************************************ */

template<typename T>
inline constexpr int Vector<T, 3>::getSize() const noexcept
{
    return 3;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setX(T x)
{
    this->x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getY() const noexcept
{
    return y;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setY(T y)
{
    this->y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getZ() const noexcept
{
    return z;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setZ(T z)
{
    this->z = std::move(z);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getWidth() const noexcept
{
    return width;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setWidth(T width)
{
    this->width = std::move(width);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getHeight() const noexcept
{
    return height;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setHeight(T height)
{
    this->height = std::move(height);
}

/* ************************************************************************ */

template<typename T>
inline constexpr const T& Vector<T, 3>::getDepth() const noexcept
{
    return depth;
}

/* ************************************************************************ */

template<typename T>
inline void Vector<T, 3>::setDepth(T depth)
{
    this->depth = std::move(depth);
}

/* ************************************************************************ */

template<typename T>
inline constexpr Vector<T, 2> rotate(const Vector<T, 2>& vec, unit::Angle angle) noexcept
{
    return {
        static_cast<T>(vec.getX() * cos(static_cast<RealType>(angle)) - vec.getY() * sin(static_cast<RealType>(angle))),
        static_cast<T>(vec.getX() * sin(static_cast<RealType>(angle)) + vec.getY() * cos(static_cast<RealType>(angle)))
    };
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline constexpr Vector<decltype(std::declval<T1>() * std::declval<T2>()), 3> cross(
    const Vector<T1, 3>& lhs,
    const Vector<T2, 3>& rhs
)
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
