//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestFamilyNotifier.hpp"
#include "MUI/Menuitem.hpp"

namespace MUI
{
    enum class MenuitemActivePage;

    class DestMenuitemNotifier : public DestFamilyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestMenuitemNotifier() = delete;
        DestMenuitemNotifier(const NotifierObject &notifierObject, const Menuitem &menuitem);
    };
}
