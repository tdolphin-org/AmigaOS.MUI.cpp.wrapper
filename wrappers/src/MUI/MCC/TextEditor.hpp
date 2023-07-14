//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"
#include "ValueTypes/TextEditor/InsertText.hpp"
#include "ValueTypes/TextEditor/MarkText.hpp"
#include "ValueTypes/TextEditor/SetBlock.hpp"
#include "ValueTypes/TextEditor/TabSize.hpp"
#include "ValueTypes/TextEditor/WrapMode.hpp"

namespace MUI::MCC
{
    class TextEditor : public MUI::Notify
    {

      public:
        TextEditor(const Object *pObject)
          : Notify(pObject)
        {
        }

        TextEditor(const APTR pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_TextEditor_Contents ]
        TextEditor &setContents(const std::string &contents);
        /// @brief [ @b MUIA_TextEditor_Contents, contents = nullptr ]
        TextEditor &setContentsNull();

        // methods, some can return object reference

        /// @brief [ @b MUIM_TextEditor_ClearText ]
        TextEditor &ClearText();
        /// @brief [ @b MUIM_TextEditor_InsertText ]
        TextEditor &InsertText(const std::string &text, const enum TextEditor_InsertText pos);
        /// @brief [ @b MUIM_TextEditor_InsertText, pos = @b MUIV_TextEditor_InsertText_Cursor ]
        TextEditor &InsertTextAtCursor(const std::string &text);
        /// @brief [ @b MUIM_TextEditor_InsertText, pos = @b MUIV_TextEditor_InsertText_Top ]
        TextEditor &InsertTextAtTop(const std::string &text);
        /// @brief [ @b MUIM_TextEditor_InsertText, pos = @b MUIV_TextEditor_InsertText_Bottom ]
        TextEditor &InsertTextAtBottom(const std::string &text);

        /// @brief [ @b MUIM_TextEditor_ExportText ]
        std::string ExportText() const;
    };

    class TextEditorBuilder : public NotifyBuilderTemplate<TextEditorBuilder, TextEditor>
    {
      public:
        TextEditorBuilder();

        /// @brief [ @b MUIA_TextEditor_Contents ]
        TextEditorBuilder &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_TextEditor_FixedFont ]
        TextEditorBuilder &tagFixedFont(const bool fixedFont = true);
        /// @brief [ @b MUIA_TextEditor_ReadOnly ]
        TextEditorBuilder &tagReadOnly(const bool readOnly = true);
        /// @brief [ @b MUIA_TextEditor_WrapMode ]
        TextEditorBuilder &tagWrapMode(const enum TextEditor_WrapMode wrapMode);
        /// @brief [ @b MUIA_TextEditor_Rows ]
        TextEditorBuilder &tagRows(const long rows);
        /// @brief [ @b MUIA_TextEditor_Slider ]
        TextEditorBuilder &tagSlider(const MUI::Root &slider);
        /// @brief [ @b MUIA_TextEditor_Slider ]
        TextEditorBuilder &tagSlider(const Object *pSlider);
    };
}
