//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AOS/ValueObject.hpp"
#include "MUI/Core/Root.hpp"
#include "NotifierObject.hpp"

#include "../Dest/DestApplicationNotifier.hpp"
#include "../Dest/DestAreaNotifier.hpp"
#include "../Dest/DestCycleNotifier.hpp"
#include "../Dest/DestGroupNotifier.hpp"
#include "../Dest/DestListNotifier.hpp"
#include "../Dest/DestNotifyNotifier.hpp"
#include "../Dest/DestWindowNotifier.hpp"

namespace MUI
{
    class SourceNotifierRoot : public NotifierObject
    {
      protected:
        SourceNotifierRoot() = delete;
        SourceNotifierRoot(const Root &root, const unsigned long attribute, const AOS::ValueObject &triggerValue);

      public:
        DestApplicationNotifier destObject(const Application &application);
        DestAreaNotifier destObject(const Area &area);
        DestCycleNotifier destObject(const Cycle &cycle);
        DestGroupNotifier destObject(const Group &group);
        DestListNotifier destObject(const List &list);
        DestNotifyNotifier destObject(const Notify &notify);
        DestWindowNotifier destObject(const Window &window);
    };

    template <typename T, typename U> class SourceNotifier : public SourceNotifierRoot
    {
        T mObject;

      public:
        SourceNotifier(const T &object, const unsigned long attribute, const AOS::ValueObject &triggerValue);
        U notifySelf();
    };

    template <typename T, typename U>
    inline SourceNotifier<T, U>::SourceNotifier(const T &object, const unsigned long attribute, const AOS::ValueObject &triggerValue)
      : mObject(object)
      , SourceNotifierRoot(object, attribute, triggerValue)
    {
    }

    /// @tparam T mui class
    /// @tparam U dest notifier class
    template <typename T, typename U> inline U SourceNotifier<T, U>::notifySelf()
    {
        return U(*this, mObject);
    }
}
