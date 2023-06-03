//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <string>

namespace AOS
{
    struct Identifier
    {
      private:
        unsigned long id;

      public:
        Identifier() = delete;
        Identifier(unsigned long id);
        Identifier(const char a, const char b, const char c, const char d);
        Identifier(const char id[4]);

        unsigned long value() const
        {
            return id;
        };

        bool operator==(const Identifier &b) const
        {
            return id == b.id;
        }

        bool operator!=(const Identifier &b) const
        {
            return id != b.id;
        }

        std::string toString() const;
    };
}
