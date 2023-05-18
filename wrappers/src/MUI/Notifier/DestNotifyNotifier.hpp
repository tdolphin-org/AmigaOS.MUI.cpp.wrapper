//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Core/DestNotifierRoot.hpp"
#include "MUI/Notify.hpp"

namespace MUI
{
    class DestNotifyNotifier : public DestNotifierRoot
    {
        friend class SourceNotifier;

      protected:
        DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify);
    };
}
