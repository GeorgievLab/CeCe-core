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
#include <algorithm>
#include <cstring>

// CeCe
#include "cece/String.hpp"
#include "cece/io/StringStream.hpp"
#include "cece/io/FilePath.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::io;

/* ************************************************************************ */

TEST(FilePath, construct)
{
    {
        auto path = FilePath();
        EXPECT_TRUE(path.isEmpty());
    }

    {
        const char* str = "filename1";
        auto path = FilePath(str);
        EXPECT_FALSE(path.isEmpty());
        EXPECT_EQ(str, path.toString());
    }

    {
        String str = "dirname/filename";
        auto path = FilePath(str);
        EXPECT_FALSE(path.isEmpty());
        EXPECT_EQ(str, path.toString());
    }
}

/* ************************************************************************ */

TEST(FilePath, append)
{
    {
        auto path = FilePath("dir");
        path /= "filename";
        EXPECT_EQ("dir/filename", path.toString());
    }

    {
        auto path = FilePath("dir");
        auto file = FilePath("filename");

        auto p = path / file;
        EXPECT_EQ("dir/filename", p.toString());
    }
}

/* ************************************************************************ */

TEST(FilePath, concat)
{
    {
        auto path = FilePath("dir");
        path += "filename";
        path += FilePath(".txt");
        EXPECT_EQ("dirfilename.txt", path.toString());
    }

    {
        auto path = FilePath("dir");
        auto file = FilePath("filename");

        auto p = path + file + ".txt";
        EXPECT_EQ("dirfilename.txt", p.toString());
    }
}

/* ************************************************************************ */

TEST(FilePath, operations)
{
    FilePath emptyPath;

    EXPECT_TRUE(emptyPath.isEmpty());
    EXPECT_EQ("", emptyPath.toString());
    EXPECT_EQ("", emptyPath.getFilename());
    EXPECT_EQ("", emptyPath.getExtension());
    EXPECT_EQ("", emptyPath.getParentPath());
    EXPECT_EQ("", emptyPath.getStem());
    EXPECT_EQ(0, emptyPath.getSize());
    EXPECT_EQ(0, std::strlen(emptyPath.c_str()));

    emptyPath /= "file";
    EXPECT_EQ("file", emptyPath.toString());

    emptyPath.replaceExtension(".txt");
    EXPECT_EQ("file.txt", emptyPath.toString());

    emptyPath.replaceExtension("pdf");
    EXPECT_EQ("file.pdf", emptyPath.toString());

    FilePath path("dir1/dir2/dir3/file.txt");

    EXPECT_FALSE(path.isEmpty());
    EXPECT_EQ(23, path.getSize());
    EXPECT_EQ("dir1/dir2/dir3/file.txt", path.toString());
    EXPECT_EQ("file.txt", path.getFilename());
    EXPECT_EQ(".txt", path.getExtension());
    EXPECT_EQ("dir1/dir2/dir3", path.getParentPath().toString());
    EXPECT_EQ("dir1/dir2/dir3/file", path.getStem().toString());

    path.replaceExtension(".img");
    EXPECT_EQ("dir1/dir2/dir3/file.img", path.toString());

    path.concat(".txt");
    EXPECT_EQ("dir1/dir2/dir3/file.img.txt", path.toString());
}

/* ************************************************************************ */

TEST(FilePath, rel)
{
    const FilePath p1("file1");
    const FilePath p2("file2");
    const FilePath p3("file1");

    EXPECT_EQ(p1, p1);
    EXPECT_NE(p1, p2);
    EXPECT_EQ(p1, p3);
    EXPECT_NE(p2, p1);
    EXPECT_EQ(p2, p2);
    EXPECT_NE(p2, p3);
    EXPECT_EQ(p3, p1);
    EXPECT_NE(p3, p2);
    EXPECT_EQ(p3, p3);

    EXPECT_EQ(p1, "file1");
    EXPECT_EQ(p1, String("file1"));
    EXPECT_NE(p1, "file2");
    EXPECT_NE(p1, String("file2"));

    EXPECT_EQ("file1", p1);
    EXPECT_EQ(String("file1"), p1);
    EXPECT_NE("file2", p1);
    EXPECT_NE(String("file2"), p1);
}

