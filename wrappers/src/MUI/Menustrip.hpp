//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
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

        // get/set (attributes), all setters return object reference

        // methods, some can return object reference
    };

    template <typename T, typename U> class MenustripBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenustripBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menustrip)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class MenustripBuilder : public MenustripBuilderTemplate<MenustripBuilder, Menustrip>
    {
      public:
        MenustripBuilder();
    };
}
