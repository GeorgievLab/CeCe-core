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
#include "cece/log/StdOutput.hpp"

// C++
#include <iostream>

// CeCe
#include "cece/io/OutStream.hpp"
#include "cece/io/CliColor.hpp"

/* ************************************************************************ */

namespace cece {
namespace log {

/* ************************************************************************ */

void StdOutput::write(Severity severity, const String& section, const String& msg)
{
    io::OutStream& os = severity == Severity::Error ? std::cerr : std::cout;

    switch (severity)
    {
    case Severity::Default: break;
    case Severity::Info:    os << io::CliColor::LightGreen   << "[INFO] "  << io::CliColor::Default; break;
    case Severity::Warning: os << io::CliColor::Yellow       << "[WARN] "  << io::CliColor::Default; break;
    case Severity::Error:   os << io::CliColor::Red          << "[ERROR] " << io::CliColor::Default; break;
    case Severity::Debug:   os << io::CliColor::Green        << "[DEBUG] " << io::CliColor::Default; break;
    }

    if (!section.empty())
        os << "[" << section << "] ";

    os << msg << std::endl;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
