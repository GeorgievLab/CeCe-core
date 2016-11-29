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
#include "cece/String.hpp"
#include "cece/io/StringStream.hpp"

/* ************************************************************************ */

namespace cece {
namespace io {

/* ************************************************************************ */

/**
 * @brief      Configuration value converter.
 *
 * @tparam     T     Type for conversion.
 */
template<typename T>
struct Converter
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static T fromString(const String& value)
    {
        io::InStringStream iss(value);

        T res;
        iss >> std::noskipws >> std::boolalpha >> res;

        return res;
    }


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(const T& value)
    {
        io::OutStringStream oss;

        oss << std::boolalpha << value;

        return oss.str();
    }

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for boolean values.
 */
template<>
struct Converter<bool>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static bool fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(bool value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for int values.
 */
template<>
struct Converter<int>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static int fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(int value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for int values.
 */
template<>
struct Converter<unsigned int>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static unsigned int fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(unsigned int value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for long values.
 */
template<>
struct Converter<long>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static long fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(long value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for long values.
 */
template<>
struct Converter<unsigned long>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static unsigned long fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(unsigned long value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for float values.
 */
template<>
struct Converter<float>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static float fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(float value) noexcept;

};

/* ************************************************************************ */

/**
 * @brief      Configuration value converter for double values.
 */
template<>
struct Converter<double>
{

    /**
     * @brief      Convert from String to required type.
     *
     * @param[in]  value  The string value.
     *
     * @return     The result value.
     */
    static double fromString(const String& value) noexcept;


    /**
     * @brief      Convert to String from required type.
     *
     * @param[in]  value  The source value.
     *
     * @return     The string value.
     */
    static String toString(double value) noexcept;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
