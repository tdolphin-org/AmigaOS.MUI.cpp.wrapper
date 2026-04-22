//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
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

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Menustrip_CaseSensitive
        /// @brief [ @b MUIA_Menustrip_CaseSensitive ]
        /// Query whether keyboard shortcut matching is case sensitive.
        bool isCaseSensitive() const;
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Query whether this menustrip is currently enabled.
        bool isEnabled() const;

        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Enable or disable this menustrip.
        Menustrip &setEnabled(const bool enabled);

        // methods, some returns object reference

#ifdef MUIM_Menustrip_ExitChange
        /// @brief [ @b MUIM_Menustrip_ExitChange ]
        /// End a menustrip change session and apply pending updates.
        Menustrip &ExitChange();
#endif
#ifdef MUIM_Menustrip_InitChange
        /// @brief [ @b MUIM_Menustrip_InitChange ]
        /// Begin a menustrip change session.
        Menustrip &InitChange();
#endif
#ifdef MUIM_Menustrip_Popup
        /// @brief [ @b MUIM_Menustrip_Popup ]
        /// Open this menustrip as a popup menu with a native parent object.
        unsigned long Popup(const Object *parent = nullptr, const unsigned long flags = 0, const long x = 0, const long y = 0);
        /// @brief [ @b MUIM_Menustrip_Popup ]
        /// Open this menustrip as a popup menu with a wrapper parent object.
        unsigned long Popup(const Root &parent, const unsigned long flags = 0, const long x = 0, const long y = 0);
#endif
#ifdef MUIM_Menustrip_WillOpen
        /// @brief [ @b MUIM_Menustrip_WillOpen ]
        /// Notify the menustrip that it is about to open.
        unsigned long WillOpen();
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
        /// Set the initial case sensitivity for shortcut matching.
        T &tagCaseSensitive(const bool caseSensitive);
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        /// Set the initial enabled state for this menustrip.
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
