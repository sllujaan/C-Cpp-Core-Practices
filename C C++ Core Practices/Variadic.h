#pragma once
#include<iostream>
#include <cstdarg>

void varidadicFunc(const char* fmt...) {

    va_list args;
    va_start(args, fmt);

    std::wcout << va_arg(args, wchar_t*) << std::endl;
    std::cout << va_arg(args, int) << std::endl;
    std::cout << va_arg(args, float) << std::endl;
    std::cout << va_arg(args, char*) << std::endl;
    std::wcout << va_arg(args, wchar_t*) << std::endl;
}


//call varidadicFunc as...
    //varidadicFunc("ab", L"abc", 1, 2.1, "abc", L"abc");