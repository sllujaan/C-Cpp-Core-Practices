// C C++ Core Practices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include"Log.h"
#include"File/File.h"


int main()
{
    
    MY_FILES::FILE_TREE _fileTree;
    MY_FILES::FILE_TREE_STRUCT treeItem = { 0 };
    treeItem.name = L"abc.txt";
    treeItem.level = 1;
    treeItem.parentName = nullptr;
    treeItem.type = "file";
    treeItem.path = L"C:\\dir";

    MY_FILES::FILE_TREE_STRUCT treeItem2 = { 0 };
    treeItem2.name = L"def.txt";
    treeItem2.level = 2;
    treeItem2.parentName = nullptr;
    treeItem2.type = "dir";
    treeItem2.path = L"C:\\dir";

    _fileTree.addTreeItem(treeItem);
    _fileTree.addTreeItem(treeItem2);

    _fileTree.addTreeItem(treeItem);
    _fileTree.addTreeItem(treeItem2);
    
    LOG_ANY(
        _fileTree.print();
    );
    _fileTree.initTreeCach();
    
    LOG_ANY(
        _fileTree.printCashed();
    );


    _fileTree.getTreeIitemsByLevel(4);

    /*int a = 10;
    int* i = nullptr;
    int& j = *i;

    std::cout << &j << std::endl;
    if (&j == nullptr) {
        LOG("j is null");
    }*/


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
