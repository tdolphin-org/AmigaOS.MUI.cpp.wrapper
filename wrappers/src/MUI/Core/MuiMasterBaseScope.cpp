//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "MuiMasterBaseScope.hpp"

#include <stdexcept>

#include <proto/exec.h>
#include <proto/muimaster.h>

struct Library *MUIMasterBase = nullptr;

MuiMasterBaseScope::MuiMasterBaseScope()
{
    if (MUIMasterBase != nullptr)
    {
        auto error = std::string { __PRETTY_FUNCTION__ } + " " + MUIMASTER_NAME + " already open!";
        throw std::runtime_error(error);
    }

    if (!(MUIMasterBase = OpenLibrary(MUIMASTER_NAME, MUIMASTER_VMIN)))
    {
        auto error = std::string { __PRETTY_FUNCTION__ } + " failed to open: " + MUIMASTER_NAME + " " + std::to_string(MUIMASTER_VMIN);
        throw std::runtime_error(error);
    }
}

MuiMasterBaseScope::~MuiMasterBaseScope()
{
    if (MUIMasterBase != nullptr)
    {
        CloseLibrary(MUIMasterBase);
        MUIMasterBase = nullptr;
    }
}
