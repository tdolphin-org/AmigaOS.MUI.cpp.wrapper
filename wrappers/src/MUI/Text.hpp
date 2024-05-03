//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
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

        Text(const Root &root)
          : Area(root.muiObject())
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

        /// @brief [ @b MUIA_Text_Contents ]
        std::string getContents() const;

        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        Text &setContents(const std::string &contents);

        // methods, some returns object reference

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
        /// @brief [ @b MUIA_Text_ControlChar ]
        T &tagControlChar(const char controlChar);
        /// @brief [ @b MUIA_Text_Copy ]
        /// When set to false, the contents will not be copied to a private buffer. By default is true, unless MUIA_Text_HiChar is also
        /// specified.
        T &tagCopy(const bool copy);
#ifdef MUIA_Text_Data
        /// @brief [ @b MUIA_Text_Data ]
        /// This attribute specifies the object's text wrapped in a Textdata object instead of directly as a string. This allows to set
        /// arbitrarily encoded text that will be converted to the local charset on the fly. The conversion will be done by invoking the
        /// Textdata object's MUIM_Textdata_Convert method. If this attribute is omitted or passed a NULL pointer the normal text specified
        /// via MUIA_Text_Contents will be used.
        /// By default is null.
        T &tagData(const Object *data);
#endif
        /// @brief [ @b MUIA_Text_HiChar ]
        /// If the character given here exists in the displayed string (no matter if upper or lower case), it will be underlined. This makes
        /// it easy to create macros such as KeyButton() that specify the control char and the underline char at the same time.
        T &tagHiChar(const char hiChar);
        /// @brief [ @b MUIA_Text_Marking ]
        /// This attribute controls whether it is possible to mark the object's text contents using the mouse and copy them to the clipboard
        /// By default is false.
        T &tagMarking(const bool marking);
        /// @brief [ @b MUIA_Text_PreParse ]
        /// format definitions to be parsed before the text from MUIA_Text_Contents is printed
        T &tagPreParse(const char *preParse);
        /// @brief [ @b MUIA_Text_PreParse ]
        /// format definitions to be parsed before the text from MUIA_Text_Contents is printed
        T &tagPreParse(const std::string &preParse);
        /// @brief [ @b MUIA_Text_SetMax ]
        /// Boolean value to indicate wether the objects maximal width shall be calculated to fit the string given with MUIA_Text_Contents.
        /// When set to false, maximum width is not limited.
        /// For a text object that needs to be updated (e.g. some information about your program's status) you would probably set
        /// MUIA_Text_SetMax to false to allow resizing of this object. For a label for one of your gadgets, you might want to give this tag
        /// a value of true to prevent MUI from inserting additional layout space.
        /// By default is false.
        T &tagSetMax(const bool setMax);
        /// @brief [ @b MUIA_Text_SetMin ]
        /// Boolean value to indicate wether the objects minimal width shall be calculated to fit the string given with MUIA_Text_Contents.
        /// When set to false, minimum width will be set to 0 and the displayed string may be clipped.
        /// By default is true.
        T &tagSetMin(const bool setMin);
        /// @brief [ @b MUIA_Text_SetVMax ]
        /// Settings this to false makes a TextObjects y-size unlimited.
        /// By default is true, which means the objects height is fixed.
        T &tagSetVMax(const bool setVMax);
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

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagControlChar(const char controlChar)
    {
        this->PushTag(MUIA_Text_ControlChar, controlChar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagCopy(const bool copy)
    {
        this->PushTag(MUIA_Text_Copy, copy);
        return (T &)*this;
    }

#ifdef MUIA_Text_Data
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagData(const Object *data)
    {
        this->PushTag(MUIA_Text_Data, data);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagHiChar(const char hiChar)
    {
        this->PushTag(MUIA_Text_HiChar, hiChar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagMarking(const bool marking)
    {
        this->PushTag(MUIA_Text_Marking, marking);
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

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetMax(const bool setMax)
    {
        this->PushTag(MUIA_Text_SetMax, setMax);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetMin(const bool setMin)
    {
        this->PushTag(MUIA_Text_SetMin, setMin);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetVMax(const bool setVMax)
    {
        this->PushTag(MUIA_Text_SetVMax, setVMax);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagShorten(const enum Text_Shorten shorten)
    {
        this->PushTag(MUIA_Text_Shorten, (long)shorten);
        return (T &)*this;
    }
}
