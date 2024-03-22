//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Root.hpp"

#include <stdexcept>

#include <proto/intuition.h>
#include <proto/muimaster.h>

namespace MUI
{
    bool instanceOf(Object *object, const char *className)
    {
        struct IClass *objClass = MUI_GetClass((char *)className);
        struct IClass *clazz;
        for (clazz = OCLASS(object); clazz; clazz = clazz->cl_Super)
            if (clazz == objClass)
                return true;
        return false;
    }

    Root::Root()
      : mpMuiObject(nullptr)
    {
    }

    Root::Root(const Object *pMuiObject)
    {
        if (pMuiObject == nullptr)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + " mui object is nullptr!";
            throw std::invalid_argument(error);
        }

        mpMuiObject = (Object *)pMuiObject;
    }

    Root::Root(const APTR pMuiObject)
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
        return (value == nullptr) ? std::string() : std::string(value); // TODO should be exception on null ??
    }

    char Root::GetValueAsChar(const unsigned long tagName) const
    {
        long value;
        GetAttr(tagName, muiObject(), (unsigned long *)&value);
        return (char)value;
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

    char **Root::GetValueAsCharArrayPtr(const unsigned long tagName) const
    {
        return (char **)GetValueAsPtr(tagName);
    }

    Object *Root::GetValueAsObjectPtr(const unsigned long tagName) const
    {
        return (Object *)GetValueAsPtr(tagName);
    }

    Hook *Root::GetValueAsHookPtr(const unsigned long tagName) const
    {
        return (Hook *)GetValueAsPtr(tagName);
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

    void Root::SetValue(const unsigned long tagName, const char *array[]) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)array, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const Object *pObject) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)pObject, TAG_END);
    }

    void Root::SetValue(const unsigned long tagName, const Hook *pHook) const
    {
        SetAttrs(muiObject(), tagName, (unsigned long)pHook, TAG_END);
    }
}
