//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Menuitem.hpp"

namespace MUI
{
    MenuitemBuilder::MenuitemBuilder() { }
    
    bool Menuitem::getEnabled() const
    {
        return GetValueAsBool(MUIA_Menuitem_Enabled);
    }
    
    std::string Menuitem::getTitle() const
    {
        return GetValueAsString(MUIA_Menuitem_Title);
    }
    
    Menuitem &Menuitem::setEnabled(const bool enabled)
    {
        SetValue(MUIA_Menuitem_Enabled, enabled);
        return *this;
    }
    
    Menuitem &Menuitem::setTitle(const std::string &title)
    {
        SetValue(MUIA_Menuitem_Title, title);
        return *this;
    }
}
