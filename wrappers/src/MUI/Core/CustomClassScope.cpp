//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "CustomClassScope.hpp"

#include <iostream>
#include <stdexcept>

#include <proto/alib.h>
#include <proto/muimaster.h>

#include "SDI/SDI_hook.h"

DISPATCHER(Empty_Dispatcher)
{
    return DoSuperMethodA(cl, obj, msg);
}

namespace MUI
{
    CustomClassScope::CustomClassScope(const std::string &className, const unsigned long dataSize, const void *dispatcher)
      : mClassName(className)
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << " : " << className << std::endl;
#endif

        mpCustomClass = MUI_CreateCustomClass(nullptr, (char *)className.c_str(), nullptr, dataSize,
                                              dispatcher ? (APTR)dispatcher : ENTRY(Empty_Dispatcher)); // nullptr
        if (mpCustomClass == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " MUI_CreateCustomClass(" + className + ") failed!";
            throw std::runtime_error(error);
        }
    }

    CustomClassScope::~CustomClassScope()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << " : " << mpCustomClass << std::endl;
#endif
        if (mpCustomClass != nullptr)
            MUI_DeleteCustomClass(mpCustomClass);
    }
}
