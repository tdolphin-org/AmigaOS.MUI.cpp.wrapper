//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Register.hpp"

#ifdef MUIC_Penadjust

namespace MUI
{
    /// @brief MUI Penadjust class wrapper.
    /// Penadjust is a private class intended for public screen inspector usage.
    class Penadjust : public Register
    {
      public:
        explicit Penadjust(Object *pMuiObject)
          : Register(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class PenadjustBuilderTemplate : public RegisterBuilderTemplate<T, U>
    {
      public:
        PenadjustBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Penadjust)
          : RegisterBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Penadjust_PSIMode
        /// @brief [ @b MUIA_Penadjust_PSIMode ] Set public-screen-inspector mode at initialization.
        T &tagPSIMode(const bool psiMode);
#endif
    };

    class PenadjustBuilder : public PenadjustBuilderTemplate<PenadjustBuilder, Penadjust>
    {
      public:
        PenadjustBuilder();
    };
}

#define MUI_PENADJUST_TPP_INCLUDE
#include "Penadjust.tpp"
#undef MUI_PENADJUST_TPP_INCLUDE

#endif
