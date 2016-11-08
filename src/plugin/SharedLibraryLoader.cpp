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
#include "cece/plugin/Exception.hpp"
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
void checkConfig(const os::SharedLibrary& lib)
{
    auto path = lib.getPath().toString();

    // Get configuration
    auto getConfigFn = lib.getAddr<GetConfigFn>("get_config");

    if (!getConfigFn)
        throw InvalidPluginException(path, "Doesn't contains 'get_config' function");

    // Get configuration
    auto config = getConfigFn();

    if (!config)
        throw InvalidPluginException(path, "Returns no config");

    if (config->apiVersion != config::PLUGIN_API_VERSION)
        throw InvalidPluginException(path, "Built against different API version than CeCe");

    if (config->realSize != sizeof(config::RealType))
        throw InvalidPluginException(path, "Built with different real type than CeCe");

#ifdef CECE_RENDER
    if (!config->renderEnabled)
        throw InvalidPluginException(path, "Built without render support, but CeCe did");
#else
    if (config->renderEnabled)
        throw InvalidPluginException(path, "Built with render support, but CeCe didn't");
#endif

#ifdef CECE_THREAD_SAFE
    if (!config->threadSafe)
        throw InvalidPluginException(path, "Built without thread safety, but CeCe did");
#else
    if (config->threadSafe)
        throw InvalidPluginException(path, "Built with thread safety, but CeCe didn't");
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
UniquePtr<Api> createApi(const os::SharedLibrary& lib)
{
    // Get create API function
    auto fn = lib.getAddr<CreateFn>("create");

    if (!fn)
        throw InvalidPluginException(lib.getPath(), "Doesn't contains 'create' function");

    return UniquePtr<Api>(fn());
}

/* ************************************************************************ */

}

/* ************************************************************************ */

DynamicArray<Plugin> SharedLibraryLoader::loadAll(const io::FilePath& directory)
{
    static const auto PREFIX = os::SharedLibrary::PREFIX + "cece-";
    static const auto EXTENSION = os::SharedLibrary::EXTENSION;

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
            os::SharedLibrary lib(path);

            // Check configuration
            checkConfig(lib);

            // Obtain API from library
            auto api = createApi(lib);

            // Store library
            m_libraries.push_back(std::move(lib));
            result.emplace_back(name, std::move(api));
        }
        catch (const InvalidPluginException& e)
        {
            Log::warning("Trying to load invalid plugin `", name, "` @ `", path, "`: ", e.what());
        }
        catch (...)
        {
            Log::warning("Internal plugin error `", name, "` @ `", path);
        }
    }

    return result;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
