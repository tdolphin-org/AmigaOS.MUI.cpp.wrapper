//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_VIRTGROUP_TPP_INCLUDE
#error "Virtgroup.tpp should only be included by Virtgroup.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_Virtgroup_Input, input);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagLeft(const long left)
    {
        this->PushTag(MUIA_Virtgroup_Left, left);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagTop(const long top)
    {
        this->PushTag(MUIA_Virtgroup_Top, top);
        return (T &)*this;
    }

#ifdef MUIA_Virtgroup_TryFit
    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagTryFit(const bool tryFit)
    {
        this->PushTag(MUIA_Virtgroup_TryFit, tryFit);
        return (T &)*this;
    }
#endif
}
