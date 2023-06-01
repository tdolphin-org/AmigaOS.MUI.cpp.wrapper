//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Family.hpp"

namespace MUI
{
    class Menustrip : public Family
    {
      public:
        Menustrip(const Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menustrip(const Root &root)
          : Family(root.muiObject())
        {
        }

        inline bool instanceOf(Object *pMuiObject) const
        {
            return MUI::instanceOf(pMuiObject, MUIC_Menustrip);
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menustrip_CaseSensitive ]
        bool getCaseSensitive() const;
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        bool getEnabled() const;

        /// @brief [ @b MUIA_Menustrip_Enabled ]
        Menustrip &setEnabled(const bool enabled);

        // methods, some can return object reference
    };

    template <typename T, typename U> class MenustripBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenustripBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menustrip)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menustrip_CaseSensitive ]
        T &tagCaseSensitive(const bool caseSensitive);
        /// @brief [ @b MUIA_Menustrip_Enabled ]
        T &tagEnabled(const bool enabled);
    };

    class MenustripBuilder : public MenustripBuilderTemplate<MenustripBuilder, Menustrip>
    {
      public:
        MenustripBuilder();
    };

    template <typename T, typename U> inline T &MenustripBuilderTemplate<T, U>::tagCaseSensitive(const bool caseSensitive)
    {
        this->PushTag(MUIA_Menustrip_CaseSensitive, caseSensitive);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenustripBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menustrip_Enabled, enabled);
        return (T &)*this;
    }
}
