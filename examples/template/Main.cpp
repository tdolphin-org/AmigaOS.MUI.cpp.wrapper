//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#include "Main.hpp"

#include <iostream>

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
        cerr << "Exception: " << e.what() << endl;
        return RETURN_FAIL;
    }
    catch (...)
    {
        cerr << "Exception(...)" << endl;
        return RETURN_FAIL;
    }

    cout << "Application finished!" << endl;

    return RETURN_OK;
}