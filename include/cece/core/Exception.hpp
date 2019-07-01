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

#if _MSC_VER
#pragma message("Include 'cece/Exception.hpp' instead")
#else
#warning "Include 'cece/Exception.hpp' instead"
#endif
#include "cece/Exception.hpp"

/* ************************************************************************ */

namespace cece {
inline namespace core {

/* ************************************************************************ */

using cece::Exception;
using cece::LogicException;
using cece::InvalidArgumentException;
using cece::DomainException;
using cece::LengthException;
using cece::OutOfRangeException;
using cece::RuntimeException;
using cece::RangeException;
using cece::OverflowException;
using cece::UndeflowException;
using cece::BadCastException;
using cece::InvalidCastException;

/* ************************************************************************ */

}
}

/* ************************************************************************ */