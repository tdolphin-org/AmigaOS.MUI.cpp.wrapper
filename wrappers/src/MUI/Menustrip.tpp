//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_MENUSTRIP_TPP_INCLUDE
#error "Menustrip.tpp should only be included by Menustrip.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Menustrip_CaseSensitive
    template <typename T, typename U> inline T &MenustripBuilderTemplate<T, U>::tagCaseSensitive(const bool caseSensitive)
    {
        this->PushTag(MUIA_Menustrip_CaseSensitive, caseSensitive);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &MenustripBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menustrip_Enabled, enabled);
        return (T &)*this;
    }
}
