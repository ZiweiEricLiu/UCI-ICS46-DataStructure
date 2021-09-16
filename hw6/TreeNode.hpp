#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <iostream>

using namespace std;

template<typename KeyType, typename ElementType>
class TreeNode
{
	KeyType key;
	ElementType info;
	TreeNode* left, *right;
	//helper methods
	static TreeNode* findPred(TreeNode* node);
	static void swapNode(TreeNode* node1, TreeNode* node2);
public:
	TreeNode(KeyType newKey, ElementType newInfo, TreeNode* l, TreeNode* r);
	static TreeNode* newNode(KeyType k, ElementType e, TreeNode* l, TreeNode* r){return new TreeNode(k,e,l,r);}
	static TreeNode* insert(KeyType key, ElementType info, TreeNode* root);
	static TreeNode* find(KeyType key, TreeNode* root);
	static TreeNode* remove(KeyType key, TreeNode* root);
	static void print(ostream& out, TreeNode* root);
	static void deleteNode(TreeNode* t){delete t;}
	static void deleteTree(TreeNode* root);
	ElementType getInfo();
	ElementType& getInfoByRef();
	static int* countLengths(TreeNode* t, int* cl, int size);
};

#include "TreeNode_impl.hpp"

#endif
