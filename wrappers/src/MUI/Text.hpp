//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/Text/Shorten.hpp"

namespace MUI
{
    /// @brief MUI Text class wrapper.
    /// Text class allows generating objects that contain styled text. It supports control sequences
    /// for formatting, color, style and alignment, and can handle multiline text fields.
    class Text : public Area
    {
      public:
        explicit Text(Object *pMuiObject)
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
#ifdef MUIA_Text_ControlChar
        /// @brief [ @b MUIA_Text_ControlChar ]
        /// Returns the control character that is underlined in the displayed text.
        char getControlChar() const;
#endif
#ifdef MUIA_Text_Copy
        /// @brief [ @b MUIA_Text_Copy ]
        /// Returns whether text contents are copied to a private buffer.
        bool getCopy() const;
#endif
#ifdef MUIA_Text_Data
        /// @brief [ @b MUIA_Text_Data ]
        /// Returns the Textdata object used as source text, or NULL if plain string contents are used.
        Object *getDataObject() const;
#endif
#ifdef MUIA_Text_Marking
        /// @brief [ @b MUIA_Text_Marking ]
        /// Returns whether text marking with mouse and clipboard copy is enabled.
        bool getMarking() const;
#endif
        /// @brief [ @b MUIA_Text_PreParse ]
        /// Returns format definitions parsed before MUIA_Text_Contents is printed.
        std::string getPreParse() const;
#ifdef MUIA_Text_Shorten
        /// @brief [ @b MUIA_Text_Shorten ]
        /// Returns how text shortening is configured.
        enum Text_Shorten getShorten() const;
#endif
#ifdef MUIA_Text_Shortened
        /// @brief [ @b MUIA_Text_Shortened ]
        /// Returns whether text was actually shortened to fit current layout.
        bool getShortened() const;
#endif

        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        /// Wrapper note: this setter does not store its own copy. If @b MUIA_Text_Copy is set to @b FALSE, caller must keep source text
        /// valid.
        Text &setContents(const std::string &contents);
#ifdef MUIA_Text_ControlChar
        /// @brief [ @b MUIA_Text_ControlChar ]
        /// Sets the character to underline in the displayed text.
        Text &setControlChar(const char controlChar);
#endif
#ifdef MUIA_Text_Copy
        /// @brief [ @b MUIA_Text_Copy ]
        /// Enables or disables copying contents to a private buffer.
        Text &setCopy(const bool copy);
#endif
#ifdef MUIA_Text_Data
        /// @brief [ @b MUIA_Text_Data ]
        /// Sets a Textdata object as source text. Passing NULL uses MUIA_Text_Contents.
        Text &setData(const Object *data);
#endif
        /// @brief [ @b MUIA_Text_PreParse ]
        /// Sets format definitions parsed before MUIA_Text_Contents is printed.
        Text &setPreParse(const std::string &preParse);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Text_SetVMax ]
        /// Setting this to false makes a Text object's y-size unlimited.
        Text &setSetVMax(const bool setVMax);
#endif
#ifdef MUIA_Text_Shorten
        /// @brief [ @b MUIA_Text_Shorten ]
        /// Controls whether and how MUI may shorten text to fit available space.
        Text &setShorten(const enum Text_Shorten shorten);
#endif

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
        /// Wrapper note: builder does not store its own copy. If @b MUIA_Text_Copy is set to @b FALSE, caller must keep source text valid.
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_Text_Contents ]
        /// String to be displayed. If the string is larger than available display space, it will be clipped. Setting
        /// @b MUIA_Text_Contents to @b NULL results in an empty text object. The string is copied into a private buffer (unless
        /// @b MUIA_Text_Copy is set to @b FALSE), you can destroy the original string after using this tag. Contest may contain some
        /// special character sequences defining format, color and style of the text.
        /// Wrapper note: builder does not store its own copy. If @b MUIA_Text_Copy is set to @b FALSE, caller must keep source text valid.
        T &tagContents(const std::string &contents);
#ifdef MUIA_Text_ControlChar
        /// @brief [ @b MUIA_Text_ControlChar ]
        T &tagControlChar(const char controlChar);
#endif
#ifdef MUIA_Text_Copy
        /// @brief [ @b MUIA_Text_Copy ]
        /// When set to false, the contents will not be copied to a private buffer. By default is true, unless MUIA_Text_HiChar is also
        /// specified.
        T &tagCopy(const bool copy);
#endif
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
#ifdef MUIA_Text_Marking
        /// @brief [ @b MUIA_Text_Marking ]
        /// This attribute controls whether it is possible to mark the object's text contents using the mouse and copy them to the clipboard
        /// By default is false.
        T &tagMarking(const bool marking);
#endif
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
#ifdef MUIA_Text_Shorten
        /// @brief [ @b MUIA_Text_Shorten ]
        /// controls whether MUI is allowed to shorten the text to be displayed and how this shortening process will be done
        T &tagShorten(const enum Text_Shorten shorten);
#endif
    };

    class TextBuilder : public TextBuilderTemplate<TextBuilder, Text>
    {
      public:
        TextBuilder();
    };
}

#define MUI_TEXT_TPP_INCLUDE
#include "Text.tpp"
#undef MUI_TEXT_TPP_INCLUDE
