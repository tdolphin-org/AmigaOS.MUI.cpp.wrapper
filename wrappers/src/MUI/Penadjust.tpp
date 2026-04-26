//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PENADJUST_TPP_INCLUDE
#error "Penadjust.tpp should only be included by Penadjust.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Penadjust_PSIMode
    template <typename T, typename U> inline T &PenadjustBuilderTemplate<T, U>::tagPSIMode(const bool psiMode)
    {
        this->PushTag(MUIA_Penadjust_PSIMode, static_cast<ULONG>(psiMode));
        return static_cast<T &>(*this);
    }
#endif
}
