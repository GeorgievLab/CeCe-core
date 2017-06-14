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
 * @tparam     N           Vector size.
 */
template<
    template<typename, int> typename VectorType,
    typename T,
    int N
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
    VectorType<T, N> operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     Vector.
     */
    VectorType<T, N> operator-() const noexcept;


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
    VectorType<T, N>& operator+=(const VectorType<T1, N>& rhs);


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
    VectorType<T, N>& operator-=(const VectorType<T1, N>& rhs);


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
    VectorType<T, N>& operator*=(T1 rhs);


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
    VectorType<T, N>& operator*=(const VectorType<T1, N>& rhs);


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
    VectorType<T, N>& operator/=(T1 rhs);


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
    VectorType<T, N>& operator/=(const VectorType<T1, N>& rhs);


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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() + std::declval<T2>()), N> operator+(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() - std::declval<T2>()), N> operator-(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const VectorType<T1, N>& lhs,
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const T1& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const VectorType<T1, N>& lhs,
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const T1& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
bool operator==(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, int N>
bool operator==(
    const VectorType<T1, N>& lhs,
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
template<template<typename, int> typename VectorType, typename T2, int N>
bool operator==(
    const Zero_t& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
bool operator!=(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
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
template<template<typename, int> typename VectorType, typename T1, int N>
bool operator!=(
    const VectorType<T1, N>& lhs,
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
template<template<typename, int> typename VectorType, typename T2, int N>
bool operator!=(
    const Zero_t& lhs,
    const VectorType<T2, N>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate dot product of two vectors.
 *
 * @param      lhs         Left operand.
 * @param      rhs         Right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Dot product.
 */
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
decltype(std::declval<T1>() * std::declval<T2>()) dot(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate distance of two vectors.
 *
 * @param      lhs         Left operand.
 * @param      rhs         Right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Distance.
 */
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
decltype(std::declval<decltype(std::declval<T1>() - std::declval<T2>())>() * std::declval<decltype(std::declval<T1>() - std::declval<T2>())>()) distanceSquared(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Calculate distance of two vectors.
 *
 * @param      lhs         Left operand.
 * @param      rhs         Right operand.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T1          Type of value in first VectorBase.
 * @tparam     T2          Type of value in second VectorBase.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Distance.
 */
template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
decltype(std::declval<T1>() - std::declval<T2>()) distance(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Check if value is in given range.
 *
 * @code
 *  value >= low && value < high;
 * @endcode
 *
 * @param[in]  value       The tested value.
 * @param[in]  low         The low value.
 * @param[in]  high        The high value.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T           Type of value.
 * @tparam     Tags        Vector type tags.
 *
 * @return     If value is in range.
 */
template<template<typename, int> typename VectorType, typename T, int N>
bool inRange(
    const VectorType<T, N>& value,
    const VectorType<T, N>& low,
    const VectorType<T, N>& high
);

/* ************************************************************************ */

/**
 * @brief      Check if value is in given range.
 *
 * @code
 *  value >= Zero && value < high;
 * @endcode
 *
 * @param[in]  value       The tested value.
 * @param[in]  high        The high value.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T           Type of value.
 * @tparam     Tags        Vector type tags.
 *
 * @return     If value is in range.
 */
template<template<typename, int> typename VectorType, typename T, int N>
bool inRange(
    const VectorType<T, N>& value,
    const VectorType<T, N>& high
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

template<template<typename, int> typename VectorType, typename T, int N>
inline VectorType<T, N> VectorBase<VectorType, T, N>::operator+() const noexcept
{
    return *static_cast<const VectorType<T, N>*>(this);
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
inline VectorType<T, N> VectorBase<VectorType, T, N>::operator-() const noexcept
{
    VectorType<T, N> res;

    // Typed alias
    auto& self = *static_cast<const VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        res[i] = -self[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator+=(const VectorType<T1, N>& rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] += rhs[i];

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator-=(const VectorType<T1, N>& rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] -= rhs[i];

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator*=(T1 rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] *= rhs;

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator*=(const VectorType<T1, N>& rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] *= rhs[i];

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator/=(T1 rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] /= rhs;

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
template<typename T1>
inline VectorType<T, N>& VectorBase<VectorType, T, N>::operator/=(const VectorType<T1, N>& rhs)
{
    // Typed alias
    auto& self = *static_cast<VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        self[i] /= rhs[i];

    return self;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
inline T VectorBase<VectorType, T, N>::getLength() const
{
    using std::sqrt;
    return static_cast<T>(sqrt(getLengthSquared()));
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
inline decltype(std::declval<T>() * std::declval<T>()) VectorBase<VectorType, T, N>::getLengthSquared() const
{
    decltype(std::declval<T>() * std::declval<T>()) res{};

    // Typed alias
    auto& self = *static_cast<const VectorType<T, N>*>(this);

    for (int i = 0; i < N; ++i)
        res += self[i] * self[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() + std::declval<T2>()), N> operator+(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() + std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] + rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() - std::declval<T2>()), N> operator-(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() - std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] - rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const VectorType<T1, N>& lhs,
    const T2& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] * rhs;

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> operator*(
    const T1& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() * std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] / rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const VectorType<T1, N>& lhs,
    const T2& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs[i] / rhs;

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> operator/(
    const T1& lhs,
    const VectorType<T2, N>& rhs
)
{
    VectorType<decltype(std::declval<T1>() / std::declval<T2>()), N> res;

    for (int i = 0; i < N; ++i)
        res[i] = lhs / rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline bool operator==(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    bool res = true;

    for (int i = 0; i < N; ++i)
        res = res && lhs[i] == rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, int N>
inline bool operator==(
    const VectorType<T1, N>& lhs,
    const Zero_t& rhs
)
{
    return operator==(lhs, VectorType<T1, N>(Zero));
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T2, int N>
inline bool operator==(
    const Zero_t& lhs,
    const VectorType<T2, N>& rhs
)
{
    return operator==(VectorType<T2, N>(lhs), rhs);
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline bool operator!=(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, int N>
inline bool operator!=(
    const VectorType<T1, N>& lhs,
    const Zero_t& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T2, int N>
inline bool operator!=(
    const Zero_t& lhs,
    const VectorType<T2, N>& rhs
)
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline decltype(std::declval<T1>() * std::declval<T2>()) dot(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    decltype(std::declval<T1>() * std::declval<T2>()) res{};

    for (int i = 0; i < N; ++i)
        res += lhs[i] * rhs[i];

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline decltype(std::declval<decltype(std::declval<T1>() - std::declval<T2>())>() * std::declval<decltype(std::declval<T1>() - std::declval<T2>())>()) distanceSquared(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    return (lhs - rhs).getLengthSquared();
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T1, typename T2, int N>
inline decltype(std::declval<T1>() - std::declval<T2>()) distance(
    const VectorType<T1, N>& lhs,
    const VectorType<T2, N>& rhs
)
{
    return (lhs - rhs).getLength();
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
inline bool inRange(
    const VectorType<T, N>& value,
    const VectorType<T, N>& low,
    const VectorType<T, N>& high
)
{
    bool res = true;

    for (int i = 0; i < N; ++i)
        res = res && (value[i] >= low[i] && value[i] < high[i]);

    return res;
}

/* ************************************************************************ */

template<template<typename, int> typename VectorType, typename T, int N>
inline bool inRange(
    const VectorType<T, N>& value,
    const VectorType<T, N>& high
)
{
    return inRange(value, VectorType<T, N>(Zero), high);
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
