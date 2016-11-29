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

// CeCe
#include "cece/Parameters.hpp"
#include "cece/io/FilePath.hpp"
#include "cece/io/Converter.hpp"
#include "cece/config/Configuration.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::config;

/* ************************************************************************ */

/**
 * @brief      Sort given names.
 *
 * @param[in]  names  The names
 *
 * @return     Sorted list of names.
 */
DynamicArray<String> sortNames(DynamicArray<String> names)
{
    // The interface doesn't define returned names order
    std::sort(names.begin(), names.end());

    return names;
}

/* ************************************************************************ */

TEST(Configuration, memory)
{
    Configuration config;
    EXPECT_FALSE(config.has("name1"));
    EXPECT_FALSE(config.has("name2"));
    EXPECT_FALSE(config.hasContent());

    config.set("name1", "value1");
    EXPECT_TRUE(config.has("name1"));
    EXPECT_FALSE(config.has("name2"));
    EXPECT_FALSE(config.hasContent());
    EXPECT_EQ("value1", config.get("name1"));
    EXPECT_EQ("value1", config.get("name1", "def-value1"));

    config.set("name2", "value2");
    EXPECT_TRUE(config.has("name1"));
    EXPECT_TRUE(config.has("name2"));
    EXPECT_FALSE(config.hasContent());
    EXPECT_EQ("value2", config.get("name2"));
    EXPECT_EQ("value2", config.get("name2", "def-value2"));

    ASSERT_FALSE(config.has("name5"));
    EXPECT_EQ("def-value5", config.get("name5", "def-value5"));
    EXPECT_THROW(config.get("name5"), NotFoundException);

    config.setContent("Hello world");
    EXPECT_TRUE(config.has("name1"));
    EXPECT_TRUE(config.has("name2"));
    EXPECT_TRUE(config.hasContent());
    EXPECT_EQ("Hello world", config.getContent());

    // Get names
    auto names = sortNames(config.getNames());
    ASSERT_EQ(2, names.size());
    EXPECT_EQ("name1", names[0]);
    EXPECT_EQ("name2", names[1]);
}

/* ************************************************************************ */

TEST(Configuration, params)
{
    Parameters params;
    params["value"] = "15";
    params["value2"] = "72";

    Configuration config(makeView(&params));

    config.set("name1", "{$value}");
    ASSERT_TRUE(config.has("name1"));
    EXPECT_EQ("15", config.get("name1"));

    // Multiple replacements
    config.set("str", "Number1 = {$value}, Number2 = {$value2}");
    ASSERT_TRUE(config.has("str"));
    EXPECT_EQ("Number1 = 15, Number2 = 72", config.get("str"));

    // Unterminated block
    config.set("name2", "{$value");
    ASSERT_TRUE(config.has("name2"));
    EXPECT_THROW(config.get("name2"), UnterminatedParameterException);

    // Invalid characters in names
    config.set("name3", "{$v-a_lue}");
    ASSERT_TRUE(config.has("name3"));
    EXPECT_THROW(config.get("name3"), InvalidParameterNameException);
}

/* ************************************************************************ */

