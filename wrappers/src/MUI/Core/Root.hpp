//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <string>

#include <intuition/classusr.h>
#include <libraries/mui.h>
#include <proto/alib.h>

namespace MUI
{
    class Root
    {
        Object *mpMuiObject;

      public:
        Root(const Object *pMuiObject);

        Object *muiObject() const
        {
            return mpMuiObject;
        }

        // methods

        std::string GetValueAsString(const unsigned long tagName) const;
        unsigned long GetValueAsULong(const unsigned long tagName) const;
        long GetValueAsLong(const unsigned long tagName) const;
        bool GetValueAsBool(const unsigned long tagName) const;
        void *GetValueAsPtr(const unsigned long tagName) const;
        Object *GetValueAsObjectPtr(const unsigned long tagName) const;

        void SetValue(const unsigned long tagName, const std::nullptr_t &null) const;
        void SetValue(const unsigned long tagName, const std::string &string) const;
        void SetValue(const unsigned long tagName, const unsigned long ulong) const;
        void SetValue(const unsigned long tagName, const signed long slong) const;
        void SetValue(const unsigned long tagName, const bool boolean) const;
        void SetValue(const unsigned long tagName, const void *pointer) const;
        void SetValue(const unsigned long tagName, const Object *pObject) const;
    };
}