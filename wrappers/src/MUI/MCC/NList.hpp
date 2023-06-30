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
        NListBuilder &tagTypeSelect(const enum MUI::MCC::TypeSelect typeSelect);

        /// @brief [ @b MUIA_NList_DefaultObjectOnClick ]
        NListBuilder &tagDefaultObjectOnClick(const bool defaultObjectOnClick);
        /// @brief [ @b MUIA_NList_ActiveObjectOnClick ]
        NListBuilder &tagActiveObjectOnClick(const bool activeObjectOnClick);
    };
}
