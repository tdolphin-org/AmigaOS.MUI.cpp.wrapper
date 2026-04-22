//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/String/Format.hpp"

#ifdef __MORPHOS__
#include <optional>
#else
#include <experimental/optional>
#endif

#undef String // undef macro from mui.h

namespace MUI
{
#ifdef __MORPHOS__
    template <typename T> using Optional = std::optional<T>;
#else
    template <typename T> using Optional = std::experimental::optional<T>;
#endif

    class String : public Area
    {
      public:
        explicit String(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        String(const Root &root)
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

        /// @brief [ @b MUIA_String_Accept ]
        /// Return the character class accepted by the string gadget.
        std::string getAccept() const;

        /// @brief [ @b MUIA_String_Accept ]
        /// Return raw accept pointer to preserve NULL semantics from MUI.
        const char *getAcceptPtr() const;

        /// @brief [ @b MUIA_String_Accept ]
        /// Return accepted character class as optional string, empty when value is NULL.
        Optional<std::string> getAcceptOptional() const;

        /// @brief [ @b MUIA_String_Accept ]
        /// Query whether accepted-character filter is set to NULL.
        bool isAcceptNull() const;

        /// @brief [ @b MUIA_String_Accept ]
        /// Set the accepted character class for text input filtering.
        String &setAccept(const std::string &accept);

        /// @brief [ @b MUIA_String_Accept, @b accept = NULL ]
        /// Pass NULL to accept all characters (default behavior).
        String &setAcceptNull();

        /// @brief [ @b MUIA_String_Acknowledge ]
        /// Return the current acknowledged contents after user confirmation.
        std::string getAcknowledge() const;

        /// @brief [ @b MUIA_String_AdvanceOnCR ]
        /// Query whether pressing Return advances focus to the next gadget.
        bool isAdvanceOnCR() const;

        /// @brief [ @b MUIA_String_AdvanceOnCR ]
        /// Control whether pressing Return advances focus to the next gadget.
        String &setAdvanceOnCR(const bool advanceOnCR);

        /// @brief [ @b MUIA_String_AttachedList ]
        /// Return the list object attached to this string gadget.
        Object *getAttachedListObject() const;

        /// @brief [ @b MUIA_String_AttachedList ]
        /// Attach a list object used for string/list interaction.
        String &setAttachedList(const Object *attachedList);

        /// @brief [ @b MUIA_String_AttachedList ]
        /// Attach a list object used for string/list interaction.
        String &setAttachedList(const Root &attachedList);

        /// @brief [ @b MUIA_String_BufferPos ]
        /// Return the current cursor position inside the edit buffer.
        long getBufferPos() const;

        /// @brief [ @b MUIA_String_BufferPos ]
        /// Set the cursor position inside the edit buffer.
        String &setBufferPos(const long bufferPos);

        /// @brief [ @b MUIA_String_Contents ]
        /// Return the current string contents.
        std::string getContents() const;

        /// @brief [ @b MUIA_String_Contents ]
        /// Set the current string contents.
        String &setContents(const std::string &contents);

        /// @brief [ @b MUIA_String_DisplayPos ]
        /// Return the first visible character position in the gadget.
        long getDisplayPos() const;

        /// @brief [ @b MUIA_String_DisplayPos ]
        /// Set the first visible character position in the gadget.
        String &setDisplayPos(const long displayPos);

        /// @brief [ @b MUIA_String_EditHook ]
        /// Return the edit hook used to validate or transform user input.
        Hook *getEditHook() const;

        /// @brief [ @b MUIA_String_EditHook ]
        /// Set an edit hook used to validate or transform user input.
        String &setEditHook(const Hook *editHook);

        /// @brief [ @b MUIA_String_Format ]
        /// Return the current text alignment format.
        enum String_Format getFormat() const;

#ifdef MUIA_String_InactiveContents
        /// @brief [ @b MUIA_String_InactiveContents ]
        /// Return the text shown while the gadget is inactive.
        std::string getInactiveContents() const;

        /// @brief [ @b MUIA_String_InactiveContents ]
        /// Set the text shown while the gadget is inactive.
        String &setInactiveContents(const std::string &inactiveContents);
#endif

        /// @brief [ @b MUIA_String_Integer ]
        /// Return the numeric value parsed from current contents.
        unsigned long getInteger() const;

        /// @brief [ @b MUIA_String_Integer ]
        /// Set the numeric value represented by the string gadget.
        String &setInteger(const unsigned long integer);

#ifdef MUIA_String_Integer64
        /// @brief [ @b MUIA_String_Integer64 ]
        /// Return pointer used for 64-bit integer exchange with this gadget.
        signed long long *getInteger64Ptr() const;

        /// @brief [ @b MUIA_String_Integer64 ]
        /// Set pointer used for 64-bit integer exchange with this gadget.
        String &setInteger64Ptr(signed long long *integer64Ptr);
#endif

        /// @brief [ @b MUIA_String_LonelyEditHook ]
        /// Query whether the edit hook is used even without an attached list.
        bool isLonelyEditHook() const;

        /// @brief [ @b MUIA_String_LonelyEditHook ]
        /// Control whether the edit hook is used even without an attached list.
        String &setLonelyEditHook(const bool lonelyEditHook);

        /// @brief [ @b MUIA_String_MaxLen ]
        /// Return maximal input length configured for this gadget.
        long getMaxLen() const;

#ifdef MUIA_String_Multiline
        /// @brief [ @b MUIA_String_Multiline ]
        /// Query whether multiline input mode is enabled.
        bool isMultiline() const;
#endif

#ifdef MUIA_String_Placeholder
        /// @brief [ @b MUIA_String_Placeholder ]
        /// Return placeholder text shown for empty input.
        std::string getPlaceholder() const;

        /// @brief [ @b MUIA_String_Placeholder ]
        /// Set placeholder text shown for empty input.
        String &setPlaceholder(const std::string &placeholder);
#endif

        /// @brief [ @b MUIA_String_Reject ]
        /// Return the character class rejected by the string gadget.
        std::string getReject() const;

        /// @brief [ @b MUIA_String_Reject ]
        /// Return raw reject pointer to preserve NULL semantics from MUI.
        const char *getRejectPtr() const;

        /// @brief [ @b MUIA_String_Reject ]
        /// Return rejected character class as optional string, empty when value is NULL.
        Optional<std::string> getRejectOptional() const;

        /// @brief [ @b MUIA_String_Reject ]
        /// Query whether rejected-character filter is set to NULL.
        bool isRejectNull() const;

        /// @brief [ @b MUIA_String_Reject ]
        /// Set the rejected character class for text input filtering.
        String &setReject(const std::string &reject);

        /// @brief [ @b MUIA_String_Reject, @b reject = NULL ]
        /// Pass NULL to reject no characters (default behavior).
        String &setRejectNull();

        /// @brief [ @b MUIA_String_Secret ]
        /// Query whether secret mode (hidden characters) is enabled.
        bool isSecret() const;

#ifdef MUIA_String_Editable
        /// @brief [ @b MUIA_String_Editable ]
        /// Query whether the gadget is editable.
        bool isEditable() const;

        /// @brief [ @b MUIA_String_Editable ]
        /// Control whether the gadget is editable.
        String &setEditable(const bool editable);
#endif

#ifdef MUIA_String_SpellChecking
        /// @brief [ @b MUIA_String_SpellChecking ]
        /// Query whether spell checking is enabled.
        bool isSpellChecking() const;

        /// @brief [ @b MUIA_String_SpellChecking ]
        /// Control whether spell checking is enabled.
        String &setSpellChecking(const bool spellChecking);
#endif

        // methods, some returns object reference

        String &Clear();
    };

