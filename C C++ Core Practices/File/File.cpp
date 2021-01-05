#include "File.h"

errno_t MY_FILES::FILE_TREE::initTreeCach()
{
	//1. iterate through all items of the tree
	//2. find tree item level
	//3. find that level in cached tree and insert that 
	for (int i = 0; i < this->tree.size(); i++) {

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
