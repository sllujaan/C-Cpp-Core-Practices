#pragma once
#include<iostream>
using namespace std;

/**
* oldFunction() has been deprecated use newFunction() instead.
* old function just displays a text.
* 
* some stuff ......
* function definitin goes here 
* sadfd
* dss
* dss
* dss
* ddddddddweee
*/
//__declspec(deprecated)
[[deprecated]]
void oldFunction() {
    cout << "old function" << endl;
}



/**
* new function just displays a text.
*
* some stuff ......
* function definitin goes here
* sadfd
* dss
* dss
* dss
* ddddddddweee
*/
void newFunction() {
    cout << "new function" << endl;
}