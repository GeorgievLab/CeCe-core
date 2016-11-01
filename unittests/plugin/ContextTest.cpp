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
#include "cece/plugin/Context.hpp"
#include "cece/plugin/Manager.hpp"
#include "cece/plugin/SharedLibraryLoader.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

TEST(Context, ctor)
{
    Manager mgr;
    Context ctx(mgr);

    EXPECT_EQ(&mgr.getRepository(), &ctx.getRepository());
}

/* ************************************************************************ */

TEST(Context, import)
{
    Manager mgr;

    // Use shared library loader
    mgr.addLoader(makeUnique<SharedLibraryLoader>());
    mgr.addDirectory(".");

    Context ctx(mgr);

    EXPECT_NO_THROW(ctx.importPlugin("test-plugin"));
    EXPECT_THROW(ctx.importPlugin("old-plugin"), RuntimeException);

    EXPECT_TRUE(ctx.isImported("test-plugin"));
    EXPECT_FALSE(ctx.isImported("old-plugin"));
}

/* ************************************************************************ */
