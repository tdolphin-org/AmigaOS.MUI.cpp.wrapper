//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    class Menuitem : public Family
    {
      public:
        Menuitem(const Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menuitem(const APTR pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menuitem(const Root &root)
          : Family(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menuitem_Checked ]
        bool isChecked() const;
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        bool isCheckit() const;
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menuitem_Title ]
        std::string getTitle() const;
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        bool isToggle() const;

        /// @brief [ @b MUIA_Menuitem_Checked ]
        Menuitem &setChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        Menuitem &setCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        Menuitem &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Title ]
        Menuitem &setTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        Menuitem &setToggle(const bool toggle);

        // methods, some can return object reference
    };

    class MenuItemFactory
    {
      public:
        /// @brief create and return menu separator [ @b NM_BARLABEL ]
        static Menuitem Separator();
        /// @brief create and return basic menu item with title and user data
        /// @param title text in item
        /// @param userData user data
        static Menuitem BasicItem(const std::string &title, const unsigned long userData);
    };

    template <typename T, typename U> class MenuitemBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuitemBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menuitem)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Define checked state of a checkit menu item
        T &tagChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// For @b true this item will become a checkmarkable item.
        T &tagCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CopyStrings ]
        T &tagCopyStrings(const bool copyStrings);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menuitem_Title ]
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Define the state of the TOGGLE flag for this item.
        T &tagToggle(const bool toggle);
    };

    class MenuitemBuilder : public MenuitemBuilderTemplate<MenuitemBuilder, Menuitem>
    {
      public:
        MenuitemBuilder();
    };

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagChecked(const bool checked)
    {
        this->PushTag(MUIA_Menuitem_Checked, checked);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCheckit(const bool checkit)
    {
        this->PushTag(MUIA_Menuitem_Checkit, checkit);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCopyStrings(const bool copyStrings)
    {
        this->PushTag(MUIA_Menuitem_CopyStrings, copyStrings);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menuitem_Enabled, enabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Menuitem_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_Menuitem_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagToggle(const bool toggle)
    {
        this->PushTag(MUIA_Menuitem_Toggle, toggle);
        return (T &)*this;
    }
}
