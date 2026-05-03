//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#undef Radio

namespace MUI
{
    /// @brief Wrapper for MUIC_Radio - a group-based radio button gadget.
    /// Radio gadgets offer cycle-like selection using one button per entry and can be laid out
    /// vertically, horizontally or in more complex group arrangements through inherited Group attributes.
    class Radio : public Group
    {
      public:
        explicit Radio(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Radio(const Root &root)
          : Group(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Radio_Active ] Get the index of the currently active radio entry.
        long getActive() const;

        /// @brief [ @b MUIA_Radio_Active ] Set the active radio entry by zero-based index.
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
        /// @brief [ @b MUIA_Radio_Entries ]
        /// Define what entries shall be displayed in your Radio gadget. The string copies are stored internally by this C++ wrapper.
        /// Radio entries may contain MUI text formatting codes.
        T &tagEntries(const std::vector<std::string> &entries);
    };

    class RadioBuilder : public RadioBuilderTemplate<RadioBuilder, Radio>
    {
      public:
        RadioBuilder();
    };
}

#define MUI_RADIO_TPP_INCLUDE
#include "Radio.tpp"
#undef MUI_RADIO_TPP_INCLUDE
