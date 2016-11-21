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
#include "cece/Exception.hpp"
#include "cece/simulation/Initializer.hpp"
#include "cece/simulation/Module.hpp"
#include "cece/simulation/Object.hpp"
#include "cece/simulation/Program.hpp"
#include "cece/plugin/definition.hpp"
#include "cece/plugin/Api.hpp"
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/RepositoryRecord.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

namespace {

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

}

/* ************************************************************************ */

class TestPluginApi : public Api
{

public:

    void onLoad(RepositoryRecord& repository) override
    {
        if (m_count != 0)
            throw RuntimeException("onLoad called multiple times");

        ++m_count;

        repository
            .registerInitializer<TestInitializer>("initializer")
            .registerModule<TestModule>("module")
            .registerObject<TestObject>("object")
            .registerProgram<TestProgram>("program")
        ;
    }

    void onUnload(RepositoryRecord& repository) override
    {
        --m_count;

        if (m_count != 0)
            throw RuntimeException("onUnload called multiple times");
    }

private:

    /// Number of onLoad calls
    int m_count = 0;

};

/* ************************************************************************ */

CECE_PLUGIN_DEFINE(test_plugin, TestPluginApi)

/* ************************************************************************ */
