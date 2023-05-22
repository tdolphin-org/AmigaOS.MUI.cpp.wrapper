//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Notifier.hpp"

namespace MUI
{
    AreaNotifier Notifier::from(const Area &area)
    {
        return AreaNotifier(area);
    }

    CycleNotifier Notifier::from(const Cycle &cycle)
    {
        return CycleNotifier(cycle);
    }

    GroupNotifier Notifier::from(const Group &group)
    {
        return GroupNotifier(group);
    }

    ListNotifier Notifier::from(const List &list)
    {
        return ListNotifier(list);
    }

    NotifyNotifier Notifier::from(const Notify &from)
    {
        return NotifyNotifier(from);
    }

    StringNotifier Notifier::from(const String &string)
    {
        return StringNotifier(string);
    }

    WindowNotifier Notifier::from(const Window &window)
    {
        return WindowNotifier(window);
    }

}
