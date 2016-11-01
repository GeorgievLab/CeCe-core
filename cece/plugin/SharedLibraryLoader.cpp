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
#include "cece/config.hpp"
#include "cece/core/Assert.hpp"
#include "cece/core/Log.hpp"
#include "cece/core/ViewPtr.hpp"
#include "cece/core/Exception.hpp"
#include "cece/plugin/definition.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/// Create API function pointer type.
using CreateFn = Api* (*)();

/* ************************************************************************ */

/// Returns plugin configuration.
using GetConfigFn = Config* (*)();

/* ************************************************************************ */

/**
 * @brief      Check configuration file.
 *
 * @param[in]  lib   The shared library.
 */
void checkConfig(const SharedLibrary& lib)
{
    auto path = lib.getPath().toString();

    // Get configuration
    auto getConfigFn = lib.getAddr<GetConfigFn>("get_config");

    if (!getConfigFn)
        throw RuntimeException("Shared library `" + path + "` doesn't contains 'get_config' function");

    // Get configuration
    auto config = getConfigFn();

    if (!config)
        throw RuntimeException("Plugin `" + path + "` returns no config");

    if (config->apiVersion != config::PLUGIN_API_VERSION)
        throw RuntimeException("Plugin `" + path + "` is built against different API version than CeCe");

    if (config->realSize != sizeof(config::RealType))
        throw RuntimeException("Plugin `" + path + "` is built with different real type than CeCe");

#ifdef CECE_RENDER
    if (!config->renderEnabled)
        throw RuntimeException("Plugin `" + path + "` is built without render support, but CeCe did");
#else
    if (config->renderEnabled)
        throw RuntimeException("Plugin `" + path + "` is built with render support, but CeCe didn't");
#endif

#ifdef CECE_THREAD_SAFE
    if (!config->threadSafe)
        throw RuntimeException("Plugin `" + path + "` is built without thread safety, but CeCe did");
#else
    if (config->threadSafe)
        throw RuntimeException("Plugin `" + path + "` is built with thread safety, but CeCe didn't");
#endif
}

/* ************************************************************************ */

/**
 * @brief      Create API from shared library.
 *
 * @param      lib   Shared library.
 *
 * @return     Plugin API.
 */
UniquePtr<Api> createApi(const SharedLibrary& lib)
{
    // Get create API function
    auto fn = lib.getAddr<CreateFn>("create");

    if (!fn)
        throw RuntimeException("Shared library `" + lib.getPath().toString() + "` doesn't contains 'create' function");

    return UniquePtr<Api>(fn());
}

/* ************************************************************************ */

}

/* ************************************************************************ */

DynamicArray<Plugin> SharedLibraryLoader::loadAll(const FilePath& directory)
{
    static const auto PREFIX = SharedLibrary::PREFIX + "cece-";
    static const auto EXTENSION = SharedLibrary::EXTENSION;

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
            Log::debug("Skipping `", path, "`: not a file");
            continue;
        }

        // Get path
        const auto filename = path.getFilename();
        const auto prefixLength = PREFIX.length();
        const auto suffixLength = EXTENSION.length();
        const auto suffixStart = filename.length() - suffixLength;

        Log::debug("Checking: `", filename, "`");

        // Different prefix
        if (filename.substr(0, prefixLength) != PREFIX)
            continue;

        // Different extension
        if (filename.substr(suffixStart) != EXTENSION)
            continue;

        // Plugin name
        const String name = filename.substr(prefixLength, suffixStart - prefixLength);

        Log::debug("Loading plugin: `", name, "` @ `", path, "`");

        try
        {
            // Open shared library
            SharedLibrary lib(path);

            // Check configuration
            checkConfig(lib);

            // Obtain API from library
            auto api = createApi(lib);

            // Store library
            m_libraries.push_back(std::move(lib));
            result.emplace_back(name, std::move(api));
        }
        catch (const Exception& e)
        {
            Log::warning("Unable to load plugin `", name, "` @ `", path, "`: ", e.what());
        }
    }

    return result;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
