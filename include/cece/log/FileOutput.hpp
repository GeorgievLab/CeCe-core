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
#include "cece/io/FilePath.hpp"
#include "cece/io/FileStream.hpp"
#include "cece/log/StreamOutput.hpp"

/* ************************************************************************ */

namespace cece {
namespace log {

/* ************************************************************************ */

/**
 * @brief      The log output for output streams.
 */
class FileOutput : public StreamOutput
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     *
     * @param      path  Path to log file.
     *
     * @throws     InvalidArgumentException If file cannot be open.
     */
    explicit FileOutput(io::FilePath path);


// Private Data Members
private:

    /// Output file stream.
    io::OutFileStream m_stream;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
