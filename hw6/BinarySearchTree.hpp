#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEATCH_TREE_HPP

#include <iostream>
#include "TreeNode.hpp"

using namespace std;

template<typename KeyType, typename ElementType>
class BinarySearchTree
{
	TreeNode<KeyType, ElementType>* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(KeyType key, ElementType info);
	ElementType find(KeyType key);
	void remove(KeyType key);
	void print(ostream& out);
	ElementType& operator[](KeyType key);
	int* countLengths(int* cl, int size);
};

#include "BinarySearchTree_impl.hpp"

#endif
