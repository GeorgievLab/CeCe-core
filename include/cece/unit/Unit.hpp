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
    constexpr StaticImpl();


    /**
     * @brief      Constructor.
     *
     * @param[in]  value  The value.
     */
    explicit constexpr StaticImpl(ValueType value) noexcept;


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


    /**
     * @brief      Returns the length exponent.
     *
     * @return     The length exponent.
     */
    constexpr int getLengthExp() const noexcept;


    /**
     * @brief      Returns the time exponent.
     *
     * @return     The time exponent.
     */
    constexpr int getTimeExp() const noexcept;


    /**
     * @brief      Returns the mass exponent.
     *
     * @return     The mass exponent.
     */
    constexpr int getMassExp() const noexcept;


    /**
     * @brief      Returns the current exponent.
     *
     * @return     The current exponent.
     */
    constexpr int getCurrentExp() const noexcept;


    /**
     * @brief      Returns the temperature exponent.
     *
     * @return     The temperature exponent.
     */
    constexpr int getTemperatureExp() const noexcept;


    /**
     * @brief      Returns the substance exponent.
     *
     * @return     The substance exponent.
     */
    constexpr int getSubstanceExp() const noexcept;


    /**
     * @brief      Returns the intensity exponent.
     *
     * @return     The intensity exponent.
     */
    constexpr int getIntensityExp() const noexcept;


    /**
     * @brief      Check dynamic implementation.
     *
     * @param[in]  impl  The implementation.
     *
     * @throw      CastException If dynamic cannot be cast to static.
     */
    void checkDynamic(const DynamicImpl& impl) const;

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
    explicit DynamicImpl(ValueType value, Detail detail = {}) noexcept;


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
    DynamicImpl(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept;


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
    DynamicImpl& operator=(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept;


    /**
     * @brief      Returns the length exponent.
     *
     * @return     The length exponent.
     */
    constexpr int getLengthExp() const noexcept;


    /**
     * @brief      Returns the time exponent.
     *
     * @return     The time exponent.
     */
    constexpr int getTimeExp() const noexcept;


    /**
     * @brief      Returns the mass exponent.
     *
     * @return     The mass exponent.
     */
    constexpr int getMassExp() const noexcept;


    /**
     * @brief      Returns the current exponent.
     *
     * @return     The current exponent.
     */
    constexpr int getCurrentExp() const noexcept;


    /**
     * @brief      Returns the temperature exponent.
     *
     * @return     The temperature exponent.
     */
    constexpr int getTemperatureExp() const noexcept;


    /**
     * @brief      Returns the substance exponent.
     *
     * @return     The substance exponent.
     */
    constexpr int getSubstanceExp() const noexcept;


    /**
     * @brief      Returns the intensity exponent.
     *
     * @return     The intensity exponent.
     */
    constexpr int getIntensityExp() const noexcept;

};

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
    constexpr UnitBase() noexcept;


    /**
     * @brief      Constructor.
     *
     * @param      value  Init value.
     */
    template<typename I = Impl,
        typename std::enable_if<
            std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value ||
            std::is_same<I, DynamicImpl>::value,
            int
        >::type = 0
    >
    constexpr UnitBase(ValueType value) noexcept;


    /**
     * @brief      Constructor.
     *
     * @param[in]  args       Construction arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args,
        typename std::enable_if<
            std::is_constructible<Impl, Args...>::value,
            int
        >::type = 0
    >
    explicit constexpr UnitBase(Args&&... args);


    /**
     * @brief      Zero constructor.
     */
    constexpr UnitBase(math::Zero_t) noexcept;


    /**
     * @brief      Constructor.
     *
     * @param[in]  unit   The unit.
     */
    constexpr UnitBase(const UnitBase& unit);


    /**
     * @brief      Constructor.
     *
     * @param[in]  unit   The unit.
     */
    constexpr UnitBase(UnitBase&& unit);


    /**
     * @brief      Constructor.
     *
     * @param[in]  unit   The unit.
     *
     * @tparam     Impl2  The second unit implementation.
     */
    template<typename Impl2>
    constexpr UnitBase(const UnitBase<Impl2>& unit);


    /**
     * @brief      Constructor.
     *
     * @param[in]  unit   The unit.
     *
     * @tparam     Impl2  The second unit implementation.
     */
    template<typename Impl2>
    UnitBase(UnitBase<Impl2>&& unit);


// Public Operators
public:


    /**
     * @brief      Assignment operator.
     *
     * @param[in]  unit   The unit.
     */
    UnitBase& operator=(const UnitBase& unit);


    /**
     * @brief      Assignment operator.
     *
     * @param[in]  unit   The unit.
     */
    UnitBase& operator=(UnitBase&& unit) noexcept;


    /**
     * @brief      Assignment operator.
     *
     * @param[in]  unit   The unit.
     *
     * @tparam     Impl2  The second unit implementation.
     */
    template<typename Impl2>
    UnitBase& operator=(const UnitBase<Impl2>& unit);


    /**
     * @brief      Cast to value type.
     */
    template<typename I = Impl,
        typename std::enable_if<std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type = 0
    >
    operator ValueType() const noexcept;


    /**
     * @brief      Cast to value type.
     */
    template<typename I = Impl,
        typename std::enable_if<!std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type = 0
    >
    explicit operator ValueType() const noexcept;


    /**
     * @brief      Unary plus operator.
     *
     * @return     New value.
     */
    UnitBase operator+() const noexcept;


    /**
     * @brief      Unary minus operator.
     *
     * @return     New value.
     */
    UnitBase operator-() const noexcept;


    /**
     * @brief      Addition operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator+=(UnitBase rhs) noexcept;


    /**
     * @brief      Substraction operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator-=(UnitBase rhs) noexcept;


    /**
     * @brief      Multiplication operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator*=(ValueType rhs) noexcept;


    /**
     * @brief      Division operator.
     *
     * @param      rhs   The right hand side.
     *
     * @return     *this.
     */
    UnitBase& operator/=(ValueType rhs) noexcept;


// Public Accessors
public:


    /**
     * @brief      Returns underlying value.
     *
     * @return     The underlying value.
     */
    constexpr ValueType get() const noexcept;


    /**
     * @brief      Returns underlying value.
     *
     * @return     The underlying value.
     *
     * @deprecated
     */
    constexpr ValueType value() const noexcept;


    /**
     * @brief      Returns the length exponent.
     *
     * @return     The length exponent.
     */
    constexpr int getLengthExp() const noexcept;


    /**
     * @brief      Returns the time exponent.
     *
     * @return     The time exponent.
     */
    constexpr int getTimeExp() const noexcept;


    /**
     * @brief      Returns the mass exponent.
     *
     * @return     The mass exponent.
     */
    constexpr int getMassExp() const noexcept;


    /**
     * @brief      Returns the current exponent.
     *
     * @return     The current exponent.
     */
    constexpr int getCurrentExp() const noexcept;


    /**
     * @brief      Returns the temperature exponent.
     *
     * @return     The temperature exponent.
     */
    constexpr int getTemperatureExp() const noexcept;


    /**
     * @brief      Returns the substance exponent.
     *
     * @return     The substance exponent.
     */
    constexpr int getSubstanceExp() const noexcept;


    /**
     * @brief      Returns the intensity exponent.
     *
     * @return     The intensity exponent.
     */
    constexpr int getIntensityExp() const noexcept;


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
 * @brief      Define empty dynamic detail.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail none() noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension length.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail length(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension time.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail time(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension mass.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail mass(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension current.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail current(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension temperature.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail temperature(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension substance.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail substance(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Define dynamic detail for N-dimension intensity.
 *
 * @param[in]  dim   The dimension.
 *
 * @return     Dynamic implementation detail.
 */
DynamicImpl::Detail intensity(int dim = 1) noexcept;

/* ************************************************************************ */

/**
 * @brief      Merge dynamic implementation detail.
 *
 * @param[in]  lhs   The left hand side.
 * @param[in]  rhs   The right hand side.
 *
 * @return     Result.
 */
DynamicImpl::Detail operator|(DynamicImpl::Detail lhs, DynamicImpl::Detail rhs) noexcept;

/* ************************************************************************ */

/**
 * @brief      Merge dynamic implementation detail.
 *
 * @param[in]  lhs   The left hand side.
 * @param[in]  rhs   The right hand side.
 *
 * @return     Result.
 */
DynamicImpl::Detail operator/(DynamicImpl::Detail lhs, DynamicImpl::Detail rhs) noexcept;

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
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator==(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator!=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator<(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator<=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator>(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept;

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
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept;

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
inline constexpr bool operator>=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept;

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
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::AddImplType>;

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
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::SubImplType>;

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
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::MulImplType>;

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
inline constexpr UnitBase<Impl1> operator*(UnitBase<Impl1> lhs, RealType rhs) noexcept;

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
inline constexpr UnitBase<Impl2> operator*(RealType lhs, UnitBase<Impl2> rhs) noexcept;

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
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::DivImplType>;

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
inline constexpr UnitBase<Impl1> operator/(UnitBase<Impl1> lhs, RealType rhs) noexcept;

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
    -> UnitBase<typename detail::ImplInverter<Impl2>::ImplType>;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
/* ************************************************************************ */
/* ************************************************************************ */

namespace cece {
namespace unit {

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::StaticImpl() = default;

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::StaticImpl(ValueType value) noexcept
    : value(value)
{
    // Check if
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::StaticImpl(const DynamicImpl& impl)
    : value(impl.value)
{
    checkDynamic(impl);
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::operator=(const DynamicImpl& impl)
{
    value = impl.value;

    checkDynamic(impl);

    return *this;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getLengthExp() const noexcept
{
    return Length;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getTimeExp() const noexcept
{
    return Time;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getMassExp() const noexcept
{
    return Mass;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getCurrentExp() const noexcept
{
    return Current;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getTemperatureExp() const noexcept
{
    return Temperature;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getSubstanceExp() const noexcept
{
    return Substance;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline constexpr int StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::getIntensityExp() const noexcept
{
    return Intensity;
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
void StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>::checkDynamic(const DynamicImpl& impl) const
{
    // Non-dimensional zero can be cast to anything
    if (value == 0.0 &&
        impl.detail.length == 0 &&
        impl.detail.time == 0 &&
        impl.detail.mass == 0 &&
        impl.detail.current == 0 &&
        impl.detail.temperature == 0 &&
        impl.detail.substance == 0 &&
        impl.detail.intensity == 0)
        return;

    // Check if can be converted
    if (impl.detail.length != Length)
        throw CastException("Length exponent mismatch: " + toString(impl.detail.length) + " vs " + toString(Length));

    if (impl.detail.time != Time)
        throw CastException("Time exponent mismatch: " + toString(impl.detail.time) + " vs " + toString(Time));

    if (impl.detail.mass != Mass)
        throw CastException("Mass exponent mismatch: " + toString(impl.detail.mass) + " vs " + toString(Mass));

    if (impl.detail.current != Current)
        throw CastException("Current exponent mismatch: " + toString(impl.detail.current) + " vs " + toString(Current));

    if (impl.detail.temperature != Temperature)
        throw CastException("Temperature exponent mismatch: " + toString(impl.detail.temperature) + " vs " + toString(Temperature));

    if (impl.detail.substance != Substance)
        throw CastException("Substance exponent mismatch: " + toString(impl.detail.substance) + " vs " + toString(Substance));

    if (impl.detail.intensity != Intensity)
        throw CastException("Intensity exponent mismatch: " + toString(impl.detail.intensity) + " vs " + toString(Intensity));
}

/* ************************************************************************ */

inline DynamicImpl::DynamicImpl(ValueType value, Detail detail) noexcept
    : value(value)
    , detail(detail)
{
    // Check if
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline DynamicImpl::DynamicImpl(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept
    : value(impl.value)
    , detail{Length, Time, Mass, Current, Temperature, Substance, Intensity}
{
    // Nothing to do
}

/* ************************************************************************ */

template<int Length, int Time, int Mass, int Current, int Temperature, int Substance, int Intensity>
inline DynamicImpl& DynamicImpl::operator=(const StaticImpl<Length, Time, Mass, Current, Temperature, Substance, Intensity>& impl) noexcept
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

/* ************************************************************************ */

inline constexpr int DynamicImpl::getLengthExp() const noexcept
{
    return detail.length;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getTimeExp() const noexcept
{
    return detail.time;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getMassExp() const noexcept
{
    return detail.mass;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getCurrentExp() const noexcept
{
    return detail.current;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getTemperatureExp() const noexcept
{
    return detail.temperature;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getSubstanceExp() const noexcept
{
    return detail.substance;
}

/* ************************************************************************ */

inline constexpr int DynamicImpl::getIntensityExp() const noexcept
{
    return detail.intensity;
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr UnitBase<Impl>::UnitBase() noexcept
    : m_impl()
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
template<typename I, typename std::enable_if<
    std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value ||
    std::is_same<I, DynamicImpl>::value,
    int
>::type>
inline constexpr UnitBase<Impl>::UnitBase(ValueType value) noexcept
    : m_impl(value)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
template<typename... Args, typename std::enable_if<
    std::is_constructible<Impl, Args...>::value,
    int
>::type>
inline constexpr UnitBase<Impl>::UnitBase(Args&&... args)
    : m_impl(std::forward<Args>(args)...)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr UnitBase<Impl>::UnitBase(math::Zero_t) noexcept
    : m_impl()
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr UnitBase<Impl>::UnitBase(const UnitBase& unit)
    : m_impl(unit.m_impl)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr UnitBase<Impl>::UnitBase(UnitBase&& unit)
    : m_impl(unit.m_impl)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
template<typename Impl2>
inline constexpr UnitBase<Impl>::UnitBase(const UnitBase<Impl2>& unit)
    : m_impl(unit.m_impl)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
template<typename Impl2>
inline UnitBase<Impl>::UnitBase(UnitBase<Impl2>&& unit)
    : m_impl(unit.m_impl)
{
    // Nothing to do
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator=(const UnitBase& unit)
{
    m_impl = unit.m_impl;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator=(UnitBase&& unit) noexcept
{
    m_impl = unit.m_impl;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
template<typename Impl2>
inline UnitBase<Impl>& UnitBase<Impl>::operator=(const UnitBase<Impl2>& unit)
{
    m_impl = unit.m_impl;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
template<typename I, typename std::enable_if<std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type>
inline UnitBase<Impl>::operator ValueType() const noexcept
{
    return get();
}

/* ************************************************************************ */

template<typename Impl>
template<typename I, typename std::enable_if<!std::is_same<I, StaticImpl<0, 0, 0, 0, 0, 0, 0>>::value, int>::type>
inline UnitBase<Impl>::operator ValueType() const noexcept
{
    return get();
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl> UnitBase<Impl>::operator+() const noexcept
{
    return UnitBase(m_impl.value);
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl> UnitBase<Impl>::operator-() const noexcept
{
    return UnitBase(-m_impl.value);
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator+=(UnitBase rhs) noexcept
{
    m_impl.value += rhs.m_impl.value;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator-=(UnitBase rhs) noexcept
{
    m_impl.value -= rhs.m_impl.value;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator*=(ValueType rhs) noexcept
{
    m_impl.value *= rhs;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
inline UnitBase<Impl>& UnitBase<Impl>::operator/=(ValueType rhs) noexcept
{
    m_impl.value /= rhs;
    return *this;
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr ValueType UnitBase<Impl>::get() const noexcept
{
    return m_impl.value;
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr ValueType UnitBase<Impl>::value() const noexcept
{
    return get();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getLengthExp() const noexcept
{
    return m_impl.getLengthExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getTimeExp() const noexcept
{
    return m_impl.getTimeExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getMassExp() const noexcept
{
    return m_impl.getMassExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getCurrentExp() const noexcept
{
    return m_impl.getCurrentExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getTemperatureExp() const noexcept
{
    return m_impl.getTemperatureExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getSubstanceExp() const noexcept
{
    return m_impl.getSubstanceExp();
}

/* ************************************************************************ */

template<typename Impl>
inline constexpr int UnitBase<Impl>::getIntensityExp() const noexcept
{
    return m_impl.getIntensityExp();
}

/* ************************************************************************ */

inline DynamicImpl::Detail none() noexcept
{
    return {};
}

/* ************************************************************************ */

inline DynamicImpl::Detail length(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.length = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail time(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.time = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail mass(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.mass = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail current(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.current = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail temperature(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.temperature = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail substance(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.substance = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail intensity(int dim) noexcept
{
    DynamicImpl::Detail detail{};
    detail.intensity = dim;
    return detail;
}

/* ************************************************************************ */

inline DynamicImpl::Detail operator|(DynamicImpl::Detail lhs, DynamicImpl::Detail rhs) noexcept
{
    lhs.length += rhs.length;
    lhs.time += rhs.time;
    lhs.mass += rhs.mass;
    lhs.current += rhs.current;
    lhs.temperature += rhs.temperature;
    lhs.substance += rhs.substance;
    lhs.intensity += rhs.intensity;
    return lhs;
}

/* ************************************************************************ */

inline DynamicImpl::Detail operator/(DynamicImpl::Detail lhs, DynamicImpl::Detail rhs) noexcept
{
    lhs.length -= rhs.length;
    lhs.time -= rhs.time;
    lhs.mass -= rhs.mass;
    lhs.current -= rhs.current;
    lhs.temperature -= rhs.temperature;
    lhs.substance -= rhs.substance;
    lhs.intensity -= rhs.intensity;
    return lhs;
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isRelSupported, "Can't compare those units");

    return std::abs(lhs.get() - rhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator==(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return std::abs(lhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator==(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return std::abs(rhs.get()) < std::numeric_limits<ValueType>::epsilon();
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator!=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator!=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    static_assert(detail::ImplHelper<Impl1, Impl2>::isRelSupported, "Can't compare those units");

    return lhs.get() < rhs.get();
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator<(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return lhs.get() < 0;
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator<(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return 0 < rhs.get();
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator<=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator<=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator>(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator>(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator>(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return operator<(rhs, lhs);
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr bool operator>=(const UnitBase<Impl1>& lhs, math::Zero_t rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr bool operator>=(math::Zero_t lhs, const UnitBase<Impl2>& rhs) noexcept
{
    return !operator<(lhs, rhs);
}

/* ************************************************************************ */

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

template<typename Impl1, typename Impl2>
inline constexpr auto operator*(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::MulImplType>
{
    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::MulImplType>(
        lhs.get() * rhs.get()
    );
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr UnitBase<Impl1> operator*(UnitBase<Impl1> lhs, RealType rhs) noexcept
{
    return lhs *= rhs;
}

/* ************************************************************************ */

template<typename Impl2>
inline constexpr UnitBase<Impl2> operator*(RealType lhs, UnitBase<Impl2> rhs) noexcept
{
    return rhs *= lhs;
}

/* ************************************************************************ */

template<typename Impl1, typename Impl2>
inline constexpr auto operator/(const UnitBase<Impl1>& lhs, const UnitBase<Impl2>& rhs) noexcept
    -> UnitBase<typename detail::ImplHelper<Impl1, Impl2>::DivImplType>
{
    return UnitBase<typename detail::ImplHelper<Impl1, Impl2>::DivImplType>(
        lhs.get() / rhs.get()
    );
}

/* ************************************************************************ */

template<typename Impl1>
inline constexpr UnitBase<Impl1> operator/(UnitBase<Impl1> lhs, RealType rhs) noexcept
{
    return lhs /= rhs;
}

/* ************************************************************************ */

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
