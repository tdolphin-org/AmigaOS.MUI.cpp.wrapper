//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "SourceNotifier.hpp"

namespace MUI
{
    class DestNotifierRoot
    {
      protected:
        SourceNotifier mSourceNotifier;
        Root mObject;

      protected:
        DestNotifierRoot(const SourceNotifier &sourceNotifier, const Root &root);

        Object *muiSourceObject()
        {
            return mSourceNotifier.mObject.muiObject();
        }

        unsigned long getAttribute()
        {
            return mSourceNotifier.mAttribute;
        }

        unsigned long getTrigValue()
        {
            return mSourceNotifier.mTrigValue;
        }
    };
}
