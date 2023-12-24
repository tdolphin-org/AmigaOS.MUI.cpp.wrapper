
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
    template <typename T = DestFamilyNotifier> class FamilyNotifier : public NotifyNotifier<T>
    {
        Family mFamily;

      public:
        FamilyNotifier() = delete;
        FamilyNotifier(const Family &family)
          : NotifyNotifier<T>(family)
          , mFamily(family)
        {
        }

        // notification methods
    };
}
