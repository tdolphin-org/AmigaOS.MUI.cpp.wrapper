//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#include "Main.hpp"

#include <cstdio>

#include "App.hpp"

using namespace std;

int main(int argc, char **argv)
{
    try
    {
        App::instance().Run();
    }
    catch (exception &e)
    {
        std::fprintf(stderr, "Exception: %s\n", e.what());
        return RETURN_FAIL;
    }
    catch (...)
    {
        std::fprintf(stderr, "%s\n", "Exception(...)");
        return RETURN_FAIL;
    }

    std::fprintf(stderr, "%s\n", "Application finished!");

    return RETURN_OK;
}