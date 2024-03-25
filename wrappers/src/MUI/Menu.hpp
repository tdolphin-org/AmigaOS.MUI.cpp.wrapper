//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
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

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menu_Enabled ]
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menu_Title ]
        std::string getTitle() const;

        /// @brief [ @b MUIA_Menu_Enabled ]
        Menu &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        Menu &setTitle(const std::string &title);

        // methods, some returns object reference
    };

    template <typename T, typename U> class MenuBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menu)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menu_CopyStrings ]
        /// Set to true if the title string defined by MUIA_Menu_Title is to be copied. Otherwise the title will be used directly and must
        /// remain valid throughout the object's life time. By default is false.
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
