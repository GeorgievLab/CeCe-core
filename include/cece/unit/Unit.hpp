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
#include <cmath>
#include <limits>
#include <type_traits>

// CeCe
#include "cece/common.hpp"
#include "cece/String.hpp"
#include "cece/math/Zero.hpp"
#include "cece/unit/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

/// Underlying type for units.
using ValueType = RealType;

/* ************************************************************************ */

struct DynamicImpl;

/* ************************************************************************ */

/**
 * @brief      Unit type static implementation.
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
struct StaticImpl
{

    /// Stored value.
    ValueType value{};


    /**
     * @brief      Default constructor.
     */
    StaticImpl() = default;


    /**
     * @brief      Constructor.
     *
     * @param[in]  value  The value.
     */
    explicit StaticImpl(ValueType value) noexcept
        : value(value)
    {
        // Check if
    }


    /**
     * @brief      Construct from dynamic implementation.
     *
     * @param[in]  impl  The implementation.
     */
    StaticImpl(const DynamicImpl& impl);


    /**
     * @brief      Assign from dynamic implementation.
     *
     * @param[in]  impl  The implementation.
     */
    StaticImpl& operator=(const DynamicImpl& impl);

};

/* ************************************************************************ */

/**
 * @brief      Unit type dynamic implementation.
 */
struct DynamicImpl
{

    struct Detail
    {
        int length      : 4;  // -7, 7
        int time        : 4;
        int mass        : 4;
        int current     : 4;
        int temperature : 4;
        int substance   : 4;
        int intensity   : 4;
    };


    /// Stored value.
    ValueType value{};

    /// Runtime detail.
    Detail detail{};


    /**
     * @brief      Default constructor.
     */
    DynamicImpl() = default;


    /**
     * @brief      Constructor.
     *
     * @param[in]  value   The value.
     * @param[in]  detail  The detail.
     */
    explicit DynamicImpl(ValueType value, Detail detail = {}) noexcept
        : value(value)
        , detail{detail}
    {
        // Check if
    }


