//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "../Core/DestNotifierRoot.hpp"
#include "MUI/Notify.hpp"

namespace MUI
{
    class NotifierObject;

    class DestNotifyNotifier : public DestNotifierRoot
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestNotifyNotifier() = delete;
        DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify);

      public:
        DestNotifyNotifier &method(const unsigned long methodId);
    };
}
