//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Popstring.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Popstring::className = MUIC_Popstring;

    PopstringBuilder::PopstringBuilder() { }

    Object *Popstring::getButton() const
    {
        return GetValueAsObjectPtr(MUIA_Popstring_Button);
    }

    Hook *Popstring::getCloseHook() const
    {
        return GetValueAsHookPtr(MUIA_Popstring_CloseHook);
    }

    Hook *Popstring::getOpenHook() const
    {
        return GetValueAsHookPtr(MUIA_Popstring_OpenHook);
    }

    Object *Popstring::getString() const
    {
        return GetValueAsObjectPtr(MUIA_Popstring_String);
    }

    bool Popstring::isToggle() const
    {
        return GetValueAsBool(MUIA_Popstring_Toggle);
    }

    Popstring &Popstring::setCloseHook(const Hook *closeHook)
    {
        SetValue(MUIA_Popstring_CloseHook, closeHook);
        return *this;
    }

    Popstring &Popstring::setOpenHook(const Hook *openHook)
    {
        SetValue(MUIA_Popstring_OpenHook, openHook);
        return *this;
    }

    Popstring &Popstring::setToggle(const bool toggle)
    {
        SetValue(MUIA_Popstring_Toggle, toggle);
        return *this;
    }

    Popstring &Popstring::Close(long result)
    {
        DoMethod(muiObject(), MUIM_Popstring_Close, result);
        return *this;
    }

    Popstring &Popstring::Open()
    {
        DoMethod(muiObject(), MUIM_Popstring_Open);
        return *this;
    }
}
