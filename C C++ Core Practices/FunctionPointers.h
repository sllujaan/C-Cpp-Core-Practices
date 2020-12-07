#pragma once

#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

class FunctionPointer {
private:

	typedef void (FunctionPointer::*callback)();
	void myFun();
	callback _callback = &FunctionPointer::myFun;
	void (FunctionPointer::*fn)() = &FunctionPointer::myFun;

	void printMsg(const char* msg);


	void subscribe(void (FunctionPointer::* fn)());
	void subscribe2(callback _callback);

public:
	FunctionPointer() {};
	void callFunc(void (*cb)());
	void init();

};