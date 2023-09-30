//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <string>
#include <vector>

/// @brief collect copies of strings as char*
class StringStorage
{
    std::vector<char *> strings;

  public:
    ~StringStorage();

    const char *Add(const std::string &string);
};
