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

// Declaration
#include "cece/simulator/DefaultSimulation.hpp"

// C++
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iterator>
#include <iomanip>

// Box2D
#include <Box2D/Box2D.h>

// CeCe
#include "cece/Assert.hpp"
#include "cece/core/Real.hpp"
#include "cece/Exception.hpp"
#include "cece/log/Log.hpp"
#include "cece/unit/UnitIo.hpp"
#include "cece/io/FileStream.hpp"
#include "cece/io/OutStream.hpp"
#include "cece/plugin/Api.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/init/Initializer.hpp"
#include "cece/module/Module.hpp"
#include "cece/object/ContactListener.hpp"
#include "cece/simulator/TimeMeasurement.hpp"
#include "cece/simulator/ConverterBox2D.hpp"

#ifdef CECE_RENDER
#  include "cece/render/PhysicsDebugger.hpp"
#endif

/* ************************************************************************ */

namespace cece {
namespace simulator {

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

#ifdef CECE_RENDER
// TODO make as simulation local
/// Physics debugger
render::PhysicsDebugger g_physicsDebugger;
#endif

/* ************************************************************************ */

}

/* ************************************************************************ */

struct DefaultSimulation::ContactListener : public b2ContactListener
{
    object::ContactListener* m_listener;

    void BeginContact(b2Contact* contact) override
    {
        if (!m_listener)
            return;

        auto body1 = contact->GetFixtureA()->GetBody();
        auto body2 = contact->GetFixtureB()->GetBody();
        auto o1 = static_cast<object::Object*>(body1->GetUserData());
        auto o2 = static_cast<object::Object*>(body2->GetUserData());

        m_listener->onContact(*o1, *o2);
    }
};

/* ************************************************************************ */

DefaultSimulation::DefaultSimulation(const plugin::Manager& manager, io::FilePath path) noexcept
    : m_pluginManager(manager)
    , m_pluginContext(m_pluginManager)
    , m_fileName(std::move(path))
    , m_world{makeUnique<b2World>(b2Vec2{0.0f, 0.0f})}
{
#ifdef CECE_RENDER
    g_physicsDebugger.SetFlags(
        render::PhysicsDebugger::e_shapeBit |
        render::PhysicsDebugger::e_centerOfMassBit |
        render::PhysicsDebugger::e_jointBit
    );

    // Set physics debugger
    m_world->SetDebugDraw(&g_physicsDebugger);
#endif
}

/* ************************************************************************ */

DefaultSimulation::~DefaultSimulation()
{
    terminate();
}

/* ************************************************************************ */

UniquePtr<io::InOutStream> DefaultSimulation::getResource(StringView name) noexcept
{
    // Path to resource
    const auto path = getFileName().getParentPath() / String(name);

    if (!pathExists(path))
        return nullptr;

    auto file = makeUnique<io::FileStream>(path.toString(), std::ios::in | std::ios::out | std::ios::binary);

    if (!file->is_open())
        return nullptr;

    return UniquePtr<io::InOutStream>{file.release()};
}

/* ************************************************************************ */

bool DefaultSimulation::hasParameter(StringView name) const noexcept
{
    return m_parameters.exists(name);
}

/* ************************************************************************ */

String DefaultSimulation::getParameter(StringView name) const
{
    return m_parameters.get(name);
}

/* ************************************************************************ */

bool DefaultSimulation::hasModule(StringView name) const noexcept
{
    return m_modules.exists(name);
}

/* ************************************************************************ */

ViewPtr<module::Module> DefaultSimulation::getModule(StringView name) const noexcept
{
    return m_modules.get(name);
}

/* ************************************************************************ */

bool DefaultSimulation::hasProgram(StringView name) const noexcept
{
    return m_programs.exists(name);
}

/* ************************************************************************ */

UniquePtr<program::Program> DefaultSimulation::getProgram(StringView name) const
{
    auto program = m_programs.get(name);

    if (program)
        return program->clone();

    return m_pluginContext.createProgram(name);
}

/* ************************************************************************ */

std::size_t DefaultSimulation::getObjectCount() const noexcept
{
    return m_objects.getCount();
}

/* ************************************************************************ */

std::size_t DefaultSimulation::getObjectCount(StringView type) const noexcept
{
    return m_objects.getCountByType(type);
}

/* ************************************************************************ */

DynamicArray<ViewPtr<object::Object>> DefaultSimulation::getObjects() const noexcept
{
    DynamicArray<ViewPtr<object::Object>> objects;
    objects.reserve(m_objects.getCount());

    for (const auto& object : m_objects)
        objects.push_back(object);

    return objects;
}

/* ************************************************************************ */

DynamicArray<ViewPtr<object::Object>> DefaultSimulation::getObjects(StringView type) const noexcept
{
    return m_objects.getByType(type);
}

/* ************************************************************************ */

unit::AccelerationVector DefaultSimulation::getGravity() const noexcept
{
    return ConverterBox2D::getInstance().convertLinearAcceleration(m_world->GetGravity());
}

/* ************************************************************************ */

unit::Time DefaultSimulation::getPhysicsEngineTimeStep() const noexcept
{
    return ConverterBox2D::getInstance().getTimeStepBox2D();
}

/* ************************************************************************ */

unit::Length DefaultSimulation::getMaxObjectTranslation() const noexcept
{
    return ConverterBox2D::getInstance().getMaxObjectTranslation();
}

/* ************************************************************************ */

ViewPtr<const plugin::Api> DefaultSimulation::loadPlugin(StringView name)
{
    auto api = m_pluginContext.importPlugin(name);

    if (!api)
        return nullptr;

    // Init simulation
    //api->initSimulation(*this);

    return api;
}

/* ************************************************************************ */

void DefaultSimulation::unloadPlugin(StringView name)
{
    auto api = m_pluginContext.removePlugin(name);

    if (!api)
        return;

    // Finalize simulation
    //api->finalizeSimulation(*this);
}

/* ************************************************************************ */

void DefaultSimulation::setTimeStep(unit::Time dt)
{
    if (dt == math::Zero)
        throw InvalidArgumentException("Time step cannot be zero");

    m_timeStep = dt;

    ConverterBox2D::getInstance().setTimeStep(dt);
}

/* ************************************************************************ */

void DefaultSimulation::setParameter(String name, String value)
{
    m_parameters.set(std::move(name), std::move(value));
}

/* ************************************************************************ */

ViewPtr<init::Initializer> DefaultSimulation::addInitializer(UniquePtr<init::Initializer> initializer)
{
    return m_initializers.add(std::move(initializer));
}

/* ************************************************************************ */

ViewPtr<init::Initializer> DefaultSimulation::createInitializer(StringView type)
{
    return addInitializer(m_pluginContext.createInitializer(type));
}

/* ************************************************************************ */

void DefaultSimulation::deleteInitializer(ViewPtr<init::Initializer> initializer)
{
    m_initializers.remove(initializer);
}

/* ************************************************************************ */

ViewPtr<module::Module> DefaultSimulation::addModule(String name, UniquePtr<module::Module> module)
{
    return m_modules.add(std::move(name), std::move(module));
}

/* ************************************************************************ */

ViewPtr<module::Module> DefaultSimulation::createModule(StringView type)
{
    return addModule(String(type), m_pluginContext.createModule(type, *this));
}

/* ************************************************************************ */

void DefaultSimulation::deleteModule(StringView name)
{
    m_modules.remove(name);
}

/* ************************************************************************ */

void DefaultSimulation::addObjectType(String name, String parent, const config::Configuration& config)
{
    return m_objectTypes.add(object::Type{
        std::move(name),
        std::move(parent),
        config.toMemory()
    });
}

/* ************************************************************************ */

ViewPtr<object::Object> DefaultSimulation::addObject(UniquePtr<object::Object> object)
{
    return m_objects.add(std::move(object));
}

/* ************************************************************************ */

ViewPtr<object::Object> DefaultSimulation::createObject(StringView type)
{
    return createObject(type, object::Object::Type::Dynamic);
}

/* ************************************************************************ */

ViewPtr<object::Object> DefaultSimulation::createObject(StringView type, object::Object::Type state)
{
    // Look in object types
    if (m_objectTypes.exists(type))
    {
        auto objType = m_objectTypes.get(type);

        // Create base object
        auto object = createObject(objType->baseName);
        object->setTypeName(String(type));
        object->configure(objType->config, *this);

        return object;
    }
    else
    {
        return addObject(m_pluginContext.createObject(type, *this, state));
    }
}

/* ************************************************************************ */

void DefaultSimulation::deleteObject(ViewPtr<object::Object> object)
{
    m_objects.deleteObject(object);
}

/* ************************************************************************ */

ViewPtr<program::Program> DefaultSimulation::addProgram(String name, UniquePtr<program::Program> program)
{
    return m_programs.add(std::move(name), std::move(program));
}

/* ************************************************************************ */

ViewPtr<program::Program> DefaultSimulation::createProgram(String name, StringView type)
{
    return addProgram(std::move(name), m_pluginContext.createProgram(type));
}

/* ************************************************************************ */

void DefaultSimulation::deleteProgram(StringView name)
{
    m_programs.remove(name);
}

/* ************************************************************************ */

void DefaultSimulation::setGravity(const unit::AccelerationVector& gravity) noexcept
{
    m_world->SetGravity(ConverterBox2D::getInstance().convertLinearAcceleration(gravity));
}

/* ************************************************************************ */

void DefaultSimulation::setPhysicsEngineTimeStep(unit::Time dt) noexcept
{
    ConverterBox2D::getInstance().setTimeStepBox2D(dt);
}

/* ************************************************************************ */

void DefaultSimulation::setContactListener(object::ContactListener* listener)
{
    if (listener)
    {
        if (!m_contactListener)
            m_contactListener = makeUnique<ContactListener>();

        m_contactListener->m_listener = listener;
        m_world->SetContactListener(m_contactListener.get());
    }
    else
    {
        m_world->SetContactListener(nullptr);
    }
}

/* ************************************************************************ */

void DefaultSimulation::loadConfig(const config::Configuration& config)
{
    if (config.has("length-coefficient"))
    {
        // TODO make as simulation local
        ConverterBox2D::getInstance().setLengthCoefficient(config.get<RealType>("length-coefficient"));
#ifdef CECE_RENDER
        g_physicsDebugger.setScale(1.0 / simulator::ConverterBox2D::getInstance().getLengthCoefficient());
#endif
    }

    Simulation::loadConfig(config);

    setGravity(config.get("gravity", getGravity()));
}

/* ************************************************************************ */

void DefaultSimulation::storeConfig(config::Configuration& config) const
{
    Simulation::storeConfig(config);

    config.set("length-coefficient", ConverterBox2D::getInstance().getLengthCoefficient());
    config.set("gravity", getGravity());
}

/* ************************************************************************ */

void DefaultSimulation::initialize(async::AtomicBool& flag)
{
    CECE_ASSERT(!isInitialized());

    // Add pending objects
    m_objects.addPending();

    // Initialize modules
    m_modules.init(flag);

    if (!flag)
        return;

    // Add pending objects
    m_objects.addPending();

    // Initialize simulation
    m_initializers.init(*this);

    // Update states
#ifdef CECE_RENDER
    m_modules.drawStoreState(m_visualization);
    m_objects.drawStoreState(m_visualization);
#endif

#ifdef CECE_RENDER
    {
#ifdef CECE_THREAD_SAFE
        MutexGuard _(m_mutex);
#endif
        // Swap states
        m_modules.drawSwapState();
        m_objects.drawSwapState();
    }
#endif

    // Mark simulation initialized
    m_initialized = true;
}

/* ************************************************************************ */

bool DefaultSimulation::update()
{
    // Initialize simulation
    if (!isInitialized())
        throw RuntimeException("Simulation is not initialized");

    // Increase step number
    m_iteration++;
    m_totalTime += getTimeStep();

    // Clear all stored forces
    for (auto& obj : m_objects)
        obj->setForce(math::Zero);

    // Update modules
    updateModules();

    // Update objects
    updateObjects();

    {
        auto _ = perf::measure_time("sim.physics", TimeMeasurement(this));

        m_world->Step(static_cast<float32>(getPhysicsEngineTimeStep().value()), 10, 10);
    }

    // Detect object that leaved the scene
    detectDeserters();

    // Update states
#ifdef CECE_RENDER
    m_modules.drawStoreState(m_visualization);
    m_objects.drawStoreState(m_visualization);
#endif

#ifdef CECE_RENDER
    {
#ifdef CECE_THREAD_SAFE
        MutexGuard _(m_mutex);
#endif
        // Swap states
        m_modules.drawSwapState();
        m_objects.drawSwapState();
    }
#endif

    {
#ifdef CECE_THREAD_SAFE
        MutexGuard _(m_mutex);
#endif
        // Remove deleted objects
        m_objects.removeDeleted();

        // Add pending objects
        m_objects.addPending();
    }

    return (hasUnlimitedIterations() || getIteration() <= getIterations());
}

/* ************************************************************************ */

bool DefaultSimulation::reset()
{
    // Resetting si not supported
    return false;
}

/* ************************************************************************ */

void DefaultSimulation::terminate()
{
    m_initialized = false;

    // Terminate modules
    m_modules.terminate();

    // Call finalize simulations for all plugins
    const auto& plugins = m_pluginContext.getImportedPlugins();
    for (auto it = plugins.rbegin(); it != plugins.rend(); ++it)
    {
        auto api = m_pluginManager.getApi(*it);
        CECE_ASSERT(api);
        //api->finalizeSimulation(*this);
    }
}

/* ************************************************************************ */

#ifdef CECE_RENDER
void DefaultSimulation::draw(render::Context& context)
{
    context.setStencilBuffer(
        static_cast<float>(getWorldSize().getWidth().value()),
        static_cast<float>(getWorldSize().getHeight().value())
    );

#ifdef CECE_THREAD_SAFE
    MutexGuard _(m_mutex);
#endif

    // Render modules
    if (m_visualization.isEnabled("modules", true))
        m_modules.draw(m_visualization, context);

    // Draw objects
    if (m_visualization.isEnabled("objects", true))
        m_objects.draw(context);

    if (m_visualization.isEnabled("physics", false))
        m_world->DrawDebugData();
}
#endif

/* ************************************************************************ */

void DefaultSimulation::updateModules()
{
    auto _ = perf::measure_time("sim.modules", TimeMeasurement(this));
    m_modules.update();
}

/* ************************************************************************ */

void DefaultSimulation::updateObjects()
{
    auto _ = perf::measure_time("sim.objects", TimeMeasurement(this));

    // Update simulations objects
    // Can't use range-for because update can add a new object.
    for (object::Container::SizeType i = 0u; i < m_objects.getCount(); ++i)
    {
        auto obj = m_objects[i];

        CECE_ASSERT(obj);
        obj->update(getTimeStep());
    }
}

/* ************************************************************************ */

void DefaultSimulation::detectDeserters()
{
    const auto hh = getWorldSize() * 0.5f;

    // Kill objects that are outside world
    for (auto& obj : m_objects)
    {
        // Ignore static objects
        if (obj->getType() == object::Object::Type::Static)
            continue;

        // Get object position
        const auto& pos = obj->getPosition();

        // Object is not in scene
        if (!pos.inRange(-hh, hh))
            m_objects.deleteObject(obj);
    };
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
