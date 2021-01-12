#pragma once

#include <windows.h>
#include<iostream>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

#include"File/File.h"
#include"Log.h"

#define NOT_DIR(X) (strcmp(X, ".") == 0) || (strcmp(X, "..") == 0)


const wchar_t* getWC(const char* c) {
	size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs_s(&cSize, wc, cSize, c, cSize);
	return wc;
}


int readDir(const char* path, unsigned int level = 1) {
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
				LOG("---------------");
				LOG(level);
				
				newPath.append("\\");
				newPath.append(ffd.cFileName);
				LOG(newPath);
				LOG("---------------");
				readDir(newPath.c_str(), level+1);
			}

		}
		else
		{

			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			LOG("_____________");
			LOG(level);
			LOG(path);
			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
			LOG("_____________");
		}
	} while (FindNextFile(hFind, &ffd) != 0);



	return 0;
}


void RefreshDirectory(LPTSTR lpDir)
{
	// This is where you might place code to refresh your
	// directory listing, but not the subtree because it
	// would not be necessary.

	_tprintf(TEXT("Directory (%s) changed.\n"), lpDir);
}

void RefreshTree(LPTSTR lpDrive)
{
	// This is where you might place code to refresh your
	// directory listing, including the subtree.

	_tprintf(TEXT("Directory tree (%s) changed.\n"), lpDrive);
}



errno_t WatchDirectory(LPCSTR lpDir) {
	DWORD dwWaitStatus;
	HANDLE dwChangeHandles[1];
	TCHAR lpDrive[4];
	TCHAR lpFile[_MAX_FNAME];
	TCHAR lpExt[_MAX_EXT];


	_tsplitpath_s(lpDir, lpDrive, 4, NULL, 0, lpFile, _MAX_FNAME, lpExt, _MAX_EXT);
	LOG(lpFile);
	LOG(lpExt);
	LOG(lpDrive);

	// Watch the directory for file creation and deletion. 

	dwChangeHandles[0] = FindFirstChangeNotification(
		lpDir,                         // directory to watch 
		FALSE,                         // do not watch subtree 
		FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME); // watch file name changes 

	if (dwChangeHandles[0] == INVALID_HANDLE_VALUE)
	{
		printf("\n ERROR: FindFirstChangeNotification function failed.\n");
		return 1;
	}

	// Watch the subtree for directory creation and deletion. 

	//dwChangeHandles[1] = FindFirstChangeNotification(
	//	lpDir,                       // directory to watch 
	//	TRUE,                          // watch the subtree 
	//	FILE_NOTIFY_CHANGE_DIR_NAME);  // watch dir name changes 

	//if (dwChangeHandles[1] == INVALID_HANDLE_VALUE)
	//{
	//	printf("\n ERROR: FindFirstChangeNotification function failed.\n");
	//	return 1;
	//}


	// Make a final validation check on our handles.

	if ((dwChangeHandles[0] == NULL)/* || (dwChangeHandles[1] == NULL)*/)
	{
		printf("\n ERROR: Unexpected NULL from FindFirstChangeNotification.\n");
		return 1;
	}

	// Change notification is set. Now wait on both notification 
// handles and refresh accordingly. 

	while (TRUE)
	{
		// Wait for notification.

		printf("\nWaiting for notification...\n");

		dwWaitStatus = WaitForMultipleObjects(1, dwChangeHandles,
			FALSE, INFINITE);

		switch (dwWaitStatus)
		{
		case WAIT_OBJECT_0:
			// A file was created, renamed, or deleted in the directory.
			// Refresh this directory and restart the notification.
			RefreshDirectory((LPTSTR)lpDir);
			if (FindNextChangeNotification(dwChangeHandles[0]) == FALSE)
			{
				printf("\n ERROR: FindNextChangeNotification function failed.\n");
				return 1;
			}
			break;

		case WAIT_OBJECT_0 + 1:
			// A directory was created, renamed, or deleted.
			// Refresh the tree and restart the notification.
			RefreshTree((LPTSTR)lpDir);
			if (FindNextChangeNotification(dwChangeHandles[1]) == FALSE)
			{
				printf("\n ERROR: FindNextChangeNotification function failed.\n");
				return 1;
			}
			break;

		case WAIT_TIMEOUT:

			// A timeout occurred, this would happen if some value other 
			// than INFINITE is used in the Wait call and no changes occur.
			// In a single-threaded environment you might not want an
			// INFINITE wait.
			printf("\nNo changes in the timeout period.\n");
			break;

		default:
			printf("\n ERROR: Unhandled dwWaitStatus.\n");
			return 1;
			break;
		}


	}




}






errno_t ReadDirChangeInfo(LPCSTR filePath) {

	HANDLE _hFile = CreateFileA(
		filePath,
		0,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_FLAG_BACKUP_SEMANTICS,
		NULL
	);

	if (_hFile == INVALID_HANDLE_VALUE) {
		std::cout << "cannot open the Directory: " << filePath << std::endl;
		return 1;
	}

	/*const int size = 10;
	void* lpBuffer[size];

	ReadDirectoryChangesW(
		_hFile,
		lpBuffer,
		size,
		true,
		,


	)*/


	return 0;
}


int readDirToTree(const char* path, MY_FILES::FILE_TREE& tree, unsigned int level = 1) {
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
				LOG("---------------");
				LOG(level);
				const wchar_t* a = getWC(path);
				//create tree items object-----------------
				MY_FILES::FILE_TREE_STRUCT treeItem = { 0 };
				treeItem.name = getWC(ffd.cFileName);
				treeItem.level = level;
				treeItem.parentName = nullptr;
				treeItem.type = "dir";
				treeItem.path = getWC(path);
				tree.addTreeItem(treeItem);
				//-------------------------------------
				newPath.append("\\");
				newPath.append(ffd.cFileName);
				LOG(newPath);
				LOG("---------------");
				//readDir(newPath.c_str(), level + 1);
				readDirToTree(newPath.c_str(), tree, level + 1);
			}

		}
		else
		{

			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			LOG("_____________");
			LOG(level);
			LOG(path);

			//create tree items object-----------------
			MY_FILES::FILE_TREE_STRUCT treeItem = { 0 };
			treeItem.name = getWC(ffd.cFileName);
			treeItem.level = level;
			treeItem.parentName = nullptr;
			treeItem.type = "file";
			treeItem.path = getWC(path);
			tree.addTreeItem(treeItem);
			//-------------------------------------

			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
			LOG("_____________");
		}
	} while (FindNextFile(hFind, &ffd) != 0);



	return 0;
}








int initListDir() {

	readDir("C:\\Users\\SALMAN-ALTAF\\Desktop\\samples");

	return 0;

}

int initListDirToTree() {

	MY_FILES::FILE_TREE _fileTree;

	readDirToTree("C:\\Users\\SALMAN-ALTAF\\Desktop\\samples", _fileTree);

	_fileTree.print();

	return 0;

}



int initDirectoryChanges() {

	//WatchDirectory("C:\\Users\\SALMAN-ALTAF\\Desktop\\testDir");
	ReadDirChangeInfo("C:\\Users\\SALMAN-ALTAF\\Desktop\\testDir");
	return 0;
}
