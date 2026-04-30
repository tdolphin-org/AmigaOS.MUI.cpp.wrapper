//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief Mccprefs is the base class for all custom class configuration classes. Each configuration class (*.mcp) must be a subclass of
    /// Mccprefs. Mccprefs does some internal house keeping stuff for configuration objects and also offers public methods that subclasses
    /// may call to improve their appearance.
    class Mccprefs : public Group
    {
      public:
        explicit Mccprefs(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference
    };

    template <typename T, typename U> class MccprefsBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        MccprefsBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Mccprefs)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class MccprefsBuilder : public MccprefsBuilderTemplate<MccprefsBuilder, Mccprefs>
    {
      public:
        MccprefsBuilder();
    };
}

#define MUI_MCCPREFS_TPP_INCLUDE
#include "Mccprefs.tpp"
#undef MUI_MCCPREFS_TPP_INCLUDE
