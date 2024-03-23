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
      : mRegisterInfo(MUI::TextBuilder().tagContents("tabs created with MUI::Register (MUIC_Register)").object())
      , mListAndImageTab()
      , mLeftTabsRegister({ { MUIX_PH "Info", mRegisterInfo }, { "List & Image", mListAndImageTab } })
      , mTitleInfo(MUI::TextBuilder().tagContents("tabs created with MUI::Title (MUIC_Title)").object())
      , mCustomClassesTab()
      , mRightTabsTitles({ { MUIX_PH "Info", mTitleInfo }, { "NList", mCustomClassesTab } })
      , mComponent(MUI::GroupBuilder().horizontal().tagChild(mLeftTabsRegister).tagChild(mRightTabsTitles).object())
    {
    }
}
