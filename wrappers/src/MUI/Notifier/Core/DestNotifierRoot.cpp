//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestNotifierRoot.hpp"

namespace MUI
{
    DestNotifierRoot::DestNotifierRoot(const SourceNotifier &sourceNotifier, const Root &root)
      : mSourceNotifier(sourceNotifier)
      , mObject(root)
    {
    }
}
