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
#include "cece/core/String.hpp"
#include "cece/io/FilePath.hpp"
#include "cece/core/Exception.hpp"
#include "cece/core/DynamicArray.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief      Base class for all plugin exceptions.
 */
class Exception : public cece::RuntimeException
{

// Public Ctors & Dtors
public:

    using cece::RuntimeException::RuntimeException;
};

/* ************************************************************************ */

/**
 * @brief      Exception thrown in case of invalid plugin loading.
 */
class InvalidPluginException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  path  The source plugin file path.
     * @param[in]  msg   The error message.
     */
    explicit InvalidPluginException(io::FilePath path, String msg) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns plugin file path.
     *
     * @return     The plugin file path.
     */
    const io::FilePath& getPath() const noexcept
    {
        return m_path;
    }


    /**
     * @brief      Returns the error message.
     *
     * @return     The error message.
     */
    const String& getErrorMessage() const noexcept
    {
        return m_errorMessage;
    }


// Private Data Members
private:

    /// Plugin source path.
    io::FilePath m_path;

    /// Error message.
    String m_errorMessage;
};

/* ************************************************************************ */

/**
 * @brief      Expection used when used by repository.
 */
class RepositoryException : public Exception
{

// Public Ctors & Dtors
public:

    using Exception::Exception;

};

/* ************************************************************************ */

/**
 * @brief      Expection used when trying to import plugin that doesn't exists.
 */
class PluginNotFoundException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  name  The plugin name.
     */
    explicit PluginNotFoundException(String name) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns plugin name.
     *
     * @return     The plugin name.
     */
    const String& getName() const noexcept
    {
        return m_name;
    }


// Private Data Members
private:

    /// Plugin name.
    String m_name;

};

/* ************************************************************************ */

/**
 * @brief      Exception thrown in case of plugin extension multiple definition.
 */
class MultipleExtensionsException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  kind     The extension kind.
     * @param[in]  name     The extension name.
     * @param[in]  plugins  The plugins where the extension was found.
     */
    explicit MultipleExtensionsException(String kind, String name, DynamicArray<String> plugins) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns extension kind.
     *
     * @return     The extension kind.
     */
    const String& getKind() const noexcept
    {
        return m_kind;
    }


    /**
     * @brief      Returns extension name.
     *
     * @return     The extension name.
     */
    const String& getName() const noexcept
    {
        return m_name;
    }


    /**
     * @brief      Returns a list of plugin names where the name was found.
     *
     * @return     A list of plugin names.
     */
    const DynamicArray<String>& getPluginNames() const noexcept
    {
        return m_pluginNames;
    }


// Private Data Members
private:

    /// Plugin extension kind.
    String m_kind;

    /// Plugin extension name.
    String m_name;

    /// A list of plugin names.
    DynamicArray<String> m_pluginNames;
};

/* ************************************************************************ */

/**
 * @brief      Exception thrown in case of plugin extension multiple definition.
 */
class ExtensionNotFoundException : public Exception
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param[in]  kind     The extension kind.
     * @param[in]  name     The extension name.
     * @param[in]  plugins  The plugins where the extension was found.
     */
    explicit ExtensionNotFoundException(String kind, String name, DynamicArray<String> plugins) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns extension kind.
     *
     * @return     The extension kind.
     */
    const String& getKind() const noexcept
    {
        return m_kind;
    }


    /**
     * @brief      Returns extension name.
     *
     * @return     The extension name.
     */
    const String& getName() const noexcept
    {
        return m_name;
    }


    /**
     * @brief      Returns a list of plugin names where the name was found.
     *
     * @return     A list of plugin names.
     */
    const DynamicArray<String>& getPluginNames() const noexcept
    {
        return m_pluginNames;
    }


// Private Data Members
private:

    /// Plugin extension kind.
    String m_kind;

    /// Plugin extension name.
    String m_name;

    /// A list of plugin names.
    DynamicArray<String> m_pluginNames;
};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
