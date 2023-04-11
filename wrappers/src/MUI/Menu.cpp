//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Menu.hpp"

namespace MUI
{
    MenuBuilder::MenuBuilder() { }
    
    bool Menu::getEnabled() const
    {
        return GetValueAsBool(MUIA_Menu_Enabled);
    }
    
    std::string Menu::getTitle() const
    {
        return GetValueAsString(MUIA_Menu_Title);
    }

    Menu &Menu::setEnabled(const bool enabled)
    {
        SetValue(MUIA_Menu_Enabled, enabled);
        return *this;
    }

    Menu &Menu::setTitle(const std::string &title)
    {
        SetValue(MUIA_Menu_Title, title);
        return *this;
    }
}
