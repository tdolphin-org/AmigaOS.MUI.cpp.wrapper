//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestNotifierRoot.hpp"

#include "MUI/Core/NullObject.hpp"
#include "NotifyDestType.hpp"

#include <iostream>

namespace MUI
{
    DestNotifierRoot::DestNotifierRoot(const NotifierObject &notifierObject, const Root &root)
      : mNotifierObject(notifierObject)
      , notifyDestType(NotifyDestType::GivenObject)
      , mObject(root)
    {
    }

    DestNotifierRoot::DestNotifierRoot(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : mNotifierObject(notifierObject)
      , notifyDestType(notifyDestType)
      , mObject(MUI::NullObject {})
    {
    }

    void *DestNotifierRoot::muiDestObject() const
    {
        switch (notifyDestType)
        {
            case NotifyDestType::GivenObject:
                return mObject.muiObject();

            case NotifyDestType::Self:
            case NotifyDestType::Window:
            case NotifyDestType::Application:
                return (void *)notifyDestType;

            default:
                std::cerr << __PRETTY_FUNCTION__ << "destination object type: " << notifyDestType << " is not supported" << std::endl;
                return nullptr;
        }
    }
}
