//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Menu.hpp"

namespace MUI
{
    const std::string Menu::className = MUIC_Menu;

    bool Menu::isEnabled() const
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

    Menu &Menu::setTitle(const char *title)
    {
        ClearStoredString(MUIA_Menu_Title);
        SetValue(MUIA_Menu_Title, title);

        return *this;
    }

    Menu &Menu::setTitle(const std::string &title, bool storeCopy)
    {
        if (storeCopy)
        {
            ClearStoredString(MUIA_Menu_Title);
            SetValue(MUIA_Menu_Title, title.c_str());
        }
        else
            SetValue(MUIA_Menu_Title, StoreString(MUIA_Menu_Title, title));

        return *this;
    }

    MenuBuilder::MenuBuilder() { }
}
