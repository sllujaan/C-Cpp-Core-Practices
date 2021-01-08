#include "pch.h"
#include "CppUnitTest.h"
#include "../C C++ Core Practices/File/File.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MY_FILES::FILE_TREE _fileTree;
			MY_FILES::FILE_TREE_STRUCT treeItem = { 0 };
			treeItem.name = L"abc.txt";
			treeItem.level = 1;
			treeItem.parentName = nullptr;
			treeItem.type = "file";
			treeItem.path = L"C:\\dir";

			_fileTree.addTreeItem(treeItem);
			Assert::AreEqual(treeItem.name, _fileTree[0]->name);
		}


		TEST_METHOD(TestMethod2)
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
				//Assert::AreEqual(treeItem.name, _fileTree[i]->name);
			}
			_fileTree.initTreeCach();
			
			std::vector<MY_FILES::FILE_TREE_STRUCT*>* items = _fileTree.getTreeIitemsByLevel(5);
			if (items == nullptr) return;
			
			for (size_t i = 0; i < items->size(); i++)
			{
				MY_FILES::FILE_TREE_STRUCT* a = items[0][i];
				std::wcout << a->name;
				std::cout << "\taddress: " << a << std::endl;
			}
			//Assert::AreEqual(treeItem.name, _fileTree[0]->name);
		}

	};
}
