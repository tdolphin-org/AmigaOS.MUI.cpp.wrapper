//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"
#include "MUI/Family.hpp"

namespace MUI
{
    class DestFamilyNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestFamilyNotifier() = delete;
        DestFamilyNotifier(const NotifierObject &notifierObject, const Family &family);
    };
}
