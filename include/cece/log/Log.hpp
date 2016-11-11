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
#include "cece/export.hpp"
#include "cece/String.hpp"
#include "cece/io/OutStream.hpp"
#include "cece/io/StringStream.hpp"
#include "cece/io/CliColor.hpp"

/* ************************************************************************ */

namespace cece {
namespace log {

/* ************************************************************************ */

/**
 * @brief Logging class.
 */
class Log
{

// Public Enums
public:


    /**
     * @brief Log message types.
     */
    enum class Type
    {
        Default,
        Info,
        Warning,
        Error,
        Debug
    };


// Public Classes
public:


    /**
     * @brief Output class that handles log output.
     */
    class Output
    {
    // Public Ctors & Dtors
    public:

        /**
         * @brief Destructor.
         */
        virtual ~Output();

    // Public Operations
    public:

        /**
         * @brief Write a message to output.
         *
         * @param type    Message type.
         * @param section Message section.
         * @param msg     Message to log.
         */
        virtual void write(Type type, const String& section, const String& msg) = 0;
    };


    /**
     * @brief Output for output streams.
     */
    class StreamOutput : public Output
    {
    // Public Ctors & Dtors
    public:

        /**
         * @brief Constructor.
         *
         * @param os
         */
        explicit StreamOutput(io::OutStream* os) : m_os(os) {}


        /**
         * @brief Destructor.
         */
        ~StreamOutput();

    // Public Operations
    public:

        /**
         * @brief Write a message to output.
         *
         * @param type    Message type.
         * @param section Message section.
         * @param msg     Message to log.
         */
        void write(Type type, const String& section, const String& msg) override;

    // Private Data Members
    private:

        /// Output stream.
        io::OutStream* m_os;
    };


// Public Mutators
public:


    /**
     * @brief Set output stream.
     *
     * @param os
     */
    static void setOutput(Output* os) noexcept
    {
        s_output = os;
    }


    /**
     * @brief Set error stream.
     *
     * @param os
     */
    static void setError(Output* os) noexcept
    {
        s_error = os;
    }


// Public Operators
public:


    /**
     * @brief Log info message.
     *
     * @param args
     */
    template<typename... Args>
    static void info(Args&&... args)
    {
        if (s_output)
        {
            io::OutStringStream oss;
            message(oss, std::forward<Args>(args)...);
            s_output->write(Type::Info, String{}, oss.str());
        }
    }


    /**
     * @brief Log debug message.
     *
     * @param args
     */
    template<typename... Args>
    static void debug(Args&&... args)
    {
#ifndef NDEBUG
        if (s_output)
        {
            io::OutStringStream oss;
            message(oss, std::forward<Args>(args)...);
            s_output->write(Type::Debug, String{}, oss.str());
        }
#endif
    }


    /**
     * @brief Log warning message.
     *
     * @param args
     */
    template<typename... Args>
    static void warning(Args&&... args)
    {
        if (s_output)
        {
            io::OutStringStream oss;
            message(oss, std::forward<Args>(args)...);
            s_output->write(Type::Warning, String{}, oss.str());
        }
    }


    /**
     * @brief Log error message.
     *
     * @param args
     */
    template<typename... Args>
    static void error(Args&&... args)
    {
        if (s_error)
        {
            io::OutStringStream oss;
            message(oss, std::forward<Args>(args)...);
            s_error->write(Type::Error, String{}, oss.str());
        }
    }


// Private Operations
private:


    /**
     * @brief Log message.
     */
    static void message(io::OutStream& os)
    {
        // Nothing to do
    }


    /**
     * @brief Log message.
     *
     * @param args
     */
    template<typename Arg, typename... Args>
    static void message(io::OutStream& os, Arg&& arg, Args&&... args)
    {
        os << arg;
        message(os, std::forward<Args>(args)...);
    }


// Private Data Members
private:

    /// Standard output.
    static CECE_EXPORT Output* s_output;

    /// Error output.
    static CECE_EXPORT Output* s_error;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
