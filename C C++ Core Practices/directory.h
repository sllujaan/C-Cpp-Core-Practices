#pragma once
#include<Windows.h>
#include<iostream>
#include<string>
#include<filesystem>
#include<vector>
#include<strsafe.h>
#include <tchar.h> 
#include <stdio.h>

using namespace std;


namespace MyFile {
	class Directory {
	private:
		vector<int> _vector;

		void readDir(wstring path);

	public:
		Directory() {};
		~Directory();
		void init();
	};
}
