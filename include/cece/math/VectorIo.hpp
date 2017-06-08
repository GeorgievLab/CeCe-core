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
#include "cece/common.hpp"
#include "cece/Assert.hpp"
#include "cece/io/InStream.hpp"
#include "cece/io/OutStream.hpp"
#include "cece/math/VectorBase.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

/**
 * @brief      Input stream operator.
 *
 * @param      is          Input stream.
 * @param      vector      Result value.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T           Type of value.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Input stream.
 */
template<template<typename, int...> typename VectorType, typename T, int... Tags>
io::InStream& operator>>(io::InStream& is, VectorType<T, Tags...>& vector);

/* ************************************************************************ */

/**
 * @brief      Output stream operator.
 *
 * @param      os          Output stream.
 * @param      vector      Input value.
 *
 * @tparam     VectorType  Vector type.
 * @tparam     T           Type of value.
 * @tparam     Tags        Vector type tags.
 *
 * @return     Output stream.
 */
template<template<typename, int...> typename VectorType, typename T, int... Tags>
io::OutStream& operator<<(io::OutStream& os, const VectorType<T, Tags...>& vector);

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
inline io::InStream& operator>>(io::InStream& is, VectorType<T, Tags...>& vector)
{
    // Read all elements
    for (int i = 0; i < vector.getSize(); ++i)
    {
        // Unable to read element
        if (!(is >> std::skipws >> vector[i]))
            break;
    }

    return is;
}

/* ************************************************************************ */

template<template<typename, int...> typename VectorType, typename T, int... Tags>
inline io::OutStream& operator<<(io::OutStream& os, const VectorType<T, Tags...>& vector)
{
    for (int i = 0; i < vector.getSize(); ++i)
    {
        if (i != 0)
            os << " ";

        os << vector[i];
    }

    return os;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
