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

// CeCe
#include "cece/String.hpp"
#include "cece/StringView.hpp"
#include "cece/SharedPtr.hpp"
#include "cece/DynamicArray.hpp"
#include "cece/StringMap.hpp"
#include "cece/config/Implementation.hpp"

/* ************************************************************************ */

namespace cece {
namespace config {

/* ************************************************************************ */

struct MemoryData;

/* ************************************************************************ */

/**
 * @brief      Memory configuration implementation.
 */
class MemoryImplementation final : public Implementation
{

// Public Ctors & Dtors
public:


    /**
     * @brief      Constructor.
     */
    MemoryImplementation();


    /**
     * @brief      Constructor.
     *
     * @param      data  Managed data.
     */
    explicit MemoryImplementation(SharedPtr<MemoryData> data);


// Public Accessors & Mutators
public:


    /**
     * @brief      Check if there is a value stored under given name.
     *
     * @param      name  The name.
     *
     * @return     `true` if value is stored, `false` otherwise.
     */
    bool has(StringView name) const override;


    /**
     * @brief      Returns stored value.
     *
     * @param      name  The name.
     *
     * @return     The stored value.
     *
     * @throws     NotFoundException  When no value is stored.
     */
    String get(StringView name) const override;


    /**
     * @brief      Store a value.
     *
     * @param      name   The name.
     * @param      value  The value to store.
     */
    void set(StringView name, String value) override;


    /**
     * @brief      Returns list of names under which values are stored.
     *
     * @return     A list of names.
     */
    DynamicArray<String> getNames() const override;


    /**
     * @brief      Checks if the configuration contains a content.
     *
     * @return     If content is present.
     */
    bool hasContent() const override;


    /**
     * @brief      Returns the configuration content.
     *
     * @return     The content with replaced parameters.
     */
    String getContent() const override;


    /**
     * @brief      Change configuration content.
     *
     * @param      content  The new content.
     */
    void setContent(String content) override;


    /**
     * @brief      Check if at least one child configuration exists.
     *
     * @param      name  The child configuration name.
     *
     * @return     `true` if exists, `false` otherwise.
     */
    bool hasChild(StringView name) const override;


    /**
     * @brief      Returns child configurations with given name.
     *
     * @param      name  The child configuration name.
     *
     * @return     List of child configurations.
     */
    PtrDynamicArray<Implementation> getChilds(StringView name) const override;


    /**
     * @brief      Returns list of available child configuration names.
     *
     * @return     A list of names.
     */
    DynamicArray<String> getChildNames() const override;


    /**
     * @brief      Create new child configuration.
     *
     * @param      name  The child configuration name.
     *
     * @return     New child configuration.
     */
    UniquePtr<Implementation> createChild(StringView name) override;


// Private Data Members
private:

    /// Shared data.
    SharedPtr<MemoryData> m_data;
};

/* ************************************************************************ */

}
}

/* ************************************************************************ */
