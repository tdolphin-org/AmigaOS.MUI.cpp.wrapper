//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Slave.hpp"

#ifdef MUIC_Slave

#include <proto/alib.h>

namespace MUI
{
    const std::string Slave::className = MUIC_Slave;

    SlaveBuilder::SlaveBuilder() { }

    Slave &Slave::Cleanup()
    {
        DoMethod(muiObject(), MUIM_Slave_Cleanup);
        return *this;
    }

    Slave &Slave::Error(Msg failedDispatch)
    {
        DoMethod(muiObject(), MUIM_Slave_Error, failedDispatch);
        return *this;
    }

    unsigned long Slave::Setup()
    {
        return DoMethod(muiObject(), MUIM_Slave_Setup);
    }

    Slave &Slave::SignalsReceived(const unsigned long sigmask)
    {
        DoMethod(muiObject(), MUIM_Slave_SignalsReceived, sigmask);
        return *this;
    }
}

#endif
