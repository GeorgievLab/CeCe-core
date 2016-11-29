/* ************************************************************************ */
/* Georgiev Lab (c) 2015-2016                                               */
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
#include <string>

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

/**
 * @brief      String type.
 */
using String = std::string;

/* ************************************************************************ */

/**
 * @brief      Converts integer value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(int value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts long value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(long value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts long long value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(long long value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts unsigned value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(unsigned value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts unsigned long value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(unsigned long value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts unsigned long long value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(unsigned long long value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts float value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(float value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts double value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(double value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts long double value to string.
 *
 * @param      value  Input value.
 *
 * @return     String value.
 */
String toString(long double value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Converts string value to integer.
 *
 * @param      value  Input value.
 *
 * @return     Parsed value.
 *
 * @throws     InvalidArgumentException  String cannot be converted.
 */
int str2i(const String& value);

/* ************************************************************************ */

/**
 * @brief      Converts string value to integer.
 *
 * @param      value  Input value.
 *
 * @return     Parsed value.
 *
 * @throws     InvalidArgumentException  String cannot be converted.
 */
long str2l(const String& value);

/* ************************************************************************ */

/**
 * @brief      Converts string value to integer.
 *
 * @param      value  Input value.
 *
 * @return     Parsed value.
 *
 * @throws     InvalidArgumentException  String cannot be converted.
 */
long long str2ll(const String& value);

/* ************************************************************************ */

/**
 * @brief      Converts string value to integer.
 *
 * @param      value  Input value.
 *
 * @return     Parsed value.
 *
 * @throws     InvalidArgumentException  String cannot be converted.
 */
float str2f(const String& value);

/* ************************************************************************ */

/**
 * @brief      Converts string value to integer.
 *
 * @param      value  Input value.
 *
 * @return     Parsed value.
 *
 * @throws     InvalidArgumentException  String cannot be converted.
 */
double str2d(const String& value);

/* ************************************************************************ */

}

/* ************************************************************************ */
