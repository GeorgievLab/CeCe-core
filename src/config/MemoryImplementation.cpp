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
#include "MemoryImplementation.hpp"

// CeCe
#include "cece/Assert.hpp"
#include "cece/config/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

struct MemoryData
{
    /// Stored values.
    StringMap<String> values;

    /// Stored content.
    String content;

    /// Child data
    StringMap<DynamicArray<SharedPtr<MemoryData>>> data;
};

/* ************************************************************************ */

MemoryImplementation::MemoryImplementation()
    : MemoryImplementation(makeShared<MemoryData>())
{
    // Nothing to do
}

/* ************************************************************************ */

MemoryImplementation::MemoryImplementation(SharedPtr<MemoryData> data)
    : m_data(std::move(data))
{
    // Nothing to do
}

/* ************************************************************************ */

bool MemoryImplementation::has(StringView name) const
{
    CECE_ASSERT(m_data);
#if __cplusplus >= 201402L
    return m_data->values.find(name) != m_data->values.end();
#else
    return m_data->values.find(String(name)) != m_data->values.end();
#endif
}

/* ************************************************************************ */

String MemoryImplementation::get(StringView name) const
{
    CECE_ASSERT(m_data);
#if __cplusplus >= 201402L
    auto it = m_data->values.find(name);
#else
    auto it = m_data->values.find(String(name));
#endif

    if (it == m_data->values.end())
        throw NotFoundException("Value stored under '" + String(name) + "' not found");

    return it->second;
}

/* ************************************************************************ */

void MemoryImplementation::set(StringView name, String value)
{
    CECE_ASSERT(m_data);
    m_data->values[String(name)] = std::move(value);
}

/* ************************************************************************ */

DynamicArray<String> MemoryImplementation::getNames() const
{
    CECE_ASSERT(m_data);

    DynamicArray<String> names;
    names.reserve(m_data->values.size());

    for (const auto& p : m_data->values)
        names.push_back(p.first);

    return names;
}

/* ************************************************************************ */

bool MemoryImplementation::hasContent() const
{
    CECE_ASSERT(m_data);
    return !m_data->content.empty();
}

/* ************************************************************************ */

String MemoryImplementation::getContent() const
{
    CECE_ASSERT(m_data);
    return m_data->content;
}

/* ************************************************************************ */

void MemoryImplementation::setContent(String content)
{
    CECE_ASSERT(m_data);
    m_data->content = std::move(content);
}

/* ************************************************************************ */

bool MemoryImplementation::hasChild(StringView name) const
{
    CECE_ASSERT(m_data);
#if __cplusplus >= 201402L
    return m_data->data.find(name) != m_data->data.end();
#else
    return m_data->data.find(String(name)) != m_data->data.end();
#endif
}

/* ************************************************************************ */

PtrDynamicArray<Implementation> MemoryImplementation::getChilds(StringView name) const
{
    CECE_ASSERT(m_data);

    // Find data
#if __cplusplus >= 201402L
    auto it = m_data->data.find(name);
#else
    auto it = m_data->data.find(String(name));
#endif

    // Nothing found
    if (it == m_data->data.end())
        return {};

    PtrDynamicArray<Implementation> res;

    for (const auto& ptr : it->second)
        res.push_back(makeUnique<MemoryImplementation>(ptr));

    return res;
}

/* ************************************************************************ */

DynamicArray<String> MemoryImplementation::getChildNames() const
{
    CECE_ASSERT(m_data);

    DynamicArray<String> names;
    names.reserve(m_data->data.size());

    for (const auto& p : m_data->data)
        names.push_back(p.first);

    return names;
}

/* ************************************************************************ */

UniquePtr<Implementation> MemoryImplementation::createChild(StringView name)
{
    // Create new shared data block
    auto data = makeShared<MemoryData>();

    // Register data
    CECE_ASSERT(m_data);
    m_data->data[String(name)].push_back(data);

    // Create implementation
    return makeUnique<MemoryImplementation>(std::move(data));
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
