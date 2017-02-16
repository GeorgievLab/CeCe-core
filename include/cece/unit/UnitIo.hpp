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

// CeCe
#include "cece/Function.hpp"
#include "cece/StringView.hpp"
#include "cece/unit/Unit.hpp"
#include "cece/io/InStream.hpp"
#include "cece/io/OutStream.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

/**
 * @brief      Parse units value.
 *
 * @param[in]  beg   The string beginning.
 * @param      end   The string end. After return it can be used as a pointer
 *                   where the parsing ended.
 *
 * @return     Result value.
 */
Unit parse(const char* beg, const char*& end);

/* ************************************************************************ */

/**
 * @brief      Parse units value.
 *
 * @details    This function can handle unit suffix and convert it into proper
 *             coefficient.
 *
 * @note       Unit prefix is not supported because there is issue with meters:
 *             `mg` - it's milligram or metergram?
 *
 * @param      is    Input stream.
 *
 * @return     Result value.
 */
Unit parse(io::InStream& is);

/* ************************************************************************ */

/**
 * @brief      Parse units value.
 *
 * @details    This function can handle unit suffix and convert it into proper
 *             coefficient.
 *
 * @note       Unit prefix is not supported because there is issue with meters:
 *             `mg` - it's milligram or metergram?
 *
 * @param      value  Value to parse.
 *
 * @return     Result value.
 */
Unit parse(StringView value);

/* ************************************************************************ */

/**
 * @brief      Register user defined symbol converter.
 *
 * @details    Adds user defined symbol so for 'km' when it parse '15km' the
 *             `parse` function invoke given function with argument `15`.
 *
 * @param[in]  name  The symbol name.
 * @param[in]  fn    The conversion function.
 */
void registerSymbol(String name, Function<Unit(ValueType)> fn);

/* ************************************************************************ */

/**
 * @brief      Remove symbol from list.
 *
 * @param[in]  name  The symbol name.
 *
 * @note       If conversion function is provided by plugin it should be
 *             unregistred before the plugin is unloaded because the function
 *             code might be in plugin code and after unload it will not be
 *             available to execute.
 */
void unregisterSymbol(StringView name);

/* ************************************************************************ */

/**
 * @brief      Input stream operator.
 *
 * @param      is    Input stream.
 * @param      unit  Result value.
 *
 * @tparam     Impl  Unit implementation.
 *
 * @return     is.
 */
template<typename Impl>
io::InStream& operator>>(io::InStream& is, UnitBase<Impl>& unit);

/* ************************************************************************ */

/**
 * @brief      Output stream operator.
 *
 * @param      os    Output stream.
 * @param      unit  Input value.
 *
 * @tparam     Impl  The unit implementation.
 *
 * @return     os.
 */
template<typename Impl>
io::OutStream& operator<<(io::OutStream& os, const UnitBase<Impl>& unit) noexcept;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

template<typename Impl>
inline io::InStream& operator>>(io::InStream& is, UnitBase<Impl>& unit)
{
    // Parse unit and convert from dynamic to static or dynamic
    unit = parse(is);

    return is;
}

/* ************************************************************************ */

/**
 * @brief      Output stream operator.
 *
 * @param      os    Output stream.
 * @param      unit  Input value.
 *
 * @tparam     Impl  The unit implementation.
 *
 * @return     os.
 */
template<typename Impl>
inline io::OutStream& operator<<(io::OutStream& os, const UnitBase<Impl>& unit) noexcept
{
    os << unit.get();

    // TODO: write suffix

    return os;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
