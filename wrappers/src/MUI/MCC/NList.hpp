//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"
#include "ValueTypes/NList/TypeSelect.hpp"

namespace MUI::MCC
{
    class NList : public MUI::Notify
    {

      public:
        NList(const Object *pObject)
          : Notify(pObject)
        {
        }

        const static std::string className;

        // is/get/set (attributes), all setters return object reference

        // methods, some can return object reference
    };

    class NListBuilder : public NotifyBuilderTemplate<NListBuilder, NList>
    {
      public:
        NListBuilder();

        /// @brief [ @b MUIA_NList_TypeSelect ]
        NListBuilder &tagTypeSelect(const enum MUI::MCC_NList::TypeSelect typeSelect);

        /// @brief [ @b MUIA_NList_TitlePen ]
        NListBuilder &tagTitlePen(const long titlePen);
        /// @brief [ @b MUIA_NList_ListPen ]
        NListBuilder &tagListPen(const long listPen);
        /// @brief [ @b MUIA_NList_SelectPen ]
        NListBuilder &tagSelectPen(const long selectPen);
        /// @brief [ @b MUIA_NList_CursorPen ]
        NListBuilder &tagCursorPen(const long cursorPen);
        /// @brief [ @b MUIA_NList_UnselCurPen ]
        NListBuilder &tagUnselCurPen(const long unselCurPen);
        /// @brief [ @b MUIA_NList_InactivePen ]
        NListBuilder &tagInactivePen(const long inactivePen);

        /// @brief [ @b MUIA_NList_ListBackground ]
        NListBuilder &tagListBackground(const long listBackground);
        /// @brief [ @b MUIA_NList_ListAltBackground ]
        NListBuilder &tagListAltBackground(const long listAltBackground);
        /// @brief [ @b MUIA_NList_TitleBackground ]
        NListBuilder &tagTitleBackground(const long titleBackground);
        /// @brief [ @b MUIA_NList_SelectBackground ]
        NListBuilder &tagSelectBackground(const long selectBackground);
        /// @brief [ @b MUIA_NList_CursorBackground ]
        NListBuilder &tagCursorBackground(const long cursorBackground);
        /// @brief [ @b MUIA_NList_UnselCurBackground ]
        NListBuilder &tagUnselCurBackground(const long unselCurBackground);
        /// @brief [ @b MUIA_NList_InactiveBackground ]
        NListBuilder &tagInactiveBackground(const long inactiveBackground);

        /// @brief [ @b MUIA_NList_DefaultObjectOnClick ]
        NListBuilder &tagDefaultObjectOnClick(const bool defaultObjectOnClick);
        /// @brief [ @b MUIA_NList_ActiveObjectOnClick ]
        NListBuilder &tagActiveObjectOnClick(const bool activeObjectOnClick);
    };
}
