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

// CeCe
#include "cece/core/Exception.hpp"
#include "cece/init/Initializer.hpp"
#include "cece/module/Module.hpp"
#include "cece/object/Object.hpp"
#include "cece/program/Program.hpp"
#include "cece/plugin/definition.hpp"
#include "cece/plugin/Api.hpp"
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/RepositoryRecord.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

class TestInitializer : public init::Initializer
{
public:
    using init::Initializer::Initializer;

    void init(simulator::Simulation& simulation) const
    {
        // Nothing to do
    }
};

/* ************************************************************************ */

class TestModule : public module::Module
{
public:
    using module::Module::Module;
};

/* ************************************************************************ */

class TestObject : public object::Object
{
public:
    using object::Object::Object;
};

/* ************************************************************************ */

class TestProgram : public program::Program
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

class TestPluginApi : public Api
{

public:

    void onLoad(Repository& repository) override
    {
        if (m_count != 0)
            throw RuntimeException("onLoad called multiple times");

        ++m_count;

        repository.registerApi(this)
            .registerInitializer<TestInitializer>("initializer")
            .registerModule<TestModule>("module")
            .registerObject<TestObject>("object")
            .registerProgram<TestProgram>("program")
        ;
    }

    void onUnload(Repository& repository) override
    {
        --m_count;

        if (m_count != 0)
            throw RuntimeException("onUnload called multiple times");

        repository.unregisterApi(this);
    }

private:

    /// Number of onLoad calls
    int m_count = 0;

};

/* ************************************************************************ */

CECE_DEFINE_PLUGIN(test_plugin, TestPluginApi)

/* ************************************************************************ */
