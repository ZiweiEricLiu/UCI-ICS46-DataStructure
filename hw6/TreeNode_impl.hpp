//helper functions
template<typename KeyType, typename ElementType>
TreeNode<KeyType, ElementType>* TreeNode<KeyType, ElementType>::findPred(TreeNode* node){
	TreeNode<KeyType, ElementType>* t;
	for(t = node->left;t!=nullptr&&t->right!=nullptr;t=t->right);
	return t;
}

//O(1)
template<typename KeyType, typename ElementType>
TreeNode<KeyType, ElementType>::TreeNode(KeyType newKey, ElementType newInfo, TreeNode* l, TreeNode* r)
	:key{newKey}, info{newInfo}, left{l}, right{r}
{}

//O(logN)
//T(9logN+4)
//N represents the size of the Tree with the root
//method newNode has T(4)
template<typename KeyType, typename ElementType>
TreeNode<KeyType, ElementType>* TreeNode<KeyType, ElementType>::insert(KeyType key, ElementType info, TreeNode* root){
	if(!root){
		 root = newNode(key, info, nullptr, nullptr);
	}else{
		TreeNode<KeyType, ElementType>* t = root;
		while(t->key != key){
			if(key < t->key){
				if(!t->left){
					t->left = newNode(key, info, nullptr, nullptr);
				}
				t = t->left;
			}else if(key > t->key){
				if(!t->right){
					t->right = newNode(key, info, nullptr, nullptr);
				}
				t = t->right;
			}
		}
		t->info = info;
	}
	return root;
}

//O(logN)
//T(3logN+2)
template<typename KeyType, typename ElementType>
TreeNode<KeyType, ElementType>* TreeNode<KeyType, ElementType>::find(KeyType key, TreeNode* root){
	TreeNode<KeyType, ElementType>* t = root;
	while(t != nullptr){
		if(key < t->key){
			t = t->left;
		}else if(key > t->key){
			t = t->right;
		}else{
			return t;
		}
	}
	return nullptr;
}

//O(logN)
//recursive method no T(N)
template<typename KeyType, typename ElementType>
TreeNode<KeyType, ElementType>* TreeNode<KeyType, ElementType>::remove(KeyType key, TreeNode* root){
	TreeNode<KeyType, ElementType>* revNode = nullptr;
	TreeNode<KeyType, ElementType>* parentNode = nullptr;
	TreeNode<KeyType, ElementType>* t = root;
	while(t != nullptr){
		if(key < t->key){
			parentNode = t;
			t = t->left;
		}else if(key > t->key){
			parentNode = t;
			t = t->right;
		}else{
			revNode = t;
			break;
		}
	}

	if(revNode == nullptr){
		return root;
	}	

	if(revNode->left == nullptr){
		if(revNode->right == nullptr){
			if(revNode == root){
				deleteNode(revNode);
				root = nullptr;
				return root;
			}else{
				if(parentNode->left == revNode){
					parentNode->left = nullptr;
				}else{
					parentNode->right = nullptr;
				}
				deleteNode(revNode);
				return root;
			}
		}else{
			if(revNode == root){
					root = root->right;
					deleteNode(revNode);
					return root;
			}
			if(parentNode->left == revNode){
				parentNode->left = revNode->right;
			}else{
				parentNode->right = revNode->right;
			}
			deleteNode(revNode);
			return root;
		}
	}else if(revNode->right == nullptr){
		if(revNode == root){
			root = root->left;
			deleteNode(revNode);
			return root;
		}
		if(parentNode->left == revNode){
			parentNode->left = revNode->left;
		}else{
			parentNode->right = revNode->left;
		}
		deleteNode(revNode);
		return root;
	}else{
		TreeNode<KeyType, ElementType>* predNode = findPred(revNode);
		KeyType tempkey = predNode->key;
		ElementType tempInfo = predNode->info;
		remove(predNode->key, root);
		revNode->key = tempkey;
		revNode->info = tempInfo;
		return root;
	}
}

//O(N)
//recursive method no T(N)
template<typename KeyType, typename ElementType>
void TreeNode<KeyType, ElementType>::print(ostream& out, TreeNode* root){
	if(root){
		out << '[';
		print(out, root->left);
		out << '(' << root->key << ',' << root->info << ')';
		print(out, root->right);
		out << ']';
	}
	else{
		out << "nullptr";
	}
}

//O(N)
//recursize method no T(N)
template<typename KeyType, typename ElementType>
void TreeNode<KeyType, ElementType>::deleteTree(TreeNode* root){
	if(root){
		deleteTree(root->left);
		deleteTree(root->right);
		deleteNode(root);
	}
}

//O(1)
template<typename KeyType, typename ElementType>
ElementType TreeNode<KeyType, ElementType>::getInfo(){
	return info;
}

//O(1)
template<typename KeyType, typename ElementType>
ElementType& TreeNode<KeyType, ElementType>::getInfoByRef(){
	return info;
}

//O(N)
//cl will be the array with size of the largest length of the data type
//cl needs to be initialize before uesing this function
//size is the size of cl
template<typename KeyType, typename ElementType>
int* TreeNode<KeyType, ElementType>::countLengths(TreeNode<KeyType, ElementType>* t, int* cl, int size){
	if(!t){
		return cl;
	}
	cl[t->key.size()-1]++;
	countLengths(t->left, cl, size);
	countLengths(t->right, cl, size);
	return cl;	
}
