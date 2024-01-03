//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AOS/ValueObject.hpp"
#include "MUI/Core/Root.hpp"

namespace MUI
{
    class NotifierObject
    {
        Root mObject;
        unsigned long mAttribute;
        AOS::ValueObject mTriggerValue;

      public:
        NotifierObject() = delete;

        NotifierObject(const Root &root, const unsigned long attribute, const AOS::ValueObject &triggerValue);

        Root getObject() const
        {
            return mObject;
        }

        unsigned long getAttribute() const
        {
            return mAttribute;
        }

        AOS::ValueObject getTriggerValue() const
        {
            return mTriggerValue;
        }
    };
}
