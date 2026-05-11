//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Dataspace.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Dataspace::className = MUIC_Dataspace;

    DataspaceBuilder::DataspaceBuilder() { }

#ifdef MUIA_Dataspace_Count
    unsigned long Dataspace::getCount() const
    {
        return GetValueAsULong(MUIA_Dataspace_Count);
    }
#endif

#ifdef MUIM_Dataspace_Add
    bool Dataspace::Add(const void *data, const long len, const unsigned long id)
    {
        if (!data)
            return false;

        return (bool)DoMethod(muiObject(), MUIM_Dataspace_Add, data, len, id);
    }
#endif

#ifdef MUIM_Dataspace_Clear
    Dataspace &Dataspace::Clear()
    {
        DoMethod(muiObject(), MUIM_Dataspace_Clear);
        return *this;
    }
#endif

#ifdef MUIM_Dataspace_Find
    const void *Dataspace::Find(const unsigned long id) const
    {
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Dataspace_Find, id));
    }
#endif

#ifdef MUIM_Dataspace_Get
    const void *Dataspace::Get(const unsigned long id, unsigned long *size) const
    {
        return reinterpret_cast<const void *>(DoMethod(muiObject(), MUIM_Dataspace_Get, id, size));
    }
#endif

#ifdef MUIM_Dataspace_Merge
    unsigned long Dataspace::Merge(const Object *dataspace)
    {
        if (!dataspace)
            return 0;

        return static_cast<unsigned long>(DoMethod(muiObject(), MUIM_Dataspace_Merge, dataspace));
    }

    unsigned long Dataspace::Merge(const Dataspace &dataspace)
    {
        return Merge(dataspace.muiObject());
    }
#endif

#ifdef MUIM_Dataspace_ReadIFF
    AOS::IFFParse::IFFError Dataspace::ReadIFF(struct IFFHandle *handle)
    {
        return static_cast<AOS::IFFParse::IFFError>(DoMethod(muiObject(), MUIM_Dataspace_ReadIFF, handle));
    }
#endif

#ifdef MUIM_Dataspace_Remove
    bool Dataspace::Remove(const unsigned long id)
    {
        return (bool)DoMethod(muiObject(), MUIM_Dataspace_Remove, id);
    }
#endif

#ifdef MUIM_Dataspace_WriteIFF
    AOS::IFFParse::IFFError Dataspace::WriteIFF(struct IFFHandle *handle, const unsigned long type, const unsigned long id)
    {
        return static_cast<AOS::IFFParse::IFFError>(DoMethod(muiObject(), MUIM_Dataspace_WriteIFF, handle, type, id));
    }
#endif
}
