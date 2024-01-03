//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

#undef Radio

namespace MUI
{
    class Radio : public Group
    {
      public:
        Radio(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Radio(const APTR pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Radio_Active ]
        long getActive() const;

        /// @brief [ @b MUIA_Radio_Active ]
        Radio &setActive(const unsigned long active);
    };

    template <typename T, typename U> class RadioBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        RadioBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Radio)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Radio_Active ]
        /// Defines the number of the active entry in the Radio gadget. Valid range is from 0 for the first entry to NumEntries-1 for the
        /// last.
        T &tagActive(const long active);
        /// @brief [ @b MUIA_Radio_Entries ]
        /// Define what entries shall be displayed in your Radio gadget. You must supply a pointer to a string array, containing one entry
        /// for each item and terminated with a NULL.
        T &tagEntries(const char *entries[]);
    };

    class RadioBuilder : public RadioBuilderTemplate<RadioBuilder, Radio>
    {
      public:
        RadioBuilder();
    };

    template <typename T, typename U> inline T &RadioBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_Radio_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RadioBuilderTemplate<T, U>::tagEntries(const char *entries[])
    {
        this->PushTag(MUIA_Radio_Entries, entries);
        return (T &)*this;
    }
}
