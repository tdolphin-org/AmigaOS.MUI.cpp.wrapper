//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AOS/ValueObject.hpp"
#include "MUI/Core/Root.hpp"

namespace MUI
{
    class Notify;
    class Area;
    class Group;

    class DestNotifierRoot;
    class DestNotifyNotifier;
    class DestAreaNotifier;
    class DestGroupNotifier;

    class SourceNotifier
    {
        friend class DestNotifierRoot;
        friend class Notify;
        friend class Area;
        friend class Group;

        Root mObject;
        unsigned long mAttribute;
        AOS::ValueObject mTrigValue;

        SourceNotifier(const Root &root, const unsigned long attribute, const void *trigValue);
        SourceNotifier(const Root &root, const unsigned long attribute, const unsigned long trigValue);
        SourceNotifier(const Root &root, const unsigned long attribute, const long trigValue);
        SourceNotifier(const Root &root, const unsigned long attribute, const void **trigValue);
        SourceNotifier(const Root &root, const unsigned long attribute, const bool trigValue);

      public:
        DestNotifyNotifier destObject(const Notify &notify);
        DestAreaNotifier destObject(const Area &area);
        DestGroupNotifier destObject(const Group &group);
    };
}
