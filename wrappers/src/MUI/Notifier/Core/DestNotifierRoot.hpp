//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "NotifierObject.hpp"

#include <libraries/mui.h>

namespace MUI
{
    enum class NotifyDestType;

    class DestNotifierRoot
    {
        NotifierObject mNotifierObject;
        enum NotifyDestType notifyDestType;
        Root mObject;

      protected:
        DestNotifierRoot() = delete;

        DestNotifierRoot(const NotifierObject &notifierObject, const Root &root);
        DestNotifierRoot(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType);

        void *muiDestObject() const;

        Object *muiSourceObject() const
        {
            return mNotifierObject.getObject().muiObject();
        }

        unsigned long getAttribute() const
        {
            return mNotifierObject.getAttribute();
        }

        unsigned long getTriggerValue() const
        {
            return mNotifierObject.getTriggerValue().value();
        }
    };
}
