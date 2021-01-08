// C C++ Core Practices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include"Log.h"
#include"File/File.h"

#define CAT_NAME(X, Y) #X" "#Y

void varidadicFunc(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    std::wcout << va_arg(args, wchar_t*) << std::endl;
    std::cout << va_arg(args, int) << std::endl;
    std::cout << va_arg(args, float) << std::endl;
    std::cout << va_arg(args, char*) << std::endl;
    std::wcout << va_arg(args, wchar_t*) << std::endl;
}

int main()
{

    LPCWSTR NAMES[] = { L"abc.txt", L"abc1.txt",  L"abc2.txt",
                L"abc3.txt",  L"abc4.txt",  L"abc5.txt",  L"abc6.txt",
                L"abc7.txt",  L"abc8.txt",  L"abc9.txt", };
    
    MY_FILES::FILE_TREE _fileTree;
    MY_FILES::FILE_TREE_STRUCT treeItem = { 0 };
    
    for (size_t i = 0; i < ARRAYSIZE(NAMES); i++)
    {
        treeItem.name = NAMES[i];
        treeItem.level = 1;
        treeItem.parentName = nullptr;
        treeItem.type = "file";
        treeItem.path = L"C:\\dir";
        _fileTree.addTreeItem(treeItem);
    }

    //if(_fileTree[0]) { std::wcout << _fileTree[0]->name << std::endl; }
    if (_fileTree[0] != nullptr) { std::wcout << _fileTree[0]->name << std::endl; }

    _fileTree.addTreeItem(treeItem);
    
    LOG_ANY(
        _fileTree.print();
    );

    _fileTree.initTreeCach();
    
    LOG_ANY(
        _fileTree.printCashed();
    );


    std::vector<MY_FILES::FILE_TREE_STRUCT*>* items = _fileTree.getTreeIitemsByLevel(1);
    
    if (items == nullptr) goto END;
    LOG("\nprinting the found values...");
    for (size_t i = 0; i < items->size(); i++)
    {
        MY_FILES::FILE_TREE_STRUCT* a = items[0][i];
        std::wcout << a->name;
        std::cout << "\taddress: " << a << std::endl;
        
    }

    if (_fileTree[1] == items[0][0]) {
        std::cout << "_fileTree[0] == items[0][0]" << std::endl;
    }

END:

    varidadicFunc("ab", L"abc", 1, 2.1, "abc", L"abc");
    //std::cout << __FUNCSIG__ << std::endl;
    LOG("----Finished----");
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
