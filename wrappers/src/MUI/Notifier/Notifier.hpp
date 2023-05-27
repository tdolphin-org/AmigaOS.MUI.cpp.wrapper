//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Source/AreaNotifier.hpp"
#include "Source/CycleNotifier.hpp"
#include "Source/FamilyNotifier.hpp"
#include "Source/GroupNotifier.hpp"
#include "Source/ListNotifier.hpp"
#include "Source/MenuitemNotifier.hpp"
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
        static FamilyNotifier from(const Family &family);
        static GroupNotifier from(const Group &group);
        static ListNotifier from(const List &list);
        static MenuitemNotifier from(const Menuitem &menuitem);
        static NotifyNotifier from(const Notify &notify);
        static StringNotifier from(const String &string);
        static WindowNotifier from(const Window &window);
    };
}
