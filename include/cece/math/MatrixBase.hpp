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

// CeCe
#include "cece/math/Vector.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      2D fixed size matrix base class.
 *
 * @tparam     MatrixType  Matrix type.
 * @tparam     T           Type of stored value.
 * @tparam     R           Number of rows.
 * @tparam     C           Number of cols.
 */
template<
    template<typename, int, int> typename MatrixType,
    typename T,
    int R,
    int C
>
struct MatrixBase
{

// Public Types
public:


    /// VectorBase value type.
    using ValueType = T;


// Public Operators
public:


    /**
     * @brief      Addition operator.
     *
     * @param      rhs   Right operand.
     *
     * @tparam     T1    The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    MatrixType<T, R, C>& operator+=(const MatrixType<T1, R, C>& rhs);


    /**
     * @brief      Substraction operator.
     *
     * @param      rhs   Right operand.
     *
     * @tparam     T1    The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    MatrixType<T, R, C>& operator-=(const MatrixType<T2, R, C>& rhs);


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs   Right operand.
     *
     * @tparam     T1    The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    MatrixType<T, R, C>& operator*=(const T1& rhs);


    /**
     * @brief      Division operator.
     *
     * @param      rhs   Right operand.
     *
     * @tparam     T1    The second type.
     *
     * @return     *this.
     */
    template<typename T1>
    MatrixType<T, R, C>& operator/=(const T1& rhs);

};

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first matrix.
 * @tparam     T2    Type of value in second matrix.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 *
 * @return     Result matrix.
 */
template<typename T1, typename T2, int R, int C>
MatrixBase<decltype(std::declval<T1>() + std::declval<T2>()), R, C> operator+(
    const MatrixBase<T1, R, C>& lhs,
    const MatrixBase<T2, R, C>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Substraction operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first matrix.
 * @tparam     T2    Type of value in second matrix.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 *
 * @return     Result matrix.
 */
template<typename T1, typename T2, int R, int C>
MatrixBase<decltype(std::declval<T1>() - std::declval<T2>()), R, C> operator-(
    const MatrixBase<T1, R, C>& lhs,
    const MatrixBase<T2, R, C>& rhs
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first matrix.
 * @tparam     T2    Type of value in second matrix.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 *
 * @return     Result matrix.
 */
template<typename T1, typename T2, int R, int C>
MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> operator*(
    const MatrixBase<T1, R, C>& lhs,
    const T2& rhs
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first matrix.
 * @tparam     T2    Type of value in second matrix.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 *
 * @return     Result matrix.
 */
template<typename T1, typename T2, int R, int C>
MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> operator*(
    const T2& lhs
    const MatrixBase<T1, R, C>& rhs,
);

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs   Left operand.
 * @param      rhs   Right operand.
 *
 * @tparam     T1    Type of value in first matrix.
 * @tparam     T2    Type of value in second matrix.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 *
 * @return     Result matrix.
 */
template<typename T1, typename T2, int R, int C>
MatrixBase<decltype(std::declval<T1>() / std::declval<T2>()), R, C> operator/(
    const MatrixBase<T1, R, C>& lhs,
    const T2& rhs
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

template<template<typename, int, int> typename MatrixType, typename T, int R, int C>
template<typename T1>
inline MatrixType<T, R, C>& MatrixBase<MatrixType, T, R, C>::operator+=(const MatrixType<T1, R, C>& rhs)
{
    auto& self = *static_cast<MatrixType<T, R, C>*>(this);

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            self[row][col] += rhs[row][col];

    return self;
}

/* ************************************************************************ */

template<template<typename, int, int> typename MatrixType, typename T, int R, int C>
template<typename T1>
inline MatrixType<T, R, C>& MatrixBase<MatrixType, T, R, C>::operator-=(const MatrixType<T2, R, C>& rhs)
{
    auto& self = *static_cast<MatrixType<T, R, C>*>(this);

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            self[row][col] -= rhs[row][col];

    return self;
}

/* ************************************************************************ */

template<template<typename, int, int> typename MatrixType, typename T, int R, int C>
template<typename T1>
inline MatrixType<T, R, C>& MatrixBase<MatrixType, T, R, C>::operator*=(const T1& rhs)
{
    auto& self = *static_cast<MatrixType<T, R, C>*>(this);

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            self[row][col] *= rhs;

    return self;
}

/* ************************************************************************ */

template<template<typename, int, int> typename MatrixType, typename T, int R, int C>
template<typename T1>
inline MatrixType<T, R, C>& MatrixBase<MatrixType, T, R, C>::operator/=(const T1& rhs)
{
    auto& self = *static_cast<MatrixType<T, R, C>*>(this);

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            self[row][col] /= rhs;

    return self;
}

/* ************************************************************************ */

template<typename T1, typename T2, int R, int C>
inline MatrixBase<decltype(std::declval<T1>() + std::declval<T2>()), R, C> operator+(
    const MatrixBase<T1, R, C>& lhs,
    const MatrixBase<T2, R, C>& rhs
)
{
    MatrixBase<decltype(std::declval<T1>() + std::declval<T2>()), R, C> res;

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            res[row][col] = lhs[row][col] + rhs[row][col];

    return res;
}

/* ************************************************************************ */

template<typename T1, typename T2, int R, int C>
inline MatrixBase<decltype(std::declval<T1>() - std::declval<T2>()), R, C> operator-(
    const MatrixBase<T1, R, C>& lhs,
    const MatrixBase<T2, R, C>& rhs
)
{
    MatrixBase<decltype(std::declval<T1>() + std::declval<T2>()), R, C> res;

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            res[row][col] = lhs[row][col] - rhs[row][col];

    return res;
}

/* ************************************************************************ */

template<typename T1, typename T2, int R, int C>
inline MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> operator*(
    const MatrixBase<T1, R, C>& lhs,
    const T2& rhs
)
{
    MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> res;

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            res[row][col] = lhs[row][col] * rhs;

    return res;
}

/* ************************************************************************ */

template<typename T1, typename T2, int R, int C>
inline MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> operator*(
    const T2& lhs
    const MatrixBase<T1, R, C>& rhs,
)
{
    MatrixBase<decltype(std::declval<T1>() * std::declval<T2>()), R, C> res;

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            res[row][col] = rhs * lhs[row][col];

    return res;
}

/* ************************************************************************ */

template<typename T1, typename T2, int R, int C>
inline MatrixBase<decltype(std::declval<T1>() / std::declval<T2>()), R, C> operator/(
    const MatrixBase<T1, R, C>& lhs,
    const T2& rhs
)
{
    MatrixBase<decltype(std::declval<T1>() + std::declval<T2>()), R, C> res;

    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            res[row][col] = lhs[row][col] / rhs;

    return res;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */

