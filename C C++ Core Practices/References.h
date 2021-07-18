#pragma once

#include<iostream>
#include<string>

#define APP_NAMESPACE_BEGIN namespace References {
#define APP_NAMESPACE_END }

APP_NAMESPACE_BEGIN

int arr[] = { 1, 2, 3, 4, 5 };

void passByRefPtr(int* arr) {
	int i = 0;
	while (arr[i] != '\0')
	{
		std::cout << arr[i] << std::endl;
		i++;
	}
}

template<size_t size>
void passByArr(int (&arr)[size]) {
	std::cout << size << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

void drawBreakLine(size_t size) {
	if ((size < 1) || (size > 200)) { std::cout << "\r\n\r\n";return; }

	std::cout << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "-";
	}
	std::cout << "\r\n\r\n";
}


APP_NAMESPACE_END