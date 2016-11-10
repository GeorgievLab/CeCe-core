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
#pragma message("Include 'cece/unit/Unit.hpp' instead")
#else
#warning "Include 'cece/unit/Unit.hpp' instead"
#endif
#include "cece/unit/Unit.hpp"

/* ************************************************************************ */

namespace cece {
inline namespace core {
namespace units {

/* ************************************************************************ */

using unit::Value;
using unit::Unit;
using unit::List;
using unit::BaseLength;
using unit::BaseMass;
using unit::BaseTime;
using unit::BaseElectricCurrent;
using unit::BaseThermodynamicTemperature;
using unit::BaseAmountOfSubstance;
using unit::BaseLuminousIntensity;
using unit::exponentToCoefficient;
using unit::LENGTH_EXPONENT;
using unit::TIME_EXPONENT;
using unit::MASS_EXPONENT;
using unit::ELECTRIC_CURRENT_EXPONENT;
using unit::THERMODYNAMIC_TEMPERATURE_EXPONENT;
using unit::AMOUNT_OF_SUBSTANCE_EXPONENT;
using unit::LUMINOUS_INTENSITY_EXPONENT;

/* ************************************************************************ */

}
}
}

/* ************************************************************************ */
