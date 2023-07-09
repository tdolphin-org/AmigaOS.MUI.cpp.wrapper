//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"

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

        // methods, some can return object reference

        TextEditor &Clear();

        /// @brief [ @b MUIM_TextEditor_ExportText ]
        std::string ExportText() const;
    };

    class TextEditorBuilder : public NotifyBuilderTemplate<TextEditorBuilder, TextEditor>
    {
      public:
        TextEditorBuilder();

        /// @brief [ @b MUIA_TextEditor_Contents ]
        TextEditorBuilder &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_TextEditor_Rows ]
        TextEditorBuilder &tagRows(const long rows);
        /// @brief [ @b MUIA_TextEditor_Slider ]
        TextEditorBuilder &tagSlider(const MUI::Root &slider);
        /// @brief [ @b MUIA_TextEditor_Slider ]
        TextEditorBuilder &tagSlider(const Object *pSlider);
    };
}
