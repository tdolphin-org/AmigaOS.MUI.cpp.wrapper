
//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Family.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    class FamilyNotifier : public NotifyNotifier
    {
        Family mFamily;

      public:
        FamilyNotifier() = delete;
        FamilyNotifier(const Family &family);

        // notification methods
    };
}
