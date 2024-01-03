//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/Gadget.hpp"

namespace MUI
{
    class DestGadgetNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestGadgetNotifier() = delete;
        DestGadgetNotifier(const NotifierObject &notifierObject, const Gadget &gadget);
    };
}
