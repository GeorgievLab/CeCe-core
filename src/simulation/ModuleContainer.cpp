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
#include "cece/simulation/ModuleContainer.hpp"

// C++
#include <algorithm>

// CeCe
#include "cece/simulation/Module.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

void ModuleContainer::init(async::AtomicBool& flag)
{
    // Update modules
    for (auto& module : getSortedListAsc())
    {
        if (!flag)
            break;

        module->init(flag);
    }
}

/* ************************************************************************ */

void ModuleContainer::update()
{
    // Update modules
    for (auto& module : getSortedListAsc())
        module->update();
}

/* ************************************************************************ */

void ModuleContainer::terminate()
{
    // Update modules
    for (auto& module : getSortedListDesc())
        module->terminate();
}

/* ************************************************************************ */

#ifdef CECE_RENDER
void ModuleContainer::draw(const simulation::Visualization& visualization, render::Context& context)
{
    const RenderState& state = m_drawableState.getFront();

    // Copy list
    DynamicArray<ViewPtr<Module>> modules = state.modules;

    // Sort modules by rendering order
    std::sort(modules.begin(), modules.end(), [](const ViewPtr<Module>& lhs, const ViewPtr<Module>& rhs) {
        return lhs->getZOrder() < rhs->getZOrder();
    });

    // Render modules
    for (auto& module : modules)
        module->draw(visualization, context);
}
#endif

/* ************************************************************************ */

#ifdef CECE_RENDER
void ModuleContainer::drawStoreState(const simulation::Visualization& visualization)
{
    RenderState& state = m_drawableState.getBack();
    state.modules.clear();

    for (auto& p : *this)
    {
        p.second->drawStoreState(visualization);
        // Store module to draw
        state.modules.push_back(p.second);
    }
}
#endif

/* ************************************************************************ */

#ifdef CECE_RENDER
void ModuleContainer::drawSwapState()
{
    for (auto& p : *this)
        p.second->drawSwapState();

    m_drawableState.swap();
}
#endif

/* ************************************************************************ */

DynamicArray<ViewPtr<Module>> ModuleContainer::getSortedListAsc() const noexcept
{
    DynamicArray<ViewPtr<Module>> modules;

    // Copy modules (view pointer)
    for (const auto& p : *this)
        modules.push_back(p.second);

    // Sort modules by priority. Cannot be precomputed, because priority can change in previous iteration
    std::sort(modules.begin(), modules.end(),
        [](const ViewPtr<Module>& lhs, const ViewPtr<Module>& rhs) {
            return lhs->getPriority() > rhs->getPriority();
    });

    return modules;
}

/* ************************************************************************ */

DynamicArray<ViewPtr<Module>> ModuleContainer::getSortedListDesc() const noexcept
{
    DynamicArray<ViewPtr<Module>> modules;

    // Copy modules (view pointer)
    for (const auto& p : *this)
        modules.push_back(p.second);

    // Sort modules by priority. Cannot be precomputed, because priority can change in previous iteration
    std::sort(modules.begin(), modules.end(),
        [](const ViewPtr<Module>& lhs, const ViewPtr<Module>& rhs) {
            return lhs->getPriority() < rhs->getPriority();
    });

    return modules;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
