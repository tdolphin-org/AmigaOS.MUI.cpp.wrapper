//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_DATAMAP_TPP_INCLUDE
#error "Datamap.tpp should only be included by Datamap.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Datamap_AutoLock
    template <typename T, typename U> inline T &DatamapBuilderTemplate<T, U>::tagAutoLock(const bool autoLock)
    {
        this->PushTag(MUIA_Datamap_AutoLock, autoLock);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Datamap_CopyKeys
    template <typename T, typename U> inline T &DatamapBuilderTemplate<T, U>::tagCopyKeys(const bool copyKeys)
    {
        this->PushTag(MUIA_Datamap_CopyKeys, copyKeys);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Datamap_Pool
    template <typename T, typename U> inline T &DatamapBuilderTemplate<T, U>::tagPool(const void *pool)
    {
        this->PushTag(MUIA_Datamap_Pool, pool);
        return (T &)*this;
    }
#endif
}
