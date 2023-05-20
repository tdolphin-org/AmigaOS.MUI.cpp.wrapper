//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NotifierFactory.hpp"

namespace MUI
{
    AreaNotifier NotifierFactory::notify(const Area &area)
    {
        return AreaNotifier(area);
    }

    CycleNotifier NotifierFactory::notify(const Cycle &cycle)
    {
        return CycleNotifier(cycle);
    }

    GroupNotifier NotifierFactory::notify(const Group &group)
    {
        return GroupNotifier(group);
    }

    ListNotifier NotifierFactory::notify(const List &list)
    {
        return ListNotifier(list);
    }

    NotifyNotifier NotifierFactory::notify(const Notify &notify)
    {
        return NotifyNotifier(notify);
    }

    WindowNotifier NotifierFactory::notify(const Window &window)
    {
        return WindowNotifier(window);
    }

}
