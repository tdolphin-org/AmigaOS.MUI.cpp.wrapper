//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SELECTGROUP_TPP_INCLUDE
#error "Selectgroup.tpp should only be included by Selectgroup.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &SelectgroupBuilderTemplate<T, U>::tagActive(long active)
    {
        this->PushTag(MUIA_Selectgroup_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &SelectgroupBuilderTemplate<T, U>::tagActive(const Selectgroup_Active active)
    {
        this->PushTag(MUIA_Selectgroup_Active, static_cast<long>(active));
        return (T &)*this;
    }
}
