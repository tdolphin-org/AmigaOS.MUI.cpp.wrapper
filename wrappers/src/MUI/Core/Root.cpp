//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Root.hpp"

#include <stdexcept>

#include <proto/intuition.h>

namespace MUI
{
    Root::Root(const Object *pMuiObject)
    {
        if (pMuiObject == nullptr)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + " mui object is nullptr!";
            throw std::invalid_argument(error);
        }

        mpMuiObject = (Object *)pMuiObject;
    }

    std::string Root::GetValueAsString(const unsigned long tagName) const
    {
        char *value;
        GetAttr(tagName, muiObject(), (unsigned long *)&value);
        return std::string(value);
    }

    unsigned long Root::GetValueAsULong(const unsigned long tagName) const
    {
        unsigned long value;
        GetAttr(tagName, muiObject(), &value);
        return value;
    }

    long Root::GetValueAsLong(const unsigned long tagName) const
    {
        long value;
        GetAttr(tagName, muiObject(), (unsigned long *)&value);
        return value;
    }

    bool Root::GetValueAsBool(const unsigned long tagName) const
    {
        unsigned long value;
        GetAttr(tagName, muiObject(), &value);
        return (value == TRUE);
    }

    void *Root::GetValueAsPtr(const unsigned long tagName) const
    {
        void *value;
        GetAttr(tagName, muiObject(), (unsigned long *)&value);
        return value;
    }

    Object *Root::GetValueAsObjectPtr(const unsigned long tagName) const
    {
        return (Object *)GetValueAsPtr(tagName);
    }

    void Root::SetValue(const unsigned long tagName, const std::nullptr_t &null) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)null, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const std::string &string) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)string.c_str(), TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const unsigned long ulong) const
    {
        SetAttrs(muiObject(), tagName, ulong, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const signed long slong) const
    {
        SetAttrs(muiObject(), tagName, slong, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const bool boolean) const
    {
        SetAttrs(muiObject(), tagName, boolean, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const void *pointer) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)pointer, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const Object *pObject) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)pObject, TAG_END);
    }
}
