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
#include <type_traits>
#include <utility>

// CeCe
#include "cece/common.hpp"
#include "cece/Assert.hpp"
#include "cece/math/Zero.hpp"
#include "cece/math/VectorBase.hpp"

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
class Vector3 : public VectorBase<Vector3, T>
{


// Public Types
public:


    /// Vector3 value type.
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

        T m[3];
    };


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    Vector3() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      val   The X, Y and Z coordinate.
     */
    explicit Vector3(T val);


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     * @param      y     The Z coordinate.
     */
    Vector3(T x, T y, T z);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    Vector3(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector3(const Vector3& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector3(Vector3&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    Vector3(const Vector3<T2>& rhs);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector3& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector3& operator=(const Vector3& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector3& operator=(Vector3&& src);


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
    Vector3& operator=(const Vector3<T2>& src);


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
    void setX(T x);


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
    void setY(T y);


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
    void setZ(T z);

};

/* ************************************************************************ */

extern template class Vector3<float>;
extern template class Vector3<double>;
extern template class Vector3<unsigned int>;
extern template class Vector3<int>;

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
Vector3<decltype(std::declval<T1>() * std::declval<T2>())>
cross(const Vector3<T1>& lhs, const Vector3<T2>& rhs);

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
    : x{}
    , y{}
    , z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(T val)
    : x{val}
    , y{val}
    , z{val}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(T x, T y, T z)
    : x{std::move(x)}
    , y{std::move(y)}
    , z{std::move(z)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(Zero_t zero)
    : x{}
    , y{}
    , z{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(const Vector3& src)
    : x{src.getX()}
    , y{src.getY()}
    , z{src.getZ()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>::Vector3(Vector3&& src)
    : x{std::move(src.x)}
    , y{std::move(src.y)}
    , z{std::move(src.z)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector3<T>::Vector3(const Vector3<T2>& rhs)
    : x(rhs.getX())
    , y(rhs.getY())
    , z(rhs.getZ())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(Zero_t zero)
{
    x = T{};
    y = T{};
    z = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(const Vector3& src)
{
    x = src.x;
    y = src.y;
    z = src.z;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector3<T>& Vector3<T>::operator=(Vector3&& src)
{
    x = std::move(src.x);
    y = std::move(src.y);
    z = std::move(src.z);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector3<T>& Vector3<T>::operator=(const Vector3<T2>& src)
{
    x = T(src.getX());
    y = T(src.getY());
    z = T(src.getZ());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline int Vector3<T>::getSize() const noexcept
{
    return 3;
}

/* ************************************************************************ */

template<typename T>
inline T& Vector3<T>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getX() const noexcept
{
    return x;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setX(T x)
{
    this->x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getY() const noexcept
{
    return y;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setY(T y)
{
    this->y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector3<T>::getZ() const noexcept
{
    return z;
}

/* ************************************************************************ */

template<typename T>
inline void Vector3<T>::setZ(T z)
{
    this->z = std::move(z);
}

/* ************************************************************************ */

template<typename T1, typename T2>
inline Vector3<decltype(std::declval<T1>() * std::declval<T2>())> cross(
    const Vector3<T1>& lhs,
    const Vector3<T2>& rhs
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
