//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "List.hpp"

namespace MUI
{
    class Floattext : public List
    {
      public:
        explicit Floattext(Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        Floattext(const Root &root)
          : List(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Floattext_Justify ]
        /// Indicate whether the text is aligned to the left and right border.
        bool isJustify() const;
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Returns pointer to the internal text buffer. May return NULL if memory was low when the text was set.
        const char *getText() const;

        /// @brief [ @b MUIA_Floattext_Justify ]
        /// Indicate whether you want your the text aligned to the left and right border.
        /// MUI will try to insert spaces between words to reach this goal.
        /// If you want right aligned or centered text, use the @b MUIA_List_Format attribute.
        Floattext &setJustify(const bool justify);
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines a string of characters that shall be skipped when displaying the text.
        /// E.g. set to "\1" to suppress CTRL-A control characters in a fido message.
        Floattext &setSkipChars(const char *skipChars);
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines a string of characters that shall be skipped when displaying the text.
        /// E.g. set to "\1" to suppress CTRL-A control characters in a fido message.
        Floattext &setSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_Floattext_TabSize ]
        /// Adjust the tab size for a text. The tab size is measured in spaces.
        /// If tabs are used not only at the beginning of a paragraph, consider using the fixed width font.
        /// Defaults to 8.
        Floattext &setTabSize(const long tabSize);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Strings of characters to be displayed as floattext. This string may contain linefeeds to mark
        /// the end of paragraphs or tab characters for indention. MUI copies the complete string into a
        /// private buffer, so the original can be freed immediately after. Setting to @b NULL clears the text.
        Floattext &setText(const char *text);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Strings of characters to be displayed as floattext. This string may contain linefeeds to mark
        /// the end of paragraphs or tab characters for indention. MUI copies the complete string into a
        /// private buffer, so the original can be freed immediately after.
        Floattext &setText(const std::string &text);

        // methods, some returns object reference

        /// @brief [ @b MUIA_Floattext_Text, @b NULL ]
        /// Clear currently displayed text (sets @b MUIA_Floattext_Text to @b NULL).
        Floattext &Clear();

#ifdef MUIM_Floattext_Append
        /// @brief [ @b MUIM_Floattext_Append ]
        /// Appends the given text to the already existing text. The additional text will be copied to a private buffer.
        /// @return reference to this object (fluent API); note that the underlying DoMethod returns a boolean success flag.
        Floattext &Append(const std::string &text);
#endif
    };

    template <typename T, typename U> class FloattextBuilderTemplate : public ListBuilderTemplate<T, U>
    {
      public:
        FloattextBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Floattext)
          : ListBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Floattext_Justify ]
        /// Indicate whether you want your the text aligned to the left and right border.
        /// MUI will try to insert spaces between words to reach this goal.
        /// If you want right aligned or centered text, use the @b MUIA_List_Format attribute.
        T &tagJustify(const bool justify);
#ifdef MUIA_Floattext_KeepStyles
        /// @brief [ @b MUIA_Floattext_KeepStyles ]
        /// If set to true any active text styles at the end of a paragraph will be kept instead of being reset
        /// back to plain text. Defaults to false.
        T &tagKeepStyles(const bool keepStyles);
#endif
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines a string of characters that shall be skipped when displaying the text.
        /// E.g. set to "\1" to suppress CTRL-A control characters in a fido message.
        T &tagSkipChars(const char *skipChars);
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines a string of characters that shall be skipped when displaying the text.
        /// E.g. set to "\1" to suppress CTRL-A control characters in a fido message.
        T &tagSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_Floattext_TabSize ]
        /// Adjust the tab size for a text. The tab size is measured in spaces.
        /// If tabs are used not only at the beginning of a paragraph, consider using the fixed width font.
        /// Defaults to 8.
        T &tagTabSize(const long tabSize);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Strings of characters to be displayed as floattext. This string may contain linefeeds to mark
        /// the end of paragraphs or tab characters for indention. MUI copies the complete string into a
        /// private buffer, so the original can be freed immediately after. Setting to @b NULL clears the text.
        T &tagText(const char *text);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Strings of characters to be displayed as floattext. MUI copies the complete string into a private buffer,
        /// so the original can be freed immediately after.
        T &tagText(const std::string &text);
    };

    class FloattextBuilder : public FloattextBuilderTemplate<FloattextBuilder, Floattext>
    {
      public:
        FloattextBuilder();
    };
}

#define MUI_FLOATTEXT_TPP_INCLUDE
#include "Floattext.tpp"
#undef MUI_FLOATTEXT_TPP_INCLUDE
