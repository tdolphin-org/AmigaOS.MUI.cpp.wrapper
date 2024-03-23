//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "Content.hpp"

#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    Content::Content()
      : mRegisterInfoGroup(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::MakeObject::HVSpace())
                .tagChild(MUI::TextBuilder().tagContents("tabs created with MUI::Register (MUIC_Register)").object())
                .tagChild(MUI::MakeObject::HVSpace())
                .object())
      , mListAndImageTab()
      , mLeftTabsRegister({ { MUIX_PH "Info", mRegisterInfoGroup }, { "List & Image", mListAndImageTab } })
      , mTitleInfoGroup(
            MUI::GroupBuilder()
                .vertical()
                .tagChild(MUI::MakeObject::HVSpace())
                .tagChild(MUI::TextBuilder().tagContents("tabs created with MUI::Title (MUIC_Title)").object())
                .tagChild(MUI::MakeObject::HVSpace())
                .object())
      , mCustomClassesTab()
      , mRightTabsTitles({ { MUIX_PH "Info", mTitleInfoGroup }, { "NList", mCustomClassesTab } })
      , mComponent(MUI::GroupBuilder().horizontal().tagChild(mLeftTabsRegister).tagChild(mRightTabsTitles).object())
    {
    }
}
