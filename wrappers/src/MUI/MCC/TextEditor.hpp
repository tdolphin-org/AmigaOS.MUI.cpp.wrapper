//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Core/BuilderRoot.hpp"
#include "MUI/Core/Root.hpp"

namespace MUI::MCC
{
    class TextEditor : public MUI::Root // TODO check if custom classes are derived from Root or Notify?
    {

      public:
        TextEditor(const Object *pObject)
          : Root(pObject)
        {
        }

        const static std::string className;

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_TextEditor_Contents ]
        TextEditor &setContents(const std::string &contents);

        // methods, some can return object reference

        TextEditor &Clear();

        /// @brief [ @b MUIM_TextEditor_ExportText ]
        std::string ExportText() const;
    };

    class TextEditorBuilder : public BuilderRoot<TextEditor>
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
