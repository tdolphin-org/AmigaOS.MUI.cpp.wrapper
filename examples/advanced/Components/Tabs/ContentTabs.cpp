//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "ContentTabs.hpp"

#include "MUI/Text.hpp"
#include "MUI/Title.hpp"

namespace Components
{
    ContentTabs::ContentTabs()
      : mListAndImageTab()
      , mCustomClassesTab()
      , mComponent(
            MUI::GroupBuilder()
                .tagCycleChain()
                .tagChild(
                    MUI::TitleBuilder()
                        .tagChild(MUI::TextBuilder().tagPreParse(MUIX_PH).tagContents("List & Image").tagFrame(MUI::Frame::Text).object())
                        .tagChild(MUI::TextBuilder().tagContents("NList").tagFont(MUI::Font::Normal).object())
                        .object())
                .tagChild(mListAndImageTab)
                .tagChild(mCustomClassesTab)
                .object())
    {
    }
}
