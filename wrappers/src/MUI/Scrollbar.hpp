//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/Scrollbar/Type.hpp"

namespace MUI
{
    /// @brief Wrapper for MUIC_Scrollbar - a group combining a prop gadget with arrow buttons.
    /// Scrollbar forwards attributes and methods to its child gadgets so it can be used like a
    /// single proportional gadget, while Group layout attributes still control horizontal or vertical layout.
    class Scrollbar : public Group
    {
      public:
        explicit Scrollbar(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Scrollbar(const Root &root)
          : Group(root.muiObject())
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

#ifdef MUIA_Scrollbar_IncDecSize
        /// @brief [ @b MUIA_Scrollbar_IncDecSize ] Get the amount by which arrow button clicks change the scrollbar position.
        unsigned long getIncDecSize() const;

        /// @brief [ @b MUIA_Scrollbar_IncDecSize ] Set the amount by which arrow button clicks change the scrollbar position.
        Scrollbar &setIncDecSize(unsigned long incDecSize);
#endif
    };

    template <typename T, typename U> class ScrollbarBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ScrollbarBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scrollbar)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
#ifdef MUIA_Scrollbar_IncDecSize
        /// @brief [ @b MUIA_Scrollbar_IncDecSize ] Set the initial amount by which arrow button clicks change the scrollbar position.
        T &tagIncDecSize(const unsigned long incDecSize);
#endif
        /// @brief [ @b MUIA_Scrollbar_Type ] Specify a certain scrollbar type.
        /// Normally the user's configured scrollbar style should be respected.
        T &tagType(const enum Scrollbar_Type type);
    };

    class ScrollbarBuilder : public ScrollbarBuilderTemplate<ScrollbarBuilder, Scrollbar>
    {
      public:
        ScrollbarBuilder();
    };
}

#define MUI_SCROLLBAR_TPP_INCLUDE
#include "Scrollbar.tpp"
#undef MUI_SCROLLBAR_TPP_INCLUDE
