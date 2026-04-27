//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Bodychunk.hpp"

#include <libraries/mui.h>
#include <proto/muimaster.h>

namespace MUI
{
    const std::string Bodychunk::className = MUIC_Bodychunk;

    BodychunkBuilder::BodychunkBuilder() { }

    unsigned char *Bodychunk::getBody() const
    {
        return static_cast<unsigned char *>(GetValueAsPtr(MUIA_Bodychunk_Body));
    }

    Bodychunk &Bodychunk::setBody(unsigned char *pBody)
    {
        SetValue(MUIA_Bodychunk_Body, pBody);
        return *this;
    }

    unsigned char Bodychunk::getCompression() const
    {
        return static_cast<unsigned char>(GetValueAsULong(MUIA_Bodychunk_Compression));
    }

    Bodychunk &Bodychunk::setCompression(const unsigned char compression)
    {
        SetValue(MUIA_Bodychunk_Compression, static_cast<unsigned long>(compression));
        return *this;
    }

    long Bodychunk::getDepth() const
    {
        return GetValueAsLong(MUIA_Bodychunk_Depth);
    }

    Bodychunk &Bodychunk::setDepth(const long depth)
    {
        SetValue(MUIA_Bodychunk_Depth, depth);
        return *this;
    }

    unsigned char Bodychunk::getMasking() const
    {
        return static_cast<unsigned char>(GetValueAsULong(MUIA_Bodychunk_Masking));
    }

    Bodychunk &Bodychunk::setMasking(const unsigned char masking)
    {
        SetValue(MUIA_Bodychunk_Masking, static_cast<unsigned long>(masking));
        return *this;
    }
}