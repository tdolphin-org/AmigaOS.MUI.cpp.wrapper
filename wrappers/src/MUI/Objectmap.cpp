//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Objectmap.hpp"

#ifdef MUIC_Objectmap

#include <proto/alib.h>

namespace MUI
{
    const std::string Objectmap::className = MUIC_Objectmap;

    ObjectmapBuilder::ObjectmapBuilder() { }

#ifdef MUIA_Objectmap_Count
    unsigned long Objectmap::getCount() const
    {
        return GetValueAsULong(MUIA_Objectmap_Count);
    }
#endif

#ifdef MUIM_Objectmap_Clear
    Objectmap &Objectmap::Clear()
    {
        DoMethod(muiObject(), MUIM_Objectmap_Clear);
        return *this;
    }
#endif

#ifdef MUIM_Objectmap_Find
    Object *Objectmap::Find(const char *key) const
    {
        if (!key)
            return nullptr;
        return reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_Objectmap_Find, key));
    }
#endif

#ifdef MUIM_Objectmap_Iterate
    Object *Objectmap::Iterate(unsigned long *counter) const
    {
        if (!counter)
            return nullptr;
        return reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_Objectmap_Iterate, counter));
    }
#endif

#ifdef MUIM_Objectmap_IterationKey
    const char *Objectmap::IterationKey(unsigned long *counter) const
    {
        if (!counter)
            return nullptr;
        return reinterpret_cast<const char *>(DoMethod(muiObject(), MUIM_Objectmap_IterationKey, counter));
    }
#endif

#ifdef MUIM_Objectmap_Remove
    Object *Objectmap::Remove(const char *key)
    {
        if (!key)
            return nullptr;
        return reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_Objectmap_Remove, key));
    }
#endif

#ifdef MUIM_Objectmap_Set
    bool Objectmap::Set(const Object *object, const char *key)
    {
        if (!object || !key)
            return false;
        return (bool)DoMethod(muiObject(), MUIM_Objectmap_Set, object, key);
    }

    bool Objectmap::Set(const Root &object, const char *key)
    {
        return Set(object.muiObject(), key);
    }
#endif
}

#endif
