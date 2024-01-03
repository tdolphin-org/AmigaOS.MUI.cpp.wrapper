//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "Main.hpp"

#include "App.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "advanced MUI application example, showing usage of 'AmigaOS MUI C++ wrapper'" << endl;

    try
    {
        App::instance().Run();
    }
    catch (const runtime_error &e)
    {
        cerr << "Runtime exception: " << e.what() << endl;
        return -1;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
        return RETURN_FAIL;
    }
    catch (...)
    {
        cerr << "Unknown exception (...)" << endl;
        return RETURN_FAIL;
    }

    std::cout << "Application finished!" << std::endl;

    return RETURN_OK;
}
