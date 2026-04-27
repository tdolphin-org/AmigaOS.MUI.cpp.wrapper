//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/StringStorage.hpp"

#include <intuition/classusr.h>

// declaration for AmigaOS
typedef ULONG Boopsiobject;

struct MsgPort;
struct DiskObject;
struct NewMenu;
struct RexxMsg;
struct MUI_Command;
struct List;
struct MinList;
struct AppMessage;
struct TextFont;
struct MUI_PenSpec;
struct Window;
struct Gadget;

namespace MUI
{
    bool instanceOf(Object *object, const char *className);

    class Root
    {
        friend class NullObject;

        Object *const mpMuiObject;

        /// @brief can be used only for NullObject
        Root();

      public:
        explicit Root(Object *pMuiObject);

        Root(const Root &other) = default;
        Root(Root &&other) = default;

        ~Root() = default; // no action on pointer 'pMuiObject', object is deleted by MUI itself

        Root &operator=(const Root &other) = delete;
        Root &operator=(Root &&other) = delete;

        operator Object *() const
        {
            return muiObject();
        }

        Object *muiObject() const
        {
            return mpMuiObject;
        }

        bool isNull() const
        {
            return mpMuiObject == nullptr;
        }

        // methods

        const char *StoreString(const unsigned long tagName, const std::string &string) const
        {
            return StringStorage::instance().Change(mpMuiObject, tagName, string);
        }

        const char *StoreString(const unsigned long tagName, const char *string) const
        {
            return StringStorage::instance().Change(mpMuiObject, tagName, string);
        }

        const char **StoreStringArray(const unsigned long tagName, const std::vector<std::string> &strings) const
        {
            return StringStorage::instance().Change(mpMuiObject, tagName, strings);
        }

        const char **StoreStringArray(const unsigned long tagName, const char *strings[]) const
        {
            return StringStorage::instance().Change(mpMuiObject, tagName, strings);
        }

        void ClearStoredString(const unsigned long tagName) const
        {
            StringStorage::instance().Remove(mpMuiObject, tagName);
        }

        std::string GetValueAsString(const unsigned long tagName) const;
        char GetValueAsChar(const unsigned long tagName) const;
        unsigned long GetValueAsULong(const unsigned long tagName) const;
        long GetValueAsLong(const unsigned long tagName) const;
        bool GetValueAsBool(const unsigned long tagName) const;
        void *GetValueAsPtr(const unsigned long tagName) const;
        char *GetValueAsCharPtr(const unsigned long tagName) const;
        const char *GetValueAsConstCharPtr(const unsigned long tagName) const;
        char **GetValueAsCharArrayPtr(const unsigned long tagName) const;
        const char **GetValueAsConstCharArrayPtr(const unsigned long tagName) const;
        unsigned long *GetValueAsULongPtr(const unsigned long tagName) const;
        Object *GetValueAsObjectPtr(const unsigned long tagName) const;
        Hook *GetValueAsHookPtr(const unsigned long tagName) const;
        MsgPort *GetValueAsMsgPortPtr(const unsigned long tagName) const;
        const DiskObject *GetValueAsDiskObjectPtr(const unsigned long tagName) const;
        const struct MUI_Command *GetValueAsCommandPtr(const unsigned long tagName) const;
        const ::NewMenu *GetValueAsNewMenuPtr(const unsigned long tagName) const;
        RexxMsg *GetValueAsRexxMsgPtr(const unsigned long tagName) const;
        AppMessage *GetValueAsAppMessagePtr(const unsigned long tagName) const;
        TextFont *GetValueAsTextFontPtr(const unsigned long tagName) const;
        ::Window *GetValueAsWindowPtr(const unsigned long tagName) const;
        ::Gadget *GetValueAsGadgetPtr(const unsigned long tagName) const;
        struct MUI_PenSpec *GetValueAsPenSpecPtr(const unsigned long tagName) const;
        const struct MUI_PenSpec *GetValueAsConstPenSpecPtr(const unsigned long tagName) const;
        struct List *GetValueAsListPtr(const unsigned long tagName) const;
        const struct List *GetValueAsConstListPtr(const unsigned long tagName) const;
        struct MinList *GetValueAsMinListPtr(const unsigned long tagName) const;
        const struct MinList *GetValueAsConstMinListPtr(const unsigned long tagName) const;

        void SetValue(const unsigned long tagName, const std::nullptr_t &null) const;
        void SetValue(const unsigned long tagName, const std::string &string) const;
        void SetValue(const unsigned long tagName, const unsigned long ulong) const;
        void SetValue(const unsigned long tagName, const signed long slong) const;
        void SetValue(const unsigned long tagName, const bool boolean) const;
        void SetValue(const unsigned long tagName, const void *pointer) const;
        void SetValue(const unsigned long tagName, const char *array[]) const;
        void SetValue(const unsigned long tagName, const Object *pObject) const;
        void SetValue(const unsigned long tagName, const Hook *pHook) const;
    };
}