/* ************************************************************************ */

TEST(FilePath, functions)
{
    EXPECT_TRUE(FilePath::exists("file1.txt"));
    EXPECT_TRUE(FilePath::isFile("file1.txt"));
    EXPECT_FALSE(FilePath::isDirectory("file1.txt"));

    EXPECT_TRUE(FilePath::exists("dir1"));
    EXPECT_TRUE(FilePath::isDirectory("dir1"));
    EXPECT_FALSE(FilePath::isFile("dir1"));

    EXPECT_TRUE(FilePath::exists("dir1/file2.txt"));
    EXPECT_TRUE(FilePath::isFile("dir1/file2.txt"));
    EXPECT_FALSE(FilePath::isDirectory("dir1/file2.txt"));

    EXPECT_FALSE(FilePath::exists("file2.txt"));
    EXPECT_FALSE(FilePath::isFile("file2.txt"));
    EXPECT_FALSE(FilePath::isDirectory("file2.txt"));

    auto temp = FilePath::getTempDirectory();
    EXPECT_TRUE(FilePath::exists(temp));
    EXPECT_TRUE(FilePath::isDirectory(temp));

    // Deprecated
    EXPECT_TRUE(pathExists("file1.txt"));
    EXPECT_TRUE(isFile("file1.txt"));
    EXPECT_FALSE(isDirectory("file1.txt"));

    EXPECT_TRUE(pathExists("dir1"));
    EXPECT_TRUE(isDirectory("dir1"));
    EXPECT_FALSE(isFile("dir1"));

    EXPECT_TRUE(pathExists("dir1/file2.txt"));
    EXPECT_TRUE(isFile("dir1/file2.txt"));
    EXPECT_FALSE(isDirectory("dir1/file2.txt"));

    EXPECT_FALSE(pathExists("file2.txt"));
    EXPECT_FALSE(isFile("file2.txt"));
    EXPECT_FALSE(isDirectory("file2.txt"));

    auto temp2 = tempDirectory();
    EXPECT_TRUE(pathExists(temp2));
    EXPECT_TRUE(isDirectory(temp2));
}

/* ************************************************************************ */

TEST(FilePath, cwd)
{
    const auto cwd = FilePath::getCurrent();
    EXPECT_TRUE(FilePath::exists(cwd));

    FilePath::setCurrent(cwd / "dir1");
    const auto cwd2 = FilePath::getCurrent();
    EXPECT_TRUE(FilePath::exists(cwd2));
    EXPECT_EQ(cwd / "dir1", cwd2);

    // Reset working directory
    FilePath::setCurrent(cwd);
}

/* ************************************************************************ */

TEST(FilePath, openDirectory)
{
    {
        ASSERT_FALSE(FilePath::exists("non-existent-directory"));
        auto items = FilePath::openDirectory("non-existent-directory");
        EXPECT_EQ(0, items.size());
    }

    {
        ASSERT_TRUE(FilePath::exists("dir1"));
        auto items = FilePath::openDirectory("dir1");
        ASSERT_EQ(2, items.size());

        // Files can be returned in any order, we need to sort them
        std::sort(items.begin(), items.end(), [](const FilePath& lhs, const FilePath& rhs) {
            return lhs.toString() < rhs.toString();
        });

        EXPECT_EQ("dir1/file2.txt", items[0]);
        EXPECT_EQ("dir1/file3.txt", items[1]);
    }
}

/* ************************************************************************ */

TEST(FilePath, inout)
{
    const FilePath in("dir1/dir2/file1");
    FilePath out;

    StringStream ss;
    ss << in;
    ss >> out;

    EXPECT_EQ(in, out);
}

/* ************************************************************************ */
