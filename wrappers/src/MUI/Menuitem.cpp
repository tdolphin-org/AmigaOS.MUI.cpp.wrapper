//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Menuitem.hpp"

namespace MUI
{
    MenuitemBuilder::MenuitemBuilder() { }

    bool Menuitem::getChecked() const
    {
        return GetValueAsBool(MUIA_Menuitem_Checked);
    }

    bool Menuitem::getCheckit() const
    {
        return GetValueAsBool(MUIA_Menuitem_Checkit);
    }

    bool Menuitem::getEnabled() const
    {
        return GetValueAsBool(MUIA_Menuitem_Enabled);
    }

    std::string Menuitem::getTitle() const
    {
        return GetValueAsString(MUIA_Menuitem_Title);
    }

    bool Menuitem::getToggle() const
    {
        return GetValueAsBool(MUIA_Menuitem_Toggle);
    }

    Menuitem &Menuitem::setChecked(const bool checked)
    {
        SetValue(MUIA_Menuitem_Checked, checked);
        return *this;
    }

    Menuitem &Menuitem::setCheckit(const bool checkit)
    {
        SetValue(MUIA_Menuitem_Checkit, checkit);
        return *this;
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

    Menuitem &Menuitem::setToggle(const bool toggle)
    {
        SetValue(MUIA_Menuitem_Toggle, toggle);
        return *this;
    }
}
