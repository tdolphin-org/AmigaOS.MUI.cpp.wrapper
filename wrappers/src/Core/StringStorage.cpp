//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "StringStorage.hpp"

#include <cstring>

StringStorage::~StringStorage()
{
    for (auto pString : strings)
        delete[] pString;
}

const char *StringStorage::Add(const std::string &string)
{
    auto pString = new char[string.size() + 1];
    std::memcpy(pString, string.c_str(), string.size() + 1);
    strings.push_back(pString);
    return pString;
}
