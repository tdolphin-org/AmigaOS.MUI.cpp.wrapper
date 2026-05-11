//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_DATASPACE_TPP_INCLUDE
#error "Dataspace.tpp should only be included by Dataspace.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Dataspace_Pool
    template <typename T, typename U> inline T &DataspaceBuilderTemplate<T, U>::tagPool(const void *pool)
    {
        this->PushTag(MUIA_Dataspace_Pool, pool);
        return (T &)*this;
    }
#endif
}
