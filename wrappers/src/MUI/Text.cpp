//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Text.hpp"

namespace MUI
{
    const std::string Text::className = MUIC_Text;

    std::string Text::getContents() const
    {
        return GetValueAsString(MUIA_Text_Contents);
    }

#ifdef MUIA_Text_ControlChar
    char Text::getControlChar() const
    {
        return GetValueAsChar(MUIA_Text_ControlChar);
    }
#endif

#ifdef MUIA_Text_Copy
    bool Text::getCopy() const
    {
        return GetValueAsBool(MUIA_Text_Copy);
    }
#endif

#ifdef MUIA_Text_Data
    Object *Text::getDataObject() const
    {
        return GetValueAsObjectPtr(MUIA_Text_Data);
    }
#endif

#ifdef MUIA_Text_Marking
    bool Text::getMarking() const
    {
        return GetValueAsBool(MUIA_Text_Marking);
    }
#endif

    std::string Text::getPreParse() const
    {
        return GetValueAsString(MUIA_Text_PreParse);
    }

#ifdef MUIA_Text_Shorten
    enum Text_Shorten Text::getShorten() const
    {
        return static_cast<enum Text_Shorten>(GetValueAsLong(MUIA_Text_Shorten));
    }
#endif

#ifdef MUIA_Text_Shortened
    bool Text::getShortened() const
    {
        return GetValueAsBool(MUIA_Text_Shortened);
    }
#endif

    Text &Text::setContents(const std::string &contents)
    {
        SetValue(MUIA_Text_Contents, contents);
        return *this;
    }

#ifdef MUIA_Text_ControlChar
    Text &Text::setControlChar(const char controlChar)
    {
        SetValue(MUIA_Text_ControlChar, static_cast<unsigned long>(controlChar));
        return *this;
    }
#endif

#ifdef MUIA_Text_Copy
    Text &Text::setCopy(const bool copy)
    {
        SetValue(MUIA_Text_Copy, copy);
        return *this;
    }
#endif

#ifdef MUIA_Text_Data
    Text &Text::setData(const Object *data)
    {
        SetValue(MUIA_Text_Data, data);
        return *this;
    }
#endif

    Text &Text::setPreParse(const std::string &preParse)
    {
        SetValue(MUIA_Text_PreParse, StoreString(MUIA_Text_PreParse, preParse));
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Text &Text::setSetVMax(const bool setVMax)
    {
        SetValue(MUIA_Text_SetVMax, setVMax);
        return *this;
    }
#endif

#ifdef MUIA_Text_Shorten
    Text &Text::setShorten(const enum Text_Shorten shorten)
    {
        SetValue(MUIA_Text_Shorten, static_cast<long>(shorten));
        return *this;
    }
#endif

    Text &Text::Clear()
    {
        SetValue(MUIA_Text_Contents, nullptr);
        return *this;
    }

    TextBuilder::TextBuilder() { }
}
