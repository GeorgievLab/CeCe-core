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

// GTest
#include "gtest/gtest.h"

// C++
#ifndef _WIN32
#include <regex>
#include <iterator>
#endif

// CeCe
#include "cece/String.hpp"
#include "cece/log/Log.hpp"

/* ************************************************************************ */

using namespace cece;

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief      Strips Linux color codes.
 *
 * @param[in]  str   The string
 *
 * @return     str without color codes.
 */
String stripcolor(String str)
{
#ifndef _WIN32
    // \x1B\[([0-9]{1,2}(;[0-9]{1,2})?)?[mGK]
    String res;

    std::regex re("\\x1B\\[([0-9]{1,2}(;[0-9]{1,2})?)?[mGK]");
    std::regex_replace(std::back_inserter(res), str.begin(), str.end(), re, "");

    return res;
#else
    return str;
#endif
}

/* ************************************************************************ */

}

/* ************************************************************************ */

TEST(Log, write0)
{
    testing::internal::CaptureStdout();

    log::msg("Default message");

    EXPECT_EQ("Default message\n", stripcolor(testing::internal::GetCapturedStdout()));
}

/* ************************************************************************ */

TEST(Log, write1)
{
    testing::internal::CaptureStdout();

    log::info("Info message");

    EXPECT_EQ("[INFO] Info message\n", stripcolor(testing::internal::GetCapturedStdout()));
}

/* ************************************************************************ */

TEST(Log, write2)
{
    testing::internal::CaptureStderr();

    log::error("Error message");

    EXPECT_EQ("[ERROR] Error message\n", stripcolor(testing::internal::GetCapturedStderr()));
}

/* ************************************************************************ */

TEST(Log, write3)
{
    testing::internal::CaptureStdout();

    log::debugS("section", "Debug message");

    EXPECT_EQ("[DEBUG] [section] Debug message\n", stripcolor(testing::internal::GetCapturedStdout()));
}

/* ************************************************************************ */

TEST(Log, write4)
{
    testing::internal::CaptureStdout();

    log::warningS("important", "Warning message");

    EXPECT_EQ("[WARN] [important] Warning message\n", stripcolor(testing::internal::GetCapturedStdout()));
}

/* ************************************************************************ */

TEST(Log, write5)
{
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();

    log::info("Info message");
    log::warning("Warning message");
    log::error("Error message");

    EXPECT_EQ(
        "[INFO] Info message\n"
        "[WARN] Warning message\n",
        stripcolor(testing::internal::GetCapturedStdout())
    );

    EXPECT_EQ(
        "[ERROR] Error message\n",
        stripcolor(testing::internal::GetCapturedStderr())
    );
}

/* ************************************************************************ */
