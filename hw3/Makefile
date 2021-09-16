CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: SortedArrayList.hpp SortedArrayList.cpp SortedLinkedList.hpp SortedLinkedList.cpp SortedListException.hpp testSortedList.cpp
	echo ----------compiling UnorderedArrayList--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) SortedArrayList.cpp SortedLinkedList.cpp testSortedList.cpp  -o  testSortedList
clean:
	echo -----------------removing executable program-----------------
	rm testSortedList
