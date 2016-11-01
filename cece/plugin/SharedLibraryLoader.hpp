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
#include "cece/core/DynamicArray.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Loader.hpp"
#include "cece/plugin/SharedLibrary.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief      Shared library plugin loader.
 *
 * @details    Open shared libraries are open until object destruction. The
 *             reason for this is the plugin uses code from shared library and
 *             it must be loaded for whole time. Unloading removes those code
 *             from runtime and application will crash. After destruction of
 *             this object no plugin code should be called. Standard usage with
 *             `Manager` should guarantee that.
 */
class SharedLibraryLoader final : public Loader
{

// Public Operations
public:


    /**
     * @brief      Scan given directory to load plugins.
     *
     * @param[in]  directory  Directory to scan.
     *
     * @return     A list of loaded plugins.
     */
    DynamicArray<Plugin> loadAll(const FilePath& directory) override;


// Private Data Members
private:

    /// Loaded libraries.
    DynamicArray<SharedLibrary> m_libraries;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
