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

    NListBuilder &NListBuilder::tagTypeSelect(const MUI::MCC::TypeSelect typeSelect)
    {
        PushTag(MUIA_NList_TypeSelect, (long)typeSelect);
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
