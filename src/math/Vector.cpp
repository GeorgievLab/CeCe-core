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
#include "cece/math/Vector.hpp"

/* ************************************************************************ */

namespace cece {
namespace math {

/* ************************************************************************ */

template class Vector<int, 2>;
template class Vector<int, 3>;
template class Vector<unsigned int, 2>;
template class Vector<unsigned int, 3>;
template class Vector<unsigned long, 2>;
template class Vector<unsigned long, 3>;
template class Vector<float, 2>;
template class Vector<float, 3>;
template class Vector<double, 2>;
template class Vector<double, 3>;

/* ************************************************************************ */

}
}

/* ************************************************************************ */
