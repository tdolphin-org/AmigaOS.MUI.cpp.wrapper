//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "CustomClassScope.hpp"

#include <stdexcept>

#include "mui.hpp"
#include <proto/alib.h>
#include <proto/muimaster.h>

#include "SDI/SDI_hook.h"

#include "amiga_std_light/iostream.hpp"

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
        std::cerr << __PRETTY_FUNCTION__ << " : " << className << "\n";
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
        std::cerr << __PRETTY_FUNCTION__ << " : " << static_cast<void *>(mpCustomClass) << "\n";
#endif
        if (mpCustomClass != nullptr)
            MUI_DeleteCustomClass(mpCustomClass);
    }

    CustomClassScope::CustomClassScope(CustomClassScope &&other) noexcept
      : mClassName(std::move(other.mClassName))
      , mpCustomClass(other.mpCustomClass)
    {
        other.mpCustomClass = nullptr;
    }

    CustomClassScope &CustomClassScope::operator=(CustomClassScope &&other) noexcept
    {
        if (this != &other)
        {
            mClassName = std::move(other.mClassName);
            mpCustomClass = other.mpCustomClass;
            other.mpCustomClass = nullptr;
        }

        return *this;
    }
}
