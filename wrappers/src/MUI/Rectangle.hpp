//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief Rectangle class objects allow insertion of space to control MUI's layout process.
    /// They can optionally display a horizontal or vertical bar used as a separator, as an alternative to group frames.
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

        /// @brief [ @b MUIA_Rectangle_BarTitle ] This attribute describes a text string which will be displayed
        /// in group title style centered in the rectangle. Really only makes sense for MUIA_Rectangle_HBar type objects.
        std::string getBarTitle() const;
        /// @brief [ @b MUIA_Rectangle_HBar ] When set to true, MUI draws a horizontal bar in the middle of the rectangle.
        /// Such bars can be used instead of group frames to separate objects in a window.
        bool isHBar() const;
        /// @brief [ @b MUIA_Rectangle_VBar ] When set to true, MUI draws a vertical bar in the middle of the rectangle.
        /// Such bars can be used instead of group frames to separate objects in a window.
        bool isVBar() const;
    };

    template <typename T, typename U> class RectangleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        RectangleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Rectangle)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Rectangle_BarTitle ] This attribute describes a text string which will be displayed
        /// in group title style centered in the rectangle. Really only makes sense for MUIA_Rectangle_HBar type objects.
        T &tagBarTitle(const char *barTitle);
        /// @brief [ @b MUIA_Rectangle_HBar ] When set to true, MUI draws a horizontal bar in the middle of the rectangle.
        /// Such bars can be used instead of group frames to separate objects in a window.
        T &tagHBar(const bool hBar);
        /// @brief [ @b MUIA_Rectangle_VBar ] When set to true, MUI draws a vertical bar in the middle of the rectangle.
        /// Such bars can be used instead of group frames to separate objects in a window.
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
