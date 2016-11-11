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

// C++
#include <utility>

// CeCe
#include "cece/String.hpp"
#include "cece/DynamicArray.hpp"
#include "cece/io/InStream.hpp"
#include "cece/io/OutStream.hpp"

/* ************************************************************************ */

namespace cece {
namespace io {

/* ************************************************************************ */

/**
 * @brief      File path type.
 */
class FilePath
{

// Public Constants
public:


    /// Path separator.
    static constexpr char SEPARATOR = '/';


// Public Ctors & Dtors
public:


    /**
     * @brief      Default constructor.
     */
    FilePath() = default;


    /**
     * @brief      Constructor.
     *
     * @param      source  The source path.
     */
    FilePath(String source)
        : m_path(std::move(source))
    {
        // Nothing to do
    }


    /**
     * @brief      Constructor.
     *
     * @param      source  The source path.
     */
    FilePath(const char* source)
        : m_path(source)
    {
        // Nothing to do
    }


// Public Operators
public:


    /**
     * @brief      Append path.
     *
     * @param      path  The path to append.
     *
     * @return     *this
     */
    FilePath& operator/=(const FilePath& path) noexcept
    {
        return append(path);
    }


    /**
     * @brief      Append source.
     *
     * @param      source  The source to append.
     *
     * @return     *this
     */
    template<typename Source>
    FilePath& operator/=(const Source& source) noexcept
    {
        return append(source);
    }


    /**
     * @brief      Append path.
     *
     * @param      path  The path to append.
     *
     * @return     *this
     */
    FilePath& operator+=(const FilePath& path) noexcept
    {
        return concat(path);
    }


    /**
     * @brief      Append source.
     *
     * @param      source  The source to append.
     *
     * @return     *this
     */
    template<typename Source>
    FilePath& operator+=(const Source& source) noexcept
    {
        return concat(source);
    }


    /**
     * @brief      Append path.
     *
     * @param      path  The path to append.
     *
     * @return     New file path.
     */
    FilePath operator/(const FilePath& path) const noexcept
    {
        return FilePath(*this).append(path);
    }


    /**
     * @brief      Append source.
     *
     * @param      source  The source to append.
     *
     * @return     New file path.
     */
    template<typename Source>
    FilePath operator/(const Source& source) const noexcept
    {
        return FilePath(*this).append(source);
    }


    /**
     * @brief      Append path.
     *
     * @param      path  The path to append.
     *
     * @return     New file path.
     */
    FilePath operator+(const FilePath& path) const noexcept
    {
        return FilePath(*this).concat(path);
    }


    /**
     * @brief      Append source.
     *
     * @param      source  The source to append.
     *
     * @return     New file path.
     */
    template<typename Source>
    FilePath operator+(const Source& source) const noexcept
    {
        return FilePath(*this).concat(source);
    }


// Public Accessors & Mutators
public:


    /**
     * @brief      Check if path is empty.
     *
     * @return     True if path is empty, False otherwise.
     */
    bool isEmpty() const noexcept
    {
        return m_path.empty();
    }


    /**
     * @brief      Returns path file name.
     *
     * @return     The filename without directory.
     */
    String getFilename() const noexcept;


    /**
     * @brief      Returns path extension.
     *
     * @return     The file extension.
     */
    String getExtension() const noexcept;


    /**
     * @brief      Returns parent path.
     *
     * @return     The parent path.
     */
    FilePath getParentPath() const noexcept;


    /**
     * @brief      Returns path stem.
     *
     * @return     The stem.
     */
    FilePath getStem() const noexcept;


    /**
     * @brief      Convert path to string.
     *
     * @return     Null terminated string.
     */
    const char* c_str() const noexcept
    {
        return m_path.c_str();
    }


    /**
     * @brief      Returns path length.
     *
     * @return     The path length.
     */
    int getSize() const noexcept
    {
        return static_cast<int>(m_path.size());
    }


    /**
     * @brief      Convert path to string.
     *
     * @return     String representation of the object.
     */
    String toString() const noexcept
    {
        return m_path;
    }


    /**
     * @brief      Append path.
     *
     * @param      source Path to append.
     *
     * @return     *this
     */
    FilePath& append(const FilePath& source) noexcept
    {
        if (!m_path.empty())
            m_path += SEPARATOR;

        m_path.append(source.m_path);
        return *this;
    }


    /**
     * @brief      Append string to the path.
     *
     * @param      source String to append.
     *
     * @return     *this
     */
    template<typename Source>
    FilePath& append(const Source& source) noexcept
    {
        return append(FilePath(source));
    }


    /**
     * @brief      Append path.
     *
     * @param      source Path to append.
     *
     * @return     *this
     */
    FilePath& concat(const FilePath& source) noexcept
    {
        m_path.append(source.m_path);
        return *this;
    }


    /**
     * @brief      Append string to the path.
     *
     * @param      source String to append.
     *
     * @return     *this
     */
    template<typename Source>
    FilePath& concat(const Source& source) noexcept
    {
        return concat(FilePath(source));
    }