    /**
     * @brief      Construct from static implementation.
     *
     * @param[in]  impl  The implementation.
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
    DynamicImpl(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept
        : value(impl.value)
        , detail{Length, Time, Mass, Current, Temperature, Substance, Intensity}
    {
        // Nothing to do
    }


    /**
     * @brief      Assign from static implementation.
     *
     * @param[in]  impl  The implementation.
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
    DynamicImpl& operator=(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept
    {
        value = impl.value;
        detail.length = Length;
        detail.time = Time;
        detail.mass = Mass;
        detail.current = Current;
        detail.temperature = Temperature;
        detail.substance = Substance;
        detail.intensity = Intensity;
        return *this;
    }

};

/* ************************************************************************ */

template<
    int Length,
    int Time,
    int Mass,
    int Current,
    int Temperature,
    int Substance,
    int Intensity
>
StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::StaticImpl(const DynamicImpl& impl)
    : value(impl.value)
{
    // Check if can be converted
    if (impl.detail.length != Length)
        throw Exception("Length exponent mismatch: " + toString(impl.detail.length) + " vs " + toString(Length));

    if (impl.detail.time != Time)
        throw Exception("Time exponent mismatch: " + toString(impl.detail.time) + " vs " + toString(Time));

    if (impl.detail.mass != Mass)
        throw Exception("Mass exponent mismatch: " + toString(impl.detail.mass) + " vs " + toString(Mass));

    if (impl.detail.current != Current)
        throw Exception("Current exponent mismatch: " + toString(impl.detail.current) + " vs " + toString(Current));

    if (impl.detail.temperature != Temperature)
        throw Exception("Temperature exponent mismatch: " + toString(impl.detail.temperature) + " vs " + toString(Temperature));

    if (impl.detail.substance != Substance)
        throw Exception("Substance exponent mismatch: " + toString(impl.detail.substance) + " vs " + toString(Substance));

    if (impl.detail.intensity != Intensity)
        throw Exception("Intensity exponent mismatch: " + toString(impl.detail.intensity) + " vs " + toString(Intensity));
}

/* ************************************************************************ */

template<
    int Length,
    int Time,
    int Mass,
    int Current,
    int Temperature,
    int Substance,
    int Intensity
>
StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>&
StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::operator=(const DynamicImpl& impl)
{
    value = impl.value;

    // Check if can be converted
    if (impl.detail.length != Length)
        throw Exception("Length exponent mismatch: " + toString(impl.detail.length) + " vs " + toString(Length));

    if (impl.detail.time != Time)
        throw Exception("Time exponent mismatch: " + toString(impl.detail.time) + " vs " + toString(Time));

    if (impl.detail.mass != Mass)
        throw Exception("Mass exponent mismatch: " + toString(impl.detail.mass) + " vs " + toString(Mass));

    if (impl.detail.current != Current)
        throw Exception("Current exponent mismatch: " + toString(impl.detail.current) + " vs " + toString(Current));

    if (impl.detail.temperature != Temperature)
        throw Exception("Temperature exponent mismatch: " + toString(impl.detail.temperature) + " vs " + toString(Temperature));

    if (impl.detail.substance != Substance)
        throw Exception("Substance exponent mismatch: " + toString(impl.detail.substance) + " vs " + toString(Substance));

    if (impl.detail.intensity != Intensity)
        throw Exception("Intensity exponent mismatch: " + toString(impl.detail.intensity) + " vs " + toString(Intensity));

    return *this;
}

/* ************************************************************************ */

namespace detail {

/* ************************************************************************ */

/**
 * @brief      Implementations helper.
 *
 * @tparam     Impl1  The first implementation.
 * @tparam     Impl2  The second implementation.
 */
template<typename Impl1, typename Impl2>
struct ImplHelper;

/* ************************************************************************ */

/**
 * @brief      Implementation helper for 2 static implementations.
 *
 * @tparam     Length1       Number of length units.
 * @tparam     Time1         Number of time units.
 * @tparam     Mass1         Number of mass units.
 * @tparam     Current1      Number of electrical current units.
 * @tparam     Temperature1  Number of temperature units.
 * @tparam     Substance1    Number of amount of substance units.
 * @tparam     Intensity1    Number of intensity units.
 * @tparam     Length2       Number of length units.
 * @tparam     Time2         Number of time units.
 * @tparam     Mass2         Number of mass units.
 * @tparam     Current2      Number of electrical current units.
 * @tparam     Temperature2  Number of temperature units.
 * @tparam     Substance2    Number of amount of substance units.
 * @tparam     Intensity2    Number of intensity units.
 */
template<
    int Length1,
    int Time1,
    int Mass1,
    int Current1,
    int Temperature1,
    int Substance1,
    int Intensity1,
    int Length2,
    int Time2,
    int Mass2,
    int Current2,
    int Temperature2,
    int Substance2,
    int Intensity2
>
struct ImplHelper<
    StaticImpl<
        Length1,
        Time1,
        Mass1,
        Current1,
        Temperature1,
        Substance1,
        Intensity1
    >, StaticImpl<
        Length2,
        Time2,
        Mass2,
        Current2,
        Temperature2,
        Substance2,
        Intensity2
    >
>
{
    /// If relational operations are supported
    static constexpr bool isRelSupported =
        Length1         == Length2 &&
        Time1           == Time2 &&
        Mass1           == Mass2 &&
        Current1        == Current2 &&
        Temperature1    == Temperature2 &&
        Substance1      == Substance2 &&
        Intensity1      == Intensity2
    ;

    /// If addition is supported
    static constexpr bool isAddSupported =
        Length1         == Length2 &&
        Time1           == Time2 &&
        Mass1           == Mass2 &&
        Current1        == Current2 &&
        Temperature1    == Temperature2 &&
        Substance1      == Substance2 &&
        Intensity1      == Intensity2
    ;

    /// If subtraction is supported
    static constexpr bool isSubSupported = isAddSupported;

    /// Addition result implementation (only valid when `isAddSupported == true`)
    using AddImplType = StaticImpl<
        Length1,
        Time1,
        Mass1,
        Current1,
        Temperature1,
        Substance1,
        Intensity1
    >;

    /// Subtraction result implementation (only valid when `isSubSupported == true`)
    using SubImplType = StaticImpl<
        Length1,
        Time1,
        Mass1,
        Current1,
        Temperature1,
        Substance1,
        Intensity1
    >;

    /// Multiplicate result implementation.
    using MulImplType = StaticImpl<
        Length1         + Length2,
        Time1           + Time2,
        Mass1           + Mass2,
        Current1        + Current2,
        Temperature1    + Temperature2,
        Substance1      + Substance2,
        Intensity1      + Intensity2
    >;

    /// Divide result implementation.
    using DivImplType = StaticImpl<
        Length1         - Length2,
        Time1           - Time2,
        Mass1           - Mass2,
        Current1        - Current2,
        Temperature1    - Temperature2,
        Substance1      - Substance2,
        Intensity1      - Intensity2
    >;

};

/* ************************************************************************ */

/**
 * @brief      Implementations inverter.
 *
 * @tparam     Impl  The implementation.
 */
template<typename Impl>
struct ImplInverter
{
    using ImplType = Impl;
};

/* ************************************************************************ */

/**
 * @brief      Implementations inverter.
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
struct ImplInverter<StaticImpl<
    Length,
    Time,
    Mass,
    Current,
    Temperature,
    Substance,
    Intensity
>>
{
    using ImplType = StaticImpl<
        -Length,
        -Time,
        -Mass,
        -Current,
        -Temperature,
        -Substance,
        -Intensity
    >;
};

/* ************************************************************************ */

}

/* ************************************************************************ */

/**
 * @brief      SI Unit.
 *
 * @tparam     Impl  Unit implementation: `StaticImpl` or `DynamicImpl`.
 */
template<typename Impl>
class UnitBase
{
    template<class T> friend class UnitBase;

// Public Ctors & Dtors
public:


