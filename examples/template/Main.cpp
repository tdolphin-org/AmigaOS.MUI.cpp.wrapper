//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#include "Main.hpp"

#include "amiga_std_light/iostream.hpp"

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
        std::cerr << "Exception: " << e.what() << "\n";
        return RETURN_FAIL;
    }
    catch (...)
    {
        std::cerr << "Exception(...)\n";
        return RETURN_FAIL;
    }

    std::cout << "Application finished!\n";

    return RETURN_OK;
}