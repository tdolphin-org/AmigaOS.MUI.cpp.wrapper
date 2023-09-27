//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Identifier.hpp"

#include <libraries/iffparse.h>

namespace AOS
{

    Identifier::Identifier(unsigned long id)
      : id(id)
    {
    }

    Identifier::Identifier(const char a, const char b, const char c, const char d)
      : id(MAKE_ID(a, b, c, d))
    {
    }

    Identifier::Identifier(const char id[4])
      : id(MAKE_ID(id[0], id[1], id[2], id[3]))
    {
    }

    std::string Identifier::toString() const
    {
        return std::string({ (char)(id >> 24 & 0xFF), (char)(id >> 16 & 0xFF), (char)(id >> 8 & 0xFF), (char)(id & 0xFF), 0 });
    }
}
