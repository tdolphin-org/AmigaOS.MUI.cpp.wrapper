//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Slider.hpp"

namespace MUI
{
    /// @brief This class is some kind of space-saving slider. No more need for extra attributes, simply use Numeric class options for this
    /// one.
    class Numericbutton : public Slider
    {
      public:
        explicit Numericbutton(Object *pMuiObject)
          : Slider(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class NumericbuttonBuilderTemplate : public SliderBuilderTemplate<T, U>
    {
      public:
        NumericbuttonBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Numericbutton)
          : SliderBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class NumericbuttonBuilder : public NumericbuttonBuilderTemplate<NumericbuttonBuilder, Numericbutton>
    {
      public:
        NumericbuttonBuilder();
    };
}

#define MUI_NUMERICBUTTON_TPP_INCLUDE
#include "Numericbutton.tpp"
#undef MUI_NUMERICBUTTON_TPP_INCLUDE
