//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SCROLLGROUP_TPP_INCLUDE
#error "Scrollgroup.tpp should only be included by Scrollgroup.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Scrollgroup_AutoBars
    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagAutoBars(const bool autoBars)
    {
        this->PushTag(MUIA_Scrollgroup_AutoBars, autoBars);
        return (T &)*this;
    }
#endif

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

#ifdef MUIA_Scrollgroup_NoHorizBar
    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagNoHorizBar(const bool noHorizBar)
    {
        this->PushTag(MUIA_Scrollgroup_NoHorizBar, noHorizBar);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Scrollgroup_NoVertBar
    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagNoVertBar(const bool noVertBar)
    {
        this->PushTag(MUIA_Scrollgroup_NoVertBar, noVertBar);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ScrollgroupBuilderTemplate<T, U>::tagUseWinBorder(const bool useWinBorder)
    {
        this->PushTag(MUIA_Scrollgroup_UseWinBorder, useWinBorder);
        return (T &)*this;
    }

    template <typename T, typename U> inline bool ScrollgroupBuilderTemplate<T, U>::Validate() const
    {
        auto result = GroupBuilderTemplate<T, U>::Validate();

        if (!this->ContainsTag(MUIA_Scrollgroup_Contents))
        {
            std::cerr << __PRETTY_FUNCTION__ << ", missing Contents attribute for Scrollgroup!" << std::endl;
            result = false;
        }

        return result;
    }
}
