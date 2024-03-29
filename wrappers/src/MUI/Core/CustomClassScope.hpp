//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <string>

#include <libraries/mui.h>

namespace MUI
{
    class CustomClassScope
    {
        const std::string mClassName;
        struct MUI_CustomClass *mpCustomClass;

      public:
        CustomClassScope(const std::string &className, const unsigned long dataSize = 0, const void *dispatcher = nullptr);
        ~CustomClassScope();

        struct MUI_CustomClass *mcc() const
        {
            return mpCustomClass;
        }

        const std::string &className() const
        {
            return mClassName;
        }
    };
};