TEST(Configuration, append)
{
    // Merge two configurations
    Configuration config1;
    Configuration config2;

    config1.set("name11", "11");
    config1.set("name12", "12");
    config1.set("name13", "13");
    {
        auto child = config1.addConfiguration("child11");
        child.set("name111", "111");
        child.set("name112", "112");
    }
    {
        auto child = config1.addConfiguration("child12");
        child.set("name121", "121");
        child.set("name122", "122");
    }
    {
        auto child = config1.addConfiguration("shared");
        child.set("name", "value1");
    }

    config1.set("shared", "value1");
    config1.setContent("content1");

    config2.set("name21", "21");
    config2.set("name22", "22");
    config2.set("name23", "23");
    {
        auto child = config2.addConfiguration("child21");
        child.set("name211", "211");
        child.set("name212", "212");
    }
    {
        auto child = config2.addConfiguration("child22");
        child.set("name221", "221");
        child.set("name222", "222");
    }
    {
        auto child = config2.addConfiguration("shared");
        child.set("name", "value2");
    }

    config2.set("shared", "value2");
    config1.setContent("content2");

    // Append configurations - overwrite shared values in config1 by config2
    config1.append(config2);

    ASSERT_TRUE(config1.has("name11"));
    EXPECT_EQ("11", config1.get("name11"));
    ASSERT_TRUE(config1.has("name12"));
    EXPECT_EQ("12", config1.get("name12"));
    ASSERT_TRUE(config1.has("name13"));
    EXPECT_EQ("13", config1.get("name13"));
    ASSERT_TRUE(config1.has("name21"));
    EXPECT_EQ("21", config1.get("name21"));
    ASSERT_TRUE(config1.has("name22"));
    EXPECT_EQ("22", config1.get("name22"));
    ASSERT_TRUE(config1.has("name23"));
    EXPECT_EQ("23", config1.get("name23"));
    ASSERT_TRUE(config1.has("shared"));
    EXPECT_EQ("value2", config1.get("shared"));
    ASSERT_TRUE(config1.hasContent());
    EXPECT_EQ("content2", config1.getContent());

    // Names
    auto names = sortNames(config1.getNames());
    ASSERT_EQ(7, names.size());
    EXPECT_EQ("name11", names[0]);
    EXPECT_EQ("name12", names[1]);
    EXPECT_EQ("name13", names[2]);
    EXPECT_EQ("name21", names[3]);
    EXPECT_EQ("name22", names[4]);
    EXPECT_EQ("name23", names[5]);
    EXPECT_EQ("shared", names[6]);

    // Child names
    auto childNames = sortNames(config1.getConfigurationNames());
    ASSERT_EQ(5, childNames.size());
    EXPECT_EQ("child11", childNames[0]);
    EXPECT_EQ("child12", childNames[1]);
    EXPECT_EQ("child21", childNames[2]);
    EXPECT_EQ("child22", childNames[3]);
    EXPECT_EQ("shared", childNames[4]);

    auto childs = config1.getConfigurations("child11");
    ASSERT_EQ(1, childs.size());
    ASSERT_TRUE(childs[0].has("name111"));
    EXPECT_EQ("111", childs[0].get("name111"));
    ASSERT_TRUE(childs[0].has("name112"));
    EXPECT_EQ("112", childs[0].get("name112"));

    childs = config1.getConfigurations("child12");
    ASSERT_EQ(1, childs.size());
    ASSERT_TRUE(childs[0].has("name121"));
    EXPECT_EQ("121", childs[0].get("name121"));
    ASSERT_TRUE(childs[0].has("name122"));
    EXPECT_EQ("122", childs[0].get("name122"));

    childs = config1.getConfigurations("child21");
    ASSERT_EQ(1, childs.size());
    ASSERT_TRUE(childs[0].has("name211"));
    EXPECT_EQ("211", childs[0].get("name211"));
    ASSERT_TRUE(childs[0].has("name212"));
    EXPECT_EQ("212", childs[0].get("name212"));

    childs = config1.getConfigurations("child22");
    ASSERT_EQ(1, childs.size());
    ASSERT_TRUE(childs[0].has("name221"));
    EXPECT_EQ("221", childs[0].get("name221"));
    ASSERT_TRUE(childs[0].has("name222"));
    EXPECT_EQ("222", childs[0].get("name222"));

    childs = config1.getConfigurations("shared");
    ASSERT_EQ(2, childs.size());
    ASSERT_TRUE(childs[0].has("name"));
    EXPECT_EQ("value1", childs[0].get("name"));
    ASSERT_TRUE(childs[1].has("name"));
    EXPECT_EQ("value2", childs[1].get("name"));
}

/* ************************************************************************ */

