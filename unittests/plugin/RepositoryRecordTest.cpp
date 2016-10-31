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
#include "cece/plugin/RepositoryRecord.hpp"
#include "cece/loader/Loader.hpp"
#include "cece/init/Initializer.hpp"
#include "cece/module/Module.hpp"
#include "cece/object/Object.hpp"
#include "cece/program/Program.hpp"
#include "cece/simulator/DefaultSimulation.hpp"
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/Manager.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

class TestLoader final : public loader::Loader
{
public:

    UniquePtr<simulator::Simulation> fromStream(const plugin::Repository& repository, InStream& is,
        const FilePath& filename = "<stream>",
        ViewPtr<const Parameters> parameters = nullptr) const override
    {
        return makeUnique<simulator::DefaultSimulation>(repository, filename);
    }

    void toStream(OutStream& os, const simulator::Simulation& simulation,
        const FilePath& filename = "<stream>") const override
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestInitializer final : public init::Initializer
{
public:
    using init::Initializer::Initializer;

    void init(simulator::Simulation& simulation) const
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestModule final : public module::Module
{
public:
    using module::Module::Module;
};

/* ************************************************************************ */

class TestObject final : public object::Object
{
public:
    using object::Object::Object;
};

/* ************************************************************************ */

class TestProgram final : public program::Program
{
public:
    using program::Program::Program;

    UniquePtr<Program> clone() const override
    {
        return makeUnique<TestProgram>(*this);
    }

    void call(simulator::Simulation& simulation, object::Object& object, units::Time dt)
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

}

/* ************************************************************************ */

TEST(RepositoryRecord, ctor)
{
    RepositoryRecord record("my-record");

    EXPECT_EQ("my-record", record.getName());
}

/* ************************************************************************ */

TEST(RepositoryRecord, loader)
{
    RepositoryRecord record("");

    EXPECT_FALSE(record.isRegisteredLoader("loader"));
    record.registerLoader<TestLoader>("loader");
    EXPECT_TRUE(record.isRegisteredLoader("loader"));

    // Create loader
    auto loader = record.createLoader("loader");
    ASSERT_NE(nullptr, loader);

    EXPECT_EQ(typeid(TestLoader), typeid(*loader));
}

/* ************************************************************************ */

TEST(RepositoryRecord, initializer)
{
    RepositoryRecord record("");

    EXPECT_FALSE(record.isRegisteredInitializer("initializer"));
    record.registerInitializer<TestInitializer>("initializer");
    EXPECT_TRUE(record.isRegisteredInitializer("initializer"));

    auto initializer = record.createInitializer("initializer");
    ASSERT_NE(nullptr, initializer);

    EXPECT_EQ(typeid(TestInitializer), typeid(*initializer));
}

/* ************************************************************************ */

TEST(RepositoryRecord, module)
{
    RepositoryRecord record("");

    EXPECT_FALSE(record.isRegisteredModule("module"));
    record.registerModule<TestModule>("module");
    EXPECT_TRUE(record.isRegisteredModule("module"));

    plugin::Manager mgr;
    plugin::Repository repo(mgr);
    simulator::DefaultSimulation simulation(repo);
    auto module = record.createModule("module", simulation);
    ASSERT_NE(nullptr, module);

    EXPECT_EQ(typeid(TestModule), typeid(*module));
}

/* ************************************************************************ */

TEST(RepositoryRecord, object)
{
    RepositoryRecord record("");

    EXPECT_FALSE(record.isRegisteredObject("object"));
    record.registerObject<TestObject>("object");
    EXPECT_TRUE(record.isRegisteredObject("object"));

    plugin::Manager mgr;
    plugin::Repository repo(mgr);
    simulator::DefaultSimulation simulation(repo);
    auto object = record.createObject("object", simulation, object::Object::Type::Static);
    ASSERT_NE(nullptr, object);

    EXPECT_EQ(typeid(TestObject), typeid(*object));
}

/* ************************************************************************ */

TEST(RepositoryRecord, program)
{
    RepositoryRecord record("");

    EXPECT_FALSE(record.isRegisteredProgram("program"));
    record.registerProgram<TestProgram>("program");
    EXPECT_TRUE(record.isRegisteredProgram("program"));

    auto program = record.createProgram("program");
    ASSERT_NE(nullptr, program);

    EXPECT_EQ(typeid(TestProgram), typeid(*program));
}

/* ************************************************************************ */