    template <typename T, typename U> class StringBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        StringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_String)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_String_Accept ]
        /// Set accepted character class for text input filtering.
        T &tagAccept(const char *accept);
        /// @brief [ @b MUIA_String_Accept, @b NULL ]
        /// Pass NULL to accept all characters (default behavior).
        T &tagAcceptNull();
        /// @brief [ @b MUIA_String_Accept ]
        /// Set accepted character class for text input filtering.
        T &tagAccept(const std::string &accept);
        /// @brief [ @b MUIA_String_AdvanceOnCR ]
        /// Control whether pressing Return advances focus to the next gadget.
        T &tagAdvanceOnCR(const bool advanceOnCR);
        /// @brief [ @b MUIA_String_AttachedList ]
        /// Attach list object used for string/list interaction.
        T &tagAttachedList(const Object *attachedList);
        /// @brief [ @b MUIA_String_AttachedList ]
        /// Attach list object used for string/list interaction.
        T &tagAttachedList(const Root &attachedList);
        /// @brief [ @b MUIA_String_BufferPos ]
        /// Set initial cursor position inside the edit buffer.
        T &tagBufferPos(const long bufferPos);
        /// @brief [ @b MUIA_String_Contents ]
        /// Set initial string contents.
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_String_Contents ]
        /// Set initial string contents.
        T &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_String_DisplayPos ]
        /// Set initial first visible character position.
        T &tagDisplayPos(const long displayPos);
        /// @brief [ @b MUIA_String_EditHook ]
        /// Set edit hook used to validate or transform user input.
        T &tagEditHook(const Hook *editHook);
        /// @brief [ @b MUIA_String_Format ]
        /// Set initial text alignment format.
        T &tagFormat(const enum String_Format format);
