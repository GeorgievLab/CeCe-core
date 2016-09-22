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
#include "cece/core/DynamicArray.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/Plugin.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief Plugin loader interface. Allows to load plugins other than
 * shared library.
 */
class Loader
{

// Public Ctors & Dtors
public:


    /**
     * @brief Destructor.
     */
    virtual ~Loader() = 0;


// Public Operations
public:


    /**
     * @brief Scan given directory to load plugins.
     *
     * @param directory Directory to scan.
     *
     * @return A list of loaded plugins.
     */
    virtual DynamicArray<Plugin> scanDirectory(const FilePath& directory) = 0;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */