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
#include "cece/plugin/Api.hpp"
#include "cece/plugin/Context.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/plugin/SharedLibraryLoader.hpp"
#include "cece/init/Initializer.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

class TestInitializer final : public init::Initializer
{
public:
    using init::Initializer::Initializer;

    void init(simulator::Simulation& simulation) const override
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestApi1 : public Api
{
    void onLoad(RepositoryRecord& repository) override
    {
        repository.registerInitializer<TestInitializer>("initializer");
    }
};

/* ************************************************************************ */

class TestApi2 : public Api
{
    void onLoad(RepositoryRecord& repository) override
    {
        repository
            .registerInitializer<TestInitializer>("initializer")
            .registerInitializer<TestInitializer>("initializer2")
        ;
    }
};

/* ************************************************************************ */

}

/* ************************************************************************ */

TEST(Context, ctor)
{
    Manager mgr;
    Context ctx(mgr);

    EXPECT_EQ(&mgr.getRepository(), &ctx.getRepository());
}

/* ************************************************************************ */

TEST(Context, import)
{
    Manager mgr;

    // Use shared library loader
    mgr.addLoader(makeUnique<SharedLibraryLoader>());
    mgr.addDirectory(".");

    Context ctx(mgr);

    EXPECT_NO_THROW(ctx.importPlugin("test-plugin"));
    EXPECT_THROW(ctx.importPlugin("old-plugin"), RuntimeException);

    EXPECT_TRUE(ctx.isImported("test-plugin"));
    EXPECT_FALSE(ctx.isImported("old-plugin"));

    EXPECT_NO_THROW(ctx.createInitializer("initializer"));
}

/* ************************************************************************ */

TEST(Context, ambiguous)
{
    Manager mgr;
    mgr.addPlugin(Plugin{"plugin1", makeUnique<TestApi1>()});
    mgr.addPlugin(Plugin{"plugin2", makeUnique<TestApi2>()});

    Context ctx(mgr);
    ctx.importPlugin("plugin1");
    ctx.importPlugin("plugin2");

    EXPECT_ANY_THROW(ctx.createInitializer("initializer"));
    EXPECT_NO_THROW(ctx.createInitializer("initializer2"));
}

/* ************************************************************************ */
