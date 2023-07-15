//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/Text/Shorten.hpp"

namespace MUI
{
    class Text : public Area
    {
      public:
        Text(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Text(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Text_Contents ]
        std::string getContents() const;

        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        Text &setContents(const std::string &contents);

        // methods, some can return object reference

        Text &Clear();
    };

    template <typename T, typename U> class TextBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        TextBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Text)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        T &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_Text_PreParse ]
        /// format definitions to be parsed before the text from MUIA_Text_Contents is printed
        T &tagPreParse(const char *preParse);
        /// @brief [ @b MUIA_Text_PreParse ]
        /// format definitions to be parsed before the text from MUIA_Text_Contents is printed
        T &tagPreParse(const std::string &preParse);
        /// @brief [ @b MUIA_Text_Shorten ]
        /// controls whether MUI is allowed to shorten the text to be displayed and how this shortening process will be done
        T &tagShorten(const enum Text_Shorten shorten);
    };

    class TextBuilder : public TextBuilderTemplate<TextBuilder, Text>
    {
      public:
        TextBuilder();
    };

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        this->PushTag(MUIA_Text_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        this->PushTag(MUIA_Text_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagPreParse(const char *preParse)
    {
        this->PushTag(MUIA_Text_PreParse, preParse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagPreParse(const std::string &preParse)
    {
        this->PushTag(MUIA_Text_PreParse, preParse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagShorten(const enum Text_Shorten shorten)
    {
        this->PushTag(MUIA_Text_Shorten, (long)shorten);
        return (T &)*this;
    }
}
