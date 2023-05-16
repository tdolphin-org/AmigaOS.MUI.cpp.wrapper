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
    class Application;
    class Area;
    class Cycle;
    class Group;
    class List;
    class Notify;
    class Window;

    class DestNotifierRoot;
    class DestNotifyNotifier;
    class DestApplicationNotifier;
    class DestAreaNotifier;
    class DestGroupNotifier;

    class SourceNotifier
    {
        friend class DestNotifierRoot;
        friend class Application;
        friend class Area;
        friend class Cycle;
        friend class Group;
        friend class List;
        friend class Notify;
        friend class Window;

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
        DestApplicationNotifier destObject(const Application &application);
        DestAreaNotifier destObject(const Area &area);
        DestGroupNotifier destObject(const Group &group);
    };
}
