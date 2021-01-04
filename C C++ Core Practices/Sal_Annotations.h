#pragma once
#include<Windows.h>
#include<iostream>
#include<sal.h>



/*
_In_
	A parameter of which a single value will be read.
	The parameter is not allowed to be null.
*/
void InOutCallee(_Inout_ int* pInt)
{
	int i = *pInt;
	*pInt = 6;
}



void initSalNot() {

	int* pInt = NULL;
	InOutCallee(pInt); // 'pInt' should not be NULL
}