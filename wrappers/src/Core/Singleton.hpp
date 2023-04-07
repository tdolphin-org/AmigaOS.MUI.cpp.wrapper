//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

namespace td
{
    template <typename T> class Singleton
    {
        Singleton() {};
        Singleton(Singleton const &) = delete;
        void operator=(Singleton const &) = delete;

      public:
        static T &instance()
        {
            static T inst;
            return inst;
        };
    };
}
