//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "List.hpp"

namespace MUI
{
    class Floattext : public List
    {
      public:
        Floattext(const Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        Floattext(const APTR pMuiObject)
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

        // methods, some can return object reference

        /// @brief [ @b MUIM_Floattext_Append ]
        /// Appends the given text to the already existing text. The additional text will be copied to a private buffer.
        Floattext &Append(const std::string &text);
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

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagJustify(const bool justify)
    {
        this->PushTag(MUIA_Floattext_Justify, justify);
        return (T &)*this;
    }
#ifdef MUIA_Floattext_KeepStyles
    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagKeepStyles(const bool keepStyles)
    {
        this->PushTag(MUIA_Floattext_KeepStyles, keepStyles);
        return (T &)*this;
    }
#endif
    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagSkipChars(const char *skipChars)
    {
        this->PushTag(MUIA_Floattext_SkipChars, skipChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagSkipChars(const std::string &skipChars)
    {
        this->PushTag(MUIA_Floattext_SkipChars, skipChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagTabSize(const long tabSize)
    {
        this->PushTag(MUIA_Floattext_TabSize, tabSize);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagText(const char *text)
    {
        this->PushTag(MUIA_Floattext_Text, text);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagText(const std::string &text)
    {
        this->PushTag(MUIA_Floattext_Text, text);
        return (T &)*this;
    }
}
