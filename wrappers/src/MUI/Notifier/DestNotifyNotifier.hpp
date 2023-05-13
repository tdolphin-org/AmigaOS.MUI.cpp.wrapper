//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Core/DestNotifierRoot.hpp"

namespace MUI
{
    class DestNotifyNotifier : public DestNotifierRoot
    {
        friend class SourceNotifier;

      protected:
        DestNotifyNotifier(const SourceNotifier &sourceNotifier, const Notify &notify);
    };
}
