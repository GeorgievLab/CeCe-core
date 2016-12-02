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
#include "cece/UniquePtr.hpp"
#include "cece/log/Logger.hpp"
#include "cece/log/Output.hpp"

/* ************************************************************************ */

namespace cece {
namespace log {

/* ************************************************************************ */

/**
 * @brief      Returns the default logger.
 *
 * @return     The logger.
 */
Logger& get_logger() noexcept;

/* ************************************************************************ */

/**
 * @brief      Returns output.
 *
 * @return     The output.
 */
inline ViewPtr<Output> get_output() noexcept
{
    return get_logger().getOutput();
}

/* ************************************************************************ */

/**
 * @brief      Change output.
 *
 * @param[in]  output  The pointer to output.
 */
inline void set_output(UniquePtr<Output> output) noexcept
{
    return get_logger().setOutput(std::move(output));
}

/* ************************************************************************ */

/**
 * @brief      Log a message.
 *
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void msg(Args&&... args)
{
    get_logger().msg(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log a message.
 *
 * @param[in]  section    Message section.
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void msgS(const String& section, Args&&... args)
{
    get_logger().msgS(section, std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log an info message.
 *
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void info(Args&&... args)
{
    get_logger().info(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log an info message.
 *
 * @param[in]  section    Message section.
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void infoS(const String& section, Args&&... args)
{
    get_logger().infoS(section, std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log a debug message.
 *
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void debug(Args&&... args)
{
    get_logger().debug(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log a debug message.
 *
 * @param[in]  section    Message section.
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void debugS(const String& section, Args&&... args)
{
    get_logger().debugS(section, std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log a warning message.
 *
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void warning(Args&&... args)
{
    get_logger().warning(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log a warning message.
 *
 * @param[in]  section    Message section.
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void warningS(const String& section, Args&&... args)
{
    get_logger().warningS(section, std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log an error message.
 *
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void error(Args&&... args)
{
    get_logger().error(std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Log an error message.
 *
 * @param[in]  section    Message section.
 * @param[in]  args       Log arguments.
 *
 * @tparam     Args       Argument types.
 */
template<typename... Args>
inline void errorS(const String& section, Args&&... args)
{
    get_logger().errorS(section, std::forward<Args>(args)...);
}

/* ************************************************************************ */

/**
 * @brief      Logging main interface.
 *
 * @deprecated
 */
class Log
{

// Public Accessors & Mutators
public:


    /**
     * @brief      Returns output.
     *
     * @return     The output.
     */
    static ViewPtr<Output> getOutput() noexcept
    {
        return get_output();
    }


    /**
     * @brief      Change output.
     *
     * @param[in]  output  The pointer to output.
     */
    static void setOutput(UniquePtr<Output> output) noexcept
    {
        set_output(std::move(output));
    }


// Public Operators
public:


    /**
     * @brief      Log an info message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    static void info(Args&&... args)
    {
        log::info(std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a debug message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    static void debug(Args&&... args)
    {
        log::debug(std::forward<Args>(args)...);
    }


    /**
     * @brief      Log a warning message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    static void warning(Args&&... args)
    {
        log::warning(std::forward<Args>(args)...);
    }


    /**
     * @brief      Log an error message.
     *
     * @param[in]  args       Log arguments.
     *
     * @tparam     Args       Argument types.
     */
    template<typename... Args>
    static void error(Args&&... args)
    {
        log::error(std::forward<Args>(args)...);
    }

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
