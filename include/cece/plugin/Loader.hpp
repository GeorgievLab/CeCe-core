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
#include "cece/ViewPtr.hpp"
#include "cece/DynamicArray.hpp"
#include "cece/io/FilePath.hpp"
#include "cece/plugin/Plugin.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief      Plugin loader interface. Allows to load plugins other than shared
 *             library.
 *
 * @details    Loader have to implement `loadAll` member function which scans
 *             given directory for plugins that match loader requirements. There
 *             is no checks if other loader loaded the same plugin.
 */
class Loader
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Destructor.
     */
    virtual ~Loader() = 0;


// Public Operations
public:


    /**
     * @brief      Load all plugins from given directory.
     *
     * @param      directory  Directory to where are plugins located. The
     *                        directory may not exists.
     *
     * @return     A list of loaded plugins.
     */
    virtual DynamicArray<Plugin> loadAll(const io::FilePath& directory) = 0;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */