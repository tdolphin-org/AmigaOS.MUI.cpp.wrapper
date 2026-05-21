//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2026 TDolphin
//

#include "Main.hpp"

#include "App.hpp"

#include "amiga_std_light/iostream.hpp"

using namespace std;

int main(int argc, char **argv)
{
    std::cerr << "advanced MUI application example, showing usage of 'AmigaOS MUI C++ wrapper'\n";

    try
    {
        App::instance().Run();
    }
    catch (const runtime_error &e)
    {
        std::cerr << "Runtime exception: " << e.what() << "\n";
        return -1;
    }
    catch (const exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
        return RETURN_FAIL;
    }
    catch (...)
    {
        std::cerr << "Unknown exception (...)\n";
        return RETURN_FAIL;
    }

    std::cout << "Application finished!\n";

    return RETURN_OK;
}
