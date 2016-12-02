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
#include "cece/log/Logger.hpp"
#include "cece/log/StreamOutput.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::log;

/* ************************************************************************ */

TEST(Logger, write0)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.msg("Default message");

    EXPECT_EQ("Default message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write1)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.info("Info", " message");

    EXPECT_EQ("[INFO] Info message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write2)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.error("Error ", "message");

    EXPECT_EQ("[ERROR] Error message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write3)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.debugS("section", "Debug message");

    EXPECT_EQ("[DEBUG] [section] Debug message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write4)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.warningS("important", "Warning message");

    EXPECT_EQ("[WARN] [important] Warning message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write5)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.info("Info message");

    EXPECT_EQ("[INFO] Info message\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, write6)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.info("Info message");
    logger.warning("Warning message");
    logger.error("Error message");

    EXPECT_EQ(
        "[INFO] Info message\n"
        "[WARN] Warning message\n"
        "[ERROR] Error message\n",
        stream.str()
    );
}

/* ************************************************************************ */

TEST(Logger, merge)
{
    io::OutStringStream stream;

    Logger logger(makeUnique<StreamOutput>(stream));
    logger.info("Result = ", 10, "ms");

    EXPECT_EQ("[INFO] Result = 10ms\n", stream.str());
}

/* ************************************************************************ */

TEST(Logger, output)
{
    io::OutStringStream stream;

    auto output1 = makeUnique<StreamOutput>(stream);
    auto output1View = makeView(output1);

    Logger logger(std::move(output1));
    EXPECT_EQ(output1View, logger.getOutput());

    auto output2 = makeUnique<StreamOutput>(stream);
    auto output2View = makeView(output2);

    logger.setOutput(std::move(output2));
    EXPECT_EQ(output2View, logger.getOutput());
}

/* ************************************************************************ */
