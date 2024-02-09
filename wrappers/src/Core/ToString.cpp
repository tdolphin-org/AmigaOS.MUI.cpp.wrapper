//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include <iostream>
#include <numeric>
#include <sstream>
#include <type_traits>

#include "ToString.hpp"

std::string ToString::FromDataPointer(const void *value)
{
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
}

std::string ToString::FromHexValue(const unsigned long value)
{
    std::stringstream stream;
    stream << "0x" << std::hex << value;
    return stream.str();
}

std::string ToString::Concatenate(const std::vector<std::string> &array, const std::string &separator)
{
    return array.size() == 1 ? array[0]
                             : std::accumulate(array.begin(), array.end(), std::string(""),
                                               [&separator](const std::string &a, const std::string &b) { return a + " " + b; });
}

std::string ToString::Replace(std::string input, const std::string &source, const std::string &replacement)
{
    std::size_t pos = 0;
    while ((pos = input.find(source, pos)) != std::string::npos)
    {
        input.replace(pos, source.size(), replacement);
        pos += replacement.size();
    }

    return input;
}

std::string ToString::Format(std::string format, const std::string &arg0)
{
    try
    {
        return format.replace(format.find("{}"), 2, arg0);
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::vector<std::string> &args0)
{
    try
    {
        auto arg0 = args0.size() == 1 ? args0[0]
                                      : std::accumulate(args0.begin(), args0.end(), std::string(""),
                                                        [](const std::string &a, const std::string &b) { return a + " " + b; });
        return format.replace(format.find("{}"), 2, arg0);
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::string &arg0, const std::string &arg1)
{
    try
    {
        format.replace(format.find("{}"), 2, arg0);
        format.replace(format.find("{}"), 2, arg1);
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::string &arg0, const std::vector<std::string> &args1)
{
    try
    {
        format.replace(format.find("{}"), 2, arg0);
        format.replace(format.find("{}"), 2, Concatenate(args1, " "));
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::vector<std::string> &args0, const std::vector<std::string> &args1)
{
    try
    {
        format.replace(format.find("{}"), 2, Concatenate(args0, " "));
        format.replace(format.find("{}"), 2, Concatenate(args1, " "));
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::string &arg0, const std::string &arg1, const std::string &arg2)
{
    try
    {
        format.replace(format.find("{}"), 2, arg0);
        format.replace(format.find("{}"), 2, arg1);
        format.replace(format.find("{}"), 2, arg2);
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1,arg2)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::string &arg0, const std::string &arg1, const std::string &arg2,
                             const std::string &arg3)
{
    try
    {
        format.replace(format.find("{}"), 2, arg0);
        format.replace(format.find("{}"), 2, arg1);
        format.replace(format.find("{}"), 2, arg2);
        format.replace(format.find("{}"), 2, arg3);
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1,arg2,arg3)=" << format << std::endl;
        return format;
    }
}

std::string ToString::Format(std::string format, const std::string &arg0, const std::string &arg1, const std::string &arg2,
                             const std::string &arg3, const std::string &arg4)
{
    try
    {
        format.replace(format.find("{}"), 2, arg0);
        format.replace(format.find("{}"), 2, arg1);
        format.replace(format.find("{}"), 2, arg2);
        format.replace(format.find("{}"), 2, arg3);
        format.replace(format.find("{}"), 2, arg4);
        return format;
    }
    catch (...)
    {
        std::cerr << "exception on std::format(arg0,arg1,arg2,arg3,arg4)=" << format << std::endl;
        return format;
    }
}
