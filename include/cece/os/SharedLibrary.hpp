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
#include "cece/export.hpp"
#include "cece/core/String.hpp"
#include "cece/core/StringView.hpp"
#include "cece/core/FilePath.hpp"

/* ************************************************************************ */

namespace cece {
namespace os {

/* ************************************************************************ */

/**
 * @brief      Shared library RAII wrapper.
 *
 * @details    It hides OS-specific shared library handling.
 */
class SharedLibrary final
{

// Public Constants
public:


    /// Library file prefix
    static const CECE_EXPORT String PREFIX;

    /// Library file extension
    static const CECE_EXPORT String EXTENSION;


// Public Ctors & Dtors
public:


    /**
     * @brief      Default constructor.
     */
    SharedLibrary() = default;


    /**
     * @brief      Constructor.
     *
     * @param      path  Path to shared library.
     */
    explicit SharedLibrary(FilePath path);


    /**
     * @brief      Destructor.
     */
    ~SharedLibrary();


    /**
     * @brief      Copy constructor.
     *
     * @param[in]  src Source object.
     */
    SharedLibrary(const SharedLibrary& src) = delete;


    /**
     * @brief      Move constructor.
     *
     * @param[in]  src Source object.
     */
    SharedLibrary(SharedLibrary&& src) noexcept;


// Public Operators
public:


    /**
     * @brief      Copy assignment operator.
     *
     * @param[in]  src   Source object.
     *
     * @return     *this.
     */
    SharedLibrary& operator=(const SharedLibrary& src) = delete;


    /**
     * @brief      Move assignment operator.
     *
     * @param[in]  src   Source object.
     *
     * @return     *this.
     */
    SharedLibrary& operator=(SharedLibrary&& src) noexcept;


// Public Accessors & Mutators
public:


    /**
     * @brief      Returns library path.
     *
     * @return     Path to shared library.
     */
    const FilePath& getPath() const noexcept
    {
        return m_path;
    }


    /**
     * @brief      Returns address of required symbol.
     *
     * @param[in]  name  Symbol name.
     *
     * @return     Pointer to symbol or nullptr.
     */
    void* getAddr(StringView name) const noexcept;


    /**
     * @brief      Returns address of required symbol.
     *
     * @param[in]  name       Symbol name.
     *
     * @tparam     Signature  Type of the symbol.
     *
     * @return     Pointer to symbol or nullptr.
     */
    template<typename Signature>
    Signature getAddr(StringView name) const noexcept
    {
        return reinterpret_cast<Signature>(reinterpret_cast<std::intptr_t>(getAddr(name)));
    }


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
