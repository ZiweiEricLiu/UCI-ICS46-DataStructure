CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

testChainedHashTable: UnorderedLinkedList.hpp UnorderedLinkedList.cpp ChainedHashTable.hpp ChainedHashTable.cpp testHash.cpp
	echo ----------compiling testChainedHashTable--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) testHash.cpp ChainedHashTable.cpp UnorderedLinkedList.cpp -o  testHash

clean:
	echo -----------------removing executable program-----------------
	rm testHash
