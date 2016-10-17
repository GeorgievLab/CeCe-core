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
#include "cece/core/ViewPtr.hpp"
#include "cece/core/UniquePtr.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Config.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

class Api;
class Context;

/* ************************************************************************ */

/**
 * @brief Shared library wrapper.
 */
class SharedLibrary final
{

// Public Constants
public:


    /// Library file prefix
    static const String FILE_PREFIX;

    /// Library file extension
    static const String FILE_EXTENSION;


// Public Types
public:


    /// Create API function pointer type.
    using CreateFn = Api* (*)();

    /// Returns plugin configuration.
    using GetConfigFn = Config* (*)();


// Public Ctors & Dtors
public:


    /**
     * @brief Default constructor.
     */
    SharedLibrary() = default;


    /**
     * @brief Constructor.
     *
     * @param path Path to shared library.
     */
    explicit SharedLibrary(FilePath path);


    /**
     * @brief Destructor.
     */
    ~SharedLibrary();


    /**
     * @brief Copy constructor.
     */
    SharedLibrary(const SharedLibrary&) = delete;


    /**
     * @brief Move constructor.
     */
    SharedLibrary(SharedLibrary&&) noexcept;


// Public Operators
public:


    /**
     * @brief Copy assignment operator.
     */
    SharedLibrary& operator=(const SharedLibrary&) = delete;


    /**
     * @brief Move assignment operator.
     */
    SharedLibrary& operator=(SharedLibrary&&) noexcept;


// Public Operations
public:


    /**
     * @brief Create plugin API.
     *
     * @Returns Created API.
     */
    UniquePtr<Api> createApi();


// Private Operations
private:


    /**
     * @brief Check configuration file.
     *
     * @param config
     *
     * @throw
     */
    void checkConfig(Config* config);


// Private Data Members
private:

    /// Path to library file.
    FilePath m_path;

    /// Shared library handle.
    void* m_handle = nullptr;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
