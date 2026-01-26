//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_GROUP_TPP_INCLUDE
#error "Group.tpp should only be included by Group.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::vertical()
    {
        this->PushTag(MUIA_Group_Horiz, false);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::horizontal()
    {
        this->PushTag(MUIA_Group_Horiz, true);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagActivePage(const unsigned long activePage)
    {
        this->PushTag(MUIA_Group_ActivePage, activePage);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagActivePage(const enum Group_ActivePage activePage)
    {
        this->PushTag(MUIA_Group_ActivePage, (long)activePage);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagChild(const Object *pChildObject, bool condition)
    {
        if (condition && pChildObject)
            this->PushTag(MUIA_Group_Child, pChildObject, false, true);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagChild(const Root &child, bool condition)
    {
        if (condition && child.muiObject())
            this->PushTag(MUIA_Group_Child, child.muiObject(), false, true);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagColumns(const long columns)
    {
        this->PushTag(MUIA_Group_Columns, columns);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Group_Horiz, horiz);
        return (T &)*this;
    }

#ifdef MUIA_Group_HorizCenter
    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagHorizCenter(const enum Group_HorizCenter horizCenter)
    {
        this->PushTag(MUIA_Group_HorizCenter, (long)horizCenter);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagHorizSpacing(const long horizSpacing)
    {
        this->PushTag(MUIA_Group_HorizSpacing, horizSpacing);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagPageMode(const bool pageMode)
    {
        this->PushTag(MUIA_Group_PageMode, pageMode);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagRows(const long rows)
    {
        this->PushTag(MUIA_Group_Rows, rows);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameHeight(const bool sameHeight)
    {
        this->PushTag(MUIA_Group_SameHeight, sameHeight);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameSize(const bool sameSize)
    {
        this->PushTag(MUIA_Group_SameSize, sameSize);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameWidth(const bool sameWidth)
    {
        this->PushTag(MUIA_Group_SameWidth, sameWidth);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSpacing(const long spacing)
    {
        this->PushTag(MUIA_Group_Spacing, spacing);
        return (T &)*this;
    }

#ifdef MUIA_Group_VertCenter
    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertCenter(const enum Group_VertCenter vertCenter)
    {
        this->PushTag(MUIA_Group_VertCenter, (long)vertCenter);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertSpacing(const long vertSpacing)
    {
        this->PushTag(MUIA_Group_VertSpacing, vertSpacing);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::groupFrame(const std::string &title)
    {
        this->PushTag(MUIA_Frame, (long)MUI::Frame::Group);
        if (!title.empty())
        {
            auto copy = this->StoreString(MUIA_FrameTitle, title);
            this->PushTag(MUIA_FrameTitle, copy);
        }
        this->PushTag(MUIA_Background, (long)MUI::ImageOrBackground::GroupBack);
        return (T &)*this;
    }
}
