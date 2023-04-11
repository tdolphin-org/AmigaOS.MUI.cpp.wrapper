//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    class Menu : public Family
    {
      public:
        Menu(const Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menu(const Root &root)
          : Family(root.muiObject())
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menu_Enabled ]
        bool getEnabled() const;
        /// @brief [ @b MUIA_Menu_Title ]
        std::string getTitle() const;

        /// @brief [ @b MUIA_Menu_Enabled ]
        Menu &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        Menu &setTitle(const std::string &title);

        // methods, some can return object reference
    };

    template <typename T, typename U> class MenuBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menu)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menu_CopyStrings ]
        T &tagCopyStrings(const bool copyStrings);
        /// @brief [ @b MUIA_Menu_Enabled ]
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menu_Title ]
        T &tagTitle(const std::string &title);
    };

    class MenuBuilder : public MenuBuilderTemplate<MenuBuilder, Menu>
    {
      public:
        MenuBuilder();
    };
    
    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagCopyStrings(const bool copyStrings)
    {
        this->PushTag(MUIA_Menu_CopyStrings, copyStrings);
        return (T &)*this;
    }
    
    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menu_Enabled, enabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Menu_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_Menu_Title, title);
        return (T &)*this;
    }
}
