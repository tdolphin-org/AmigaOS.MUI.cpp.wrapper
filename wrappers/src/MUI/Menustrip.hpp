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
        bool isCaseSensitive() const;
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        bool isEnabled() const;

        /// @brief [ @b MUIA_Menustrip_Enabled ]
        Menustrip &setEnabled(const bool enabled);

        // methods, some returns object reference
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
        T &tagCaseSensitive(const bool caseSensitive);
#endif
        /// @brief [ @b MUIA_Menustrip_Enabled ]
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
