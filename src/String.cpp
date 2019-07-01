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
#include "cece/String.hpp"

// C++
#include <cstdio>
#include <cstdlib>

// CeCe
#include "cece/Assert.hpp"
#include "cece/Exception.hpp"

/* ************************************************************************ */

namespace cece {

/* ************************************************************************ */

String toString(int value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%d", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(long value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%ld", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(long long value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%lld", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(unsigned value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%u", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(unsigned long value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%lu", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(unsigned long long value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%llu", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(float value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%f", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(double value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%f", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

String toString(long double value) noexcept
{
    char buffer[64];
    const int count = std::snprintf(buffer, sizeof buffer, "%Lf", value);
    CECE_ASSERT(count > 0);
    CECE_ASSERT(count <= static_cast<int>(sizeof buffer));
    return String(buffer, count);
}

/* ************************************************************************ */

int str2i(const String& value)
{
    char* end;
    int val = std::strtol(value.c_str(), &end, 10);

    if (value.empty() || end != value.c_str() + value.size())
        throw InvalidArgumentException("Cannot convert '" + value + "' to int");

    return val;
}

/* ************************************************************************ */

long str2l(const String& value)
{
    char* end;
    long val = std::strtol(value.c_str(), &end, 10);

    if (value.empty() || end != value.c_str() + value.size())
        throw InvalidArgumentException("Cannot convert '" + value + "' to long");

    return val;
}

/* ************************************************************************ */

long long str2ll(const String& value)
{
    char* end;
    long long val = std::strtoll(value.c_str(), &end, 10);

    if (value.empty() || end != value.c_str() + value.size())
        throw InvalidArgumentException("Cannot convert '" + value + "' to long long");

    return val;
}

/* ************************************************************************ */

float str2f(const String& value)
{
    char* end;
    float val = std::strtof(value.c_str(), &end);

    if (value.empty() || end != value.c_str() + value.size())
        throw InvalidArgumentException("Cannot convert '" + value + "' to float");

    return val;
}

/* ************************************************************************ */

double str2d(const String& value)
{
    char* end;
    double val = std::strtod(value.c_str(), &end);

    if (value.empty() || end != value.c_str() + value.size())
        throw InvalidArgumentException("Cannot convert '" + value + "' to double");

    return val;
}

/* ************************************************************************ */

}

/* ************************************************************************ */