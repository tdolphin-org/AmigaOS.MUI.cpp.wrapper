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
    class Slider : public Numeric
    {
      public:
        explicit Slider(Object *pMuiObject)
          : Numeric(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Slider_Horiz ] Get the slider orientation flag.
        /// Returns true for a horizontal slider and false for a vertical slider.
        bool getHoriz() const;

        /// @brief [ @b MUIA_Slider_Horiz ] Set the slider orientation flag.
        /// Set to true for a horizontal slider and false for a vertical slider.
        Slider &setHoriz(const bool horiz);
    };

    template <typename T, typename U> class SliderBuilderTemplate : public NumericBuilderTemplate<T, U>
    {
      public:
        SliderBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Slider)
          : NumericBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Slider_Horiz ] Set the initial slider orientation.
        /// Set to true for a horizontal slider and false for a vertical slider.
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Slider_Quiet ] Set quiet mode during object creation.
        /// If true, the slider remains visually quiet while being dragged.
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
