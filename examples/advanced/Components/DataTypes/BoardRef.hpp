//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include <cstring>

#define VENDOR_NAME_LEN 64
#define DEVICE_NAME_LEN 128

// board reference structure for MUI list
struct BoardRef
{
    char vendor[9 + VENDOR_NAME_LEN]; // prefix: "[0xffff] ".size()
    char device[9 + DEVICE_NAME_LEN]; // prefix: "[0xffff] ".size()

    BoardRef()
    {
        vendor[0] = 0;
        device[0] = 0;
    }

    BoardRef(const std::string &vendor, const std::string &device)
    {
        strncpy(this->vendor, vendor.c_str(), sizeof(this->vendor));
        strncpy(this->device, device.c_str(), sizeof(this->device));
    }
};
