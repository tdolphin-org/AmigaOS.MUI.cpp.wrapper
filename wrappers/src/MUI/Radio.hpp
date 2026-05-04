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
    /// @brief Radio class generates radio button gadgets. They do the same job as cycle gadgets and
    /// eat up more window space. Since Radio class is a subclass of Group, you can use group layout
    /// attributes to adjust the layout to your needs.
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

        /// @brief [ @b MUIA_Radio_Active ] The number of the active entry in the radio gadget.
        /// Valid range is from 0 for the first entry to NumEntries-1 for the last.
        long getActive() const;

        /// @brief [ @b MUIA_Radio_Active ] The number of the active entry in the radio gadget.
        /// Setting this causes the gadget to be updated. Valid range is from 0 to NumEntries-1.
        Radio &setActive(const long active);
    };

    template <typename T, typename U> class RadioBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        RadioBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Radio)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Radio_Active ] The number of the active entry in the radio gadget.
        /// Defines the number of the active entry. Valid range is from 0 for the first entry to NumEntries-1 for the last.
        T &tagActive(const long active);
        /// @brief [ @b MUIA_Radio_Entries ] Define what entries shall be displayed in your radio gadget.
        /// You must supply a pointer to a string array, containing one entry for each item and terminated with a NULL.
        /// Radio entries may contain any MUI text formatting codes such as bold, italic or underlined characters.
        T &tagEntries(const char *entries[]);
        /// @brief [ @b MUIA_Radio_Entries ] Define what entries shall be displayed in your radio gadget.
        /// The string copies are stored internally by this C++ wrapper.
        /// Radio entries may contain any MUI text formatting codes such as bold, italic or underlined characters.
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
