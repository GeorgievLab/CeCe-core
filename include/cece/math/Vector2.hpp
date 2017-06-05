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
class Vector2 : public VectorBase<Vector2, T>
{


// Public Types
public:


    /// Vector2 value type.
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

        T m[2];
    };


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    Vector2();


    /**
     * @brief      Constructor.
     *
     * @param      x     The X and Y coordinate.
     */
    explicit Vector2(T value);


    /**
     * @brief      Constructor.
     *
     * @param      x     The X coordinate.
     * @param      y     The Y coordinate.
     */
    Vector2(T x, T y);


    /**
     * @brief      Zero value constructor.
     *
     * @param[in]  zero  The zero value.
     */
    Vector2(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector2(const Vector2& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     */
    Vector2(Vector2&& src);


    /**
     * @brief      Copy constructor.
     *
     * @param      rhs   Source vector.
     *
     * @tparam     T2    The source vector element type.
     */
    template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type* = nullptr>
    Vector2(const Vector2<T2>& rhs);


// Public Operators
public:


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  zero  The zero value.
     *
     * @return     *this.
     */
    Vector2& operator=(Zero_t zero);


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector2& operator=(const Vector2& src);


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src   The source vector.
     *
     * @return     *this.
     */
    Vector2& operator=(Vector2&& src);


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
    Vector2& operator=(const Vector2<T2>& src);


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

};

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
Vector2<T> rotate(const Vector2<T>& vec, unit::Angle angle) noexcept;

/* ************************************************************************ */

extern template class Vector2<float>;
extern template class Vector2<double>;
extern template class Vector2<unsigned int>;
extern template class Vector2<int>;

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
inline Vector2<T>::Vector2()
    : x{}
    , y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>::Vector2(T val)
    : x{val}
    , y{val}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>::Vector2(T x, T y)
    : x{std::move(x)}
    , y{std::move(y)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>::Vector2(Zero_t zero)
    : x{}
    , y{}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>::Vector2(const Vector2& src)
    : x{src.getX()}
    , y{src.getY()}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>::Vector2(Vector2&& src)
    : x{std::move(src.x)}
    , y{std::move(src.y)}
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector2<T>::Vector2(const Vector2<T2>& rhs)
    : x(rhs.getX())
    , y(rhs.getY())
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>& Vector2<T>::operator=(Zero_t zero)
{
    x = T{};
    y = T{};

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>& Vector2<T>::operator=(const Vector2& src)
{
    x = src.x;
    y = src.y;

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T>& Vector2<T>::operator=(Vector2&& src)
{
    x = std::move(src.x);
    y = std::move(src.y);

    return *this;
}

/* ************************************************************************ */

template<typename T>
template<typename T2, typename std::enable_if<std::is_constructible<T, T2>::value>::type*>
inline Vector2<T>& Vector2<T>::operator=(const Vector2<T2>& src)
{
    x = T(src.getX());
    y = T(src.getY());

    return *this;
}

/* ************************************************************************ */

template<typename T>
inline T& Vector2<T>::operator[](int pos) noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector2<T>::operator[](int pos) const noexcept
{
    CECE_ASSERT(pos >= 0);
    CECE_ASSERT(pos < getSize());
    return (&x)[pos];
}

/* ************************************************************************ */

template<typename T>
inline int Vector2<T>::getSize() const noexcept
{
    return 2;
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector2<T>::getX() const noexcept
{
    return x;
}

/* ************************************************************************ */

template<typename T>
inline void Vector2<T>::setX(T x)
{
    this->x = std::move(x);
}

/* ************************************************************************ */

template<typename T>
inline const T& Vector2<T>::getY() const noexcept
{
    return y;
}

/* ************************************************************************ */

template<typename T>
inline void Vector2<T>::setY(T y)
{
    this->y = std::move(y);
}

/* ************************************************************************ */

template<typename T>
inline Vector2<T> rotate(const Vector2<T>& vec, unit::Angle angle) noexcept
{
    return {
        static_cast<T>(vec.getX() * cos(static_cast<RealType>(angle)) - vec.getY() * sin(static_cast<RealType>(angle))),
        static_cast<T>(vec.getX() * sin(static_cast<RealType>(angle)) + vec.getY() * cos(static_cast<RealType>(angle)))
    };
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
