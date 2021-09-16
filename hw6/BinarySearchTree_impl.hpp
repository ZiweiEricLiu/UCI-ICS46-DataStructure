//O(1)
template<typename KeyType, typename ElementType>
BinarySearchTree<KeyType, ElementType>::BinarySearchTree()
	:root{nullptr}
{}

//O(N)
template<typename KeyType, typename ElementType>
BinarySearchTree<KeyType, ElementType>::~BinarySearchTree(){
	TreeNode<KeyType, ElementType>::deleteTree(root);
}

//O(logN)
//T(9logN+4)
template<typename KeyType, typename ElementType>
void BinarySearchTree<KeyType, ElementType>::insert(KeyType key, ElementType info){
	root = TreeNode<KeyType, ElementType>::insert(key, info, root);
}

//O(logN)
//T(3logN+3) if key in the Tree
//T(15logN+10) if key not in the Tree
template<typename KeyType, typename ElementType>
ElementType BinarySearchTree<KeyType, ElementType>::find(KeyType key){
	TreeNode<KeyType, ElementType>* t = TreeNode<KeyType, ElementType>::find(key, root);
	if(t == nullptr){
		insert(key, ElementType());
		t = TreeNode<KeyType, ElementType>::find(key, root);
	}
	return t->getInfo();
}

//O(logN)
//recursive method no T(N)
template<typename KeyType, typename ElementType>
void BinarySearchTree<KeyType, ElementType>::remove(KeyType key){
	root = TreeNode<KeyType, ElementType>::remove(key, root);
}

//O(N)
//recursive method no T(N)
template<typename KeyType, typename ElementType>
void BinarySearchTree<KeyType, ElementType>::print(ostream& out){
	TreeNode<KeyType, ElementType>::print(out, root);
}

//O(logN)
//T(3logN+4)
template<typename KeyType, typename ElementType>
ElementType& BinarySearchTree<KeyType, ElementType>::operator[](KeyType key){
	TreeNode<KeyType, ElementType>* t = TreeNode<KeyType, ElementType>::find(key, root);
	return t->getInfoByRef();
}

//O(N)
//See TreeNode_impl.hpp for description
template<typename KeyType, typename ElementType>
int* BinarySearchTree<KeyType, ElementType>::countLengths(int* cl, int size){
	return TreeNode<KeyType, ElementType>::countLengths(root, cl, size);
}
