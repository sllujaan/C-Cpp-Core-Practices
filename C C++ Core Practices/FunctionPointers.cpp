#include "FunctionPointers.h"

void FunctionPointer::myFun()
{
	cout << "myFun called" << endl;
}

void FunctionPointer::printMsg(const char* msg)
{
	cout << msg << endl;
}

void FunctionPointer::subscribe(void (FunctionPointer::* fn)())
{
	(this->*fn)();
}

void FunctionPointer::subscribe2(callback _callback)
{
	(this->*_callback)();
}

void FunctionPointer::callFunc(void(*cb)())
{
	for (size_t i = 0; i < 10; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		(cb)();
	}
	
}

void FunctionPointer::init()
{
	this->printMsg("hello from function pointer");
	
	this->subscribe(&FunctionPointer::myFun);
	this->subscribe2(&FunctionPointer::myFun);
}
