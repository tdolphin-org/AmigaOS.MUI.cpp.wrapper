//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Numeric.hpp"

namespace MUI
{
    /// @brief This is a subclass of Numeric class which offers a knob that the user may turn.
    class Knob : public Numeric
    {
      public:
        explicit Knob(Object *pMuiObject)
          : Numeric(pMuiObject)
        {
        }

        Knob(const Root &root)
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
    };

    template <typename T, typename U> class KnobBuilderTemplate : public NumericBuilderTemplate<T, U>
    {
      public:
        KnobBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Knob)
          : NumericBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class KnobBuilder : public KnobBuilderTemplate<KnobBuilder, Knob>
    {
      public:
        KnobBuilder();
    };
}

#define MUI_KNOB_TPP_INCLUDE
#include "Knob.tpp"
#undef MUI_KNOB_TPP_INCLUDE
