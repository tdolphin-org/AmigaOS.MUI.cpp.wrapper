//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/TextEditor_mcc.h>

namespace MUI::MCC
{
    enum class TextEditor_WrapMode
    {
        NoWrap = MUIV_TextEditor_WrapMode_NoWrap,
        SoftWrap = MUIV_TextEditor_WrapMode_SoftWrap,
        HardWrap = MUIV_TextEditor_WrapMode_HardWrap,
    };
}
