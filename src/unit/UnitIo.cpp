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
#include "cece/unit/UnitIo.hpp"

// C++
#include <cstdlib>

// CeCe
#include "cece/Exception.hpp"
#include "cece/unit/UnitsCtors.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief      Check if given character can be a part of symbol.
 *
 * @param      c     The tested character.
 *
 * @return     True if symbol character, False otherwise.
 */
bool isSymbolChar(char c) noexcept
{
    return (
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '/')
    );
}

/* ************************************************************************ */

}

/* ************************************************************************ */

Unit parse(const char* beg, const char*& end)
{
    char* fend;

    // Read float value
    const auto value = std::strtod(beg, &fend);

    // Not a float value
    if (fend == beg)
        throw InvalidArgumentException("Cannot parse unit value from: " + String(beg, end));

    String symbol;

    // Store symbol characters
    const char* pSym = fend;
    for (; pSym != end && isSymbolChar(*pSym); ++pSym)
        symbol.push_back(*pSym);

    // No symbol
    if (symbol.empty())
    {
        end = fend;
        return Unit(DynamicImpl(value, DynamicImpl::Detail{}));
    }

    end = pSym;

#define CECE_UNIT_SYMBOL(unit, name, sym, def) if (symbol == sym) return name(value)
#include "cece/unit/Units.def"

    // TODO: dynamic symbol parser

    // Unknown symbol
    throw InvalidArgumentException("Unsupported or invalid unit symbol: " + symbol);
}

/* ************************************************************************ */

Unit parse(io::InStream& is)
{
    String str;
    is >> str;

    return parse(str);
}

/* ************************************************************************ */

Unit parse(StringView str)
{
    const char* end = str.getData() + str.getLength();
    return parse(str.getData(), end);
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
