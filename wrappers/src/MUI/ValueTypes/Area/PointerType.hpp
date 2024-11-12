//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
#ifdef MUIA_PointerType
    enum class PointerType
    {
        Parent = MUIV_PointerType_Parent,
        Normal = MUIV_PointerType_Normal,
        Busy = MUIV_PointerType_Busy,
        Alias = MUIV_PointerType_Alias,
        Cell = MUIV_PointerType_Cell,
        ColumnResize = MUIV_PointerType_ColumnResize,
        ContextMenu = MUIV_PointerType_ContextMenu,
        Copy = MUIV_PointerType_Copy,
        Cross = MUIV_PointerType_Cross,
        DragAndDrop = MUIV_PointerType_DragAndDrop,
        EastResize = MUIV_PointerType_EastResize,
        EastWestResize = MUIV_PointerType_EastWestResize,
        Hand = MUIV_PointerType_Hand,
        Help = MUIV_PointerType_Help,
        Link = MUIV_PointerType_Link,
        Menu = MUIV_PointerType_Menu,
        NoDrop = MUIV_PointerType_NoDrop,
        None = MUIV_PointerType_None,
        NorthEastResize = MUIV_PointerType_NorthEastResize,
        NorthEastSouthWestResize = MUIV_PointerType_NorthEastSouthWestResize,
        NorthResize = MUIV_PointerType_NorthResize,
        NorthSouthResize = MUIV_PointerType_NorthSouthResize,
        NorthWestResize = MUIV_PointerType_NorthWestResize,
        NorthWestSouthEastResize = MUIV_PointerType_NorthWestSouthEastResize,
        NotAllowed = MUIV_PointerType_NotAllowed,
        Progress = MUIV_PointerType_Progress,
        RowResize = MUIV_PointerType_RowResize,
        ScrollAll = MUIV_PointerType_ScrollAll,
        SouthEastResize = MUIV_PointerType_SouthEastResize,
        SouthResize = MUIV_PointerType_SouthResize,
        SouthWestResize = MUIV_PointerType_SouthWestResize,
        Text = MUIV_PointerType_Text,
        VerticalText = MUIV_PointerType_VerticalText,
        WestResize = MUIV_PointerType_WestResize,
        ZoomIn = MUIV_PointerType_ZoomIn,
        ZoomOut = MUIV_PointerType_ZoomOut,
        Pen = MUIV_PointerType_Pen,
        Rotate = MUIV_PointerType_Rotate,
        Rubber = MUIV_PointerType_Rubber,
        Select = MUIV_PointerType_Select,
        Smudge = MUIV_PointerType_Smudge,
        Count = MUIV_PointerType_Count
    };
#endif
}
