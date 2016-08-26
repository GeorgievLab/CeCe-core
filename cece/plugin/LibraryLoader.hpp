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
#include "cece/core/ViewPtr.hpp"
#include "cece/core/Map.hpp"
#include "cece/core/String.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Loader.hpp"
#include "cece/plugin/Library.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief Shared library plugin loader.
 */
class LibraryLoader : public Loader
{

// Public Operations
public:


    /**
     * @brief Scan given directory to find available plugins.
     *
     * @param directory Directory to scan.
     *
     * @return Map of found plugins.
     */
    Map<String, FilePath> scanDirectory(const FilePath& directory) const override;


    /**
     * @brief Load plugin.
     *
     * @param name Plugin name.
     * @param path Path to plugin file.
     *
     * @return Pointer to plugin API. API is managed by loader.
     */
    ViewPtr<Api> loadPlugin(const String& name, const FilePath& path) override;


// Private Data Members
private:

    /// Loaded libraries.
    Map<String, Library> m_libraries;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
