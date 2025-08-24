//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "Content.hpp"

#include "MUI/Balance.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    Content::Content()
      : mRegisterInfoGroup(MUI::GroupBuilder()
                               .vertical()
                               .tagChild(MUI::MakeObject::HVSpace())
                               .tagChild(MUI::GroupBuilder()
                                             .horizontal()
                                             .tagChild(MUI::MakeObject::Checkmark("_C"))
                                             .tagChild(MUI::MakeObject::LLabel("_Checkmark"))
                                             .tagChild(MUI::MakeObject::HSpace(0))
                                             .object())
                               .tagChild(MUI::TextBuilder()
                                             .tagFrame(MUI::Frame::String)
                                             .tagSetMin(false)
#ifdef MUIA_Text_Shorten_ElideRight
                                             .tagShorten(MUI::Text_Shorten::ElideRight)
#endif
                                             .tagContents("tabs created with MUI::Register (MUIC_Register)")
                                             .object())
                               .tagChild(MUI::MakeObject::HVSpace())
                               .object())
      , mListAndImageTab()
      , mLeftTabsRegister({ { MUIX_PH "Info", mRegisterInfoGroup }, { "List & Image", mListAndImageTab } })
      , mTitleInfoGroup(MUI::GroupBuilder()
                            .vertical()
                            .tagChild(MUI::MakeObject::HVSpace())
                            .tagChild(MUI::TextBuilder()
                                          .tagFrame(MUI::Frame::String)
                                          .tagSetMin(false)
#ifdef MUIA_Text_Shorten_ElideRight
                                          .tagShorten(MUI::Text_Shorten::ElideRight)
#endif
                                          .tagContents("tabs created with MUI::Title (MUIC_Title)")
                                          .object())
                            .tagChild(MUI::MakeObject::HVSpace())
                            .object())
      , mCustomClassesTab()
      , mRightTabsTitles({ { MUIX_PH "Info", mTitleInfoGroup }, { "NList", mCustomClassesTab } })
      , mComponent(MUI::GroupBuilder()
                       .horizontal()
                       .tagChild(mLeftTabsRegister)
                       .tagChild(MUI::BalanceBuilder().object())
                       .tagChild(mRightTabsTitles)
                       .object())
    {
    }
}
