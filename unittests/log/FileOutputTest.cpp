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
#include <cstdio>
#include <iterator>

// CeCe
#include "cece/String.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/Exception.hpp"
#include "cece/io/FilePath.hpp"
#include "cece/io/FileStream.hpp"
#include "cece/log/FileOutput.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::log;

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

String readfile(io::FilePath path)
{
    io::InFileStream file(path.toString());

    return String(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>()
    );
}

/* ************************************************************************ */

}

/* ************************************************************************ */

TEST(FileOutput, invalidFile)
{
    EXPECT_THROW(FileOutput("/invalid directory/test.log"), InvalidArgumentException);
}

/* ************************************************************************ */

TEST(FileOutput, write0)
{
    FileOutput output("write0.log");
    output.write(Severity::Default, {}, "Default message");

    EXPECT_EQ("Default message\n", readfile("write0.log"));
    remove("write0.log");
}

/* ************************************************************************ */

TEST(FileOutput, write1)
{
    FileOutput output("write1.log");
    output.write(Severity::Info, {}, "Info message");

    EXPECT_EQ("[INFO] Info message\n", readfile("write1.log"));
    remove("write1.log");
}

/* ************************************************************************ */

TEST(FileOutput, write2)
{
    FileOutput output("write2.log");
    output.write(Severity::Error, {}, "Error message");

    EXPECT_EQ("[ERROR] Error message\n", readfile("write2.log"));
    remove("write2.log");
}

/* ************************************************************************ */

TEST(FileOutput, write3)
{
    FileOutput output("write3.log");
    output.write(Severity::Debug, "section", "Debug message");

    EXPECT_EQ("[DEBUG] [section] Debug message\n", readfile("write3.log"));
    remove("write3.log");
}

/* ************************************************************************ */

TEST(FileOutput, write4)
{
    FileOutput output("write4.log");
    output.write(Severity::Warning, "important", "Warning message");

    EXPECT_EQ("[WARN] [important] Warning message\n", readfile("write4.log"));
    remove("write4.log");
}

/* ************************************************************************ */

TEST(FileOutput, write5)
{
    UniquePtr<Output> output = makeUnique<FileOutput>("write5.log");
    output->write(Severity::Info, {}, "Info message");

    EXPECT_EQ("[INFO] Info message\n", readfile("write5.log"));
    remove("write5.log");
}

/* ************************************************************************ */

TEST(FileOutput, write6)
{
    UniquePtr<Output> output = makeUnique<FileOutput>("write6.log");
    output->write(Severity::Info, {}, "Info message");
    output->write(Severity::Warning, {}, "Warning message");
    output->write(Severity::Error, {}, "Error message");

    EXPECT_EQ(
        "[INFO] Info message\n"
        "[WARN] Warning message\n"
        "[ERROR] Error message\n",
        readfile("write6.log")
    );

    remove("write6.log");
}

/* ************************************************************************ */

TEST(FileOutput, append)
{
    {
        FileOutput output("append.log");
        output.write(Severity::Info, {}, "Info message");
    }

    {
        FileOutput output("append.log");
        output.write(Severity::Warning, {}, "Warning message");
    }

    {
        FileOutput output("append.log");
        output.write(Severity::Error, {}, "Error message");
    }

    EXPECT_EQ(
        "[INFO] Info message\n"
        "[WARN] Warning message\n"
        "[ERROR] Error message\n",
        readfile("append.log")
    );

    remove("append.log");
}

/* ************************************************************************ */
