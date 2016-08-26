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
#include "cece/plugin/LibraryLoader.hpp"

// CeCe
#include "cece/core/Log.hpp"
#include "cece/core/Tuple.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

Map<String, FilePath> LibraryLoader::scanDirectory(const FilePath& directory) const
{
    Map<String, FilePath> result;

    Log::debug("Scanning `", directory, "` for shared library plugins");

    if (!isDirectory(directory))
    {
        Log::warning("Directory `", directory, "` doesn't exists");
        return result;
    }

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
        const auto prefixLength = Library::FILE_PREFIX.length();
        const auto suffixLength = Library::FILE_EXTENSION.length();
        const auto suffixStart = filename.length() - suffixLength;

        Log::debug("Checking: ", filename);

        // Different prefix
        if (filename.substr(0, prefixLength) != Library::FILE_PREFIX)
            continue;

        // Different extension
        if (filename.substr(suffixStart) != Library::FILE_EXTENSION)
            continue;

        Log::debug("Plugin: ", filename.substr(prefixLength, suffixStart - prefixLength), " @ ", path);

        result.emplace(filename.substr(prefixLength, suffixStart - prefixLength), std::move(path));
    }

    return result;
}

/* ************************************************************************ */

ViewPtr<Api> LibraryLoader::loadPlugin(const String& name, const FilePath& path)
{
    // Try to find library in cache
    auto it = m_libraries.find(name);

    // Found
    if (it != m_libraries.end())
        return getValue<1>(*it).getApi();

    Log::debug("Loading shared library plugin `", name, "` from `", path, "`...");

    // Insert into cache
    auto ptr = m_libraries.emplace(std::piecewise_construct,
        std::forward_as_tuple(name),
        std::forward_as_tuple(name, path)
    );

    return getValue<1>(*getValue<0>(ptr)).getApi();
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
