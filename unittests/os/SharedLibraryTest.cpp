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
#include "cece/os/SharedLibrary.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::os;
using namespace cece::io;

/* ************************************************************************ */

TEST(SharedLibrary, formatName)
{
    EXPECT_EQ(SharedLibrary::PREFIX + "mylib" + SharedLibrary::EXTENSION, SharedLibrary::formatName("mylib"));
}

/* ************************************************************************ */

TEST(SharedLibrary, ctor)
{
    ASSERT_PRED1(FilePath::exists, os::SharedLibrary::formatName("library1"));
    ASSERT_PRED1(FilePath::exists, FilePath::getCurrent() / os::SharedLibrary::formatName("library1"));

    // Default
    {
        SharedLibrary lib;
        EXPECT_FALSE(lib.isOpen());
    }

    // With path
    {
        SharedLibrary lib(FilePath::getCurrent() / SharedLibrary::formatName("library1"));
        EXPECT_TRUE(lib.isOpen());
    }

    // Move
    {
        SharedLibrary lib(FilePath::getCurrent() / SharedLibrary::formatName("library1"));
        EXPECT_TRUE(lib.isOpen());

        SharedLibrary lib2(std::move(lib));
        EXPECT_TRUE(lib2.isOpen());

        EXPECT_FALSE(lib.isOpen());
    }

    // Assignment
    {
        SharedLibrary lib;
        EXPECT_FALSE(lib.isOpen());

        lib = SharedLibrary(FilePath::getCurrent() / SharedLibrary::formatName("library1"));
        EXPECT_TRUE(lib.isOpen());
    }

    // Move Assignment
    {
        SharedLibrary lib;
        EXPECT_FALSE(lib.isOpen());

        SharedLibrary lib2(FilePath::getCurrent() / SharedLibrary::formatName("library1"));
        EXPECT_TRUE(lib2.isOpen());

        lib = std::move(lib2);
        EXPECT_TRUE(lib.isOpen());
        EXPECT_FALSE(lib2.isOpen());
    }
}

/* ************************************************************************ */

TEST(SharedLibrary, open)
{
    SharedLibrary lib;
    EXPECT_FALSE(lib.isOpen());

    ASSERT_PRED1(FilePath::exists, os::SharedLibrary::formatName("library1"));
    ASSERT_PRED1(FilePath::exists, FilePath::getCurrent() / os::SharedLibrary::formatName("library1"));

    ASSERT_NO_THROW(lib = SharedLibrary(FilePath::getCurrent() / SharedLibrary::formatName("library1")));
    ASSERT_TRUE(lib.isOpen());
    EXPECT_EQ((FilePath::getCurrent() / SharedLibrary::formatName("library1")).toString(), lib.getPath().toString());

    // Get symbol
    auto identity = lib.getAddr<int(*)(int)>("identity");
    ASSERT_NE(nullptr, identity);
    EXPECT_EQ(100, identity(100));

    EXPECT_EQ(nullptr, lib.getAddr("other"));
}

/* ************************************************************************ */
