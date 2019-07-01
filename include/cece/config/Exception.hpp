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
#include "cece/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

/**
 * @brief      Configuration exception.
 */
class Exception : public RuntimeException
{
    using RuntimeException::RuntimeException;
};

/* ************************************************************************ */

/**
 * @brief      Not found exception.
 */
class NotFoundException : public Exception
{
    using Exception::Exception;
};

/* ************************************************************************ */

/**
 * @brief      Error when parameter is not properly terminated.
 *
 * @details    Used in cases when the config parameter is not properly
 *             terminated: `{$name`.
 */
class UnterminatedParameterException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  text  The text where the replacement was taken place.
     */
    explicit UnterminatedParameterException(String text);


// Accessors & Mutators
public:


    /**
     * @brief      Returns the text.
     *
     * @return     The text.
     */
    const String& getText() const noexcept
    {
        return m_text;
    }


// Private Data Members
private:

    /// The text.
    String m_text;

};

/* ************************************************************************ */

/**
 * @brief      Invalid parameter name.
 *
 * @details    Used in cases when the config parameter name contains invalid
 *             characters.
 */
class InvalidParameterNameException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  name  The parameter name.
     * @param[in]  text  The text where the replacement was taken place.
     */
    explicit InvalidParameterNameException(String name, String text);


// Accessors & Mutators
public:


    /**
     * @brief      Returns parameter name.
     *
     * @return     The parameter name.
     */
    const String& getName() const noexcept
    {
        return m_name;
    }


    /**
     * @brief      Returns text.
     *
     * @return     The text.
     */
    const String& getText() const noexcept
    {
        return m_text;
    }


// Private Data Members
private:

    /// The parameter name.
    String m_name;

    /// The text.
    String m_text;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */