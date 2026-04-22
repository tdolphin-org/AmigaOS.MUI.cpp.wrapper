//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Menuitem.hpp"

#include "libraries/gadtools.h"

namespace MUI
{
    const std::string Menuitem::className = MUIC_Menuitem;

    bool Menuitem::isChecked() const
    {
        return GetValueAsBool(MUIA_Menuitem_Checked);
    }

    bool Menuitem::isCheckit() const
    {
        return GetValueAsBool(MUIA_Menuitem_Checkit);
    }

    bool Menuitem::isCommandString() const
    {
        return GetValueAsBool(MUIA_Menuitem_CommandString);
    }

    bool Menuitem::isEnabled() const
    {
        return GetValueAsBool(MUIA_Menuitem_Enabled);
    }

    std::string Menuitem::getTitle() const
    {
        return GetValueAsString(MUIA_Menuitem_Title);
    }

    bool Menuitem::isToggle() const
    {
        return GetValueAsBool(MUIA_Menuitem_Toggle);
    }

    std::string Menuitem::getShortcut() const
    {
        return GetValueAsString(MUIA_Menuitem_Shortcut);
    }

    const MenuItem *Menuitem::getTrigger() const
    {
        return (const MenuItem *)GetValueAsULong(MUIA_Menuitem_Trigger);
    }

#ifdef MUIA_Menuitem_AISSName
    std::string Menuitem::getAISSName() const
    {
        return GetValueAsString(MUIA_Menuitem_AISSName);
    }
#endif

#ifdef MUIA_Menuitem_Image
    const ::Image *Menuitem::getImage() const
    {
        return (const ::Image *)GetValueAsULong(MUIA_Menuitem_Image);
    }
#endif

#ifdef MUIA_Menuitem_Menuitem
    Object *Menuitem::getMenuitemObject() const
    {
        return GetValueAsObjectPtr(MUIA_Menuitem_Menuitem);
    }

    Menuitem Menuitem::getMenuitem() const
    {
        return Menuitem(getMenuitemObject());
    }
#endif

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

    Menuitem &Menuitem::setCommandString(const bool commandString)
    {
        SetValue(MUIA_Menuitem_CommandString, commandString);
        return *this;
    }

    Menuitem &Menuitem::setEnabled(const bool enabled)
    {
        SetValue(MUIA_Menuitem_Enabled, enabled);
        return *this;
    }

    Menuitem &Menuitem::setTitle(const std::string &title)
    {
        SetValue(MUIA_Menuitem_Title, StoreString(MUIA_Menuitem_Title, title));
        return *this;
    }

    Menuitem &Menuitem::setToggle(const bool toggle)
    {
        SetValue(MUIA_Menuitem_Toggle, toggle);
        return *this;
    }

    Menuitem MenuItemFactory::Separator()
    {
        return MenuitemBuilder().tagTitle(NM_BARLABEL).object();
    }

    Menuitem MenuItemFactory::BasicItem(const std::string &title, const unsigned long userData)
    {
        return MenuitemBuilder().tagTitle(title).tagUserData(userData).object();
    }

    MenuitemBuilder::MenuitemBuilder() { }
}
