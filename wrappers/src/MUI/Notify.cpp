//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Notify.hpp"

namespace MUI
{
    Object *Notify::getApplicationObject() const
    {
        return GetValueAsObjectPtr(MUIA_ApplicationObject);
    }

    long Notify::getHelpLine() const
    {
        return GetValueAsLong(MUIA_HelpLine);
    }

    std::string Notify::getHelpNode() const
    {
        return GetValueAsString(MUIA_HelpNode);
    }

    unsigned long Notify::getObjectID() const
    {
        return GetValueAsULong(MUIA_ObjectID);
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

    NotifyBuilder::NotifyBuilder() { }
}
