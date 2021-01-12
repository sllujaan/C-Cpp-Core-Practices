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


		TEST_METHOD(Test_cachedMemoryLocations)
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
			
			std::vector<MY_FILES::FILE_TREE_STRUCT*>* cachedItems = _fileTree.getTreeIitemsByLevel(1);
			if (cachedItems == nullptr) {
				Assert::IsTrue(false);
			}

			Assert::IsTrue(_fileTree[0] == cachedItems[0][0]);
			Assert::IsTrue(_fileTree[1] == cachedItems[0][1]);
			Assert::IsTrue(_fileTree[2] == cachedItems[0][2]);
			Assert::IsTrue(_fileTree[3] == cachedItems[0][3]);
			Assert::IsTrue(_fileTree[4] == cachedItems[0][4]);
			Assert::IsTrue(_fileTree[5] == cachedItems[0][5]);
			Assert::IsTrue(_fileTree[6] == cachedItems[0][6]);
			Assert::IsTrue(_fileTree[7] == cachedItems[0][7]);
			Assert::IsTrue(_fileTree[8] == cachedItems[0][8]);
			Assert::IsTrue(_fileTree[9] == cachedItems[0][9]);
		}

	};
}
