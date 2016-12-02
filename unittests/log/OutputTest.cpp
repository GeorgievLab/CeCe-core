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
#include "cece/log/Output.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::log;

/* ************************************************************************ */

struct TestOutput : public Output
{
    int called = 0;

    void write(Severity severity, const String& section, const String& msg) override
    {
        EXPECT_EQ(Severity::Info, severity);
        EXPECT_EQ("", section);
        EXPECT_EQ("Message", msg);

        ++called;
    }
};

/* ************************************************************************ */

TEST(Output, write)
{
    TestOutput output;
    output.write(Severity::Info, {}, "Message");

    EXPECT_EQ(1, output.called);
}

/* ************************************************************************ */

TEST(Output, writeAbstract)
{
    UniquePtr<Output> output = makeUnique<TestOutput>();
    EXPECT_NE(nullptr, output);
    output->write(Severity::Info, {}, "Message");
    output->write(Severity::Info, {}, "Message");
    output->write(Severity::Info, {}, "Message");

    EXPECT_EQ(3, static_cast<TestOutput*>(output.get())->called);
}

/* ************************************************************************ */
