//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Scale : public Area
    {
      public:
        explicit Scale(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Scale_Horiz
        /// @brief [ @b MUIA_Scale_Horiz ]
        bool getHoriz() const;

        /// @brief [ @b MUIA_Scale_Horiz ]
        Scale &setHoriz(const bool horiz);
#endif
    };

    template <typename T, typename U> class ScaleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ScaleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scale)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Scale_Horiz
        /// @brief [ @b MUIA_Scale_Horiz ]
        T &tagHoriz(const bool horiz);
#endif
    };

    class ScaleBuilder : public ScaleBuilderTemplate<ScaleBuilder, Scale>
    {
      public:
        ScaleBuilder();
    };
}

#define MUI_SCALE_TPP_INCLUDE
#include "Scale.tpp"
#undef MUI_SCALE_TPP_INCLUDE
