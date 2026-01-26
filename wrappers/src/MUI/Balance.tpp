//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_BALANCE_TPP_INCLUDE
#error "File Balance.tpp can not be included directly, include file Balance.hpp instead!"
#endif

namespace MUI
{
#ifdef MUIA_Balance_Quiet
    template <typename T, typename U> inline T &BalanceBuilderTemplate<T, U>::tagQuiet(const bool quiet)
    {
        this->PushTag(MUIA_Balance_Quiet, quiet);
        return (T &)*this;
    }
#endif
}
