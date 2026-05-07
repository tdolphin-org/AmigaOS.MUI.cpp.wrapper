//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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
        return GetValueAsAppMessagePtr(MUIA_AppMessage);
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

    Notify &Notify::setHelpNode(const char *helpNode)
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
    bool Notify::FindObject(const Root &findme) const
    {
        return DoMethod(muiObject(), MUIM_FindObject, findme.muiObject()) != 0;
    }

    bool Notify::FindObject(const Object *findme) const
    {
        return DoMethod(muiObject(), MUIM_FindObject, findme) != 0;
    }
#endif

    Object *Notify::FindUData(const unsigned long udata) const
    {
        return (Object *)DoMethod(muiObject(), MUIM_FindUData, udata);
    }

    Object *Notify::GetUData(const unsigned long udata, const unsigned long attr, unsigned long *storage)
    {
        return (Object *)DoMethod(muiObject(), MUIM_GetUData, udata, attr, storage);
    }

    unsigned long Notify::GetConfigItem(const unsigned long id, unsigned long *storage) const
    {
        return DoMethod(muiObject(), MUIM_GetConfigItem, id, storage);
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

    Notify &Notify::Set(const unsigned long attr, const unsigned long val)
    {
        DoMethod(muiObject(), MUIM_Set, attr, val);
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

    unsigned long Notify::Export(const Root &dataspace)
    {
        return DoMethod(muiObject(), MUIM_Export, dataspace.muiObject());
    }

    unsigned long Notify::Import(const Root &dataspace)
    {
        return DoMethod(muiObject(), MUIM_Import, dataspace.muiObject());
    }

    Notify &Notify::WriteLong(const unsigned long value, unsigned long *memory)
    {
        DoMethod(muiObject(), MUIM_WriteLong, value, memory);
        return *this;
    }

    Notify &Notify::WriteString(const char *value, char *memory)
    {
        DoMethod(muiObject(), MUIM_WriteString, value, memory);
        return *this;
    }

    Notify &Notify::WriteString(const std::string &value, char *memory)
    {
        return WriteString(value.c_str(), memory);
    }

    NotifyBuilder::NotifyBuilder() { }
}
