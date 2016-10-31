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
#include "cece/core/ViewPtr.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

// We don't need access to those objects, just define forward declaration
namespace cece { namespace config { class Configuration; } }
namespace cece { namespace plugin { class Repository; } }
namespace cece { namespace simulator { class Simulation; } }

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

class TestApi final : public Api
{

// Public Operations
public:


    /**
     * @brief Returns a list of required plugins.
     *
     * @return
     */
    DynamicArray<String> requiredPlugins() const override
    {
        return {"plugin1", "plugin2"};
    }


    /**
     * @brief Returns a list of plugins that will conflict with.
     *
     * @return
     */
    DynamicArray<String> conflictPlugins() const override
    {
        return {"plugin3", "plugin4"};
    }


    /**
     * @brief On plugin load.
     *
     * @param repository Plugins repository.
     */
    void onLoad(Repository& repository) override
    {
        onLoadCalled = true;
    }


    /**
     * @brief On plugin unload.
     *
     * @param repository Plugins repository.
     */
    void onUnload(Repository& repository) override
    {
        onUnloadCalled = true;
    }


    /**
     * @brief Init simulation.
     *
     * @param simulation Simulation.
     */
    void initSimulation(simulator::Simulation& simulation) const override
    {
        initSimulationCalled = true;
    }


    /**
     * @brief Finalize simulation.
     *
     * @param simulation Simulation.
     */
    void finalizeSimulation(simulator::Simulation& simulation) const override
    {
        finalizeSimulationCalled = true;
    }


    /**
     * @brief Load plugin configuration.
     *
     * @param simulation Current simulation.
     * @param config     Plugin configuration.
     */
    void loadConfig(simulator::Simulation& simulation, const config::Configuration& config) const override
    {
        loadConfigCalled = true;
    }


    /**
     * @brief Store plugin configuration.
     *
     * @param simulation Current simulation.
     * @param config     Plugin configuration.
     */
    void storeConfig(const simulator::Simulation& simulation, config::Configuration& config) const override
    {
        storeConfigCalled = true;
    }


// Public Data Members
public:

    mutable bool onLoadCalled = false;
    mutable bool onUnloadCalled = false;
    mutable bool initSimulationCalled = false;
    mutable bool finalizeSimulationCalled = false;
    mutable bool loadConfigCalled = false;
    mutable bool storeConfigCalled = false;
};

/* ************************************************************************ */

TEST(Api, virtualFunctions)
{
    auto api = makeUnique<TestApi>();
    ViewPtr<Api> base = api;

    ASSERT_NE(api, nullptr);
    ASSERT_NE(base, nullptr);
    ASSERT_EQ(base, api);

    // No access to those objects, just for passing references to the functions.
    Repository* repository = nullptr;
    config::Configuration* config = nullptr;
    simulator::Simulation* sim = nullptr;

    EXPECT_EQ((DynamicArray<String>{"plugin1", "plugin2"}), base->requiredPlugins());
    EXPECT_EQ((DynamicArray<String>{"plugin3", "plugin4"}), base->conflictPlugins());

    EXPECT_FALSE(api->onLoadCalled);
    base->onLoad(*repository);
    EXPECT_TRUE(api->onLoadCalled);

    EXPECT_FALSE(api->onUnloadCalled);
    base->onUnload(*repository);
    EXPECT_TRUE(api->onUnloadCalled);

    EXPECT_FALSE(api->initSimulationCalled);
    base->initSimulation(*sim);
    EXPECT_TRUE(api->initSimulationCalled);

    EXPECT_FALSE(api->finalizeSimulationCalled);
    base->finalizeSimulation(*sim);
    EXPECT_TRUE(api->finalizeSimulationCalled);

    EXPECT_FALSE(api->loadConfigCalled);
    base->loadConfig(*sim, *config);
    EXPECT_TRUE(api->loadConfigCalled);

    EXPECT_FALSE(api->storeConfigCalled);
    base->storeConfig(*sim, *config);
    EXPECT_TRUE(api->storeConfigCalled);

}

/* ************************************************************************ */
