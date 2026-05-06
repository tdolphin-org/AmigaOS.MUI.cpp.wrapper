//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_OBJECTMAP_TPP_INCLUDE
#error "Objectmap.tpp should only be included by Objectmap.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Objectmap_AutoLock
    template <typename T, typename U> inline T &ObjectmapBuilderTemplate<T, U>::tagAutoLock(const bool autoLock)
    {
        this->PushTag(MUIA_Objectmap_AutoLock, autoLock);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Objectmap_CopyKeys
    template <typename T, typename U> inline T &ObjectmapBuilderTemplate<T, U>::tagCopyKeys(const bool copyKeys)
    {
        this->PushTag(MUIA_Objectmap_CopyKeys, copyKeys);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Objectmap_Pool
    template <typename T, typename U> inline T &ObjectmapBuilderTemplate<T, U>::tagPool(const void *pool)
    {
        this->PushTag(MUIA_Objectmap_Pool, pool);
        return (T &)*this;
    }
#endif
}
