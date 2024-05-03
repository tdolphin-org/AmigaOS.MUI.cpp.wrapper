//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/Scrollbar/Type.hpp"

namespace MUI
{
    class Scrollbar : public Group
    {
      public:
        Scrollbar(const Object *pMuiObject)
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

#ifdef MUIA_Scrollbar_IncDecSize
        /// @brief [ @b MUIA_Scrollbar_IncDecSize ]
        unsigned long getIncDecSize() const;

        /// @brief [ @b MUIA_Scrollbar_IncDecSize ]
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
        /// @brief [ @b MUIA_Scrollbar_IncDecSize ]
        T &tagIncDecSize(const unsigned long incDecSize);
#endif
        /// @brief [ @b MUIA_Scrollbar_Type ]
        T &tagType(const enum Scrollbar_Type type);
    };

    class ScrollbarBuilder : public ScrollbarBuilderTemplate<ScrollbarBuilder, Scrollbar>
    {
      public:
        ScrollbarBuilder();
    };

#ifdef MUIA_Scrollbar_IncDecSize
    template <typename T, typename U> inline T &ScrollbarBuilderTemplate<T, U>::tagIncDecSize(const unsigned long incDecSize)
    {
        this->PushTag(MUIA_Scrollbar_IncDecSize, incDecSize);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ScrollbarBuilderTemplate<T, U>::tagType(const enum Scrollbar_Type type)
    {
        this->PushTag(MUIA_Scrollbar_Type, (long)type);
        return (T &)*this;
    }
}
