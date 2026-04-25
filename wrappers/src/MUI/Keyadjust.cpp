//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Keyadjust.hpp"

#ifdef MUIC_Keyadjust

namespace MUI
{
    const std::string Keyadjust::className = MUIC_Keyadjust;

    bool Keyadjust::getAllowDoubleClick() const
    {
        return GetValueAsBool(MUIA_Keyadjust_AllowDoubleClick);
    }

    bool Keyadjust::getAllowMouseEvents() const
    {
        return GetValueAsBool(MUIA_Keyadjust_AllowMouseEvents);
    }

    bool Keyadjust::getAllowMultipleKeys() const
    {
        return GetValueAsBool(MUIA_Keyadjust_AllowMultipleKeys);
    }

    bool Keyadjust::getAllowTripleClick() const
    {
        return GetValueAsBool(MUIA_Keyadjust_AllowTripleClick);
    }

#ifdef MUIA_Keyadjust_ForceKeyCode
    unsigned long Keyadjust::getForceKeyCode() const
    {
        return GetValueAsULong(MUIA_Keyadjust_ForceKeyCode);
    }
#endif

    std::string Keyadjust::getKey() const
    {
        return GetValueAsString(MUIA_Keyadjust_Key);
    }

    Keyadjust &Keyadjust::setAllowDoubleClick(const bool allowDoubleClick)
    {
        SetValue(MUIA_Keyadjust_AllowDoubleClick, (ULONG)allowDoubleClick);
        return *this;
    }

    Keyadjust &Keyadjust::setAllowMouseEvents(const bool allowMouseEvents)
    {
        SetValue(MUIA_Keyadjust_AllowMouseEvents, (ULONG)allowMouseEvents);
        return *this;
    }

    Keyadjust &Keyadjust::setAllowMultipleKeys(const bool allowMultipleKeys)
    {
        SetValue(MUIA_Keyadjust_AllowMultipleKeys, (ULONG)allowMultipleKeys);
        return *this;
    }

    Keyadjust &Keyadjust::setAllowTripleClick(const bool allowTripleClick)
    {
        SetValue(MUIA_Keyadjust_AllowTripleClick, (ULONG)allowTripleClick);
        return *this;
    }

#ifdef MUIA_Keyadjust_ForceKeyCode
    Keyadjust &Keyadjust::setForceKeyCode(const unsigned long forceKeyCode)
    {
        SetValue(MUIA_Keyadjust_ForceKeyCode, forceKeyCode);
        return *this;
    }
#endif

    Keyadjust &Keyadjust::setKey(const char *key)
    {
        if (key == nullptr)
        {
            ClearStoredString(MUIA_Keyadjust_Key);
            SetValue(MUIA_Keyadjust_Key, nullptr);
        }
        else
            SetValue(MUIA_Keyadjust_Key, StoreString(MUIA_Keyadjust_Key, std::string { key }));

        return *this;
    }

    Keyadjust &Keyadjust::setKey(const std::string &key)
    {
        SetValue(MUIA_Keyadjust_Key, StoreString(MUIA_Keyadjust_Key, key));
        return *this;
    }
}

#endif
