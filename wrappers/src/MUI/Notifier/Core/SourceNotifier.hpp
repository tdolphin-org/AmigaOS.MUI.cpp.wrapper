//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AOS/ValueObject.hpp"
#include "MUI/Core/Root.hpp"
#include "NotifierObject.hpp"
#include "NotifyDestType.hpp"

#include "../Dest/DestApplicationNotifier.hpp"
#include "../Dest/DestAreaNotifier.hpp"
#include "../Dest/DestCycleNotifier.hpp"
#include "../Dest/DestFamilyNotifier.hpp"
#include "../Dest/DestGadgetNotifier.hpp"
#include "../Dest/DestGroupNotifier.hpp"
#include "../Dest/DestListNotifier.hpp"
#include "../Dest/DestMenuitemNotifier.hpp"
#include "../Dest/DestNotifyNotifier.hpp"
#include "../Dest/DestPendisplayNotifier.hpp"
#include "../Dest/DestPropNotifier.hpp"
#include "../Dest/DestRegisterNotifier.hpp"
#include "../Dest/DestStringNotifier.hpp"
#include "../Dest/DestWindowNotifier.hpp"

namespace MUI
{
    class SourceNotifierRoot : public NotifierObject
    {
      protected:
        SourceNotifierRoot() = delete;
        SourceNotifierRoot(const Root &root, const unsigned long attribute, const AOS::ValueObject &triggerValue);

      public:
        DestApplicationNotifier notifyObject(const Application &application);
        DestAreaNotifier notifyObject(const Area &area);
        DestCycleNotifier notifyObject(const Cycle &cycle);
        DestFamilyNotifier notifyObject(const Family &family);
        DestGadgetNotifier notifyObject(const Gadget &gadget);
        DestGroupNotifier notifyObject(const Group &group);
        DestListNotifier notifyObject(const List &list);
        DestMenuitemNotifier notifyObject(const Menuitem &menuitem);
        DestNotifyNotifier notifyObject(const Notify &notify);
        DestPendisplayNotifier notifyObject(const Pendisplay &pendisplay);
        DestPropNotifier notifyObject(const Prop &prop);
        DestRegisterNotifier notifyObject(const Register &registerObject);
        DestStringNotifier notifyObject(const String &string);
        DestWindowNotifier notifyObject(const Window &window);

        DestApplicationNotifier notifyApplication();
        DestWindowNotifier notifyWindow();
    };

    /// @brief
    /// @tparam T object class, source of notification
    /// @tparam U dest notifier to notify self
    template <typename T, typename U> class SourceNotifier : public SourceNotifierRoot
    {
        T mObject;

      public:
        SourceNotifier(const T &object, const unsigned long attribute, const AOS::ValueObject &triggerValue);
        U notifySelf();
    };

    template <typename T, typename U>
    inline SourceNotifier<T, U>::SourceNotifier(const T &object, const unsigned long attribute, const AOS::ValueObject &triggerValue)
      : SourceNotifierRoot(object, attribute, triggerValue)
      , mObject(object)
    {
    }

    /// @tparam T mui source class
    /// @tparam U dest notifier class
    template <typename T, typename U> inline U SourceNotifier<T, U>::notifySelf()
    {
        return U(*this, NotifyDestType::Self);
    }
}
