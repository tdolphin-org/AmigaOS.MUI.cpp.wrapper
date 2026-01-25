//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_RADIO_TPP_INCLUDE
#error "Radio.tpp should only be included by Radio.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &RadioBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_Radio_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RadioBuilderTemplate<T, U>::tagEntries(const char *entries[])
    {
        this->PushTag(MUIA_Radio_Entries, entries);
        return (T &)*this;
    }
}
