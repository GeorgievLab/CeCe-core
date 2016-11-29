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
#include "cece/config/Configuration.hpp"

// C++
#include <utility>
#include <algorithm>

// CeCe
#include "cece/Assert.hpp"
#include "cece/Parameters.hpp"
#include "cece/Exception.hpp"
#include "cece/config/Implementation.hpp"

// Private
#include "MemoryImplementation.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

Configuration::Configuration(UniquePtr<Implementation> impl, ViewPtr<Parameters> parameters)
    : m_impl(std::move(impl))
    , m_parameters(parameters)
{
    // Nothing to do
}

/* ************************************************************************ */

Configuration::Configuration(ViewPtr<Parameters> parameters)
    : Configuration(makeUnique<MemoryImplementation>(), parameters)
{
    // Nothign to do
}

/* ************************************************************************ */

bool Configuration::has(StringView name) const
{
    CECE_ASSERT(m_impl);
    return m_impl->has(name);
}

/* ************************************************************************ */

String Configuration::get(StringView name) const
{
    CECE_ASSERT(m_impl);
    return replaceParameters(m_impl->get(name));
}

/* ************************************************************************ */

String Configuration::get(StringView name, String def) const
{
    CECE_ASSERT(m_impl);
    return has(name)
        ? replaceParameters(m_impl->get(name))
        : std::move(def)
    ;
}

/* ************************************************************************ */

void Configuration::set(StringView name, String value)
{
    CECE_ASSERT(m_impl);
    m_impl->set(name, std::move(value));
}

/* ************************************************************************ */

DynamicArray<String> Configuration::getNames() const
{
    CECE_ASSERT(m_impl);
    return m_impl->getNames();
}

/* ************************************************************************ */

bool Configuration::hasContent() const
{
    CECE_ASSERT(m_impl);
    return m_impl->hasContent();
}

/* ************************************************************************ */

String Configuration::getContent() const
{
    CECE_ASSERT(m_impl);
    return replaceParameters(m_impl->getContent());
}

/* ************************************************************************ */

void Configuration::setContent(String content)
{
    CECE_ASSERT(m_impl);
    m_impl->setContent(std::move(content));
}

/* ************************************************************************ */

bool Configuration::hasConfiguration(StringView name) const
{
    CECE_ASSERT(m_impl);
    return m_impl->hasChild(name);
}

/* ************************************************************************ */

Configuration Configuration::getConfiguration(StringView name) const
{
    if (!hasConfiguration(name))
        throw NotFoundException("No configuration found: " + String(name));

    auto&& configs = getConfigurations(name);
    CECE_ASSERT(!configs.empty());
    return configs[0];
}

/* ************************************************************************ */

DynamicArray<Configuration> Configuration::getConfigurations(StringView name) const
{
    DynamicArray<Configuration> res;

    CECE_ASSERT(m_impl);
    for (auto&& ptr : m_impl->getChilds(name))
        res.emplace_back(std::move(ptr), m_parameters);

    return res;
}

/* ************************************************************************ */

DynamicArray<String> Configuration::getConfigurationNames() const
{
    CECE_ASSERT(m_impl);
    return m_impl->getChildNames();
}

/* ************************************************************************ */

Configuration Configuration::addConfiguration(StringView name)
{
    CECE_ASSERT(m_impl);
    return Configuration{m_impl->createChild(name)};
}

/* ************************************************************************ */

void Configuration::append(const Configuration& config)
{
    // Overwrite values
    for (const auto& name : config.getNames())
        set(name, config.get(name));

    // Set content
    if (config.hasContent())
        setContent(config.getContent());

    // Append child configurations
    for (const auto& name : config.getConfigurationNames())
    {
        for (auto&& cfg : config.getConfigurations(name))
            addConfiguration(name).append(cfg);
    }
}

/* ************************************************************************ */

Configuration Configuration::toMemory() const
{
    Configuration config;
    config.append(*this);
    return config;
}

/* ************************************************************************ */

String Configuration::replaceParameters(String str) const
{
    // No parameters, nothing to replace
    if (!m_parameters)
        return str;

    String::size_type start = 0;

    // Find parameter begin part
    while ((start = str.find("{$")) != String::npos)
    {
        // {$var}
        // 012345

        // Find ending character
        const auto end = str.find('}', start + 2);

        if (end == String::npos)
            throw UnterminatedParameterException(std::move(str));

        // Copy name
        const String name = str.substr(start + 2, (end - start + 1) - 3);

        // Check name characters
        const auto valid = std::find_if(std::begin(name), std::end(name), [] (String::value_type c) {
            return !isalnum(c);
        }) == name.end();

        if (!valid)
            throw InvalidParameterNameException(std::move(name), std::move(str));

        // Try to find parameter
        const auto value = m_parameters->get(name);

        // Replace parameter with value
        str.replace(start, end - start + 1, value);
    }

    return str;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
