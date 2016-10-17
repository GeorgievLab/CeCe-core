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
#include "cece/plugin/SharedLibraryLoader.hpp"

// CeCe
#include "cece/core/Assert.hpp"
#include "cece/core/Log.hpp"
#include "cece/core/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

DynamicArray<Plugin> SharedLibraryLoader::loadAll(const FilePath& directory)
{
    Log::debug("Scanning `", directory, "` for shared library plugins");

    // Not a directory
    if (!isDirectory(directory))
    {
        Log::warning("`", directory, "` is not a directory, skipping...");
        return {};
    }

    CECE_ASSERT(isDirectory(directory));

    DynamicArray<Plugin> result;

    // Foreach directory
    for (const auto& path : openDirectory(directory))
    {
        // Only files
        if (!isFile(path))
        {
            Log::debug("Skipping `", path, "` - not a file");
            continue;
        }

        // Get path
        const auto filename = path.getFilename();
        const auto prefixLength = SharedLibrary::FILE_PREFIX.length();
        const auto suffixLength = SharedLibrary::FILE_EXTENSION.length();
        const auto suffixStart = filename.length() - suffixLength;

        Log::debug("Checking: ", filename);

        // Different prefix
        if (filename.substr(0, prefixLength) != SharedLibrary::FILE_PREFIX)
            continue;

        // Different extension
        if (filename.substr(suffixStart) != SharedLibrary::FILE_EXTENSION)
            continue;

        // Plugin name
        const String name = filename.substr(prefixLength, suffixStart - prefixLength);

        Log::debug("Loading plugin: ", name, " @ ", path);

        try
        {
            // Open shared library
            SharedLibrary lib(path);

            // Obtain API from library
            auto api = lib.createApi();

            // Store library
            m_libraries.push_back(std::move(lib));
            result.emplace_back(name, std::move(api));
        }
        catch (const Exception& e)
        {
            Log::warning("Unable to load shared library from: ", path, " (", e.what(), ")");
        }
    }

    return result;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
