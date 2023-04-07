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

    Notify &Notify::setHelpLine(const long helpLine)
    {
        SetValue(MUIA_HelpLine, helpLine);
        return *this;
    }

    Object *Notify::getParent()
    {
        return GetValueAsObjectPtr(MUIA_Parent);
    }

    NotifyBuilder::NotifyBuilder() { }
}
