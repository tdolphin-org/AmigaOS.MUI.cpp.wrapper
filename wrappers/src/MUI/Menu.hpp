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

        // methods, some can return object reference
    };

    template <typename T, typename U> class MenuBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menu)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class MenuBuilder : public MenuBuilderTemplate<MenuBuilder, Menu>
    {
      public:
        MenuBuilder();
    };
}
