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
#include "cece/math/constants.hpp"
#include "cece/unit/Unit.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

namespace detail {

/* ************************************************************************ */

/**
 * @brief      Square root helper.
 *
 * @tparam     Impl  Implementation detail.
 */
template<typename Impl>
struct SqrtHelper;

/* ************************************************************************ */

/**
 * @brief      Square root helper.
 *
 * @tparam     Length       Number of length units.
 * @tparam     Time         Number of time units.
 * @tparam     Mass         Number of mass units.
 * @tparam     Current      Number of electrical current units.
 * @tparam     Temperature  Number of temperature units.
 * @tparam     Substance    Number of amount of substance units.
 * @tparam     Intensity    Number of intensity units.
 */
template<
    int Length,
    int Time,
    int Mass,
    int Current,
    int Temperature,
    int Substance,
    int Intensity
>
struct SqrtHelper<StaticImpl<
    Length,
    Time,
    Mass,
    Current,
    Temperature,
    Substance,
    Intensity
>>
{

    // Calculate if unit can be used as sqrt argument.
    static constexpr bool isValid =
        Length      % 2 == 0 &&
        Time        % 2 == 0 &&
        Mass        % 2 == 0 &&
        Current     % 2 == 0 &&
        Temperature % 2 == 0 &&
        Substance   % 2 == 0 &&
        Intensity   % 2 == 0
    ;

    using ImplType = StaticImpl<
        Length      / 2,
        Time        / 2,
        Mass        / 2,
        Current     / 2,
        Temperature / 2,
        Substance   / 2,
        Intensity   / 2
    >;
};

/* ************************************************************************ */

}

/* ************************************************************************ */

/**
 * @brief      Calculate square root of given unit.
 *
 * @param[in]  value  The unit value.
 *
 * @tparam     Impl   The unit implementation.
 *
 * @return     The square root value.
 */
template<typename Impl>
auto sqrt(UnitBase<Impl> value) noexcept -> UnitBase<typename detail::SqrtHelper<Impl>::ImplType>;

/* ************************************************************************ */

/**
 * @brief      Calculate absolute value.
 *
 * @param      unit  The unit.
 *
 * @tparam     Impl  The unit implementation.
 *
 * @return     The absolute value.
 */
template<typename Impl>
constexpr UnitBase<Impl> abs(UnitBase<Impl> unit) noexcept;

/* ************************************************************************ */

/**
 * @brief      Convert degrees to radians.
 *
 * @param      value  Degrees.
 *
 * @return     Radians
 */
constexpr ValueType deg2rad(ValueType value) noexcept;

/* ************************************************************************ */

/**
 * @brief      Convert radians to degrees.
 *
 * @param      value  Radians.
 *
 * @return     Degrees.
 */
constexpr ValueType rad2deg(ValueType value) noexcept;

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
inline auto sqrt(UnitBase<Impl> value) noexcept
    -> UnitBase<typename detail::SqrtHelper<Impl>::ImplType>
{
    static_assert(detail::SqrtHelper<Impl>::isValid, "Unit cannot be used as sqrt argument");

    return UnitBase<typename detail::SqrtHelper<Impl>::ImplType>(
        std::sqrt(value.get())
    );
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr UnitBase<Impl> abs(UnitBase<Impl> unit) noexcept
{
    return UnitBase<Impl>(unit.get() > ValueType(0)
        ? unit.get()
        : -unit.get()
    );
}

/* ************************************************************************ */

inline constexpr ValueType deg2rad(ValueType value) noexcept
{
    return value * math::PI / 180.0;
}

/* ************************************************************************ */

inline constexpr ValueType rad2deg(ValueType value) noexcept
{
    return value * 180.0 / math::PI;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
