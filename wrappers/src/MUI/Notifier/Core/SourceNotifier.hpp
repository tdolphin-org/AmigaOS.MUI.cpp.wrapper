//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

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
        unsigned long mTrigValue;

        SourceNotifier(const Root &root, unsigned long attribute, unsigned long trigValue);

      public:
        DestNotifyNotifier destObject(const Notify &notify);
        DestAreaNotifier destObject(const Area &area);
        DestGroupNotifier destObject(const Group &group);
    };
}
