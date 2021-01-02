#pragma once

#include <windows.h>
#include<iostream>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

#define NOT_DIR(X) (strcmp(X, ".") == 0) || (strcmp(X, "..") == 0)


int readDir(const char* path) {
	std::string newPath = path;
	newPath += +"\\*";

	//newPath.c_str();
	/*newPath.c_str();
	char arr[3];
	const char* cPtr = "ab";
	strcpy_s<3>(arr, cPtr);*/

	

	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	strcpy_s<MAX_PATH>(szDir, newPath.c_str());
	HANDLE hFind = INVALID_HANDLE_VALUE;



	// Find the first file in the directory.
	hFind = FindFirstFile(szDir, &ffd);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		std::cout << "FindFirstFile failed" << std::endl;
		return 1;
	}


	// List all the files in the directory with some info about them.


	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			LOG_ANY(_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName));
			//_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
			
			if (NOT_DIR(ffd.cFileName)) {
				LOG("Not Directory");
			}
			else {
				newPath = path;
				newPath.append("\\");
				newPath.append(ffd.cFileName);
				LOG(newPath);
				readDir(newPath.c_str());
			}

		}
		else
		{

			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			
			LOG(path);
			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
		}
	} while (FindNextFile(hFind, &ffd) != 0);



	return 0;
}





int initListDir() {

	readDir("C:\\Users\\SALMAN-ALTAF\\Desktop\\samples");

	return 0;

}
