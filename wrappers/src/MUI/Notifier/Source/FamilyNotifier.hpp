
//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "MUI/Family.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    template <typename T = Family, typename U = DestFamilyNotifier> class FamilyNotifier : public NotifyNotifier<T, U>
    {
      public:
        FamilyNotifier() = delete;
        FamilyNotifier(const T &family)
          : NotifyNotifier<T, U>(family)
        {
        }

        // notification methods
    };
}
