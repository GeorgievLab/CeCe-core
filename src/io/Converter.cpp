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

// Declaration
#include "cece/io/Converter.hpp"

// CeCe
#include "cece/String.hpp"

/* ************************************************************************ */

namespace cece {
namespace io {

/* ************************************************************************ */

bool Converter<bool>::fromString(const String& value) noexcept
{
    return value == "true";
}

/* ************************************************************************ */

String Converter<bool>::toString(bool value) noexcept
{
    return value ? "true" : "false";
}

/* ************************************************************************ */

int Converter<int>::fromString(const String& value)
{
    return str2i(value);
}

/* ************************************************************************ */

String Converter<int>::toString(int value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

unsigned int Converter<unsigned int>::fromString(const String& value)
{
    return str2i(value);
}

/* ************************************************************************ */

String Converter<unsigned int>::toString(unsigned int value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

long Converter<long>::fromString(const String& value)
{
    return str2l(value);
}

/* ************************************************************************ */

String Converter<long>::toString(long value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

unsigned long Converter<unsigned long>::fromString(const String& value)
{
    return str2ll(value);
}

/* ************************************************************************ */

String Converter<unsigned long>::toString(unsigned long value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

float Converter<float>::fromString(const String& value)
{
    return str2f(value);
}

/* ************************************************************************ */

String Converter<float>::toString(float value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

double Converter<double>::fromString(const String& value)
{
    return str2d(value);
}

/* ************************************************************************ */

String Converter<double>::toString(double value) noexcept
{
    return cece::toString(value);
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
