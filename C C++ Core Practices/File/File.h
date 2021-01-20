#pragma once
#include"pch.h"

#include"Log.h"


#ifndef NOT_DIR
#define NOT_DIR(X) (strcmp(X, ".") == 0) || (strcmp(X, "..") == 0)
#endif

#define FTSPTR std::vector<MY_FILES::FILE_TREE_STRUCT*>*

const wchar_t* getWC(const char* c);


namespace  MY_FILES {

	struct FILE_TREE_STRUCT {
		LPCWSTR name;
		LPCWSTR parentName;
		size_t level;
		LPCSTR type;
		LPCWSTR path;

		 operator bool();
		 BOOL operator == (std::nullptr_t nullStruct);
		 BOOL operator != (std::nullptr_t nullStruct);
	};

	
	/*BOOL operator == (FILE_TREE_STRUCT& str1, std::nullptr_t nullStruct);
	BOOL operator != (FILE_TREE_STRUCT& str1, std::nullptr_t nullStruct);*/

	class  FILE_TREE {
	private:
		std::vector<FILE_TREE_STRUCT> tree;
		//structure for caching tree items into specific levels for better retrieval or data
		struct FILE_TREE_STRUCT_CACHED {
			size_t CACHED_LEVEL;
			std::vector<FILE_TREE_STRUCT*> tree;
		};
		//instance of cached tree structure
		std::vector<FILE_TREE_STRUCT_CACHED> treeCached;

		//file tree
		static MY_FILES::FILE_TREE _fileTree;
		
		errno_t addTreeCach(size_t level, FILE_TREE_STRUCT& _tree);
		errno_t createPushTreeCach(size_t level, FILE_TREE_STRUCT& _tree);
		BOOL isItemExists(std::vector<FILE_TREE_STRUCT*>& tree, LPCWSTR name);

	public:
		FILE_TREE();
		errno_t addTreeItem(FILE_TREE_STRUCT treeItem);
		//init cache
		errno_t initTreeCach();
		FTSPTR getTreeIitemsByLevel(size_t level);
		//errno_t readDirToTree(const char* path, MY_FILES::FILE_TREE& tree = _fileTree, unsigned int level = 1);

		static void sample(static FILE_TREE& tree = FILE_TREE::_fileTree);

		FILE_TREE_STRUCT* operator[] (size_t);


		errno_t getFileNameFromPath(LPCWSTR path, LPCWSTR* destination);

		size_t getArrayCount(WCHAR arr[]);
		
		void print();
		void printCashed();

	};
}
