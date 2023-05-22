//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Source/AreaNotifier.hpp"
#include "Source/CycleNotifier.hpp"
#include "Source/GroupNotifier.hpp"
#include "Source/ListNotifier.hpp"
#include "Source/NotifyNotifier.hpp"
#include "Source/StringNotifier.hpp"
#include "Source/WindowNotifier.hpp"

namespace MUI
{
    /// @brief source notifiers factory
    class Notifier
    {
      public:
        static AreaNotifier from(const Area &area);
        static CycleNotifier from(const Cycle &cycle);
        static GroupNotifier from(const Group &group);
        static ListNotifier from(const List &list);
        static NotifyNotifier from(const Notify &from);
        static StringNotifier from(const String &string);
        static WindowNotifier from(const Window &window);
    };
}
