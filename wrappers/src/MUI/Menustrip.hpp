//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    /// @brief MUI Menustrip class wrapper.
    /// Base class for MUI's object oriented menus. Its children are objects of Menu class, each of them describes exactly one menu.
    /// A Menustrip object simply acts as father for multiple Menu objects and is usually specified as a child of
    /// either Application or Window class via @b MUIA_Application_Menustrip or @b MUIA_Window_Menustrip.
    class Menustrip : public Family
    {
      public:
        explicit Menustrip(Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menustrip(const Root &root)
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

#ifdef MUIA_Menustrip_CaseSensitive
        /// @brief [ @b MUIA_Menustrip_CaseSensitive ]
        /// Returns whether this menu strip is using case-sensitive keyboard shortcuts,
        /// i.e. whether it distinguishes between upper and lower case shortcuts such as 'a' and 'A'. Defaults to false.
        bool isCaseSensitive() const;
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Returns whether this menu strip is currently enabled.
        bool isEnabled() const;

        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Enable or disable the complete menu strip.
        Menustrip &setEnabled(const bool enabled);

        // methods, some returns object reference

#ifdef MUIM_Menustrip_ExitChange
        /// @brief [ @b MUIM_Menustrip_ExitChange ]
        /// Terminates the @b MUIM_Menustrip_InitChange state, causing MUI to relayout the menustrip with all pending changes applied.
        Menustrip &ExitChange();
#endif
#ifdef MUIM_Menustrip_InitChange
        /// @brief [ @b MUIM_Menustrip_InitChange ]
        /// Prepares a menustrip for dynamic adding or removing of menu items, even while the containing window is open.
        /// Call @b ExitChange() when done to make MUI relayout the menustrip.
        Menustrip &InitChange();
#endif
#ifdef MUIM_Menustrip_Popup
        /// @brief [ @b MUIM_Menustrip_Popup ]
        /// Open a menustrip for user input even without active user interaction.
        /// @param parent The parent object relative to which the menustrip will be opened.
        /// @param flags Reserved, set to 0.
        /// @param x Additional horizontal offset added to the parent object's left coordinate.
        /// @param y Additional vertical offset added to the parent object's top coordinate.
        /// @return The @b MUIA_UserData attribute of the selected menu item.
        unsigned long Popup(const Object *parent = nullptr, const unsigned long flags = 0, const long x = 0, const long y = 0);
        /// @brief [ @b MUIM_Menustrip_Popup ]
        /// Open a menustrip for user input even without active user interaction.
        /// @param parent The parent object relative to which the menustrip will be opened.
        /// @param flags Reserved, set to 0.
        /// @param x Additional horizontal offset added to the parent object's left coordinate.
        /// @param y Additional vertical offset added to the parent object's top coordinate.
        /// @return The @b MUIA_UserData attribute of the selected menu item.
        unsigned long Popup(const Root &parent, const unsigned long flags = 0, const long x = 0, const long y = 0);
#endif
#ifdef MUIM_Menustrip_WillOpen
        /// @brief [ @b MUIM_Menustrip_WillOpen ]
        /// Informs the application that a menustrip is about to be opened, allowing the application to update the
        /// menu strip before it is actually displayed.
        Menustrip &WillOpen();
#endif
    };

    template <typename T, typename U> class MenustripBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenustripBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menustrip)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Menustrip_CaseSensitive
        /// @brief [ @b MUIA_Menustrip_CaseSensitive ]
        /// Set to true if the menu strip uses items with both upper and lower case shortcuts (e.g. 'a' and 'A'),
        /// so MUI can distinguish between them. Defaults to false.
        T &tagCaseSensitive(const bool caseSensitive);
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Set the initial enabled or disabled state of the complete menu strip.
        T &tagEnabled(const bool enabled);
    };

    class MenustripBuilder : public MenustripBuilderTemplate<MenustripBuilder, Menustrip>
    {
      public:
        MenustripBuilder();
    };
}

#define MUI_MENUSTRIP_TPP_INCLUDE
#include "Menustrip.tpp"
#undef MUI_MENUSTRIP_TPP_INCLUDE
