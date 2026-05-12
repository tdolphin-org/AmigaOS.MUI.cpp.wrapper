//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Datamap.hpp"

#ifdef MUIC_Datamap

#include <proto/alib.h>

namespace MUI
{
    const std::string Datamap::className = MUIC_Datamap;

    DatamapBuilder::DatamapBuilder() { }

#ifdef MUIA_Datamap_Count
    unsigned long Datamap::getCount() const
    {
        return GetValueAsULong(MUIA_Datamap_Count);
    }
#endif

#ifdef MUIM_Datamap_Clear
    Datamap &Datamap::Clear()
    {
        DoMethod(muiObject(), MUIM_Datamap_Clear);
        return *this;
    }
#endif

#ifdef MUIM_Datamap_Find
    const void *Datamap::Find(const char *key) const
    {
        if (!key)
            return nullptr;
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Datamap_Find, key));
    }

    const void *Datamap::Find(const std::string &key) const
    {
        return Find(key.c_str());
    }
#endif

#ifdef MUIM_Datamap_Get
    const void *Datamap::Get(const char *key, unsigned long *size) const
    {
        if (!key)
            return nullptr;
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Datamap_Get, key, size));
    }

    const void *Datamap::Get(const std::string &key, unsigned long *size) const
    {
        return Get(key.c_str(), size);
    }
#endif

#ifdef MUIM_Datamap_Iterate
    const void *Datamap::Iterate(unsigned long *counter) const
    {
        if (!counter)
            return nullptr;
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Datamap_Iterate, counter));
    }
#endif

#ifdef MUIM_Datamap_IterationKey
    const char *Datamap::IterationKey(unsigned long *counter) const
    {
        if (!counter)
            return nullptr;
        return reinterpret_cast<const char *>(DoMethod(muiObject(), MUIM_Datamap_IterationKey, counter));
    }
#endif

#ifdef MUIM_Datamap_Remove
    const void *Datamap::Remove(const char *key)
    {
        if (!key)
            return nullptr;
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Datamap_Remove, key));
    }

    const void *Datamap::Remove(const std::string &key)
    {
        return Remove(key.c_str());
    }
#endif

#ifdef MUIM_Datamap_Set
    bool Datamap::Set(const void *data, const long len, const char *key)
    {
        if (!data || !key)
            return false;
        return (bool)DoMethod(muiObject(), MUIM_Datamap_Set, data, len, key);
    }

    bool Datamap::Set(const void *data, const long len, const std::string &key)
    {
        return Set(data, len, key.c_str());
    }
#endif
}

#endif
