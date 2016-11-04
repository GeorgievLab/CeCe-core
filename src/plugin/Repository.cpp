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
#include "cece/plugin/Repository.hpp"

// CeCe
#include "cece/core/Assert.hpp"
#include "cece/plugin/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

bool Repository::exists(StringView name) const noexcept
{
    return m_records.find(String(name)) != m_records.end();
}

/* ************************************************************************ */

RepositoryRecord& Repository::get(StringView name)
{
    auto it = m_records.find(String(name));

    if (it == m_records.end())
        throw RepositoryException("Record with name `" + String(name) + "` doesn't exists");

    return it->second;
}

/* ************************************************************************ */

const RepositoryRecord& Repository::get(StringView name) const
{
    auto it = m_records.find(String(name));

    if (it == m_records.end())
        throw RepositoryException("Record with name `" + String(name) + "` doesn't exists");

    return it->second;
}

/* ************************************************************************ */

RepositoryRecord& Repository::createRecord(String name)
{
    // Try to find existing record
    if (exists(name))
        throw RepositoryException("Record with name `" + name + "` already exists");

    auto pair = m_records.emplace(name, RepositoryRecord{});
    CECE_ASSERT(pair.second);
    return pair.first->second;
}

/* ************************************************************************ */

void Repository::removeRecord(StringView name) noexcept
{
    m_records.erase(String(name));
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