TEST(Configuration, childs)
{
    Configuration config;

    // No child configuration
    EXPECT_EQ(0, config.getConfigurationNames().size());
    EXPECT_FALSE(config.hasConfiguration("child1"));
    EXPECT_FALSE(config.hasConfiguration("child2"));

    // Get childs
    auto childs = config.getConfigurations("child1");
    EXPECT_EQ(0, childs.size());
    EXPECT_THROW(config.getConfiguration("child1"), NotFoundException);

    // Create child configuration
    auto child1 = config.addConfiguration("child1");
    auto child2 = config.addConfiguration("child2");
    EXPECT_TRUE(config.hasConfiguration("child1"));
    EXPECT_TRUE(config.hasConfiguration("child2"));

    auto names = sortNames(config.getConfigurationNames());
    ASSERT_EQ(2, names.size());
    EXPECT_EQ("child1", names[0]);
    EXPECT_EQ("child2", names[1]);

    // It shouldn't throw
    EXPECT_NO_THROW(config.getConfiguration("child1"));

    // One child
    childs = config.getConfigurations("child1");
    EXPECT_EQ(1, childs.size());
}

/* ************************************************************************ */

TEST(Configuration, toMemory)
{
    Configuration config1;
    config1.set("name1", "1");
    config1.set("name2", "2");

    auto child1 = config1.addConfiguration("child1");
    child1.set("name11", "11");
    child1.setContent("content11");

    // Create memory version
    auto config2 = config1.toMemory();

    ASSERT_TRUE(config2.has("name1"));
    EXPECT_EQ("1", config2.get("name1"));
    ASSERT_TRUE(config2.has("name2"));
    EXPECT_EQ("2", config2.get("name2"));

    ASSERT_TRUE(config2.hasConfiguration("child1"));
    auto child2 = config2.getConfiguration("child1");
    ASSERT_TRUE(child2.has("name11"));
    EXPECT_EQ("11", child2.get("name11"));
    ASSERT_TRUE(child2.hasContent());
    EXPECT_EQ("content11", child2.getContent());
}

/* ************************************************************************ */

TEST(Configuration, converter)
{
    Configuration config;

    config.set("bool", true);
    ASSERT_TRUE(config.has("bool"));
    EXPECT_TRUE(config.get<bool>("bool"));
    EXPECT_TRUE(config.get<bool>("bool", false));

    config.set("bool", false);
    ASSERT_TRUE(config.has("bool"));
    EXPECT_FALSE(config.get<bool>("bool"));
    EXPECT_FALSE(config.get<bool>("bool", true));

    config.set("int", 15);
    ASSERT_TRUE(config.has("int"));
    EXPECT_EQ(15, config.get<int>("int"));
    EXPECT_EQ(15, config.get<int>("int", 753));

    config.set("uint", 15u);
    ASSERT_TRUE(config.has("uint"));
    EXPECT_EQ(15u, config.get<unsigned int>("uint"));
    EXPECT_EQ(15u, config.get<unsigned int>("uint", 45632u));

    config.set("ulong", 14596423135ul);
    ASSERT_TRUE(config.has("ulong"));
    EXPECT_EQ(14596423135ul, config.get<unsigned long>("ulong"));
    EXPECT_EQ(14596423135ul, config.get<unsigned long>("ulong", 4244ul));

    config.set("float", 0.31f);
    ASSERT_TRUE(config.has("float"));
    EXPECT_FLOAT_EQ(0.31f, config.get<float>("float"));
    EXPECT_FLOAT_EQ(0.31f, config.get<float>("float", 0.1f));

    config.set("double", 0.31);
    ASSERT_TRUE(config.has("double"));
    EXPECT_FLOAT_EQ(0.31, config.get<double>("double"));
    EXPECT_FLOAT_EQ(0.31, config.get("double", 0.0));

    ASSERT_FALSE(config.has("double2"));
    EXPECT_FLOAT_EQ(0.31, config.get("double2", 0.31));

    config.set("path", io::FilePath("/home/user/file.txt"));
    ASSERT_TRUE(config.has("path"));
    EXPECT_EQ("/home/user/file.txt", config.get<io::FilePath>("path"));
    EXPECT_EQ("/tmp", config.get<io::FilePath>("path2", "/tmp"));
}

/* ************************************************************************ */
