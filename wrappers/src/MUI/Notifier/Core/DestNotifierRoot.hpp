//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "NotifierObject.hpp"

namespace MUI
{
    class DestNotifierRoot
    {
      protected:
        NotifierObject mNotifierObject;
        Root mObject;

      protected:
        DestNotifierRoot() = delete;

        DestNotifierRoot(const NotifierObject &notifierObject, const Root &root);

        Object *muiSourceObject()
        {
            return mNotifierObject.getObject().muiObject();
        }

        unsigned long getAttribute()
        {
            return mNotifierObject.getAttribute();
        }

        unsigned long getTriggerValue()
        {
            return mNotifierObject.getTriggerValue().value();
        }
    };
}
