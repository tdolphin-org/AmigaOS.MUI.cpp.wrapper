//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "List.hpp"

namespace MUI
{
    /// @brief Private List subclass that populates itself with all available screen modes.
    /// This is a private class used only by the MUI preferences program. It has no own
    /// attributes or methods; all configuration is done through inherited List attributes.
    class Scrmodelist : public List
    {
      public:
        explicit Scrmodelist(Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        Scrmodelist(const Root &root)
          : List(root.muiObject())
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
