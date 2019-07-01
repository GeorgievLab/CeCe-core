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
#include "cece/math/Zero.hpp"
#include "cece/math/MatrixBase.hpp"
#include "cece/math/Vector.hpp"
#include "cece/unit/Units.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      2D matrix implementation.
 *
 * @tparam     T     Type of stored value.
 * @tparam     R     Number of rows.
 * @tparam     C     Number of columns.
 */
template<typename T, int R, int C = R>
struct Matrix : public MatrixBase<Matrix, R, C>
{

// Public Types
public:


    /// Row type.
    using RowType = Vector<T, C>;

    /// Column type.
    using ColumnType = Vector<T, R>;


// Public Data Members
public:


    /// Matrix data.
    Vector<RowType, R> m;


// Public Ctors
public:


    /**
     * @brief      Default constructor.
     */
    Matrix();


    /**
     * @brief      Zero constructor.
     *
     * @param[in]  zero  Zero value.
     */
    Matrix(Zero_t zero);


    /**
     * @brief      Constructor.
     *
     * @param      src   Initial data
     */
    Matrix(const T (&src)[R][C]);


    /**
     * @brief      Constructor.
     *
     * @param      src   Initial data
     */
    Matrix(const RowType (&src)[R]);


    /**
     * @brief      Copy constructor.
     *
     * @param      src   Source matrix.
     */
    Matrix(const Matrix& src);


    /**
     * @brief      Move constructor.
     *
     * @param      src   Source matrix.
     */
    Matrix(Matrix&& src);


// Public Operators
public:


    /**
     * @brief      Copy assignment operator.
     *
     * @param      src   The source matrix.
     *
     * @return     *this.
     */
    Matrix& operator=(const Matrix& src);


    /**
     * @brief      Move assignment operator.
     *
     * @param      src   The source matrix.
     *
     * @return     *this.
     */
    Matrix& operator=(Matrix&& src);


    /**
     * @brief      Row access operator.
     *
     * @param[in]  pos   The row number.
     *
     * @return     Row.
     */
    RowType& operator[](int pos) noexcept;


    /**
     * @brief      Row access operator.
     *
     * @param      pos   The row number.
     *
     * @return     Row.
     */
    const RowType& operator[](int pos) const noexcept;


    /**
     * @brief      Element access operator.
     *
     * @param      coord  Coordinates.
     *
     * @return     Element.
     */
    T& operator[](Vector2<int> coord) noexcept;


    /**
     * @brief      Element access operator.
     *
     * @param      coord  Coordinates.
     *
     * @return     Element.
     */
    const T& operator[](Vector2<int> coord) const noexcept;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix()
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix(Zero_t zero)
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = Zero;
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix(const T (&src)[R][C])
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = src[row][col];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix(const RowType (&src)[R])
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = src[row][col];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix(const Matrix& src)
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = src[row][col];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::Matrix(Matrix&& src)
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = std::move(src[row][col]);
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>& Matrix<T, R, C>::operator=(const Matrix& src)
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = src[row][col];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>& Matrix<T, R, C>::operator=(Matrix&& src)
{
    for (int row = 0; row < R; ++row)
        for (int col = 0; col < C; ++col)
            m[row][col] = std::move(src[row][col]);
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline Matrix<T, R, C>::RowType& Matrix<T, R, C>::operator[](int pos) noexcept
{
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline const Matrix<T, R, C>::RowType& Matrix<T, R, C>::operator[](int pos) const noexcept
{
    return m[pos];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline T& Matrix<T, R, C>::operator[](Vector2<int> coord) noexcept
{
    return m[coord.x][coord.y];
}

/* ************************************************************************ */

template<typename T, int R, int C>
inline const T& Matrix<T, R, C>::operator[](Vector2<int> coord) const noexcept
{
    return m[coord.x][coord.y];
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */

