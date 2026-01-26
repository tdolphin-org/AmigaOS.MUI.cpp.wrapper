//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PROP_TPP_INCLUDE
#error "Prop.tpp should only be included by Prop.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Prop_DeltaFactor
    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagDeltaFactor(const long deltaFactor)
    {
        this->PushTag(MUIA_Prop_DeltaFactor, deltaFactor);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagEntries(const long entries)
    {
        this->PushTag(MUIA_Prop_Entries, entries);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagFirst(const long first)
    {
        this->PushTag(MUIA_Prop_First, first);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Prop_Horiz, horiz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagUseWinBorder(const enum Prop_UseWinBorder useWinBorder)
    {
        this->PushTag(MUIA_Prop_UseWinBorder, useWinBorder);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagVisible(const long visible)
    {
        this->PushTag(MUIA_Prop_Visible, visible);
        return (T &)*this;
    }
}
