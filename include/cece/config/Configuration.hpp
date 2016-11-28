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

#pragma once

/* ************************************************************************ */

// CeCe
#include "cece/String.hpp"
#include "cece/StringView.hpp"
#include "cece/UniquePtr.hpp"
#include "cece/SharedPtr.hpp"
#include "cece/ViewPtr.hpp"
#include "cece/DynamicArray.hpp"
#include "cece/io/StringStream.hpp"
#include "cece/config/Exception.hpp"
#include "cece/config/Converter.hpp"

/* ************************************************************************ */

namespace cece { class Parameters; }

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

class Implementation;

/* ************************************************************************ */

/**
 * @brief      A interface for configuration.
 *
 * @details    The configuration is an interface for different configuration
 *             implementations (see `Implementation`). This class is just a
 *             layer used to hide real configuration implementation where the
 *             data can be stored in the memory or somewhere else.
 */
class Configuration
{

// Public Ctors
public:


    /**
     * @brief      Constructor.
     *
     * @param      impl        Implementation.
     * @param      parameters  Optional parameters.
     */
    explicit Configuration(UniquePtr<Implementation> impl, ViewPtr<Parameters> parameters = nullptr);


    /**
     * @brief      Constructor (memory version).
     *
     * @param      parameters  Optional parameters.
     */
    explicit Configuration(ViewPtr<Parameters> parameters = nullptr);


// Public Accessors & Mutators
public:


    /**
     * @brief      Checks if a value is stored under given name.
     *
     * @param      name  The name.
     *
     * @return     `true` if value is stored, `false` otherwise.
     */
    bool has(StringView name) const;


    /**
     * @brief      Returns stored value.
     *
     * @param      name  The name.
     *
     * @return     Stored value with replaced parameters.
     *
     * @throws     NotFoundException  When no value is stored.
     */
    String get(StringView name) const;


    /**
     * @brief      Returns stored value.
     *
     * @param      name  The name.
     * @param      def   Default value returned if no value is stored..
     *
     * @return     Stored value with replaced parameters.
     */
    String get(StringView name, String def) const;


    /**
     * @brief      Returns stored value.
     *
     * @param      name  The name.
     * @param      def   Default value returned if no value is stored..
     *
     * @return     Stored value with replaced parameters.
     */
    String get(StringView name, const char* def) const
    {
        return get(name, String(def));
    }


    /**
     * @brief      Store a value.
     *
     * @param      name   The name.
     * @param      value  The value to store.
     */
    void set(StringView name, String value);


    /**
     * @brief      Store a value.
     *
     * @param      name   The name.
     * @param      value  The value to store.
     */
    void set(StringView name, const char* value)
    {
        set(name, String(value));
    }


    /**
     * @brief      Returns stored value converted into required type.
     *
     * @details    Conversion is done by `Converter` class which allows you to
     *             define custom conversion rules.
     *
     * @param      name  The name.
     *
     * @tparam     T     The required result type.
     *
     * @return     Result value.
     */
    template<typename T>
    T get(StringView name) const
    {
        return Converter<T>::fromString(get(name));
    }


    /**
     * @brief      Returns stored value converted into required type.
     *
     * @details    Conversion is done by `Converter` class which allows you to
     *             define custom conversion rules.
     *
     * @param      name  The name.
     * @param      def   Default value returned if no value is stored..
     *
     * @tparam     T     Required value type.
     *
     * @return     Stored value with replaced parameters (the default value is
     *             not replaced).
     */
    template<typename T>
    T get(StringView name, T def) const
    {
        return has(name) ? get<T>(name) : std::move(def);
    }


    /**
     * @brief      Store a value.
     *
     * @details    Conversion is done by `Converter` class which allows you to
     *             define custom conversion rules.
     *
     * @param      name   The name.
     * @param      value  The value to store.
     *
     * @tparam     T      Value type.
     */
    template<typename T>
    void set(StringView name, const T& value) noexcept
    {
        set(name, Converter<T>::toString(value));
    }


    /**
     * @brief      Returns list of names under which values are stored.
     *
     * @return     A list of names.
     */
    DynamicArray<String> getNames() const;


    /**
     * @brief      Checks if the configuration contains a content.
     *
     * @return     If content is present.
     */
    bool hasContent() const;


    /**
     * @brief      Returns the configuration content.
     *
     * @return     The content with replaced parameters.
     */
    String getContent() const;


    /**
     * @brief      Change configuration content.
     *
     * @param      content  The new content.
     */
    void setContent(String content);


    /**
     * @brief      Check if at least one child configuration exists.
     *
     * @param      name  The child configuration name.
     *
     * @return     `true` if exists, `false` otherwise.
     */
    bool hasConfiguration(StringView name) const;


    /**
     * @brief      Returns the first child configuration with given name.
     *
     * @param      name  The child configuration name.
     *
     * @return     The child configuration.
     *
     * @throws     NotFoundException  If no child configuration exists:
     *                                `hasConfiguration` returns `false`.
     */
    Configuration getConfiguration(StringView name) const;


    /**
     * @brief      Returns child configurations with given name.
     *
     * @param      name  The child configuration name.
     *
     * @return     List of child configurations.
     */
    DynamicArray<Configuration> getConfigurations(StringView name) const;


    /**
     * @brief      Returns list of available child configuration names.
     *
     * @return     A list of names.
     */
    DynamicArray<String> getConfigurationNames() const;


    /**
     * @brief      Create new child configuration.
     *
     * @param      name  The child configuration name.
     *
     * @return     New child configuration.
     */
    Configuration addConfiguration(StringView name);


// Public Operations
public:


    /**
     * @brief      Append configuration values from other one.
     *
     * @param      src   The source configuration.
     */
    void append(const Configuration& src);


    /**
     * @brief      Create a configuration which uses memory implementation.
     *
     * @details    This function is useful when you need to store configuration
     *             for later use and the used implementation might not be valid
     *             at time when you wan to use.
     *
     * @return     The new configuration.
     */
    Configuration toMemory() const;


// Private Operations
private:


    /**
     * @brief      Replace parameters in given string.
     *
     * @details    Function replaces special expressions `{$name}` where the
     *             `name` is a parameter name.
     *
     * @param      str   The source string.
     *
     * @return     Result string with replaced parameters.
     */
    String replaceParameters(String str) const;


// Private Data Members
private:

    /// Configuration implementation.
    SharedPtr<Implementation> m_impl;

    /// Optional parameters.
    ViewPtr<Parameters> m_parameters;
};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
