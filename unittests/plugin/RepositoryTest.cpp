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
#include "cece/plugin/Repository.hpp"
#include "cece/plugin/Exception.hpp"

/* ************************************************************************ */

using namespace cece;
using namespace cece::plugin;

/* ************************************************************************ */

TEST(Repository, records)
{
    Repository repo;
    const Repository& crepo = repo;

    EXPECT_EQ(0, repo.getRecords().size());

    auto& record1 = repo.createRecord("record1");
    EXPECT_EQ(1, repo.getRecords().size());
    EXPECT_TRUE(repo.exists("record1"));
    EXPECT_FALSE(repo.exists("record2"));
    EXPECT_NO_THROW(repo.get("record1"));
    EXPECT_THROW(repo.get("record2"), RepositoryException);

    EXPECT_EQ(1, crepo.getRecords().size());
    EXPECT_TRUE(crepo.exists("record1"));
    EXPECT_FALSE(crepo.exists("record2"));
    EXPECT_NO_THROW(crepo.get("record1"));
    EXPECT_THROW(crepo.get("record2"), RepositoryException);

    auto& record2 = repo.createRecord("record2");
    EXPECT_EQ(2, repo.getRecords().size());
    EXPECT_TRUE(repo.exists("record1"));
    EXPECT_TRUE(repo.exists("record2"));
    EXPECT_NO_THROW(repo.get("record1"));
    EXPECT_NO_THROW(repo.get("record2"));

    EXPECT_EQ(2, crepo.getRecords().size());
    EXPECT_TRUE(crepo.exists("record1"));
    EXPECT_TRUE(crepo.exists("record2"));
    EXPECT_NO_THROW(crepo.get("record1"));
    EXPECT_NO_THROW(crepo.get("record2"));

    repo.removeRecord("record1");
    EXPECT_EQ(1, repo.getRecords().size());
    EXPECT_FALSE(repo.exists("record1"));
    EXPECT_TRUE(repo.exists("record2"));
    EXPECT_THROW(repo.get("record1"), RepositoryException);
    EXPECT_NO_THROW(repo.get("record2"));

    EXPECT_EQ(1, crepo.getRecords().size());
    EXPECT_FALSE(crepo.exists("record1"));
    EXPECT_TRUE(crepo.exists("record2"));
    EXPECT_THROW(crepo.get("record1"), RepositoryException);
    EXPECT_NO_THROW(crepo.get("record2"));

    // Add duplicit record
    EXPECT_THROW(repo.createRecord("record2"), RepositoryException);
}

/* ************************************************************************ */
