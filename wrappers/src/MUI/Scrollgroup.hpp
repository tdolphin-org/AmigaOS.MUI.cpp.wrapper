//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Virtgroup.hpp"

namespace MUI
{
    class Scrollgroup : public Group
    {
      public:
        explicit Scrollgroup(Object *pMuiObject)
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

    template <typename T, typename U> class ScrollgroupBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ScrollgroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scrollgroup)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Scrollgroup_AutoBars
        /// @brief [ @b MUIA_Scrollgroup_AutoBars ]
        T &tagAutoBars(const bool autoBars);
#endif
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// You have to specify an object of Virtgroup class here.
        T &tagContents(const Object *contents);
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        T &tagContents(const Virtgroup &contents);
        /// @brief [ @b MUIA_Scrollgroup_FreeHoriz ]
        T &tagFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Scrollgroup_FreeVert ]
        T &tagFreeVert(const bool freeVert);
#ifdef MUIA_Scrollgroup_NoHorizBar
        /// @brief [ @b MUIA_Scrollgroup_NoHorizBar ]
        T &tagNoHorizBar(const bool noHorizBar);
#endif
#ifdef MUIA_Scrollgroup_NoVertBar
        /// @brief [ @b MUIA_Scrollgroup_NoVertBar ]
        T &tagNoVertBar(const bool noVertBar);
#endif
        /// @brief [ @b MUIA_Scrollgroup_UseWinBorder ]
        T &tagUseWinBorder(const bool useWinBorder);

      protected:
        bool Validate() const override;
    };

    class ScrollgroupBuilder : public ScrollgroupBuilderTemplate<ScrollgroupBuilder, Scrollgroup>
    {
      public:
        ScrollgroupBuilder();
    };
}

#define MUI_SCROLLGROUP_TPP_INCLUDE
#include "Scrollgroup.tpp"
#undef MUI_SCROLLGROUP_TPP_INCLUDE
