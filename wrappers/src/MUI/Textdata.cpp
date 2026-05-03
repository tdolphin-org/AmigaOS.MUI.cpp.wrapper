//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Textdata.hpp"

#ifdef MUIC_Textdata

#include <proto/alib.h>

namespace MUI
{
    const std::string Textdata::className = MUIC_Textdata;

    TextdataBuilder::TextdataBuilder() { }

#ifdef MUIA_Textdata_Contents
    std::string Textdata::getContents() const
    {
        return GetValueAsString(MUIA_Textdata_Contents);
    }
#endif

#ifdef MUIA_Textdata_Encoding
    unsigned long Textdata::getEncoding() const
    {
        return GetValueAsULong(MUIA_Textdata_Encoding);
    }
#endif

#ifdef MUIM_Textdata_Convert
    const char *Textdata::Convert(const unsigned long encoding) const
    {
        return reinterpret_cast<const char *>(DoMethod(muiObject(), MUIM_Textdata_Convert, encoding));
    }
#endif
}

#endif
