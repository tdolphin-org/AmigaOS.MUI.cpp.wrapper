//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "String.hpp"

namespace MUI
{
    const std::string String::className = MUIC_String;

    std::string String::getAccept() const
    {
        return GetValueAsString(MUIA_String_Accept);
    }

    const char *String::getAcceptPtr() const
    {
        return GetValueAsConstCharPtr(MUIA_String_Accept);
    }

    Optional<std::string> String::getAcceptOptional() const
    {
        const auto *accept = getAcceptPtr();
        if (accept == nullptr)
            return { };
        return std::string { accept };
    }

    String &String::setAccept(const char *accept)
    {
        SetValue(MUIA_String_Accept, StoreString(MUIA_String_Accept, accept));
        return *this;
    }

    bool String::isAcceptNull() const
    {
        return getAcceptPtr() == nullptr;
    }

    String &String::setAccept(const std::string &accept)
    {
        SetValue(MUIA_String_Accept, StoreString(MUIA_String_Accept, accept));
        return *this;
    }

    String &String::setAcceptNull()
    {
        ClearStoredString(MUIA_String_Accept);
        SetValue(MUIA_String_Accept, nullptr);
        return *this;
    }

    std::string String::getAcknowledge() const
    {
        return GetValueAsString(MUIA_String_Acknowledge);
    }

    bool String::isAdvanceOnCR() const
    {
        return GetValueAsBool(MUIA_String_AdvanceOnCR);
    }

    String &String::setAdvanceOnCR(const bool advanceOnCR)
    {
        SetValue(MUIA_String_AdvanceOnCR, advanceOnCR);
        return *this;
    }

    Object *String::getAttachedListObject() const
    {
        return GetValueAsObjectPtr(MUIA_String_AttachedList);
    }

    String &String::setAttachedList(const Object *attachedList)
    {
        SetValue(MUIA_String_AttachedList, attachedList);
        return *this;
    }

    String &String::setAttachedList(const Root &attachedList)
    {
        return setAttachedList(attachedList.muiObject());
    }

    long String::getBufferPos() const
    {
        return GetValueAsLong(MUIA_String_BufferPos);
    }

    String &String::setBufferPos(const long bufferPos)
    {
        SetValue(MUIA_String_BufferPos, bufferPos);
        return *this;
    }

    std::string String::getContents() const
    {
        return GetValueAsString(MUIA_String_Contents);
    }

    String &String::setContents(const char *contents)
    {
        SetValue(MUIA_String_Contents, StoreString(MUIA_String_Contents, contents));
        return *this;
    }

    String &String::setContents(const std::string &contents)
    {
        SetValue(MUIA_String_Contents, StoreString(MUIA_String_Contents, contents));
        return *this;
    }

    long String::getDisplayPos() const
    {
        return GetValueAsLong(MUIA_String_DisplayPos);
    }

    String &String::setDisplayPos(const long displayPos)
    {
        SetValue(MUIA_String_DisplayPos, displayPos);
        return *this;
    }

    Hook *String::getEditHook() const
    {
        return GetValueAsHookPtr(MUIA_String_EditHook);
    }

    String &String::setEditHook(const Hook *editHook)
    {
        SetValue(MUIA_String_EditHook, editHook);
        return *this;
    }

    enum String_Format String::getFormat() const
    {
        return static_cast<enum String_Format>(GetValueAsLong(MUIA_String_Format));
    }

#ifdef MUIA_String_InactiveContents
    std::string String::getInactiveContents() const
    {
        return GetValueAsString(MUIA_String_InactiveContents);
    }

    String &String::setInactiveContents(const char *inactiveContents)
    {
        SetValue(MUIA_String_InactiveContents, StoreString(MUIA_String_InactiveContents, inactiveContents));
        return *this;
    }

    String &String::setInactiveContents(const std::string &inactiveContents)
    {
        SetValue(MUIA_String_InactiveContents, StoreString(MUIA_String_InactiveContents, inactiveContents));
        return *this;
    }
#endif

    unsigned long String::getInteger() const
    {
        return GetValueAsULong(MUIA_String_Integer);
    }

    String &String::setInteger(const unsigned long integer)
    {
        SetValue(MUIA_String_Integer, integer);
        return *this;
    }

#ifdef MUIA_String_Integer64
    signed long long *String::getInteger64Ptr() const
    {
        return static_cast<signed long long *>(GetValueAsPtr(MUIA_String_Integer64));
    }

    String &String::setInteger64Ptr(signed long long *integer64Ptr)
    {
        SetValue(MUIA_String_Integer64, integer64Ptr);
        return *this;
    }
#endif

    bool String::isLonelyEditHook() const
    {
        return GetValueAsBool(MUIA_String_LonelyEditHook);
    }

    String &String::setLonelyEditHook(const bool lonelyEditHook)
    {
        SetValue(MUIA_String_LonelyEditHook, lonelyEditHook);
        return *this;
    }

    long String::getMaxLen() const
    {
        return GetValueAsLong(MUIA_String_MaxLen);
    }

#ifdef MUIA_String_Multiline
    bool String::isMultiline() const
    {
        return GetValueAsBool(MUIA_String_Multiline);
    }
#endif

#ifdef MUIA_String_Placeholder
    std::string String::getPlaceholder() const
    {
        return GetValueAsString(MUIA_String_Placeholder);
    }

    String &String::setPlaceholder(const char *placeholder)
    {
        SetValue(MUIA_String_Placeholder, StoreString(MUIA_String_Placeholder, placeholder));
        return *this;
    }

    String &String::setPlaceholder(const std::string &placeholder)
    {
        SetValue(MUIA_String_Placeholder, StoreString(MUIA_String_Placeholder, placeholder));
        return *this;
    }
#endif

    std::string String::getReject() const
    {
        return GetValueAsString(MUIA_String_Reject);
    }

    const char *String::getRejectPtr() const
    {
        return GetValueAsConstCharPtr(MUIA_String_Reject);
    }

    Optional<std::string> String::getRejectOptional() const
    {
        const auto *reject = getRejectPtr();
        if (reject == nullptr)
            return { };
        return std::string { reject };
    }

    bool String::isRejectNull() const
    {
        return getRejectPtr() == nullptr;
    }

    String &String::setReject(const std::string &reject)
    {
        SetValue(MUIA_String_Reject, StoreString(MUIA_String_Reject, reject));
        return *this;
    }

    String &String::setReject(const char *reject)
    {
        SetValue(MUIA_String_Reject, StoreString(MUIA_String_Reject, reject));
        return *this;
    }

    String &String::setRejectNull()
    {
        ClearStoredString(MUIA_String_Reject);
        SetValue(MUIA_String_Reject, nullptr);
        return *this;
    }

    bool String::isSecret() const
    {
        return GetValueAsBool(MUIA_String_Secret);
    }

#ifdef MUIA_String_Editable
    bool String::isEditable() const
    {
        return GetValueAsBool(MUIA_String_Editable);
    }

    String &String::setEditable(const bool editable)
    {
        SetValue(MUIA_String_Editable, editable);
        return *this;
    }
#endif

#ifdef MUIA_String_SpellChecking
    bool String::isSpellChecking() const
    {
        return GetValueAsBool(MUIA_String_SpellChecking);
    }

    String &String::setSpellChecking(const bool spellChecking)
    {
        SetValue(MUIA_String_SpellChecking, spellChecking);
        return *this;
    }
#endif

    String &String::Clear()
    {
        return setContents("");
    }

    StringBuilder::StringBuilder() { }
}
