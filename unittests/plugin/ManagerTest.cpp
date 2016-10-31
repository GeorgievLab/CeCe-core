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
#include <gtest/gtest.h>

// CeCe
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/plugin/SharedLibraryLoader.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

class TestLoader : public Loader
{
public:

    int getCalled() const noexcept
    {
        return m_called;
    }

    DynamicArray<Plugin> loadAll(const FilePath& directory)
    {
        ++m_called;

        return {};
    }

private:

    int m_called = 0;
};

/* ************************************************************************ */

TEST(Manager, directories)
{
    Manager mgr;

    mgr.addDirectory(".");
    mgr.addDirectory("plugins");

    EXPECT_EQ(2, mgr.getDirectories().size());

    mgr.addDirectories({"/home/cece/.cece/plugins", "/home/cece/.cece/python-plugins"});

    EXPECT_EQ(4, mgr.getDirectories().size());
}

/* ************************************************************************ */

TEST(Manager, load)
{
    Manager mgr;

    // Use shared library loader
    mgr.addLoader(makeUnique<SharedLibraryLoader>());
    mgr.addDirectory(".");

    ASSERT_PRED1(pathExists, SharedLibrary::PREFIX + "cece-test-plugin" + SharedLibrary::EXTENSION);
    EXPECT_PRED1(pathExists, SharedLibrary::PREFIX + "cece-invalid-plugin" + SharedLibrary::EXTENSION);
    EXPECT_PRED1(pathExists, SharedLibrary::PREFIX + "cece-old-plugin" + SharedLibrary::EXTENSION);

    // Plugins should be loaded
    EXPECT_TRUE(mgr.isLoaded("test-plugin"));

    // Load test plugin
    auto api = mgr.getApi("test-plugin");

    ASSERT_NE(nullptr, api);
    EXPECT_EQ("test-plugin", mgr.getName(api));

    // Test plugin should add some testing classes to repository
    ASSERT_TRUE(mgr.getRepository().exists(api));

    // Get record
    auto record = mgr.getRepository().get(api);
    ASSERT_NE(nullptr, record);

    EXPECT_TRUE(record->getInitFactoryManager().exists("initializer"));
    EXPECT_FALSE(record->getInitFactoryManager().exists("init"));
    EXPECT_TRUE(record->getModuleFactoryManager().exists("module"));
    EXPECT_TRUE(record->getObjectFactoryManager().exists("object"));
    EXPECT_TRUE(record->getProgramFactoryManager().exists("program"));

    // Plugin cannot be loaded - missing functions
    EXPECT_EQ(nullptr, mgr.getApi("invalid-plugin"));

    // Plugin cannot be loaded - old API
    EXPECT_EQ(nullptr, mgr.getApi("old-plugin"));
}

/* ************************************************************************ */

TEST(Manager, invoke1)
{
    Manager mgr;

    ASSERT_EQ(0, mgr.getLoaders().size());

    // Add directory
    mgr.addDirectory(".");
    mgr.addDirectory("test");

    // When a loader is added it's invoked with current directories
    mgr.addLoader(makeUnique<TestLoader>());

    //ASSERT_EQ(1, mgr.getLoaders().size());
    const auto& loader = static_cast<TestLoader*>(mgr.getLoaders()[0].get());

    EXPECT_EQ(2, loader->getCalled());
}

/* ************************************************************************ */

TEST(Manager, invoke2)
{
    Manager mgr;

    ASSERT_EQ(0, mgr.getLoaders().size());

    // New loader
    mgr.addLoader(makeUnique<TestLoader>());

    ASSERT_EQ(1, mgr.getLoaders().size());
    const auto& loader = static_cast<TestLoader*>(mgr.getLoaders()[0].get());

    // When directory is added it's invoked for all current loaders.
    mgr.addDirectory(".");
    mgr.addDirectory("test");
    mgr.addDirectory("test2");

    EXPECT_EQ(3, loader->getCalled());
}

/* ************************************************************************ */
