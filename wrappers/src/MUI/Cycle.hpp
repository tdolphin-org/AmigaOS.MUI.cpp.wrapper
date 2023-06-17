//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/CycleActive.hpp"

#undef Cycle

namespace MUI
{
    class Cycle : public Group
    {
      public:
        Cycle(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Cycle(const APTR pMuiObject)
          : Group(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Cycle);
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Cycle_Active ]
        long getActive() const;

        /// @brief [ @b MUIA_Cycle_Active ]
        Cycle &setActive(const enum CycleActive active);
        /// @brief [ @b MUIA_Cycle_Active, @b MUIV_Cycle_Active_Next ]
        Cycle &setActiveNext();
        /// @brief [ @b MUIA_Cycle_Active, @b MUIV_Cycle_Active_Prev ]
        Cycle &setActivePrev();
        /// @brief [ @b MUIA_Cycle_Active ]
        Cycle &setActive(const unsigned long active);
        /// @brief [ @b MUIA_Cycle_Entries ]
        Cycle &setEntries(const char *entries[]);
    };

    template <typename T, typename U> class CycleBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        CycleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Cycle)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Cycle_Active ]
        /// Defines the number of the active entry in the cycle gadget. Valid range is from 0 for the first entry to NumEntries-1 for the
        /// last.
        T &tagActive(const long active);
        /// @brief [ @b MUIA_Cycle_Entries ]
        /// Define what entries shall be displayed in your cycle gadget. You must supply a pointer to a string array, containing one entry
        /// for each item and terminated with a NULL.
        T &tagEntries(const char *entries[]);
    };

    class CycleBuilder : public CycleBuilderTemplate<CycleBuilder, Cycle>
    {
      public:
        CycleBuilder();
    };

    template <typename T, typename U> inline T &CycleBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_Cycle_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &CycleBuilderTemplate<T, U>::tagEntries(const char *entries[])
    {
        this->PushTag(MUIA_Cycle_Entries, entries);
        return (T &)*this;
    }
}