    /**
     * @brief      Replace path extension.
     *
     * @param      ext   New extension.
     *
     * @return     this
     */
    FilePath& replaceExtension(const String& ext);


// Public Operations
public:


    /**
     * @brief      Clear path.
     */
    void clear() noexcept
    {
        m_path.clear();
    }


    /**
     * @brief      Input stream operator.
     *
     * @param      is    The input stream.
     * @param      path  The path to write.
     *
     * @return     The input stream.
     */
    friend InStream& operator>>(InStream& is, FilePath& path)
    {
        return is >> path.m_path;
    }


    /**
     * @brief      Output stream operator.
     *
     * @param      os    The output stream.
     * @param      path  The path read to.
     *
     * @return     The output stream.
     */
    friend OutStream& operator<<(OutStream& os, const FilePath& path)
    {
        return os << path.m_path;
    }


    /**
     * @brief      Returns current working directory.
     *
     * @return     Current working directory.
     */
    static FilePath getCurrent();


    /**
     * @brief      Changes current working directory.
     *
     * @param[in]  path  The new current path.
     */
    static void setCurrent(const FilePath& path);


    /**
     * @brief      Test if given path is a file.
     *
     * @param[in]  path  The path.
     *
     * @return     True if path is a file, False otherwise.
     */
    static bool isFile(const FilePath& path) noexcept;

    /**
     * @brief      Tests if path is a directory.
     *
     * @param      path  The path
     *
     * @return     True if directory, False otherwise.
     */
    static bool isDirectory(const FilePath& path) noexcept;


    /**
     * @brief      Tests if file path exists.
     *
     * @param      path  The path
     *
     * @return     True if path exists, False otherwise.
     */
    static bool exists(const FilePath& path) noexcept;


    /**
     * @brief      Returns temporary directory.
     *
     * @return     Path to temporary directory.
     */
    static FilePath getTempDirectory();


    /**
     * @brief      Get all entries in given directory.
     *
     * @param      dir   Directory to iterate.
     *
     * @return     Result paths. `dot` and `dot-dot` are skipped.
     */
    static DynamicArray<FilePath> openDirectory(const FilePath& dir);


// Private Data Members
private:

    /// Path value.
    String m_path;
};

/* ************************************************************************ */

/**
 * @brief Tests if path is a file.
 *
 * @param path
 *
 * @return
 *
 * @deprecated
 */
inline bool isFile(const FilePath& path) noexcept
{
    return FilePath::isFile(path);
}

/* ************************************************************************ */

/**
 * @brief Tests if path is a directory.
 *
 * @param path
 *
 * @return
 *
 * @deprecated
 */
inline bool isDirectory(const FilePath& path) noexcept
{
    return FilePath::isDirectory(path);
}

/* ************************************************************************ */

/**
 * @brief Tests if file path exists.
 *
 * @param path
 *
 * @return
 *
 * @deprecated
 */
inline bool pathExists(const FilePath& path) noexcept
{
    return FilePath::exists(path);
}

/* ************************************************************************ */

/**
 * @brief Returns temporary directory.
 *
 * @return
 *
 * @deprecated
 */
inline FilePath tempDirectory()
{
    return FilePath::getTempDirectory();
}

/* ************************************************************************ */

/**
 * @brief Get all entries in given directory.
 *
 * @param dir
 *
 * @return
 *
 * @deprecated
 */
inline DynamicArray<FilePath> openDirectory(const FilePath& dir)
{
    return FilePath::openDirectory(dir);
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are equal, `false` otherwise.
 */
inline bool operator==(const FilePath& lhs, const FilePath& rhs) noexcept
{
    return lhs.toString() == rhs.toString();
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are equal, `false` otherwise.
 */
inline bool operator==(const FilePath& lhs, const String& rhs) noexcept
{
    return lhs.toString() == rhs;
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are equal, `false` otherwise.
 */
inline bool operator==(const FilePath& lhs, const char* rhs) noexcept
{
    return lhs.toString() == rhs;
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are equal, `false` otherwise.
 */
inline bool operator==(const String& lhs, const FilePath& rhs) noexcept
{
    return lhs == rhs.toString();
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are equal, `false` otherwise.
 */
inline bool operator==(const char* lhs, const FilePath& rhs) noexcept
{
    return lhs == rhs.toString();
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are not equal, `false` otherwise.
 */
inline bool operator!=(const FilePath& lhs, const FilePath& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are not equal, `false` otherwise.
 */
inline bool operator!=(const FilePath& lhs, const String& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are not equal, `false` otherwise.
 */
inline bool operator!=(const FilePath& lhs, const char* rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are not equal, `false` otherwise.
 */
inline bool operator!=(const String& lhs, const FilePath& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

/**
 * @brief      Relational operator.
 *
 * @param[in]  lhs   The first path.
 * @param[in]  rhs   The second path.
 *
 * @return     `true` if paths are not equal, `false` otherwise.
 */
inline bool operator!=(const char* lhs, const FilePath& rhs) noexcept
{
    return !operator==(lhs, rhs);
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
