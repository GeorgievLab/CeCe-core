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
#include "cece/config/Configuration.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::config;

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

    config.setContent("Hello world");
    EXPECT_TRUE(config.has("name1"));
    EXPECT_TRUE(config.has("name2"));
    EXPECT_TRUE(config.hasContent());
    EXPECT_EQ("Hello world", config.getContent());

    config.set("bool", true);
    ASSERT_TRUE(config.has("bool"));
    EXPECT_TRUE(config.get<bool>("bool"));

    config.set("bool", false);
    ASSERT_TRUE(config.has("bool"));
    EXPECT_FALSE(config.get<bool>("bool"));

    config.set("int", 15);
    ASSERT_TRUE(config.has("int"));
    EXPECT_EQ(15, config.get<int>("int"));

    config.set("uint", 15u);
    ASSERT_TRUE(config.has("uint"));
    EXPECT_EQ(15u, config.get<unsigned int>("uint"));

    config.set("float", 0.31f);
    ASSERT_TRUE(config.has("float"));
    EXPECT_FLOAT_EQ(0.31f, config.get<float>("float"));

    config.set("double", 0.31);
    ASSERT_TRUE(config.has("double"));
    EXPECT_FLOAT_EQ(0.31, config.get("double", 0.0));

    ASSERT_FALSE(config.has("double2"));
    EXPECT_FLOAT_EQ(0.31, config.get("double2", 0.31));
}

/* ************************************************************************ */

TEST(Configuration, params)
{
    Configuration config;
}

/* ************************************************************************ */
