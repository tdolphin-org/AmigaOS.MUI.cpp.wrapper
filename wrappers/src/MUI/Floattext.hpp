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

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Floattext_Justify ]
        /// Is the text aligned to the left and right border.
        bool isJustify() const;
        /// @brief [ @b MUIA_Floattext_Text ]
        /// Returns pointer to text buffer, could be NULL.
        char *getText() const;

        /// @brief [ @b MUIA_Floattext_Justify ]
        /// Indicate whether you want your the text aligned to the left and right border.
        Floattext &setJustify(const bool justify);
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines an array of characters that shall be skipped when displaying the text.
        Floattext &setSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_Floattext_TabSize ]
        /// Adjust the tab size for a text. The tab size is measured in spaces.
        Floattext &setTabSize(const long tabSize);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// MUI copies the complete string into a private buffer.
        Floattext &setText(const std::string &text);

        // methods, some returns object reference

#ifdef MUIM_Floattext_Append
        /// @brief [ @b MUIM_Floattext_Append ]
        /// Appends the given text to the already existing text. The additional text will be copied to a private buffer.
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
        T &tagJustify(const bool justify);
#ifdef MUIA_Floattext_KeepStyles
        /// @brief [ @b MUIA_Floattext_KeepStyles ]
        T &tagKeepStyles(const bool keepStyles);
#endif
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines an array of characters that shall be skipped when displaying the text.
        T &tagSkipChars(const char *skipChars);
        /// @brief [ @b MUIA_Floattext_SkipChars ]
        /// Defines an array of characters that shall be skipped when displaying the text.
        T &tagSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_Floattext_TabSize ]
        /// Adjust the tab size for a text. The tab size is measured in spaces.
        T &tagTabSize(const long tabSize);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// MUI copies the complete string into a private buffer.
        T &tagText(const char *text);
        /// @brief [ @b MUIA_Floattext_Text ]
        /// MUI copies the complete string into a private buffer.
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
