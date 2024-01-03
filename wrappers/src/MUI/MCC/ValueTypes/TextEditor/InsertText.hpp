//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/TextEditor_mcc.h>

namespace MUI::MCC
{
    enum class TextEditor_InsertText
    {
        Cursor = MUIV_TextEditor_InsertText_Cursor,
        Top = MUIV_TextEditor_InsertText_Top,
        Bottom = MUIV_TextEditor_InsertText_Bottom,
    };
}
