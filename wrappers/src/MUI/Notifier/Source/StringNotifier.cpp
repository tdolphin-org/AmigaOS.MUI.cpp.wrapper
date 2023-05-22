//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "StringNotifier.hpp"

namespace MUI
{
    StringNotifier::StringNotifier(const String &string)
      : mString(string)
      , AreaNotifier(string)
    {
    }

    SourceNotifier<String, DestStringNotifier> StringNotifier::onContentsEveryTime()
    {
        return SourceNotifier<String, DestStringNotifier>(mString, MUIA_String_Contents, (long)MUIV_EveryTime);
    }
}
