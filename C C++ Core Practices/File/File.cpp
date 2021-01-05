#include "File.h"

errno_t MY_FILES::FILE_TREE::initTreeCach()
{
	//1. iterate through all items of the tree.
	//2. find tree item level.
	//3. find that level in cached tree and
	//   insert that item's address in cache tree at that level.
	//4. if the level is not found in cached tree
	//   create that new level in cached tree and
	//   insert that item's address in cache tree at that level.


	//1. iterate through all items of the tree
	for (int i = 0; i < this->tree.size(); i++) {
		//2. find tree item level.
		this->tree[i].level;
	}
	return TASK_SUCCESS;
}

errno_t MY_FILES::FILE_TREE::addTreeCach(size_t level, FILE_TREE_STRUCT& _tree)
{

	if (this->treeCached.size() == 0) {
		FILE_TREE_STRUCT_CACHED treeStructTemp;
		treeStructTemp.CACHED_LEVEL = level;
		treeStructTemp.tree.push_back(_tree);
		this->treeCached.push_back(treeStructTemp);
	}
	
	for (int i = 0; i < this->treeCached.size(); i++) {

	}

	return TASK_SUCCESS;
}

MY_FILES::FILE_TREE::FILE_TREE()
{

}

errno_t MY_FILES::FILE_TREE::addTreeItem(FILE_TREE_STRUCT treeItem)
{
	this->tree.push_back(treeItem);

	return TASK_SUCCESS;
}

void MY_FILES::FILE_TREE::print()
{
	for (int i = 0; i < this->tree.size(); i++) {
		std::wcout << this->tree[i].name << "\t";
		std::wcout<< this->tree[i].type << "\t";
		std::cout << this->tree[i].level << std::endl;
	}
}
