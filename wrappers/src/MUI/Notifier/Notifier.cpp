//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Notifier.hpp"

namespace MUI
{
    AreaNotifier<> Notifier::from(const Area &area)
    {
        return AreaNotifier<>(area);
    }

    CycleNotifier<> Notifier::from(const Cycle &cycle)
    {
        return CycleNotifier<>(cycle);
    }

    FamilyNotifier<> Notifier::from(const Family &family)
    {
        return FamilyNotifier<>(family);
    }

    GadgetNotifier<> Notifier::from(const Gadget &gadget)
    {
        return GadgetNotifier<>(gadget);
    }

    GroupNotifier<> Notifier::from(const Group &group)
    {
        return GroupNotifier<>(group);
    }

    ListNotifier<> Notifier::from(const List &list)
    {
        return ListNotifier<>(list);
    }

    MenuitemNotifier<> Notifier::from(const Menuitem &menuitem)
    {
        return MenuitemNotifier<>(menuitem);
    }

    NotifyNotifier<> Notifier::from(const Notify &notify)
    {
        return NotifyNotifier<>(notify);
    }

    PropNotifier<> Notifier::from(const Prop &prop)
    {
        return PropNotifier<>(prop);
    }

    StringNotifier<> Notifier::from(const String &string)
    {
        return StringNotifier<>(string);
    }

    WindowNotifier<> Notifier::from(const Window &window)
    {
        return WindowNotifier<>(window);
    }

}
