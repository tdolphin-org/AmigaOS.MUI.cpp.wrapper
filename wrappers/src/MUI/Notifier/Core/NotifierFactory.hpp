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
    class NotifierFactory
    {
      public:
        static AreaNotifier notify(const Area &area);
        static CycleNotifier notify(const Cycle &cycle);
        static GroupNotifier notify(const Group &group);
        static ListNotifier notify(const List &list);
        static NotifyNotifier notify(const Notify &notify);
        static WindowNotifier notify(const Window &window);
    };
}
