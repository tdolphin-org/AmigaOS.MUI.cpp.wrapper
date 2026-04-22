//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    class Menu : public Family
    {
      public:
        explicit Menu(Object *pMuiObject)
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
        /// Query whether this menu is currently enabled.
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menu_Title ]
        /// Return the current title text of this menu.
        std::string getTitle() const;

        /// @brief [ @b MUIA_Menu_Enabled ]
        /// Enable or disable this menu.
        Menu &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set the visible title text of this menu.
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

#ifdef MUIA_Menu_CopyStrings
        /// @brief [ @b MUIA_Menu_CopyStrings ]
        /// Set to true if the title string defined by MUIA_Menu_Title is to be copied. Otherwise the title will be used directly and must
        /// remain valid throughout the object's life time. By default is false.
        T &tagCopyStrings(const bool copyStrings);
#endif
        /// @brief [ @b MUIA_Menu_Enabled ]
        /// Set the initial enabled state for this menu.
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set the initial title text from a C string.
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set the initial title text from a std::string.
        T &tagTitle(const std::string &title);
    };

    class MenuBuilder : public MenuBuilderTemplate<MenuBuilder, Menu>
    {
      public:
        MenuBuilder();
    };
}

#define MUI_MENU_TPP_INCLUDE
#include "Menu.tpp"
#undef MUI_MENU_TPP_INCLUDE
