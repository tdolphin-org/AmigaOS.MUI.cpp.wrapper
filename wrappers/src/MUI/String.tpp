//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_STRING_TPP_INCLUDE
#error "String.tpp should only be included by String.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAccept(const char *accept)
    {
        if (accept == nullptr)
            this->PushTag(MUIA_String_Accept, accept);
        else
            this->PushTag(MUIA_String_Accept, this->StoreString(MUIA_String_Accept, accept));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAcceptNull()
    {
        this->PushTag(MUIA_String_Accept, nullptr);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAccept(const std::string &accept)
    {
        auto copy = this->StoreString(MUIA_String_Accept, accept);
        this->PushTag(MUIA_String_Accept, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAdvanceOnCR(const bool advanceOnCR)
    {
        this->PushTag(MUIA_String_AdvanceOnCR, advanceOnCR);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAttachedList(const Object *attachedList)
    {
        this->PushTag(MUIA_String_AttachedList, attachedList);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagAttachedList(const Root &attachedList)
    {
        return tagAttachedList(attachedList.muiObject());
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        if (contents == nullptr)
            this->PushTag(MUIA_String_Contents, contents);
        else
            this->PushTag(MUIA_String_Contents, this->StoreString(MUIA_String_Contents, contents));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        auto copy = this->StoreString(MUIA_String_Contents, contents);
        this->PushTag(MUIA_String_Contents, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagEditHook(const Hook *editHook)
    {
        this->PushTag(MUIA_String_EditHook, editHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagFormat(const enum String_Format format)
    {
        this->PushTag(MUIA_String_Format, (long)format);
        return (T &)*this;
    }

#ifdef MUIA_String_InactiveContents
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagInactiveContents(const char *inactiveContents)
    {
        if (inactiveContents == nullptr)
            this->PushTag(MUIA_String_InactiveContents, inactiveContents);
        else
            this->PushTag(MUIA_String_InactiveContents, this->StoreString(MUIA_String_InactiveContents, inactiveContents));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagInactiveContents(const std::string &inactiveContents)
    {
        auto copy = this->StoreString(MUIA_String_InactiveContents, inactiveContents);
        this->PushTag(MUIA_String_InactiveContents, copy);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagInteger(const unsigned long integer)
    {
        this->PushTag(MUIA_String_Integer, integer);
        return (T &)*this;
    }

#ifdef MUIA_String_Integer64
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagInteger64Ptr(signed long long *integer64Ptr)
    {
        this->PushTag(MUIA_String_Integer64, integer64Ptr);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagLonelyEditHook(const bool lonelyEditHook)
    {
        this->PushTag(MUIA_String_LonelyEditHook, lonelyEditHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMaxLen(const long maxLen)
    {
        this->PushTag(MUIA_String_MaxLen, maxLen);
        return (T &)*this;
    }

#ifdef MUIA_String_Multiline
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMultiline(const bool multiline)
    {
        this->PushTag(MUIA_String_Multiline, multiline);
        return (T &)*this;
    }
#endif

#ifdef MUIA_String_Placeholder
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagPlaceholder(const char *placeholder)
    {
        if (placeholder == nullptr)
            this->PushTag(MUIA_String_Placeholder, placeholder);
        else
            this->PushTag(MUIA_String_Placeholder, this->StoreString(MUIA_String_Placeholder, placeholder));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagPlaceholder(const std::string &placeholder)
    {
        auto copy = this->StoreString(MUIA_String_Placeholder, placeholder);
        this->PushTag(MUIA_String_Placeholder, copy);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagReject(const char *reject)
    {
        if (reject == nullptr)
            this->PushTag(MUIA_String_Reject, reject);
        else
            this->PushTag(MUIA_String_Reject, this->StoreString(MUIA_String_Reject, reject));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagRejectNull()
    {
        this->PushTag(MUIA_String_Reject, nullptr);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagReject(const std::string &reject)
    {
        auto copy = this->StoreString(MUIA_String_Reject, reject);
        this->PushTag(MUIA_String_Reject, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagSecret(const bool secret)
    {
        this->PushTag(MUIA_String_Secret, secret);
        return (T &)*this;
    }

#ifdef MUIA_String_Editable
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagEditable(const bool editable)
    {
        this->PushTag(MUIA_String_Editable, editable);
        return (T &)*this;
    }
#endif

#ifdef MUIA_String_SpellChecking
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagSpellChecking(const bool spellChecking)
    {
        this->PushTag(MUIA_String_SpellChecking, spellChecking);
        return (T &)*this;
    }
#endif
}
