#include "File.h"

errno_t MY_FILES::FILE_TREE::initTreeCach()
{
	//1. iterate through all items of the tree.
	//2. find tree item level.
	//3. insert into treeCached


	//1. iterate through all items of the tree
	for (int i = 0; i < this->tree.size(); i++) {
		//2. find tree item level.
		//this->tree[i].level;

		//3. insert into treeCached
		this->addTreeCach(this->tree[i].level, this->tree[i]);
	}
	return TASK_SUCCESS;
}

errno_t MY_FILES::FILE_TREE::addTreeCach(size_t level, FILE_TREE_STRUCT& _tree)
{
	//1. find that level in cached tree and
	//   insert that item's address in cache tree at that level.
	//2. if the level is not found in cached tree
	//   create that new level in cached tree and
	//   insert that item's address in cache tree at that level.
	BOOL levelFound = FALSE;

	//if treeCached is empty
	if (this->treeCached.size() == 0) {
		this->createPushTreeCach(level, _tree);
		return TASK_SUCCESS;
	}
	
	for (int i = 0; i < this->treeCached.size(); i++) {
		//1. find that level in cached tree and
		//   insert that item's address in cache tree at that level.
		if (this->treeCached[0].CACHED_LEVEL == level) {
			this->treeCached[0].tree.push_back(&_tree);
			levelFound = TRUE;
			return TASK_SUCCESS;
		}

	}


	//2. if the level is not found in cached tree
	//   create that new level in cached tree and
	//   insert that item's address in cache tree at that level.
	if (levelFound == FALSE) {
		this->createPushTreeCach(level, _tree);
		return TASK_SUCCESS;
	}


	return TASK_SUCCESS;
}

errno_t MY_FILES::FILE_TREE::createPushTreeCach(size_t level, FILE_TREE_STRUCT& _tree)
{
	//create temporary cached tree structure
	FILE_TREE_STRUCT_CACHED treeStructTemp;
	treeStructTemp.CACHED_LEVEL = level;
	treeStructTemp.tree.push_back(&_tree);

	//push that cahed tree structure in treeCached.
	this->treeCached.push_back(treeStructTemp);

	return TASK_SUCCESS;
}

MY_FILES::FILE_TREE::FILE_TREE()
{

}

errno_t MY_FILES::FILE_TREE::addTreeItem(FILE_TREE_STRUCT treeItem)
{
	this->tree.push_back(treeItem);

	this->initTreeCach();

	return TASK_SUCCESS;
}

void MY_FILES::FILE_TREE::print()
{
	for (int i = 0; i < this->tree.size(); i++) {
		std::wcout << this->tree[i].name << "\t";
		std::wcout<< this->tree[i].type << "\t";
		std::cout << this->tree[i].level << "\t";
		std::cout << "structure address:\t" << &this->tree[i] << std::endl;
	}
}

void MY_FILES::FILE_TREE::printCashed()
{
	for (int i = 0; i < this->treeCached.size(); i++) {
		std::wcout << this->treeCached[i].tree[0]->name << "\t";
		std::cout << "structure address:\t" << this->treeCached[i].tree[0] << std::endl;
	}
}
