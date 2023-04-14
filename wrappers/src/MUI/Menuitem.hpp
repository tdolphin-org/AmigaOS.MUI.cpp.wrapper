//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
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

        Menuitem(const Root &root)
          : Family(root.muiObject())
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menuitem_Checked ]
        bool getChecked() const;
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        bool getCheckit() const;
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        bool getEnabled() const;
        /// @brief [ @b MUIA_Menuitem_Title ]
        std::string getTitle() const;
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        bool getToggle() const;

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

    template <typename T, typename U> class MenuitemBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuitemBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menuitem)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menuitem_Checked ]
        T &tagChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
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
