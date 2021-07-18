#pragma once
#pragma once
#include<iostream>
#include<string>
#include<thread>

#define APP_NAMESPACE_BEGIN namespace Template2 {
#define APP_NAMESPACE_END }

APP_NAMESPACE_BEGIN


void fn(int a, int b) {
	std::cout << a + b << std::endl;
}

template<class Fn, class... Args>
void callFun(Fn&& fn, Args&&... args) {
	//fn(args...);
	std::cout << sizeof...(args) << std::endl;
}


void init()
{
	int param1 = 20, param2 = 20;
	callFun(fn, param1, param2, param1, param2);
}

APP_NAMESPACE_END