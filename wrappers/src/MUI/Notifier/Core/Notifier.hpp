//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "../AreaNotifier.hpp"
#include "../CycleNotifier.hpp"
#include "../GroupNotifier.hpp"
#include "../ListNotifier.hpp"
#include "../NotifyNotifier.hpp"
#include "../WindowNotifier.hpp"

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
        static WindowNotifier from(const Window &window);
    };
}
