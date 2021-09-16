CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: UnorderedArrayList.hpp UnorderedArrayList.cpp UnorderedLinkedList.hpp UnorderedLinkedList.cpp UnorderedListException.hpp testUnorderedList.cpp
	echo ----------compiling UnorderedArrayList--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) UnorderedArrayList.cpp UnorderedLinkedList.cpp testUnorderedList.cpp  -o  testUnorderedList
clean:
	echo -----------------removing executable program-----------------
	rm testUnorderedList
