#pragma once
#include<iostream>
using namespace std;

void printMsg() {
	cout << "hello world." << endl;
}

//type definition by using "typdef" keyword
typedef int myInt1, *myIntPtr1;
typedef void(*myFuncPtr1)();


//type definition by using "using" keyword
using myInt2 = int;
using myIntPtr2 = int*;
using myFuncPtr2 = void(*)();



myFuncPtr1 fptr1 = printMsg;
myFuncPtr2 fptr2 = printMsg;