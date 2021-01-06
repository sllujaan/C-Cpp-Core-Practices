#include "File.h"


BOOL MY_FILES::operator == (FILE_TREE_STRUCT& str, std::nullptr_t nullStruct) {
	if (str.name == nullptr) return TRUE;
	if (str.type == nullptr) return TRUE;
	if (str.level < 1) return TRUE;
	if (str.path == nullptr) return TRUE;

	return FALSE;

}

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
	//1. find the level in cached tree.
	
	//2. find if the name of item already exists at that level in cached tree. if not
	//   insert that item's address in cache tree at that level.

	//3. if the level is not found in cached tree
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
		if (this->treeCached[i].CACHED_LEVEL == level) {
			//2. find if the name of item already exists at that level in cached tree. if not
			//   insert that item's address in cache tree at that level.

			if (!this->isItemExists(treeCached[i].tree, _tree.name)) {
				this->treeCached[i].tree.push_back(&_tree);
			}
			else {
				std::cout << "item already exists in cache at level: " << level << std::endl;
			}

			//this->treeCached[0].tree.push_back(&_tree);
			levelFound = TRUE;
			return TASK_SUCCESS;
		}

	}


	//3. if the level is not found in cached tree
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

BOOL MY_FILES::FILE_TREE::isItemExists(std::vector<FILE_TREE_STRUCT*>& tree, LPCWSTR name)
{

	for (int i = 0; i < tree.size(); i++) {
		if (wcscmp(tree[i]->name, name) == 0) return TRUE;
	}

	return FALSE;
}

MY_FILES::FILE_TREE::FILE_TREE()
{

}

errno_t MY_FILES::FILE_TREE::addTreeItem(FILE_TREE_STRUCT treeItem)
{
	if(treeItem == NULL) {
		std::cout << "treeItem was invalid or NULL" << std::endl;
		return TASK_FAILURE;
	}

	this->tree.push_back(treeItem);

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
		std::cout << "printing cashed level: \t";
		std::wcout << this->treeCached[i].CACHED_LEVEL << std::endl;

		for (size_t j = 0; j < this->treeCached[i].tree.size(); j++)
		{
			//std::wcout << this->treeCached[i].tree[j]->name << std::endl;
			std::cout << "structure address:\t" << this->treeCached[i].tree[j] << std::endl;
		}

		/*std::wcout << this->treeCached[i].tree[0]->level << "\t";
		std::cout << "structure address:\t" << this->treeCached[i].tree[0] << std::endl;*/
	}
}
