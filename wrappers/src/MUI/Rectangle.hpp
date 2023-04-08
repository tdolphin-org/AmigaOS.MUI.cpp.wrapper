//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Rectangle : public Area
    {
      public:
        Rectangle(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }
    };

    template <typename T, typename U> class RectangleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        RectangleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Rectangle)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief MUIA_Rectangle_BarTitle
        T &tagBarTitle(const char *barTitle);
        /// @brief MUIA_Rectangle_HBar
        T &tagHBar(const bool hBar);
        /// @brief MUIA_Rectangle_VBar
        T &tagVBar(const bool vBar);
    };

    class RectangleBuilder : public RectangleBuilderTemplate<RectangleBuilder, Rectangle>
    {
      public:
        RectangleBuilder();
    };

    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagBarTitle(const char *barTitle)
    {
        this->PushTag(MUIA_Rectangle_BarTitle, barTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagHBar(const bool hBar)
    {
        this->PushTag(MUIA_Rectangle_HBar, hBar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagVBar(const bool vBar)
    {
        this->PushTag(MUIA_Rectangle_VBar, vBar);
        return (T &)*this;
    }
}
