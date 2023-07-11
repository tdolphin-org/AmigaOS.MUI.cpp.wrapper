//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "TextEditor.hpp"

#include <mui/TextEditor_mcc.h>
#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string TextEditor::className = MUIC_TextEditor;

    TextEditorBuilder::TextEditorBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, TextEditor::className)
    {
    }

    TextEditor &TextEditor::setContents(const std::string &contents)
    {
        SetValue(MUIA_TextEditor_Contents, contents);
        return *this;
    }

    TextEditor &TextEditor::Clear()
    {
        SetValue(MUIA_TextEditor_Contents, nullptr);
        return *this;
    }

    std::string TextEditor::ExportText() const
    {
        char *text = (char *)DoMethod(muiObject(), MUIM_TextEditor_ExportText);
        return std::string(text);
    }

    TextEditorBuilder &TextEditorBuilder::tagContents(const std::string &contents)
    {
        PushTag(MUIA_TextEditor_Contents, contents);
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagFixedFont(const bool fixedFont)
    {
        PushTag(MUIA_TextEditor_FixedFont, fixedFont);
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagReadOnly(const bool readOnly)
    {
        PushTag(MUIA_TextEditor_ReadOnly, readOnly);
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagWrapMode(const enum TextEditor_WrapMode wrapMode)
    {
        PushTag(MUIA_TextEditor_WrapMode, (unsigned long)wrapMode);
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagRows(const long rows)
    {
        PushTag(MUIA_TextEditor_Rows, rows);
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagSlider(const MUI::Root &slider)
    {
        PushTag(MUIA_TextEditor_Slider, slider.muiObject());
        return *this;
    }

    TextEditorBuilder &TextEditorBuilder::tagSlider(const Object *pSlider)
    {
        PushTag(MUIA_TextEditor_Slider, pSlider);
        return *this;
    }
}
