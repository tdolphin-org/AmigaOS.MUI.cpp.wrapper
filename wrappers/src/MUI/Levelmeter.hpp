//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Numeric.hpp"

namespace MUI
{
    /// @brief This is a subclass of numeric class that display a levelmeter.
    class Levelmeter : public Numeric
    {
      public:
        explicit Levelmeter(Object *pMuiObject)
          : Numeric(pMuiObject)
        {
        }

        Levelmeter(const Root &root)
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

        /// @brief [ @b MUIA_Levelmeter_Label ] Return the current levelmeter label text.
        std::string getLabel() const;

        /// @brief [ @b MUIA_Levelmeter_Label ] Set the displayed levelmeter label text.
        Levelmeter &setLabel(const char *label);

        /// @brief [ @b MUIA_Levelmeter_Label ] Set the displayed levelmeter label text.
        Levelmeter &setLabel(const std::string &label);
    };

    template <typename T, typename U> class LevelmeterBuilderTemplate : public NumericBuilderTemplate<T, U>
    {
      public:
        LevelmeterBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId,
                                  const std::string &muiClassName = MUIC_Levelmeter)
          : NumericBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Levelmeter_Label ] Set the initial levelmeter label text from a C string.
        T &tagLabel(const char *label);
        /// @brief [ @b MUIA_Levelmeter_Label ] Set the initial levelmeter label text from a std::string.
        T &tagLabel(const std::string &label);
    };

    class LevelmeterBuilder : public LevelmeterBuilderTemplate<LevelmeterBuilder, Levelmeter>
    {
      public:
        LevelmeterBuilder();
    };
}

#define MUI_LEVELMETER_TPP_INCLUDE
#include "Levelmeter.tpp"
#undef MUI_LEVELMETER_TPP_INCLUDE
