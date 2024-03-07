//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "CustomClassesTab.hpp"

const char *items[] = { "AmigaOS", "MorphOS", "AROS", nullptr };
const char *itemsWrapped[] = { "AmigaOS 3.1", "MorphOS 3.18", "AROS 2k23", nullptr };
const char *itemLong = "AmigaOS MUI C++ wrapper .. Advanced Example .. (c) 2022-2024 TDolphin";

namespace Components
{
    CustomClassesTab::CustomClassesTab()
      : mItemsNList(MUI::MCC::NListBuilder()
                        .tagObjectID("NLST")
                        .tagDefaultObjectOnClick(true)
                        .tagFormat("WEIGHT=200 BAR, MINPIXWIDTH=4 COLWIDTH=4 BAR, MINPIXWIDTH=4 COLWIDTH=4 BAR")
                        .tagMultiSelect(MUI::MCC::NList_MultiSelect::None)
                        .tagSourceArray(items)
                        .tagAutoVisible(true)
                        .tagEntryValueDependent(true)
                        .tagTitle(true)
                        .tagTitleSeparator(true)
                        .tagFont(MUI::Font::Fixed)
                        .tagConstructHookString()
                        .tagDestructHookString()
                        .tagFrame(MUI::Frame::ReadList)
                        .object())
      , mItemsNListview(MUI::MCC::NListviewBuilder()
                            .tagHoriz_ScrollBar(MUI::MCC::NListview_HSB::Always)
                            .tagVert_ScrollBar(MUI::MCC::NListview_VSB::Always)
                            .tagNList(mItemsNList)
                            .object())
      , mComponent(MUI::GroupBuilder().tagChild(mItemsNListview).object())
    {
        mItemsNList.InsertWrapBottom((const void **)itemsWrapped, MUI::MCC::NList_WrapCol::WrapColumn0, MUI::MCC::NList_Align::Left);
        mItemsNList.InsertSingleWrapBottom(itemLong, MUI::MCC::NList_WrapCol::WrapColumn0, MUI::MCC::NList_Align::Left);
    }
}
