//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    /// @brief MUI Menu class wrapper.
    /// Describes exactly one pulldown menu. As a subclass of Family class it acts as a container for Menuitem objects.
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

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menu_Enabled ]
        /// Returns true if this menu is currently enabled.
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menu_Title ]
        /// Returns the current title text of this menu.
        std::string getTitle() const;

        /// @brief [ @b MUIA_Menu_Enabled ]
        /// Enable or disable the complete menu.
        Menu &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set the visible title text of this menu from a raw C string pointer.
        /// The pointer is forwarded directly (no internal copy), so it must remain valid for MUI usage time.
        Menu &setTitle(const char *title);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set the visible title text of this menu.
        /// @param storeCopy If true, forward a raw pointer and expect MUI to copy it (e.g. when @b MUIA_Menu_CopyStrings is enabled).
        /// If false, wrapper stores and manages an internal copy for safe lifetime.
        Menu &setTitle(const std::string &title, bool storeCopy = true);

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
        /// Set to true if the title string (@b MUIA_Menu_Title) is to be copied by MUI. Otherwise the title must
        /// remain valid throughout the object's lifetime. Defaults to false.
        T &tagCopyStrings(const bool copyStrings);
#endif
        /// @brief [ @b MUIA_Menu_Enabled ]
        /// Set the initial enabled or disabled state for the complete menu.
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set title from a C string literal. The string is NOT copied by MUI and must remain valid until the menu
        /// object is disposed (unless @b MUIA_Menu_CopyStrings is set to true).
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menu_Title ]
        /// Set title from a std::string.
        /// @param storeCopy If true, forward a raw pointer and expect MUI to copy it (e.g. when @b MUIA_Menu_CopyStrings is enabled).
        /// If false, builder stores and manages an internal copy for safe lifetime.
        T &tagTitle(const std::string &title, bool storeCopy = true);
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
