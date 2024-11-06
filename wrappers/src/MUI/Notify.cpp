//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Notify.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Notify::className = MUIC_Notify;

    Object *Notify::getApplicationObject() const
    {
        return GetValueAsObjectPtr(MUIA_ApplicationObject);
    }

    AppMessage *Notify::getAppMessage() const
    {
        return (AppMessage *)GetValueAsPtr(MUIA_AppMessage);
    }

    long Notify::getHelpLine() const
    {
        return GetValueAsLong(MUIA_HelpLine);
    }

    std::string Notify::getHelpNode() const
    {
        return GetValueAsString(MUIA_HelpNode);
    }

    AOS::Identifier Notify::getObjectID() const
    {
        return AOS::Identifier(GetValueAsULong(MUIA_ObjectID));
    }

    Object *Notify::getParent()
    {
        return GetValueAsObjectPtr(MUIA_Parent);
    }

    long Notify::getRevision() const
    {
        return GetValueAsLong(MUIA_Revision);
    }

    unsigned long Notify::getUserData() const
    {
        return GetValueAsULong(MUIA_UserData);
    }

    long Notify::getVersion() const
    {
        return GetValueAsLong(MUIA_Version);
    }

    Notify &Notify::setHelpLine(const long helpLine)
    {
        SetValue(MUIA_HelpLine, helpLine);
        return *this;
    }

    Notify &Notify::setHelpNode(const std::string &helpNode)
    {
        SetValue(MUIA_HelpNode, helpNode);
        return *this;
    }

    Notify &Notify::setNoNotify(const bool noNotify)
    {
        SetValue(MUIA_NoNotify, noNotify);
        return *this;
    }

#ifdef MUIA_NoNotifyMethod
    Notify &Notify::setNoNotifyMethod(const unsigned long noNotifyMethod)
    {
        SetValue(MUIA_NoNotifyMethod, noNotifyMethod);
        return *this;
    }
#endif

    Notify &Notify::setObjectID(const AOS::Identifier &objectID)
    {
        SetValue(MUIA_ObjectID, objectID.value());
        return *this;
    }

    Notify &Notify::setUserData(const unsigned long userData)
    {
        SetValue(MUIA_UserData, userData);
        return *this;
    }

#ifdef MUIM_FindObject
    Object *Notify::FindObject(const Root &findme) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_FindObject, findme.muiObject());
    }

    Object *Notify::FindObject(const Object *findme) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_FindObject, findme);
    }
#endif

    Object *Notify::FindUData(const unsigned long udata) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_FindUData, udata);
    }

    Object *Notify::GetUData(const unsigned long udata, const unsigned long attr, const unsigned long *storage)
    {
        return (Object *)DoMethod(muiObject(), MUIM_GetUData, udata, attr, storage);
    }

    Notify &Notify::KillNotify(const unsigned long trigAttr)
    {
        DoMethod(muiObject(), MUIM_KillNotify, trigAttr);
        return *this;
    }

    Notify &Notify::KillNotifyObj(const unsigned long trigAttr, const Root &dest)
    {
        DoMethod(muiObject(), MUIM_KillNotifyObj, trigAttr, dest.muiObject());
        return *this;
    }

    Notify &Notify::KillNotifyObj(const unsigned long trigAttr, const Object *dest)
    {
        DoMethod(muiObject(), MUIM_KillNotifyObj, trigAttr, dest);
        return *this;
    }

    Notify &Notify::MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0)
    {
        DoMethod(muiObject(), MUIM_MultiSet, attr, val, obj0.muiObject());
        return *this;
    }

    Notify &Notify::MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1)
    {
        DoMethod(muiObject(), MUIM_MultiSet, attr, val, obj0.muiObject(), obj1.muiObject());
        return *this;
    }

    Notify &Notify::MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1, const Root &obj2)
    {
        DoMethod(muiObject(), MUIM_MultiSet, attr, val, obj0.muiObject(), obj1.muiObject(), obj2.muiObject());
        return *this;
    }

    Notify &Notify::MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1, const Root &obj2,
                             const Root &obj3)
    {
        DoMethod(muiObject(), MUIM_MultiSet, attr, val, obj0.muiObject(), obj1.muiObject(), obj2.muiObject(), obj3.muiObject());
        return *this;
    }

    Notify &Notify::NoNotifySet(const unsigned long attr, const unsigned long val)
    {
        DoMethod(muiObject(), MUIM_NoNotifySet, attr, val);
        return *this;
    }

    Notify &Notify::doNotify(const unsigned long attr, const unsigned long val, const Root destObj)
    {
        DoMethod(muiObject(), MUIM_Notify, attr, val, destObj);
        return *this;
    }

    Notify &Notify::Set(const unsigned long attr, const unsigned long val)
    {
        DoMethod(muiObject(), MUIM_Set, attr, val);
        return *this;
    }

    Notify &Notify::SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0)
    {
        DoMethod(muiObject(), MUIM_SetAsString, attr, format, val0);
        return *this;
    }

    Notify &Notify::SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0, const unsigned long val1)
    {
        DoMethod(muiObject(), MUIM_SetAsString, attr, format, val0, val1);
        return *this;
    }

    Notify &Notify::SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0, const unsigned long val1,
                                const unsigned long val2)
    {
        DoMethod(muiObject(), MUIM_SetAsString, attr, format, val0, val1, val2);
        return *this;
    }

    Notify &Notify::SetUData(const unsigned long udata, const unsigned long attr, const unsigned long val)
    {
        DoMethod(muiObject(), MUIM_SetUData, udata, attr, val);
        return *this;
    }

    Notify &Notify::SetUDataOnce(const unsigned long udata, const unsigned long attr, const unsigned long val)
    {
        DoMethod(muiObject(), MUIM_SetUDataOnce, udata, attr, val);
        return *this;
    }

    NotifyBuilder::NotifyBuilder() { }
}
