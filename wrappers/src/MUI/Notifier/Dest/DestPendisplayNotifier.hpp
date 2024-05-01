//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/Pendisplay.hpp"

namespace MUI
{
    enum class Pendisplay_ActivePage;

    class DestPendisplayNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestPendisplayNotifier() = delete;
        DestPendisplayNotifier(const NotifierObject &notifierObject, const Pendisplay &pendisplay);
    };
}
