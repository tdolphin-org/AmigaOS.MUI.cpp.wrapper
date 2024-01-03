//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/String.hpp"

namespace MUI
{
    enum class StringActivePage;

    class DestStringNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestStringNotifier() = delete;
        DestStringNotifier(const NotifierObject &notifierObject, const String &string);
    };
}
