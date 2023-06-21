//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#include "Main.hpp

#include "Components/Application.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << "advanced MUI app example, created with 'AmigaOS MUI C++ wrapper'" << endl;

    MuiMasterBaseScope muiBase;

    Components::Application application;
    
    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope appScope(application);


    return 0;
}
