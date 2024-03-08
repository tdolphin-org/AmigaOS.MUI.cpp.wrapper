//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "Content.hpp"

namespace Components
{
    Content::Content()
      : mListAndImageTab()
      , mCustomClassesTab()
      , mComponent({ { std::string(MUIX_PH "List & Image"), mListAndImageTab }, { "NList", mCustomClassesTab } })
    {
    }
}
