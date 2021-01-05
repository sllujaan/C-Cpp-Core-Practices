#pragma once
#include <windows.h>
#include<iostream>
#include<vector>


#include"../Log.h"




namespace MY_FILES {

	struct FILE_TREE_STRUCT {
		LPCWSTR name;
		LPCWSTR parentName;
		size_t level;
		LPCSTR type;
	};
 


	class FILE_TREE {
	private:
		std::vector<FILE_TREE_STRUCT> tree;
		//structure for caching tree items into specific levels for better retrieval or data
		struct FILE_TREE_STRUCT_CACHED {
			size_t CACHED_LEVEL;
			std::vector<FILE_TREE_STRUCT&> tree;
		};
		//instance of cached tree structure
		FILE_TREE_STRUCT_CACHED treeCached;
		//init cache
		errno_t initTreeCach();

	public:
		FILE_TREE();
		errno_t addTreeItem(FILE_TREE_STRUCT treeItem);
		void print();

	};
}