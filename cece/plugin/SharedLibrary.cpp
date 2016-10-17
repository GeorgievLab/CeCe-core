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
#include "cece/plugin/SharedLibrary.hpp"

// C++
#include <cstdint>
#include <cstdlib>

#if _WIN32
#  include <windows.h>
#else
// POSIX
#  include <dlfcn.h>
#endif

// CeCe
#include "cece/config.hpp"
#include "cece/core/Log.hpp"
#include "cece/core/Exception.hpp"
#include "cece/core/FilePath.hpp"
#include "cece/plugin/definition.hpp"
#include "cece/plugin/Api.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

#if __linux__
const String SharedLibrary::FILE_PREFIX = "libcece-";
#elif __MINGW32__
const String SharedLibrary::FILE_PREFIX = "libcece-";
#elif _WIN32
const String SharedLibrary::FILE_PREFIX = "cece-";
#elif __APPLE__ && __MACH__
const String SharedLibrary::FILE_PREFIX = "libcece-";
#endif

/* ************************************************************************ */

#if __linux__
const String SharedLibrary::FILE_EXTENSION = ".so";
#elif _WIN32
const String SharedLibrary::FILE_EXTENSION = ".dll";
#elif __APPLE__ && __MACH__
const String SharedLibrary::FILE_EXTENSION = ".dylib";
#endif

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief Open shared library.
 *
 * @param path Path to library.
 *
 * @return Library handle.
 */
void* openLibrary(const FilePath& path) noexcept
{
#if _WIN32
    String str = path.toString();
    int size = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int) str.size(), NULL, 0);
    std::wstring result(size, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, str.data(), (int) str.size(), &result.front(), size);
    return LoadLibraryW(result.c_str());
#else
    // POSIX
    return dlopen(path.c_str(), RTLD_LAZY);
#endif
}

/* ************************************************************************ */

/**
 * @brief Close shared library.
 *
 * @param handle Library handle.
 */
void closeLibrary(void* handle) noexcept
{
#if _WIN32
    // WIN32
    FreeLibrary(handle);
#else
    // POSIX
    if (handle)
        dlclose(handle);
#endif
}

/* ************************************************************************ */

/**
 * Check if library is loaded.
 * @param  handle Library handle.
 * @return Is loaded?
 */
bool isLoaded(void* handle) noexcept
{
    return handle != nullptr;
}

/* ************************************************************************ */

/**
 * @brief Returns error string.
 *
 * @return
 */
String getError(void* handle) noexcept
{
#if _WIN32
    // Get error message
    const auto err = ::GetLastError();
    if (err == 0)
        return {};

    LPSTR buffer = nullptr;
    const auto size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, err, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPSTR)&buffer, 0, NULL
    );

    while (size > 0 && (buffer[size - 1] == '\r' || buffer[size - 1] == '\n'))
        --size;

    String message(buffer, size);

    // Free the buffer
    LocalFree(buffer);

    return message;
#else
    return dlerror();
#endif
}

/* ************************************************************************ */

/**
 * @brief Returns address of required symbol.
 *
 * @param handle Library handle.
 * @param name   Symbol name.
 *
 * @return Pointer to symbol or nullptr.
 */
void* getAddr(void* handle, const char* name) noexcept
{
#if _WIN32
    return reinterpret_cast<void*>(reinterpret_cast<std::intptr_t>(GetProcAddress(handle, name)));
#else
    // POSIX
    return dlsym(handle, name);
#endif
}

/* ************************************************************************ */

/**
 * @brief Returns address of required symbol.
 *
 * @param handle Library handle.
 * @param name   Symbol name.
 *
 * @return Pointer to symbol or nullptr.
 */
template<typename T>
T getAddr(void* handle, const char* name) noexcept
{
    return reinterpret_cast<T>(reinterpret_cast<std::intptr_t>(getAddr(handle, name)));
}


/* ************************************************************************ */

}

/* ************************************************************************ */

SharedLibrary::SharedLibrary(FilePath path)
    : m_path(std::move(path))
    , m_handle(openLibrary(m_path))
{
    if (!isLoaded(m_handle))
        throw RuntimeException("Shared library '" + m_path.toString() + "' cannot be loaded: " + getError(m_handle));

    // Get configuration
    auto getConfigFn = getAddr<GetConfigFn>(m_handle, "get_config");

    if (!getConfigFn)
        throw RuntimeException("Shared library '" + m_path.toString() + "' doesn't contains 'get_config' function");

    // Check configuration
    checkConfig(getConfigFn());

    Log::debug("Library loaded `", m_path, "`.");
}

/* ************************************************************************ */

SharedLibrary::~SharedLibrary()
{
    if (m_handle)
    {
        Log::debug("Closing shared library `", m_path, "`");
        closeLibrary(m_handle);
        Log::debug("Shared library closed `", m_path, "`");
    }
}

/* ************************************************************************ */

SharedLibrary::SharedLibrary(SharedLibrary&& src) noexcept
    : m_path(std::move(src.m_path))
    , m_handle(src.m_handle)
{
    src.m_handle = nullptr;
}

/* ************************************************************************ */

SharedLibrary& SharedLibrary::operator=(SharedLibrary&& src) noexcept
{
    std::swap(m_path, src.m_path);
    std::swap(m_handle, src.m_handle);

    return *this;
}

/* ************************************************************************ */

UniquePtr<Api> SharedLibrary::createApi()
{
    // Get create API function
    auto fn = getAddr<CreateFn>(m_handle, "create");

    if (!fn)
        throw RuntimeException("Shared library '" + m_path.toString() + "' doesn't contains 'create' function");

    return UniquePtr<Api>(fn());
}

/* ************************************************************************ */

void SharedLibrary::checkConfig(Config* config)
{
    const auto path = m_path.toString();

    if (!config)
        throw RuntimeException("Library '" + path + "' returns no config");

    if (config->apiVersion != config::PLUGIN_API_VERSION)
        throw RuntimeException("Library '" + path + "' is built against different API version than CeCe");

    if (config->dimension != config::DIMENSION)
        throw RuntimeException("Library '" + path + "' returns nullptr config");

    if (config->realSize != sizeof(config::RealType))
        throw RuntimeException("Library '" + path + "' is built with different real type than CeCe");

#ifdef CECE_RENDER
    if (!config->renderEnabled)
        throw RuntimeException("Library '" + path + "' is built without render support, but CeCe did");
#else
    if (config->renderEnabled)
        throw RuntimeException("Library '" + path + "' is built with render support, but CeCe didn't");
#endif

#ifdef CECE_THREAD_SAFE
    if (!config->threadSafe)
        throw RuntimeException("Library '" + path + "' is built without thread safety, but CeCe did");
#else
    if (config->threadSafe)
        throw RuntimeException("Library '" + path + "' is built with thread safety, but CeCe didn't");
#endif
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
