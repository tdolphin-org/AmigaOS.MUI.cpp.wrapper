//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Root.hpp"

#include <proto/intuition.h>
#include <proto/muimaster.h>

#ifdef TRACE_MUI
#include <cstdio>
#endif

#include <stdexcept>

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
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif
    }

    Root::Root(Object *pMuiObject)
      : mpMuiObject { pMuiObject }
    {
        if (pMuiObject == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " mui object is nullptr!";
            throw std::invalid_argument(error);
        }
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

    char *Root::GetValueAsCharPtr(const unsigned long tagName) const
    {
        return static_cast<char *>(GetValueAsPtr(tagName));
    }

    const char *Root::GetValueAsConstCharPtr(const unsigned long tagName) const
    {
        return static_cast<const char *>(GetValueAsPtr(tagName));
    }

    char **Root::GetValueAsCharArrayPtr(const unsigned long tagName) const
    {
        return static_cast<char **>(GetValueAsPtr(tagName));
    }

    const char **Root::GetValueAsConstCharArrayPtr(const unsigned long tagName) const
    {
        return static_cast<const char **>(GetValueAsPtr(tagName));
    }

    unsigned long *Root::GetValueAsULongPtr(const unsigned long tagName) const
    {
        return static_cast<unsigned long *>(GetValueAsPtr(tagName));
    }

    Object *Root::GetValueAsObjectPtr(const unsigned long tagName) const
    {
        return static_cast<Object *>(GetValueAsPtr(tagName));
    }

    ::Hook *Root::GetValueAsHookPtr(const unsigned long tagName) const
    {
        return static_cast<::Hook *>(GetValueAsPtr(tagName));
    }

    ::MsgPort *Root::GetValueAsMsgPortPtr(const unsigned long tagName) const
    {
        return static_cast<::MsgPort *>(GetValueAsPtr(tagName));
    }

    const ::DiskObject *Root::GetValueAsDiskObjectPtr(const unsigned long tagName) const
    {
        return static_cast<const ::DiskObject *>(GetValueAsPtr(tagName));
    }

    const ::MUI_Command *Root::GetValueAsCommandPtr(const unsigned long tagName) const
    {
        return static_cast<const ::MUI_Command *>(GetValueAsPtr(tagName));
    }

    const ::NewMenu *Root::GetValueAsNewMenuPtr(const unsigned long tagName) const
    {
        return static_cast<const ::NewMenu *>(GetValueAsPtr(tagName));
    }

    ::RexxMsg *Root::GetValueAsRexxMsgPtr(const unsigned long tagName) const
    {
        return static_cast<::RexxMsg *>(GetValueAsPtr(tagName));
    }

    ::AppMessage *Root::GetValueAsAppMessagePtr(const unsigned long tagName) const
    {
        return static_cast<::AppMessage *>(GetValueAsPtr(tagName));
    }

    ::TextFont *Root::GetValueAsTextFontPtr(const unsigned long tagName) const
    {
        return static_cast<::TextFont *>(GetValueAsPtr(tagName));
    }

    const ::DrawInfo *Root::GetValueAsDrawInfoPtr(const unsigned long tagName) const
    {
        return static_cast<const ::DrawInfo *>(GetValueAsPtr(tagName));
    }

    ::InputEvent *Root::GetValueAsInputEventPtr(const unsigned long tagName) const
    {
        return static_cast<::InputEvent *>(GetValueAsPtr(tagName));
    }

    ::Screen *Root::GetValueAsScreenPtr(const unsigned long tagName) const
    {
        return static_cast<::Screen *>(GetValueAsPtr(tagName));
    }

    ::Window *Root::GetValueAsWindowPtr(const unsigned long tagName) const
    {
        return static_cast<::Window *>(GetValueAsPtr(tagName));
    }

    ::Gadget *Root::GetValueAsGadgetPtr(const unsigned long tagName) const
    {
        return static_cast<::Gadget *>(GetValueAsPtr(tagName));
    }

    ::MUI_Palette_Entry *Root::GetValueAsPaletteEntryPtr(const unsigned long tagName) const
    {
        return static_cast<::MUI_Palette_Entry *>(GetValueAsPtr(tagName));
    }

    ::MUI_PenSpec *Root::GetValueAsPenSpecPtr(const unsigned long tagName) const
    {
        return static_cast<::MUI_PenSpec *>(GetValueAsPtr(tagName));
    }

    const ::MUI_PenSpec *Root::GetValueAsConstPenSpecPtr(const unsigned long tagName) const
    {
        return static_cast<const ::MUI_PenSpec *>(GetValueAsPtr(tagName));
    }

    ::List *Root::GetValueAsListPtr(const unsigned long tagName) const
    {
        return static_cast<::List *>(GetValueAsPtr(tagName));
    }

    const ::List *Root::GetValueAsConstListPtr(const unsigned long tagName) const
    {
        return static_cast<const ::List *>(GetValueAsPtr(tagName));
    }

    ::MinList *Root::GetValueAsMinListPtr(const unsigned long tagName) const
    {
        return static_cast<::MinList *>(GetValueAsPtr(tagName));
    }

    const ::MinList *Root::GetValueAsConstMinListPtr(const unsigned long tagName) const
    {
        return static_cast<const ::MinList *>(GetValueAsPtr(tagName));
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
        if (array == nullptr)
        {
            ClearStoredString(tagName);
            SetAttrs(muiObject(), tagName, (unsigned long)nullptr, TAG_END);
            return;
        }

        auto copy = StoreStringArray(tagName, array);
        SetAttrs(muiObject(), tagName, (unsigned long)copy, TAG_END);
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
