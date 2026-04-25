//
//  AmigaOS MUI C++ wrapper - Keyadjust builder template
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_KEYADJUST_TPP_INCLUDE
#error This file is supposed to be included from Keyadjust.hpp only!
#endif

#ifdef MUIC_Keyadjust

namespace MUI
{
    // Keyadjust builder

    inline KeyadjustBuilder::KeyadjustBuilder()
      : KeyadjustBuilderTemplate(MUI::EmptyUniqueId, MUIC_Keyadjust)
    {
    }

    // KeyadjustBuilderTemplate

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagAllowDoubleClick(const bool allowDoubleClick)
    {
        this->PushTag(MUIA_Keyadjust_AllowDoubleClick, (ULONG)allowDoubleClick);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagAllowMouseEvents(const bool allowMouseEvents)
    {
        this->PushTag(MUIA_Keyadjust_AllowMouseEvents, (ULONG)allowMouseEvents);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagAllowMultipleKeys(const bool allowMultipleKeys)
    {
        this->PushTag(MUIA_Keyadjust_AllowMultipleKeys, (ULONG)allowMultipleKeys);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagAllowTripleClick(const bool allowTripleClick)
    {
        this->PushTag(MUIA_Keyadjust_AllowTripleClick, (ULONG)allowTripleClick);
        return static_cast<T &>(*this);
    }

#ifdef MUIA_Keyadjust_ForceKeyCode
    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagForceKeyCode(const unsigned long forceKeyCode)
    {
        this->PushTag(MUIA_Keyadjust_ForceKeyCode, forceKeyCode);
        return static_cast<T &>(*this);
    }
#endif

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagKey(const char *key)
    {
        if (key)
        {
            this->PushTag(MUIA_Keyadjust_Key, (ULONG)this->StoreString(MUIA_Keyadjust_Key, std::string { key }));
        }
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &KeyadjustBuilderTemplate<T, U>::tagKey(const std::string &key)
    {
        this->PushTag(MUIA_Keyadjust_Key, (ULONG)this->StoreString(MUIA_Keyadjust_Key, key));
        return static_cast<T &>(*this);
    }
}

#endif