    /**
     * @brief      Default constructor.
     */
    constexpr UnitBase() noexcept
        : m_impl{}
    {
        // Nothing to do
    }


    /**
     * @brief      Constructor.
     *
     * @param[in]  impl  The implementation.
     */
    constexpr UnitBase(Impl impl) noexcept
        : m_impl{impl}
    {
        // Nothing to do
    }


    /**
     * @brief      Constructor.
     *
     * @param      value  Init value.
     */
    template<typename I = Impl,
        typename std::enable_if<
            std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value ||
            std::is_same<I, DynamicImpl>::value,
        int>::type = 0
    >
    constexpr UnitBase(ValueType value) noexcept
        : m_impl{value}
    {
        // Nothing to do
    }


    /**
     * @brief      Constructor.
     *
     * @param      value  Init value.
     */
    template<typename I = Impl,
        typename std::enable_if<!(
            std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value ||
            std::is_same<I, DynamicImpl>::value),
        int>::type = 0
    >
    explicit constexpr UnitBase(ValueType value) noexcept
        : m_impl{value}
    {
        // Nothing to do
    }


    /**
     * @brief      Zero constructor.
     */
    constexpr UnitBase(math::Zero_t) noexcept
        : m_impl{}
    {
        // Nothing to do
    }


    /**
     * @brief      Constructor.
     *
     * @param[in]  unit   The unit.
     *
     * @tparam     Impl2  The second unit implementation.
     */
    template<typename Impl2>
    UnitBase(const UnitBase<Impl2>& unit)
        : m_impl(unit.m_impl)
    {
        // Nothing to do
    }


// Public Operators
public:


    /**
     * @brief      Assignment operator.
     *
     * @param[in]  unit   The unit.
     *
     * @tparam     Impl2  The second unit implementation.
     */
    template<typename Impl2>
    UnitBase& operator=(const UnitBase<Impl2>& unit)
    {
        m_impl = unit.m_impl;
        return *this;
    }


    /**
     * @brief      If value is set operator.
     */
    explicit operator bool() const noexcept
    {
        return get() != ValueType(0.0);
    }


    /**
     * @brief      Cast to value type.
     */
    template<typename I = Impl,
        typename std::enable_if<std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type = 0
    >
    operator ValueType() const noexcept
    {
        return get();
    }


    /**
     * @brief      Cast to value type.
     */
    template<typename I = Impl,
        typename std::enable_if<!std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type = 0
    >
    explicit operator ValueType() const noexcept
    {
        return get();
    }


    /**
     * @brief      Unary plus operator.
     *
     * @return     New value.
     */
    UnitBase operator+() const noexcept
    {
        return UnitBase(m_impl.value);
    }


    /**
     * @brief      Unary minus operator.
     *
     * @return     New value.
     */
    UnitBase operator-() const noexcept
    {
        return UnitBase(-m_impl.value);
    }


    /**
     * @brief      Addition operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator+=(UnitBase rhs) noexcept
    {
        m_impl.value += rhs.m_impl.value;
        return *this;
    }


    /**
     * @brief      Substraction operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator-=(UnitBase rhs) noexcept
    {
        m_impl.value -= rhs.m_impl.value;
        return *this;
    }


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator*=(ValueType rhs) noexcept
    {
        m_impl.value *= rhs;
        return *this;
    }


    /**
     * @brief      Division operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator/=(ValueType rhs) noexcept
    {
        m_impl.value /= rhs;
        return *this;
    }


// Public Accessors
public:


    /**
     * @brief      Returns underlying value.
     *
     * @return     The underlying value.
     */
    constexpr ValueType get() const noexcept
    {
        return m_impl.value;
    }


    /**
     * @brief      Returns underlying value.
     *
     * @return     The underlying value.
     *
     * @deprecated
     */
    constexpr ValueType value() const noexcept
    {
        return get();
    }


// Private Data Members
private:

