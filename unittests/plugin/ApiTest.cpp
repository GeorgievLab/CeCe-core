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

namespace {

/* ************************************************************************ */

class DummyApi final : public Api {};

/* ************************************************************************ */

class TestApi final : public Api
{

// Public Operations
public:


    /**
     * @brief      When the plugin is loaded by plugin manager.
     *
     * @param      repository  Repository record for the plugin.
     */
    void onLoad(RepositoryRecord& repository) override
    {
        onLoadCalled = true;
    }


    /**
     * @brief      When the plugin is unloaded from plugin manager.
     *
     * @param      repository  Repository record for the plugin.
     */
    void onUnload(RepositoryRecord& repository) override
    {
        onUnloadCalled = true;
    }


    /**
     * @brief      When the plugin is imported into simulation.
     *
     * @param      simulation  The simulation which imports the plugin.
     * @param[in]  config      Plugin import configuration.
     */
    void onImport(simulator::Simulation& simulation, const config::Configuration& config) override
    {
        onImportCalled = true;
    }


    /**
     * @brief      When the plugin is being removed from the simulation.
     *
     * @param      simulation  The simulation.
     */
    void onRemove(simulator::Simulation& simulation) override
    {
        onRemoveCalled = true;
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
    mutable bool onImportCalled = false;
    mutable bool onRemoveCalled = false;
    mutable bool storeConfigCalled = false;
};

/* ************************************************************************ */

}

/* ************************************************************************ */

TEST(Api, dummy)
{
    // Api with no override can be used
    auto api = makeUnique<DummyApi>();

    // No access to those objects, just for passing references to the functions.
    RepositoryRecord* record = nullptr;
    config::Configuration* config = nullptr;
    simulator::Simulation* sim = nullptr;

    api->onLoad(*record);
    api->onUnload(*record);
    api->onImport(*sim, *config);
    api->onRemove(*sim);
    api->storeConfig(*sim, *config);
}

/* ************************************************************************ */

TEST(Api, virtualFunctions)
{
    auto api = makeUnique<TestApi>();
    ViewPtr<Api> base = api;

    ASSERT_NE(api, nullptr);
    ASSERT_NE(base, nullptr);
    ASSERT_EQ(base, api);

    // No access to those objects, just for passing references to the functions.
    RepositoryRecord* record = nullptr;
    config::Configuration* config = nullptr;
    simulator::Simulation* sim = nullptr;

    EXPECT_FALSE(api->onLoadCalled);
    base->onLoad(*record);
    EXPECT_TRUE(api->onLoadCalled);

    EXPECT_FALSE(api->onUnloadCalled);
    base->onUnload(*record);
    EXPECT_TRUE(api->onUnloadCalled);

    EXPECT_FALSE(api->onImportCalled);
    base->onImport(*sim, *config);
    EXPECT_TRUE(api->onImportCalled);

    EXPECT_FALSE(api->onRemoveCalled);
    base->onRemove(*sim);
    EXPECT_TRUE(api->onRemoveCalled);

    EXPECT_FALSE(api->storeConfigCalled);
    base->storeConfig(*sim, *config);
    EXPECT_TRUE(api->storeConfigCalled);

}

/* ************************************************************************ */
