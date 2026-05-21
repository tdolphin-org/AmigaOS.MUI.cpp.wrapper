//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "DebugLog.hpp"

#include "amiga_std_light/iostream.hpp"

namespace MUI
{
    void DebugLogError(const std::string &message)
    {
        std::cerr << message << "\n";
    }

    void DebugLogInfo(const std::string &message)
    {
        std::cout << message << "\n";
    }
}
