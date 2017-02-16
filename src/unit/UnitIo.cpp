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
#include "cece/Map.hpp"
#include "cece/Function.hpp"
#include "cece/Pair.hpp"
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
        (c == '/') || (c == '%')
    );
}

/* ************************************************************************ */

#define CECE_UNIT_SYMBOL(unit, name, sym, def) {sym, +[] (ValueType value) -> Unit { return name(value); }},

const Map<String, Function<Unit(ValueType)>> symbols{
#include "cece/unit/Units.def"
};

/* ************************************************************************ */

// User defined symbol parsers
Map<String, Function<Unit(ValueType)>> userSymbols;

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
        return Unit(value);
    }

    end = pSym;

    // Use known symbol
    auto it = symbols.find(symbol);
    if (it != symbols.end())
        return it->second(value);

    auto it2 = userSymbols.find(symbol);
    if (it2 != userSymbols.end())
        return it2->second(value);

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

void registerSymbol(String name, Function<Unit(ValueType)> fn)
{
    userSymbols.emplace(std::move(name), std::move(fn));
}

/* ************************************************************************ */

void unregisterSymbol(StringView name)
{
#if __cplusplus >= 201402L
    userSymbols.erase(name);
#else
    userSymbols.erase(String(name));
#endif
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
