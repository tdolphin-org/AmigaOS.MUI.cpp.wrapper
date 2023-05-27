
//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "FamilyNotifier.hpp"

namespace MUI
{
    FamilyNotifier::FamilyNotifier(const Family &family)
      : NotifyNotifier(family)
      , mFamily(family)
    {
    }
}
