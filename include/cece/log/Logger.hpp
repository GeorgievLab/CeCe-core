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
#include "cece/ViewPtr.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/io/StringStream.hpp"
#include "cece/log/Severity.hpp"

/* ************************************************************************ */

namespace cece {
namespace log {

/* ************************************************************************ */

class Output;

/* ************************************************************************ */

/**
 * @brief      The message logger.
 */
class Logger
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  output  The output.
     */
    explicit Logger(UniquePtr<Output> output) noexcept
        : m_output(std::move(output))
    {
        // Nothing to do
    }


// Public Accessors & Mutators
public:


    /**
     * @brief      Get the logger output.
     *
     * @return     The output.
     */
    ViewPtr<Output> getOutput() const noexcept
    {
        return makeView(m_output);
    }


    /**
     * @brief      Change default output.
     *
     * @param[in]  output  The pointer to output.
     */
    void setOutput(UniquePtr<Output> output) noexcept
    {
        m_output = std::move(output);
    }


// Public Operators
public:


    /**
     * @brief      Log a default message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void msg(Args&&... args)
    {
        message(Severity::Default, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a default message.
     *
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void msgS(const String& section, Args&&... args)
    {
        messageS(Severity::Default, section, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log an info message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void info(Args&&... args)
    {
        message(Severity::Info, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log an info message.
     *
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void infoS(const String& section, Args&&... args)
    {
        messageS(Severity::Info, section, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a debug message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void debug(Args&&... args)
    {
        message(Severity::Debug, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a debug message.
     *
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void debugS(const String& section, Args&&... args)
    {
        messageS(Severity::Debug, section, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a warning message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void warning(Args&&... args)
    {
        message(Severity::Warning, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a warning message.
     *
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void warningS(const String& section, Args&&... args)
    {
        messageS(Severity::Warning, section, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log an error message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void error(Args&&... args)
    {
        message(Severity::Error, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log an error message.
     *
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void errorS(const String& section, Args&&... args)
    {
        messageS(Severity::Error, section, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a message.
     *
     * @param[in]  severity   Message severity.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void message(Severity severity, Args&&... args)
    {
        messageS(severity, {}, std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a message.
     *
     * @param[in]  severity   Message severity.
     * @param[in]  section    Message section.
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    void messageS(Severity severity, const String& section, Args&&... args)
    {
        io::OutStringStream oss;
        buildMessage(oss, std::forward<Args>(args)...);
        writeMessage(severity, section, oss.str());
    }


// Private Operations
private:


    /**
     * @brief      Write a message.
     *
     * @param[in]  severity  The message severity.
     * @param[in]  section   The message section.
     * @param[in]  msg       The message.
     */
    void writeMessage(Severity severity, const String& section, const String& msg);


    /**
     * @brief      Build a message.
     *
     * @param      stream  The output stream.
     */
    static void buildMessage(io::OutStringStream& stream)
    {
        // Nothing to do
    }


    /**
     * @brief      Build a message.
     *
     * @param      stream     The output stream.
     * @param[in]  arg        The fist argument.
     * @param[in]  args       The remaining arguments.
     *
     * @tparam     Arg        Type of the first argument.
     * @tparam     Args       Types of the remaining arguments.
     */
    template<typename Arg, typename... Args>
    static void buildMessage(io::OutStringStream& stream, Arg&& arg, Args&&... args)
    {
        stream << arg;
        buildMessage(stream, std::forward<Args>(args)...);
    }


// Private Data Members
private:

    /// Standard output.
    UniquePtr<Output> m_output;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
