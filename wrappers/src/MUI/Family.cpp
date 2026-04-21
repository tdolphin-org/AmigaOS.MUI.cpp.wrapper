//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Family.hpp"
#include "Core/ObjectVectorUtils.hpp"

#include <clib/alib_protos.h>

namespace MUI
{
    const std::string Family::className = MUIC_Family;

#ifdef MUIA_Family_ChildCount
    long Family::getChildCount() const
    {
        return GetValueAsLong(MUIA_Family_ChildCount);
    }
#endif

    const MinList *Family::getChildList() const
    {
        return GetValueAsConstMinListPtr(MUIA_Family_List);
    }

    Family &Family::AddHead(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Family_AddHead, (ULONG)pChildObject);
        return *this;
    }

    Family &Family::AddHead(const Root &child)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Family_AddHead, (ULONG)child.muiObject());
        return *this;
    }

    Family &Family::AddTail(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Family_AddTail, (ULONG)pChildObject);
        return *this;
    }

    Family &Family::AddTail(const Root &child)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Family_AddTail, (ULONG)child.muiObject());
        return *this;
    }

#ifdef MUIM_Family_GetChild
    Object *Family::GetChild(const long nr, const Object *ref) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_Family_GetChild, nr, ref);
    }

    Object *Family::GetChild(const long nr, const Root &ref) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_Family_GetChild, nr, ref.muiObject());
    }

    Object *Family::GetChildFirst() const
    {
        return GetChild(MUIV_Family_GetChild_First);
    }

    Object *Family::GetChildLast() const
    {
        return GetChild(MUIV_Family_GetChild_Last);
    }

    Object *Family::GetChildNext(const Object *ref) const
    {
        return GetChild(MUIV_Family_GetChild_Next, ref);
    }

    Object *Family::GetChildNext(const Root &ref) const
    {
        return GetChild(MUIV_Family_GetChild_Next, ref);
    }

    Object *Family::GetChildPrevious(const Object *ref) const
    {
        return GetChild(MUIV_Family_GetChild_Previous, ref);
    }

    Object *Family::GetChildPrevious(const Root &ref) const
    {
        return GetChild(MUIV_Family_GetChild_Previous, ref);
    }

    Object *Family::GetChildIterate(void *iteratorRef) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_Family_GetChild, MUIV_Family_GetChild_Iterate, iteratorRef);
    }
#endif

    Family &Family::Insert(const Object *pChildObject, const Object *pPredecessorObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Family_Insert, pChildObject, pPredecessorObject);
        return *this;
    }

    Family &Family::Insert(const MUI::Root &obj, const MUI::Root &pred)
    {
        if (obj.muiObject())
            DoMethod(muiObject(), MUIM_Family_Insert, obj.muiObject(), pred.muiObject());
        return *this;
    }

    Family &Family::Remove(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Family_Remove, pChildObject);
        return *this;
    }

    Family &Family::Remove(const MUI::Root &obj)
    {
        if (obj.muiObject())
            DoMethod(muiObject(), MUIM_Family_Remove, obj.muiObject());
        return *this;
    }

#ifdef MUIM_Family_Reorder
    Family &Family::Reorder(const Object *after, const std::vector<const Object *> &objects)
    {
        auto orderedObjects = Detail::makeNullTerminatedObjectVector(objects);
        DoMethod(muiObject(), MUIM_Family_Reorder, after, orderedObjects.data());
        return *this;
    }

    Family &Family::Reorder(const Object *after, const std::initializer_list<const Object *> &objects)
    {
        return Reorder(after, std::vector<const Object *>(objects));
    }

    Family &Family::ReorderFront(const std::vector<const Object *> &objects)
    {
        return Reorder(nullptr, objects);
    }

    Family &Family::ReorderFront(const std::initializer_list<const Object *> &objects)
    {
        return ReorderFront(std::vector<const Object *>(objects));
    }

    Family &Family::ReorderBack(const std::vector<const Object *> &objects)
    {
        return Reorder((const Object *)-1, objects);
    }

    Family &Family::ReorderBack(const std::initializer_list<const Object *> &objects)
    {
        return ReorderBack(std::vector<const Object *>(objects));
    }
#endif

    Family &Family::Sort(const std::vector<const Object *> &objects)
    {
        auto orderedObjects = Detail::makeNullTerminatedObjectVector(objects);
        DoMethod(muiObject(), MUIM_Family_Sort, orderedObjects.data());
        return *this;
    }

    Family &Family::Sort(const std::initializer_list<const Object *> &objects)
    {
        return Sort(std::vector<const Object *>(objects));
    }

    Family &Family::Transfer(const Object *pDestinationFamilyObject)
    {
        if (pDestinationFamilyObject)
            DoMethod(muiObject(), MUIM_Family_Transfer, pDestinationFamilyObject);
        return *this;
    }

    Family &Family::Transfer(const Family &destinationFamily)
    {
        if (destinationFamily.muiObject())
            DoMethod(muiObject(), MUIM_Family_Transfer, destinationFamily.muiObject());
        return *this;
    }

    FamilyBuilder::FamilyBuilder() { }
}
