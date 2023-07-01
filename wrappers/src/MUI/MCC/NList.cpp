//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NList.hpp"

#include <mui/NList_mcc.h>
#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string NList::className = MUIC_NList;

    NListBuilder::NListBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, NList::className)
    {
    }

    NListBuilder &NListBuilder::tagTypeSelect(const enum MUI::MCC_NList::TypeSelect typeSelect)
    {
        PushTag(MUIA_NList_TypeSelect, (long)typeSelect);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitlePen(const long titlePen)
    {
        PushTag(MUIA_NList_TitlePen, titlePen);
        return *this;
    }

    NListBuilder &NListBuilder::tagListPen(const long listPen)
    {
        PushTag(MUIA_NList_ListPen, listPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagSelectPen(const long selectPen)
    {
        PushTag(MUIA_NList_SelectPen, selectPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagCursorPen(const long cursorPen)
    {
        PushTag(MUIA_NList_CursorPen, cursorPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagUnselCurPen(const long unselCurPen)
    {
        PushTag(MUIA_NList_UnselCurPen, unselCurPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagInactivePen(const long inactivePen)
    {
        PushTag(MUIA_NList_InactivePen, inactivePen);
        return *this;
    }

    NListBuilder &NListBuilder::tagListBackground(const long listBackground)
    {
        PushTag(MUIA_NList_ListBackground, listBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagListAltBackground(const long listAltBackground)
    {
        PushTag(MUIA_NList_ListAltBackground, listAltBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitleBackground(const long titleBackground)
    {
        PushTag(MUIA_NList_TitleBackground, titleBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagSelectBackground(const long selectBackground)
    {
        PushTag(MUIA_NList_SelectBackground, selectBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagCursorBackground(const long cursorBackground)
    {
        PushTag(MUIA_NList_CursorBackground, cursorBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagUnselCurBackground(const long unselCurBackground)
    {
        PushTag(MUIA_NList_UnselCurBackground, unselCurBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagInactiveBackground(const long inactiveBackground)
    {
        PushTag(MUIA_NList_InactiveBackground, inactiveBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagDefaultObjectOnClick(const bool defaultObjectOnClick)
    {
        PushTag(MUIA_NList_DefaultObjectOnClick, defaultObjectOnClick);
        return *this;
    }

    NListBuilder &NListBuilder::tagActiveObjectOnClick(const bool activeObjectOnClick)
    {
        PushTag(MUIA_NList_ActiveObjectOnClick, activeObjectOnClick);
        return *this;
    }
}
