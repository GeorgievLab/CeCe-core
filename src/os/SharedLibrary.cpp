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
#include "cece/os/SharedLibrary.hpp"

// C++
#include <cstdint>
#include <cstdlib>
#include <utility>

#if _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

// CeCe
#include "cece/core/Exception.hpp"
#include "cece/log/Log.hpp"

/* ************************************************************************ */

namespace cece {
namespace os {

/* ************************************************************************ */

#if __linux__ || __MINGW32__
const String SharedLibrary::PREFIX = "lib";
#elif _WIN32
const String SharedLibrary::PREFIX = "";
#elif __APPLE__ && __MACH__
const String SharedLibrary::PREFIX = "lib";
#endif

/* ************************************************************************ */

#if __linux__
const String SharedLibrary::EXTENSION = ".so";
#elif _WIN32
const String SharedLibrary::EXTENSION = ".dll";
#elif __APPLE__ && __MACH__
const String SharedLibrary::EXTENSION = ".dylib";
#endif

/* ************************************************************************ */

namespace {

/* ************************************************************************ */

/**
 * @brief      Open shared library.
 *
 * @param      path  Path to library.
 *
 * @return     Library handle.
 */
void* openLibrary(const io::FilePath& path) noexcept
{
#if _WIN32
    String str = path.toString();
    int size = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int) str.size(), NULL, 0);
    std::wstring result(size, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, str.data(), (int) str.size(), &result.front(), size);

    DWORD oldMode;
    SetThreadErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX, &oldMode);
    auto handle = LoadLibraryW(result.c_str());
    SetThreadErrorMode(oldMode, NULL);
    return reinterpret_cast<void*>(handle);
#else
    // POSIX
    return dlopen(path.c_str(), RTLD_LAZY);
#endif
}

/* ************************************************************************ */

/**
 * @brief      Close shared library.
 *
 * @param      handle  Library handle.
 */
void closeLibrary(void* handle) noexcept
{
#if _WIN32
    // WIN32
    FreeLibrary(reinterpret_cast<HMODULE>(handle));
#else
    // POSIX
    if (handle)
        dlclose(handle);
#endif
}

/* ************************************************************************ */

/**
 * @brief      Returns error string.
 *
 * @param[in]  handle  Handle to shared library.
 *
 * @return     The error message.
 */
String getError(void* handle) noexcept
{
#if _WIN32
    // Get error message
    const auto err = ::GetLastError();
    if (err == 0)
        return {};

    LPSTR buffer = nullptr;
    auto size = FormatMessageA(
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

}

/* ************************************************************************ */

SharedLibrary::SharedLibrary(io::FilePath path)
    : m_path(std::move(path))
    , m_handle(openLibrary(m_path))
{
    if (!isOpen())
        throw RuntimeException("Shared library `" + m_path.toString() + "` cannot be loaded: " + getError(m_handle));

    log::Log::debug("Library loaded `", m_path, "`.");
}

/* ************************************************************************ */

SharedLibrary::~SharedLibrary()
{
    if (isOpen())
    {
        log::Log::debug("Closing shared library `", m_path, "`");
        closeLibrary(m_handle);
        log::Log::debug("Shared library closed `", m_path, "`");
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
    using std::swap;
    swap(m_path, src.m_path);
    swap(m_handle, src.m_handle);

    return *this;
}

/* ************************************************************************ */

void* SharedLibrary::getAddr(StringView name) const noexcept
{
#if _WIN32
    return reinterpret_cast<void*>(reinterpret_cast<std::intptr_t>(
        GetProcAddress(reinterpret_cast<HMODULE>(m_handle), name.getData())
    ));
#else
    // POSIX
    return dlsym(m_handle, name.getData());
#endif
}

/* ************************************************************************ */

String SharedLibrary::formatName(String name)
{
    return PREFIX + name + EXTENSION;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