#ifdef MUIA_String_InactiveContents
        /// @brief [ @b MUIA_String_InactiveContents ]
        /// Set text shown while gadget is inactive.
        T &tagInactiveContents(const char *inactiveContents);
        /// @brief [ @b MUIA_String_InactiveContents ]
        /// Set text shown while gadget is inactive.
        T &tagInactiveContents(const std::string &inactiveContents);
#endif
        /// @brief [ @b MUIA_String_Integer ]
        /// Set initial numeric value represented by the gadget.
        T &tagInteger(const unsigned long integer);
#ifdef MUIA_String_Integer64
        /// @brief [ @b MUIA_String_Integer64 ]
        /// Set pointer used for 64-bit integer exchange.
        T &tagInteger64Ptr(signed long long *integer64Ptr);
#endif
        /// @brief [ @b MUIA_String_LonelyEditHook ]
        /// Control edit-hook usage without attached list.
        T &tagLonelyEditHook(const bool lonelyEditHook);
        /// @brief [ @b MUIA_String_MaxLen ]
        /// Set maximal input length.
        T &tagMaxLen(const long maxLen);
#ifdef MUIA_String_Multiline
        /// @brief [ @b MUIA_String_Multiline ]
        /// Enable or disable multiline mode.
        T &tagMultiline(const bool multiline);
#endif
#ifdef MUIA_String_Placeholder
        /// @brief [ @b MUIA_String_Placeholder ]
        /// Set placeholder text shown for empty input.
        T &tagPlaceholder(const char *placeholder);
        /// @brief [ @b MUIA_String_Placeholder ]
        /// Set placeholder text shown for empty input.
        T &tagPlaceholder(const std::string &placeholder);
#endif
        /// @brief [ @b MUIA_String_Reject ]
        /// Set rejected character class for text input filtering.
        T &tagReject(const char *reject);
        /// @brief [ @b MUIA_String_Reject, @b NULL ]
        /// Pass NULL to reject no characters (default behavior).
        T &tagRejectNull();
        /// @brief [ @b MUIA_String_Reject ]
        /// Set rejected character class for text input filtering.
        T &tagReject(const std::string &reject);
        /// @brief [ @b MUIA_String_Secret ]
        /// Enable or disable secret mode (hidden characters).
        T &tagSecret(const bool secret);
#ifdef MUIA_String_Editable
        /// @brief [ @b MUIA_String_Editable ]
        /// Enable or disable editability.
        T &tagEditable(const bool editable);
#endif
#ifdef MUIA_String_SpellChecking
        /// @brief [ @b MUIA_String_SpellChecking ]
        /// Enable or disable spell checking.
        T &tagSpellChecking(const bool spellChecking);
#endif
    };

    class StringBuilder : public StringBuilderTemplate<StringBuilder, String>
    {
      public:
        StringBuilder();
    };
}

#define MUI_STRING_TPP_INCLUDE
#include "String.tpp"
#undef MUI_STRING_TPP_INCLUDE
