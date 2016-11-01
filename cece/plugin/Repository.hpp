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
#include "cece/core/String.hpp"
#include "cece/core/StringView.hpp"
#include "cece/core/Map.hpp"
#include "cece/plugin/RepositoryRecord.hpp"

/* ************************************************************************ */

namespace cece {
namespace plugin {

/* ************************************************************************ */

/**
 * @brief Repository is a set of repository record which hold information
 * about simulation extensions.
 */
class Repository final
{

// Public Accessors & Mutators
public:


    /**
     * @brief      Returns all repository records.
     *
     * @return     A map of repository records.
     */
    const Map<String, RepositoryRecord>& getRecords() const noexcept
    {
        return m_records;
    }


    /**
     * @brief      Returns if record with given name exists.
     *
     * @param[in]  name  Record name.
     *
     * @return     Exists a record with given name?
     */
    bool exists(StringView name) const noexcept;


    /**
     * @brief      Returns repository record with given name.
     *
     * @param[in]  name  Record name.
     *
     * @return     Repository record.
     * @throws     InvalidArgumentException  In case a record with given name doesn't
     *                                       exists.
     */
    RepositoryRecord& get(StringView name);


    /**
     * @brief      Returns repository record with given name.
     *
     * @param[in]  name  Record name.
     *
     * @return     Repository record.
     * @throws     InvalidArgumentException  In case a record with given name doesn't
     *                                       exists.
     */
    const RepositoryRecord& get(StringView name) const;


    /**
     * @brief      Create a new record..
     *
     * @param[in]  name  Record name.
     *
     * @return     Repository record.
     * @throws     InvalidArgumentException  In case a record with given name already
     *                                       exists.
     */
    RepositoryRecord& createRecord(String name);


    /**
     * @brief      Remove repository record.
     *
     * @param[in]  name  Record name.
     */
    void removeRecord(StringView name) noexcept;


// Private Data Members
private:

    /// Repository records.
    Map<String, RepositoryRecord> m_records;

};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
