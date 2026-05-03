//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Numeric.hpp"

#undef Slider

namespace MUI
{
    /// @brief The slider class generates a GU element that allows a user to adjust a numeric value.
    /// The class offers only a small amount of slider-specific API and relies on its Numeric base for
    /// the active numeric range and value interface.
    class Slider : public Numeric
    {
      public:
        explicit Slider(Object *pMuiObject)
          : Numeric(pMuiObject)
        {
        }

        Slider(const Root &root)
          : Numeric(root.muiObject())
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

        /// @brief [ @b MUIA_Slider_Horiz ] Return whether the slider is horizontal or vertical.
        /// This attribute also understands MUIA_Group_Horiz for compatibility with older MUI versions.
        bool getHoriz() const;

        /// @brief [ @b MUIA_Slider_Horiz ] Specify whether the slider is horizontal or vertical.
        /// This attribute also understands MUIA_Group_Horiz for compatibility with older MUI versions.
        Slider &setHoriz(const bool horiz);
    };

    template <typename T, typename U> class SliderBuilderTemplate : public NumericBuilderTemplate<T, U>
    {
      public:
        SliderBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Slider)
          : NumericBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Slider_Horiz ] Specify whether the initial slider is horizontal or vertical.
        /// This attribute also understands MUIA_Group_Horiz for compatibility with older MUI versions.
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Slider_Quiet ] Configure whether the slider hides its current level text.
        /// When set to true, the slider does not display its current level in a text object.
        T &tagQuiet(const bool quiet);
    };

    class SliderBuilder : public SliderBuilderTemplate<SliderBuilder, Slider>
    {
      public:
        SliderBuilder();
    };
}

#define MUI_SLIDER_TPP_INCLUDE
#include "Slider.tpp"
#undef MUI_SLIDER_TPP_INCLUDE
