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

// CeCe
#include "cece/String.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/io/StringStream.hpp"
#include "cece/log/StreamOutput.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::log;

/* ************************************************************************ */

TEST(StreamOutput, write0)
{
    io::OutStringStream stream;

    StreamOutput output(stream);
    output.write(Severity::Default, {}, "Default message");

    EXPECT_EQ("Default message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write1)
{
    io::OutStringStream stream;

    StreamOutput output(stream);
    output.write(Severity::Info, {}, "Info message");

    EXPECT_EQ("[INFO] Info message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write2)
{
    io::OutStringStream stream;

    StreamOutput output(stream);
    output.write(Severity::Error, {}, "Error message");

    EXPECT_EQ("[ERROR] Error message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write3)
{
    io::OutStringStream stream;

    StreamOutput output(stream);
    output.write(Severity::Debug, "section", "Debug message");

    EXPECT_EQ("[DEBUG] [section] Debug message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write4)
{
    io::OutStringStream stream;

    StreamOutput output(stream);
    output.write(Severity::Warning, "important", "Warning message");

    EXPECT_EQ("[WARN] [important] Warning message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write5)
{
    io::OutStringStream stream;

    UniquePtr<Output> output = makeUnique<StreamOutput>(stream);
    output->write(Severity::Info, {}, "Info message");

    EXPECT_EQ("[INFO] Info message\n", stream.str());
}

/* ************************************************************************ */

TEST(StreamOutput, write6)
{
    io::OutStringStream stream;

    UniquePtr<Output> output = makeUnique<StreamOutput>(stream);
    output->write(Severity::Info, {}, "Info message");
    output->write(Severity::Warning, {}, "Warning message");
    output->write(Severity::Error, {}, "Error message");

    EXPECT_EQ(
        "[INFO] Info message\n"
        "[WARN] Warning message\n"
        "[ERROR] Error message\n",
        stream.str()
    );
}

/* ************************************************************************ */
