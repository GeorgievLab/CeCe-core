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
#include "cece/io/CsvFile.hpp"

// CeCe
#include "cece/core/Exception.hpp"

/* ************************************************************************ */

namespace cece {
namespace io {

/* ************************************************************************ */

CsvFile::CsvFile(io::FilePath path)
{
    open(std::move(path));
}

/* ************************************************************************ */

bool CsvFile::isOpen() const noexcept
{
    return m_file.is_open();
}

/* ************************************************************************ */

void CsvFile::open()
{
    open(std::move(m_path));
}

/* ************************************************************************ */

void CsvFile::open(io::FilePath path)
{
    m_path = std::move(path);
    m_file.open(m_path.toString(), std::ios::binary | std::ios::out | std::ios::trunc);

    if (!m_file.is_open())
        throw RuntimeException("Cannot open file: " + m_path.toString());
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
