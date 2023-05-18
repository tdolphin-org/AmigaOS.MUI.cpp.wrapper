//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NotifierObject.hpp"

namespace MUI
{
    NotifierObject::NotifierObject(const Root &root, const unsigned long attribute, const AOS::ValueObject &triggerValue)
      : mObject(root)
      , mAttribute(attribute)
      , mTriggerValue(triggerValue)
    {
    }
}
