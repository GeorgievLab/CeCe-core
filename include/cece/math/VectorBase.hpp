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

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      Vector adaptor.
 *
 * @tparam     VectorType  The vector type.
 * @tparam     T           Value type.
 * @tparam     Tags        Additional tags.
 */
template<
    template<typename, int...> typename VectorType,
    typename T,
    int... Tags
>
class VectorBase
{

// Public Types
public:


    /// VectorBase value type.
    using ValueType = T;


// Public Operators
public:


    /**
     * @brief      Unary plus operator.
     *
     * @return     Vector.
     */
    VectorType<T, Tags...> operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     Vector.
     */
    VectorType<T, Tags...> operator-() const noexcept;


    /**
     * @brief      Addition operator.
     *
     * @param      rhs        The right operand.
     *
     * @tparam     T1         The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator+=(const VectorType<T1, Tags...>& rhs);


    /**
     * @brief      Subtraction operator.
     *
     * @param      rhs        The right operand.
     *
     * @tparam     T1         The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator-=(const VectorType<T1, Tags...>& rhs);


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        The right operand.
     *
     * @tparam     T1         Type of right operand.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator*=(T1 rhs);


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs        The right operand.
     *
     * @tparam     T1         The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator*=(const VectorType<T1, Tags...>& rhs);


    /**
     * @brief      Division operator.
     *
     * @param      rhs        The right operand.
     *
     * @tparam     T1         Type of right operand.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator/=(T1 rhs);


    /**
     * @brief      Division operator.
     *
     * @param      rhs        Right operand.
     *
     * @tparam     T1         The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    VectorType<T, Tags...>& operator/=(const VectorType<T1, Tags...>& rhs);


    /**
     * @brief      Access operator.
     *
     * @param      pos   The position.
     *
     * @return     Reference to the element.
     */
    T& operator[](int pos);


    /**
     * @brief      Access operator.
     *
     * @param      pos   The position.
     *
     * @return     Reference to the element.
     */
    const T& operator[](int pos) const;


// Public Accessors
public:


    /**
     * @brief      Returns vector size.
     *
     * @return     The size.
     */
    int getSize() const;


// Public Operations
public:


    /**
     * @brief      Calculate vector length.
     *
     * @return     The length.
     */
    T getLength() const;


