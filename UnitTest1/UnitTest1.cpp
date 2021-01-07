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
			Assert::AreEqual(treeItem.name, treeItem.name);
		}
	};
}
