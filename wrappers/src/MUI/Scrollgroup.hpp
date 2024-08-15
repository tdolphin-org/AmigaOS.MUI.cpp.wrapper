//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
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

        /// @brief [ @b MUIA_Scrollgroup_AutoBars ]
        T &tagAutoBars(const bool autoBars);
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// You have to specify an object of Virtgroup class here.
        T &tagContents(const Object *contents);
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        T &tagContents(const Virtgroup &contents);
        /// @brief [ @b MUIA_Scrollgroup_FreeHoriz ]
        T &tagFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Scrollgroup_FreeVert ]
        T &tagFreeVert(const bool freeVert);
        /// @brief [ @b MUIA_Scrollgroup_NoHorizBar ]
        T &tagNoHorizBar(const bool noHorizBar);
        /// @brief [ @b MUIA_Scrollgroup_NoVertBar ]
        T &tagNoVertBar(const bool noVertBar);
        /// @brief [ @b MUIA_Scrollgroup_UseWinBorder ]
        T &tagUseWinBorder(const bool useWinBorder);
    };

    class ScrollgroupBuilder : public ScrollgroupBuilderTemplate<ScrollgroupBuilder, Scrollgroup>
    {
      public:
        ScrollgroupBuilder();
    };

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagAutoBars(const bool autoBars)
    {
        this->PushTag(MUIA_Scrollgroup_AutoBars, autoBars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagContents(const Object *contents)
    {
        this->PushTag(MUIA_Scrollgroup_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagContents(const Virtgroup &contents)
    {
        if (contents.muiObject())
            this->PushTag(MUIA_Scrollgroup_Contents, contents.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagFreeHoriz(const bool freeHoriz)
    {
        this->PushTag(MUIA_Scrollgroup_FreeHoriz, freeHoriz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagFreeVert(const bool freeVert)
    {
        this->PushTag(MUIA_Scrollgroup_FreeVert, freeVert);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagNoHorizBar(const bool noHorizBar)
    {
        this->PushTag(MUIA_Scrollgroup_NoHorizBar, noHorizBar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagNoVertBar(const bool noVertBar)
    {
        this->PushTag(MUIA_Scrollgroup_NoVertBar, noVertBar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagUseWinBorder(const bool useWinBorder)
    {
        this->PushTag(MUIA_Scrollgroup_UseWinBorder, useWinBorder);
        return (T &)*this;
    }
}
