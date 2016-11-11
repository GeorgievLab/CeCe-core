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
#include "ConverterBox2D.hpp"

/* ************************************************************************ */

namespace cece {
namespace simulation {

/* ************************************************************************ */

RealType ConverterBox2D::getTimeCoefficient() const noexcept
{
    return m_timeStepBox2D / m_timeStep;
}

/* ************************************************************************ */

unit::Length ConverterBox2D::convertLength(float32 length) const noexcept
{
    const auto coeff = 1.0 / getLengthCoefficient();

    return coeff * unit::Length(length);
}

/* ************************************************************************ */

float32 ConverterBox2D::convertLength(unit::Length length) const noexcept
{
    const auto coeff = getLengthCoefficient();

    return static_cast<float32>(coeff * length.value());
}

/* ************************************************************************ */

unit::PositionVector ConverterBox2D::convertPosition(b2Vec2 position) const noexcept
{
    const auto coeff = 1.0 / getLengthCoefficient();

    return coeff * unit::PositionVector{
        unit::Length(position.x),
        unit::Length(position.y)
    };
}

/* ************************************************************************ */

b2Vec2 ConverterBox2D::convertPosition(unit::PositionVector position) const noexcept
{
    const auto coeff = getLengthCoefficient();

    return static_cast<float32>(coeff) * b2Vec2{
        static_cast<float32>(position.getX().value()),
        static_cast<float32>(position.getY().value())
    };
}

/* ************************************************************************ */

unit::Angle ConverterBox2D::convertAngle(float32 angle) const noexcept
{
    return unit::Angle{angle};
}

/* ************************************************************************ */

float32 ConverterBox2D::convertAngle(unit::Angle angle) const noexcept
{
    return static_cast<float32>(angle.value());
}

/* ************************************************************************ */

unit::VelocityVector ConverterBox2D::convertLinearVelocity(b2Vec2 velocity) const noexcept
{
    const auto coeff = getTimeCoefficient() / getLengthCoefficient();

    return coeff * unit::VelocityVector{
        unit::Velocity(velocity.x),
        unit::Velocity(velocity.y)
    };
}

/* ************************************************************************ */

b2Vec2 ConverterBox2D::convertLinearVelocity(unit::VelocityVector velocity) const noexcept
{
    const auto coeff = getLengthCoefficient() / getTimeCoefficient();

    return static_cast<float32>(coeff) * b2Vec2(
        static_cast<float32>(velocity.getX().value()),
        static_cast<float32>(velocity.getY().value())
    );
}

/* ************************************************************************ */

unit::AngularVelocity ConverterBox2D::convertAngularVelocity(float32 velocity) const noexcept
{
    const auto coeff = getTimeCoefficient();

    return coeff * unit::AngularVelocity{velocity};
}

/* ************************************************************************ */

float32 ConverterBox2D::convertAngularVelocity(unit::AngularVelocity velocity) const noexcept
{
    const auto coeff = 1.0 / getTimeCoefficient();

    return static_cast<float32>(coeff * velocity.value());
}

/* ************************************************************************ */

unit::AccelerationVector ConverterBox2D::convertLinearAcceleration(b2Vec2 acceleration) const noexcept
{
    const auto coeff = (getTimeCoefficient() * getTimeCoefficient()) / getLengthCoefficient();

    return coeff * unit::AccelerationVector(
        unit::Acceleration(acceleration.x),
        unit::Acceleration(acceleration.y)
    );
}

/* ************************************************************************ */

b2Vec2 ConverterBox2D::convertLinearAcceleration(unit::AccelerationVector acceleration) const noexcept
{
    const auto coeff = getLengthCoefficient() / (getTimeCoefficient() * getTimeCoefficient());

    return static_cast<float32>(coeff) * b2Vec2(
        static_cast<float32>(acceleration.getX().value()),
        static_cast<float32>(acceleration.getY().value())
    );
}

/* ************************************************************************ */

unit::Acceleration ConverterBox2D::convertAngularAcceleration(float32 acceleration) const noexcept
{
    const auto coeff = 1;

    return coeff * unit::Acceleration(acceleration);
}

/* ************************************************************************ */

float32 ConverterBox2D::convertAngularAcceleration(unit::Acceleration acceleration) const noexcept
{
    return static_cast<float32>(acceleration.value());
}

/* ************************************************************************ */

unit::ForceVector ConverterBox2D::convertForce(b2Vec2 force) const noexcept
{
    const auto coeff = (getTimeCoefficient() * getTimeCoefficient()) / getLengthCoefficient();

    return coeff * unit::ForceVector(
        unit::Force(force.x),
        unit::Force(force.y)
    );
}

/* ************************************************************************ */

b2Vec2 ConverterBox2D::convertForce(unit::ForceVector force) const noexcept
{
    const auto coeff = getLengthCoefficient() / (getTimeCoefficient() * getTimeCoefficient());

    return static_cast<float32>(coeff) * b2Vec2{
        static_cast<float32>(force.getX().value()),
        static_cast<float32>(force.getY().value())
    };
}

/* ************************************************************************ */

unit::Force ConverterBox2D::convertTorque(float32 torque) const noexcept
{
    const auto coeff = (getTimeCoefficient() * getTimeCoefficient()) / getLengthCoefficient();

    return coeff * unit::Force{torque};
}

/* ************************************************************************ */

float32 ConverterBox2D::convertTorque(unit::Force torque) const noexcept
{
    const auto coeff = getLengthCoefficient() / (getTimeCoefficient() * getTimeCoefficient());

    return static_cast<float32>(coeff * torque.value());
}

/* ************************************************************************ */

unit::ImpulseVector ConverterBox2D::convertLinearImpulse(b2Vec2 impulse) const noexcept
{
    const auto coeff = getTimeCoefficient() / getLengthCoefficient();

    return coeff * unit::ImpulseVector(
        unit::Impulse(impulse.x),
        unit::Impulse(impulse.y)
    );
}

/* ************************************************************************ */

b2Vec2 ConverterBox2D::convertLinearImpulse(unit::ImpulseVector impulse) const noexcept
{
    const auto coeff = getLengthCoefficient() / getTimeCoefficient();

    return static_cast<float32>(coeff) * b2Vec2{
        static_cast<float32>(impulse.getX().value()),
        static_cast<float32>(impulse.getY().value())
    };
}

/* ************************************************************************ */

unit::Impulse ConverterBox2D::convertAngularImpulse(float32 impulse) const noexcept
{
    const auto coeff = getTimeCoefficient() / getLengthCoefficient();

    return coeff * unit::Impulse{impulse};
}

/* ************************************************************************ */

float32 ConverterBox2D::convertAngularImpulse(unit::Impulse impulse) const noexcept
{
    const auto coeff = getLengthCoefficient() / getTimeCoefficient();

    return static_cast<float32>(coeff * impulse.value());
}

/* ************************************************************************ */

unit::Mass ConverterBox2D::convertMass(float32 mass) const noexcept
{
    return unit::Mass(mass);
}

/* ************************************************************************ */

float32 ConverterBox2D::convertMass(unit::Mass mass) const noexcept
{
    return static_cast<float32>(mass.value());
}

/* ************************************************************************ */

unit::Density ConverterBox2D::convertDensity(float32 density) const noexcept
{
    const auto coeff = 1.0 / (getLengthCoefficient() * getLengthCoefficient() * getLengthCoefficient());

    return coeff * unit::Density(density);
}

/* ************************************************************************ */

float32 ConverterBox2D::convertDensity(unit::Density density) const noexcept
{
    const auto coeff = getLengthCoefficient() * getLengthCoefficient() * getLengthCoefficient();

    return static_cast<float32>(coeff * density.value());
}

/* ************************************************************************ */

unit::Length ConverterBox2D::getMaxObjectTranslation() const noexcept
{
    const auto coeff = 1.0 / getLengthCoefficient();

    return coeff * unit::Length{b2_maxTranslation};
}

/* ************************************************************************ */

ConverterBox2D& ConverterBox2D::getInstance() noexcept
{
    static ConverterBox2D instance;
    return instance;
}

/* ************************************************************************ */

}
}

/* ************************************************************************ */
