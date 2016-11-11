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
#include "cece/plugin/RepositoryRecord.hpp"

// CeCe
#include "cece/loader/Loader.hpp"
#include "cece/init/Initializer.hpp"
#include "cece/module/Module.hpp"
#include "cece/object/Object.hpp"
#include "cece/program/Program.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

UniquePtr<loader::Loader> RepositoryRecord::createLoader(StringView name) const
{
    return m_loaderFactoryManager.createLoader(name);
}

/* ************************************************************************ */

UniquePtr<init::Initializer> RepositoryRecord::createInitializer(StringView name) const
{
    return m_initFactoryManager.createInitializer(name);
}

/* ************************************************************************ */

UniquePtr<module::Module> RepositoryRecord::createModule(StringView name, simulation::Simulation& simulation) const
{
    return m_moduleFactoryManager.createModule(name, simulation);
}

/* ************************************************************************ */

UniquePtr<object::Object> RepositoryRecord::createObject(StringView name, simulation::Simulation& simulation, object::Object::Type type) const
{
    return m_objectFactoryManager.createObject(name, simulation, type);
}

/* ************************************************************************ */

UniquePtr<program::Program> RepositoryRecord::createProgram(StringView name) const
{
    return m_programFactoryManager.createProgram(name);
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
