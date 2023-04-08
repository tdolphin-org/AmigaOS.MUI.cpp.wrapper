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

        // methods, some can return object reference
    };

    template <typename T, typename U> class MenuitemBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuitemBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menuitem)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Menuitem_Enabled ]
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menuitem_Title ]
        T &tagTitle(const std::string &title);
    };

    class MenuitemBuilder : public MenuitemBuilderTemplate<MenuitemBuilder, Menuitem>
    {
      public:
        MenuitemBuilder();
    };

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
}
