//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/ScrollbarType.hpp"

namespace MUI
{
    class Scrollbar : public Group
    {
      public:
        Scrollbar(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Scrollbar);
        }
    };

    template <typename T, typename U> class ScrollbarBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ScrollbarBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scrollbar)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Scrollbar_Type ]
        T &tagType(const enum ScrollbarType type);
    };

    class ScrollbarBuilder : public ScrollbarBuilderTemplate<ScrollbarBuilder, Scrollbar>
    {
      public:
        ScrollbarBuilder();
    };

    template <typename T, typename U> inline T &ScrollbarBuilderTemplate<T, U>::tagType(const enum ScrollbarType type)
    {
        this->PushTag(MUIA_Scrollbar_Type, (long)type);
        return (T &)*this;
    }
}
