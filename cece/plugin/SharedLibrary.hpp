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

#if _WIN32
#include <windows.h>
#endif

// CeCe
#include "cece/core/String.hpp"
#include "cece/core/StringView.hpp"
#include "cece/core/FilePath.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief Shared library RAII wrapper.
 *
 * It hides OS-specific shared library handling.
 */
class SharedLibrary final
{

// Public Constants
public:


    /// Library file prefix
    static const String PREFIX;

    /// Library file extension
    static const String EXTENSION;


// Public Types
public:


#if _WIN32
    /// Handle type - Win32.
    using HandleType = HMODULE;
#else
    /// Handle type - POSIX.
    using HandleType = void*;
#endif


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


// Public Accessors & Mutators
public:


    /**
     * @brief Returns library path.
     *
     * @return Path to shared library.
     */
    const FilePath& getPath() const noexcept
    {
        return m_path;
    }


    /**
     * @brief Returns address of required symbol.
     *
     * @param name Symbol name.
     *
     * @return Pointer to symbol or nullptr.
     */
    void* getAddr(StringView name) const noexcept;


    /**
     * @brief Returns address of required symbol.
     *
     * @tparam T Type of the symbol.
     *
     * @param name Symbol name.
     *
     * @return Pointer to symbol or nullptr.
     */
    template<typename T>
    T getAddr(StringView name) const noexcept
    {
        return reinterpret_cast<T>(reinterpret_cast<std::intptr_t>(getAddr(name)));
    }


// Private Data Members
private:

    /// Path to library file.
    FilePath m_path;

    /// Shared library handle.
    HandleType m_handle = nullptr;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
