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

// GTest
#include "gtest/gtest.h"

// CeCe
#include "cece/UniquePtr.hpp"
#include "cece/config/Exception.hpp"

/* ************************************************************************ */

using namespace cece::config;

/* ************************************************************************ */

TEST(Exception, base)
{
    Exception e("Test");

    // Test virtual destructor
    cece::UniquePtr<cece::Exception> ptr = cece::makeUnique<Exception>("Test");
}

/* ************************************************************************ */

TEST(Exception, not_found)
{
    NotFoundException e("Test");

    // Test virtual destructor
    cece::UniquePtr<Exception> ptr = cece::makeUnique<NotFoundException>("Test");
}

/* ************************************************************************ */

TEST(Exception, unterminated_parameter)
{
    UnterminatedParameterException e("{$name");

    EXPECT_EQ("{$name", e.getText());

    // Test virtual destructor
    cece::UniquePtr<Exception> ptr = cece::makeUnique<UnterminatedParameterException>("Test");
}

/* ************************************************************************ */

TEST(Exception, invalid_parameter_name)
{
    InvalidParameterNameException e("name 1", "{$name 1}");

    EXPECT_EQ("name 1", e.getName());
    EXPECT_EQ("{$name 1}", e.getText());

    // Test virtual destructor
    cece::UniquePtr<Exception> ptr = cece::makeUnique<InvalidParameterNameException>("Test", "Test");
}

/* ************************************************************************ */
