//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SCROLLBAR_TPP_INCLUDE
#error "Scrollbar.tpp should only be included by Scrollbar.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Scrollbar_IncDecSize
    template <typename T, typename U> inline T &ScrollbarBuilderTemplate<T, U>::tagIncDecSize(const unsigned long incDecSize)
    {
        this->PushTag(MUIA_Scrollbar_IncDecSize, incDecSize);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ScrollbarBuilderTemplate<T, U>::tagType(const enum Scrollbar_Type type)
    {
        this->PushTag(MUIA_Scrollbar_Type, (long)type);
        return (T &)*this;
    }
}