    /// Unit implementation.
    Impl m_impl;

};

/* ************************************************************************ */

/**
 * @brief      Default unit is dynamic.
 */
using Unit = UnitBase<DynamicImpl>;

/* ************************************************************************ */

/**
 * @brief      Sum index values.
 *
 * @tparam     Values  The values to sum.
 */
template<int... Values>
struct ComposeSum;

/* ************************************************************************ */

/**
 * @brief      Sum index values.
 *
 * @tparam     Value   The first value.
 * @tparam     Values  The remaining values.
 */
template<int Value, int... Values>
struct ComposeSum<Value, Values...>
{
    /// Result sum value
    static constexpr int value = Value + ComposeSum<Values...>::value;
};

/* ************************************************************************ */

/**
 * @brief      Sum index values.
 *
 * @tparam     Value   The last value.
 */
template<int Value>
struct ComposeSum<Value>
{
    /// Result sum value
    static constexpr int value = Value;
};

/* ************************************************************************ */

/**
 * @brief      Compose unit types.
 *
 * @tparam     Impls  Implementations.
 */
template<typename... Impls>
struct Compose;

/* ************************************************************************ */

/**
 * @brief      Compose unit types.
 *
 * @tparam     Lengths       A list of lengths.
 * @tparam     Times         A list of times.
 * @tparam     Masses        A list of masses.
 * @tparam     Currents      A list of currents.
 * @tparam     Temperatures  A list of temperatures.
 * @tparam     Substances    A list of substances.
 * @tparam     Intensities   A list of intensities.
 */
template<
    int... Lengths,
    int... Times,
    int... Masses,
    int... Currents,
    int... Temperatures,
    int... Substances,
    int... Intensities
>
struct Compose<UnitBase<StaticImpl<Lengths, Times, Masses, Currents, Temperatures, Substances, Intensities>>...>
{
    using type = UnitBase<StaticImpl<
        ComposeSum<Lengths...>::value,
        ComposeSum<Times...>::value,
        ComposeSum<Masses...>::value,
        ComposeSum<Currents...>::value,
        ComposeSum<Temperatures...>::value,
        ComposeSum<Substances...>::value,
        ComposeSum<Intensities...>::value
    >>;
};

/* ************************************************************************ */

/**
 * @brief      Equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isRelSupported, "Can't compare those units");

    return std::abs(lhs.get() - rhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

/**
 * @brief      Equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return std::abs(lhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

/**
 * @brief      Equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator==(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return std::abs(rhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

/**
 * @brief      Not equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Not equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Not equal operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator!=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Less than operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isRelSupported, "Can't compare those units");

    return lhs.get() < rhs.get();
}

/* ************************************************************************ */

/**
 * @brief      Less than operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return lhs.get() < 0;
}

/* ************************************************************************ */

/**
 * @brief      Less than operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator<(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return 0 < rhs.get();
}

/* ************************************************************************ */

/**
 * @brief      Less equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Less equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Less equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator<=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater operator.
 *
 * @param      rhs    Right operand.
 * @param      lhs    Left operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater operator.
 *
 * @param      rhs    Right operand.
 * @param      lhs    Left operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater operator.
 *
 * @param      rhs    Right operand.
 * @param      lhs    Left operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator>(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Greater equals operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr bool operator>=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Addition operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr auto operator+(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::AddImplType>
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isAddSupported, "Can't add those units");

    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::AddImplType>(
        lhs.get() + rhs.get()
    );
}

/* ************************************************************************ */

/**
 * @brief      Substraction operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr auto operator-(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::SubImplType>
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isSubSupported, "Can't subtract those units");

    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::SubImplType>(
        lhs.get() - rhs.get()
    );
}

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr auto operator*(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::MulImplType>
{
    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::MulImplType>(
        lhs.get() * rhs.get()
    );
}

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr UnitBase<Impl1> operator*(UnitBase<Impl1> lhs, RealType rhs) noexcept
{
    return lhs *= rhs;
}

/* ************************************************************************ */

/**
 * @brief      Multiplication operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr UnitBase<Impl2> operator*(RealType lhs, UnitBase<Impl2> rhs) noexcept
{
    return rhs *= lhs;
}

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The first unit implementation.
 * @tparam     Impl2  The second unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1, typename Impl2>
inline constexpr auto operator/(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::DivImplType>
{
    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::DivImplType>(
        lhs.get() / rhs.get()
    );
}

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl1  The unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl1>
inline constexpr UnitBase<Impl1> operator/(UnitBase<Impl1> lhs, RealType rhs) noexcept
{
    return lhs /= rhs;
}

/* ************************************************************************ */

/**
 * @brief      Division operator.
 *
 * @param      lhs    Left operand.
 * @param      rhs    Right operand.
 *
 * @tparam     Impl2  The unit implementation.
 *
 * @return     Result value.
 */
template<typename Impl2>
inline constexpr auto operator/(RealType lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplInverter<Impl2>::ImplType>
{
    return UnitBase<typename detail::ImplInverter<Impl2>::ImplType>(lhs / rhs.get());
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