    /**
     * @brief      Calculate vector length - squared.
     *
     * @return     The length squared.
     */
    decltype(std::declval<T>() * std::declval<T>()) getLengthSquared() const;

};

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() + std::declval<T2>()), Tags...> operator+(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Substract operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() - std::declval<T2>()), Tags...> operator-(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const VectorType<T1, Tags...>& lhs,
    const T2& rhs
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const T1& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const VectorType<T1, Tags...>& lhs,
    const T2& rhs
);

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Result vector.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const T1& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator==(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, int... Tags>
bool operator==(
    const VectorType<T1, Tags...>& lhs,
    const Zero_t& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T2, int... Tags>
bool operator==(
    const Zero_t& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator!=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, int... Tags>
bool operator!=(
    const VectorType<T1, Tags...>& lhs,
    const Zero_t& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T2, int... Tags>
bool operator!=(
    const Zero_t& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator<(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator<=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator>(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Compare vectors.
 *
 * @param      lhs         The left operand.
 * @param      rhs         The right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Operation result.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
bool operator>=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate dot product of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @return     Dot product.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
decltype(std::declval<T1>() * std::declval<T2>()) dot(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate distance of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @return     Distance.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
decltype(std::declval<decltype(std::declval<T1>() - std::declval<T2>())>() * std::declval<decltype(std::declval<T1>() - std::declval<T2>())>()) distanceSquared(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate distance of two vectors.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @return     Distance.
 */
template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
decltype(std::declval<T1>() - std::declval<T2>()) distance(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
);

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline VectorType<T, Tags...> VectorBase<VectorType, T, Tags...>::operator+() const noexcept
{
    return *static_cast<const VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline VectorType<T, Tags...> VectorBase<VectorType, T, Tags...>::operator-() const noexcept
{
    VectorType<T, Tags...> res;

    for (int i = 0; i < getSize(); ++i)
        res[i] = -(*this)[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator+=(const VectorType<T1, Tags...>& rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] += rhs[i];

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator-=(const VectorType<T1, Tags...>& rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] -= rhs[i];

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator*=(T1 rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] *= rhs;

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator*=(const VectorType<T1, Tags...>& rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] *= rhs[i];

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator/=(T1 rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] /= rhs;

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
template<typename T1>
inline VectorType<T, Tags...>& VectorBase<VectorType, T, Tags...>::operator/=(const VectorType<T1, Tags...>& rhs)
{
    for (int i = 0; i < getSize(); ++i)
        (*this)[i] /= rhs[i];

    return *static_cast<VectorType<T, Tags...>*>(this);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline T& VectorBase<VectorType, T, Tags...>::operator[](int pos)
{
    // TODO: recursion possibility
    return (*static_cast<VectorType<T, Tags...>*>(this))[pos];
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline const T& VectorBase<VectorType, T, Tags...>::operator[](int pos) const
{
    // TODO: recursion possibility
    return (*static_cast<const VectorType<T, Tags...>*>(this))[pos];
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline int VectorBase<VectorType, T, Tags...>::getSize() const
{
    // TODO: recursion possibility
    return static_cast<const VectorType<T, Tags...>*>(this)->getSize();
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline T VectorBase<VectorType, T, Tags...>::getLength() const
{
    using std::sqrt;
    return static_cast<T>(sqrt(getLengthSquared()));
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline decltype(std::declval<T>() * std::declval<T>()) VectorBase<VectorType, T, Tags...>::getLengthSquared() const
{
    decltype(std::declval<T>() * std::declval<T>()) res{};

    for (int i = 0; i < getSize(); ++i)
        res += (*this)[i] * (*this)[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() + std::declval<T2>()), Tags...> operator+(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() + std::declval<T2>()), Tags...> res;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());
    CECE_ASSERT(res.getSize() == lhs.getSize());
    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() - std::declval<T2>()), Tags...> operator-(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() - std::declval<T2>()), Tags...> res;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());
    CECE_ASSERT(res.getSize() == lhs.getSize());
    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] - rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> res;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());
    CECE_ASSERT(res.getSize() == lhs.getSize());
    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const VectorType<T1, Tags...>& lhs,
    const T2& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> res;

    CECE_ASSERT(res.getSize() == lhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] * rhs;

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> operator*(
    const T1& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), Tags...> res;

    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> res;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());
    CECE_ASSERT(res.getSize() == lhs.getSize());
    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] / rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const VectorType<T1, Tags...>& lhs,
    const T2& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> res;

    CECE_ASSERT(res.getSize() == lhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs[i] / rhs;

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> operator/(
    const T1& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), Tags...> res;

    CECE_ASSERT(res.getSize() == rhs.getSize());

    for (int i = 0; i < res.getSize(); ++i)
        res[i] = lhs / rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator==(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    bool res = true;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());

    for (int i = 0; i < lhs.getSize(); ++i)
        res = res && lhs[i] == rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, int... Tags>
inline bool operator==(
    const VectorType<T1, Tags...>& lhs,
    const Zero_t& rhs
)
{
    return operator==(lhs, VectorType<T1, Tags...>(Zero));
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T2, int... Tags>
inline bool operator==(
    const Zero_t& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return operator==(VectorType<T2, Tags...>(lhs), rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator!=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, int... Tags>
inline bool operator!=(
    const VectorType<T1, Tags...>& lhs,
    const Zero_t& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T2, int... Tags>
inline bool operator!=(
    const Zero_t& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator<(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    bool res = true;

    CECE_ASSERT(lhs.getSize() == rhs.getSize());

    for (int i = 0; i < lhs.getSize(); ++i)
        res = res && (lhs[i] < rhs[i]);

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator<=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator>(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline bool operator>=(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline decltype(std::declval<T1>() * std::declval<T2>()) dot(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    decltype(std::declval<T1>() * std::declval<T2>()) res{};

    CECE_ASSERT(lhs.getSize() == rhs.getSize());

    for (int i = 0; i < lhs.getSize(); ++i)
        res += lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline decltype(std::declval<decltype(std::declval<T1>() - std::declval<T2>())>() * std::declval<decltype(std::declval<T1>() - std::declval<T2>())>()) distanceSquared(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return (lhs - rhs).getLengthSquared();
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T1, typename T2, int... Tags>
inline decltype(std::declval<T1>() - std::declval<T2>()) distance(
    const VectorType<T1, Tags...>& lhs,
    const VectorType<T2, Tags...>& rhs
)
{
    return (lhs - rhs).getLength();
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
