//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "List.hpp"

namespace MUI
{
    /// @brief MUI Scrmodelist class wrapper.
    /// A special List subclass that automatically populates itself with all available screen modes.
    /// It has no own attributes; all configuration is done through the inherited List and Area attributes.
    class Scrmodelist : public List
    {
      public:
        explicit Scrmodelist(Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class ScrmodelistBuilderTemplate : public ListBuilderTemplate<T, U>
    {
      public:
        ScrmodelistBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scrmodelist)
          : ListBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class ScrmodelistBuilder : public ScrmodelistBuilderTemplate<ScrmodelistBuilder, Scrmodelist>
    {
      public:
        ScrmodelistBuilder();
    };
}

#define MUI_SCRMODELIST_TPP_INCLUDE
#include "Scrmodelist.tpp"
#undef MUI_SCRMODELIST_TPP_INCLUDE
