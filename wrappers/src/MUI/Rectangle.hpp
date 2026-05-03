//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief MUI Rectangle class wrapper.
    /// A lightweight spacer/separator object used to influence MUI layout, optionally as horizontal/vertical bar.
    class Rectangle : public Area
    {
      public:
        explicit Rectangle(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Rectangle(const Root &root)
          : Area(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Rectangle_BarTitle ] Returns the title text drawn centered in group-title style on horizontal bar rectangles.
        std::string getBarTitle() const;
        /// @brief [ @b MUIA_Rectangle_HBar ] Returns whether this rectangle is configured to draw a horizontal bar.
        bool isHBar() const;
        /// @brief [ @b MUIA_Rectangle_VBar ] Returns whether this rectangle is configured to draw a vertical bar.
        bool isVBar() const;
    };

    template <typename T, typename U> class RectangleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        RectangleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Rectangle)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Rectangle_BarTitle ] Sets the title text drawn in group-title style (primarily meaningful for horizontal bars).
        T &tagBarTitle(const char *barTitle);
        /// @brief [ @b MUIA_Rectangle_HBar ] Enables or disables drawing a horizontal bar in the middle of the rectangle.
        T &tagHBar(const bool hBar);
        /// @brief [ @b MUIA_Rectangle_VBar ] Enables or disables drawing a vertical bar in the middle of the rectangle.
        T &tagVBar(const bool vBar);
    };

    class RectangleBuilder : public RectangleBuilderTemplate<RectangleBuilder, Rectangle>
    {
      public:
        RectangleBuilder();
    };
}

#define MUI_RECTANGLE_TPP_INCLUDE
#include "Rectangle.tpp"
#undef MUI_RECTANGLE_TPP_INCLUDE
