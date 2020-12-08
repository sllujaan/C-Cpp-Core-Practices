#include "directory.h"

void MyFile::Directory::readDir(wstring path)
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	wstring _path = path + L"\\*";
	//LPCWSTR _path = L"C:\\Users\\SALMAN-ALTAF\\Desktop\\testDir\\*";


	hFind = FindFirstFile(_path.c_str(), &ffd);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "FindFirstFile filed" << endl;
		return;
	}


	// List all the files in the directory with some info about them.
	do {

		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
		}


	} while (FindNextFile(hFind, &ffd) != 0);
}

MyFile::Directory::~Directory()
{

}

void MyFile::Directory::init()
{
	this->readDir(L"C:\\Users\\SALMAN-ALTAF\\Desktop\\testDir");
}
