//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include <exec/types.h>
#include <map>
#include <string>

namespace AOS
{
    class TagUtil
    {
        static std::map<ULONG, std::string> mNames;

      public:
        static std::string ToString(const ULONG tagName);
    };
}