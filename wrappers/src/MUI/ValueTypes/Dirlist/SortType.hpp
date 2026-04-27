//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Dirlist_SortType
    {
        Name = MUIV_Dirlist_SortType_Name,
        Date = MUIV_Dirlist_SortType_Date,
        Size = MUIV_Dirlist_SortType_Size,
#ifdef MUIV_Dirlist_SortType_Comment
        Comment = MUIV_Dirlist_SortType_Comment,
#endif
#ifdef MUIV_Dirlist_SortType_Flags
        Flags = MUIV_Dirlist_SortType_Flags,
#endif
#ifdef MUIV_Dirlist_SortType_Type
        Type = MUIV_Dirlist_SortType_Type,
#endif
#ifdef MUIV_Dirlist_SortType_Used
        Used = MUIV_Dirlist_SortType_Used,
#endif
#ifdef MUIV_Dirlist_SortType_Time
        Time = MUIV_Dirlist_SortType_Time,
#endif
#ifdef MUIV_Dirlist_SortType_DateTime
        DateTime = MUIV_Dirlist_SortType_DateTime,
#endif
#ifdef MUIV_Dirlist_SortType_Count
        Count = MUIV_Dirlist_SortType_Count,
#endif
    };
}
