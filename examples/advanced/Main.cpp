//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2026 TDolphin
//

#include "Main.hpp"

#include "App.hpp"

#include <cstdio>

using namespace std;

int main(int argc, char **argv)
{
    std::fprintf(stderr, "%s\n", "advanced MUI application example, showing usage of 'AmigaOS MUI C++ wrapper'");

    try
    {
        App::instance().Run();
    }
    catch (const runtime_error &e)
    {
        std::fprintf(stderr, "Runtime exception: %s\n", e.what());
        return -1;
    }
    catch (const exception &e)
    {
        std::fprintf(stderr, "Exception: %s\n", e.what());
        return RETURN_FAIL;
    }
    catch (...)
    {
        std::fprintf(stderr, "%s\n", "Unknown exception (...)");
        return RETURN_FAIL;
    }

    std::fprintf(stderr, "%s\n", "Application finished!");

    return RETURN_OK;
}
