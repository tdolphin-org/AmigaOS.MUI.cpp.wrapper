//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    enum class ScrollbarType
    {
        Default = MUIV_Scrollbar_Type_Default,
        Bottom = MUIV_Scrollbar_Type_Bottom,
        Top = MUIV_Scrollbar_Type_Top,
        Sym = MUIV_Scrollbar_Type_Sym,
        None = MUIV_Scrollbar_Type_None,
    };

    class Scrollbar : public Group
    {
      public:
        Scrollbar(const Object *pMuiObject)
          : Group(pMuiObject)
        {
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
