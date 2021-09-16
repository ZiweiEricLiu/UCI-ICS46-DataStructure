CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

testSort: Sorter.hpp Sorter.cpp InsertionSorter.hpp InsertionSorter.cpp QuickSorter.hpp QuickSorter.cpp HeapSorter.hpp HeapSorter.cpp testSort.cpp
	echo ----------compiling testSort--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) testSort.cpp Sorter.cpp InsertionSorter.cpp QuickSorter.cpp HeapSorter.cpp -o  testSort

clean:
	echo -----------------removing executable program-----------------
	rm testSort
