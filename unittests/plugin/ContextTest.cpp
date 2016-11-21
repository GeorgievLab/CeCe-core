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
#include "cece/plugin/Exception.hpp"
#include "cece/simulation/Loader.hpp"
#include "cece/simulation/Initializer.hpp"
#include "cece/simulation/Module.hpp"
#include "cece/simulation/Object.hpp"
#include "cece/simulation/Program.hpp"
#include "cece/simulation/DefaultSimulation.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

class TestLoader final : public simulation::Loader
{
public:

    UniquePtr<simulation::Simulation> fromStream(const plugin::Manager& manager, io::InStream& is,
        const io::FilePath& filename = "<stream>",
        ViewPtr<const Parameters> parameters = nullptr) const override
    {
        return makeUnique<simulation::DefaultSimulation>(manager, filename);
    }

    void toStream(io::OutStream& os, const simulation::Simulation& simulation,
        const io::FilePath& filename = "<stream>") const override
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestInitializer final : public simulation::Initializer
{
public:
    using simulation::Initializer::Initializer;

    void init(simulation::Simulation& simulation) const override
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestModule final : public simulation::Module
{
public:
    using simulation::Module::Module;
};

/* ************************************************************************ */

class TestObject final : public simulation::Object
{
public:
    using simulation::Object::Object;
};

/* ************************************************************************ */

class TestProgram final : public simulation::Program
{
public:
    using simulation::Program::Program;

    UniquePtr<Program> clone() const override
    {
        return makeUnique<TestProgram>(*this);
    }

    void call(simulation::Simulation& simulation, simulation::Object& object, unit::Time dt) override
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestApi0 : public Api
{
    void onLoad(RepositoryRecord& repository) override
    {
        repository
            .registerLoader<TestLoader>("loader")
            .registerInitializer<TestInitializer>("initializer")
            .registerModule<TestModule>("module")
            .registerObject<TestObject>("object")
            .registerProgram<TestProgram>("program")
        ;
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
    EXPECT_THROW(ctx.importPlugin("old-plugin"), PluginNotFoundException);

    EXPECT_TRUE(ctx.isImported("test-plugin"));
    EXPECT_FALSE(ctx.isImported("old-plugin"));

    EXPECT_NO_THROW(ctx.createInitializer("initializer"));

    ctx.removePlugin("test-plugin");
    EXPECT_FALSE(ctx.isImported("test-plugin"));

    // Import twice
    EXPECT_NO_THROW(ctx.importPlugin("test-plugin"));
    EXPECT_TRUE(ctx.isImported("test-plugin"));
    EXPECT_NO_THROW(ctx.importPlugin("test-plugin"));
    EXPECT_TRUE(ctx.isImported("test-plugin"));

    // Remove multiple time
    EXPECT_NO_THROW(ctx.removePlugin("test-plugin"));
    EXPECT_FALSE(ctx.isImported("test-plugin"));
    EXPECT_NO_THROW(ctx.removePlugin("test-plugin"));
    EXPECT_FALSE(ctx.isImported("test-plugin"));
    EXPECT_NO_THROW(ctx.removePlugin("test-plugin"));
    EXPECT_FALSE(ctx.isImported("test-plugin"));
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

    EXPECT_THROW(ctx.createInitializer("initializer"), MultipleExtensionsException);
    EXPECT_NO_THROW(ctx.createInitializer("initializer2"));
}

/* ************************************************************************ */

TEST(Context, not_imported)
{
    Manager mgr;
    mgr.addPlugin(Plugin{"plugin1", makeUnique<TestApi1>()});
    mgr.addPlugin(Plugin{"plugin2", makeUnique<TestApi2>()});

    Context ctx(mgr);

    EXPECT_THROW(ctx.createInitializer("initializer"), ExtensionNotFoundException);
}

/* ************************************************************************ */

TEST(Context, create)
{
    Manager mgr;
    mgr.addPlugin(Plugin{"plugin", makeUnique<TestApi0>()});

    Context ctx(mgr);
    ctx.importPlugin("plugin");

    simulation::DefaultSimulation simulation(mgr);

    EXPECT_NO_THROW(ctx.createLoader("loader"));
    EXPECT_NO_THROW(ctx.createInitializer("initializer"));
    EXPECT_NO_THROW(ctx.createModule("module", simulation));
    EXPECT_NO_THROW(ctx.createObject("object", simulation, simulation::Object::Type::Static));
    EXPECT_NO_THROW(ctx.createProgram("program"));

    EXPECT_THROW(ctx.createLoader("loader0"), ExtensionNotFoundException);
    EXPECT_THROW(ctx.createInitializer("initializer0"), ExtensionNotFoundException);
    EXPECT_THROW(ctx.createModule("module0", simulation), ExtensionNotFoundException);
    EXPECT_THROW(ctx.createObject("object0", simulation, simulation::Object::Type::Static), ExtensionNotFoundException);
    EXPECT_THROW(ctx.createProgram("program0"), ExtensionNotFoundException);
}

/* ************************************************************************ */
