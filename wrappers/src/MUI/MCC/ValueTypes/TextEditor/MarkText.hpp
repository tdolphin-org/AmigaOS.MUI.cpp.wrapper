//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/TextEditor_mcc.h>

namespace MUI::MCC
{
    enum class TextEditor_MarkText
    {
        All = MUIV_TextEditor_MarkText_All,
        None = MUIV_TextEditor_MarkText_None,
    };
}
