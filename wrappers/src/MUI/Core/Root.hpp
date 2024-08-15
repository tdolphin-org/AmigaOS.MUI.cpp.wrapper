//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/StringStorage.hpp"

#include <intuition/classusr.h>

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

        ~Root() = default; // no action on pointer 'pMuiObject', object is deleted by MUI itself

        Root &operator=(const Root &other) = delete;

        explicit operator Object *() const
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

        const char *StoreString(const unsigned long tagName, const std::string &string)
        {
            return StringStorage::instance().Change(mpMuiObject, tagName, string);
        }

        std::string GetValueAsString(const unsigned long tagName) const;
        char GetValueAsChar(const unsigned long tagName) const;
        unsigned long GetValueAsULong(const unsigned long tagName) const;
        long GetValueAsLong(const unsigned long tagName) const;
        bool GetValueAsBool(const unsigned long tagName) const;
        void *GetValueAsPtr(const unsigned long tagName) const;
        char **GetValueAsCharArrayPtr(const unsigned long tagName) const;
        Object *GetValueAsObjectPtr(const unsigned long tagName) const;
        Hook *GetValueAsHookPtr(const unsigned long tagName) const;

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
