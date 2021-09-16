CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

testBST: TreeNode.hpp TreeNode_impl.hpp BinarySearchTree.hpp BinarySearchTree_impl.hpp testBST.cpp
	echo ----------compiling testBST--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) testBST.cpp -o  testBST

clean:
	echo -----------------removing executable program-----------------
	rm testBST
