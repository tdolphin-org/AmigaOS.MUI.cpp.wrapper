//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_POPSTRING_TPP_INCLUDE
#error "Popstring.tpp should only be included by Popstring.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagButton(const Object *button)
    {
        this->PushTag(MUIA_Popstring_Button, button);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagCloseHook(const Hook *closeHook)
    {
        this->PushTag(MUIA_Popstring_CloseHook, closeHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagOpenHook(const Hook *openHook)
    {
        this->PushTag(MUIA_Popstring_OpenHook, openHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagString(const Object *string)
    {
        this->PushTag(MUIA_Popstring_String, string);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagToggle(const bool toggle)
    {
        this->PushTag(MUIA_Popstring_Toggle, toggle);
        return (T &)*this;
    }
}
