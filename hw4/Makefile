CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: test_stack test_queue isBalanced

test_stack: ArrayStack.hpp ArrayStack.cpp LinkedStack.hpp LinkedStack.cpp testStack.cpp ContainerOverFlow.hpp ContainerUnderFlow.hpp
	echo ----------compiling test_stack--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) ArrayStack.cpp LinkedStack.cpp testStack.cpp  -o  test_stack

test_queue: ArrayQueue.hpp ArrayQueue.cpp LinkedQueue.hpp LinkedQueue.cpp testQueue.cpp ContainerOverFlow.hpp ContainerUnderFlow.hpp
	echo -----------compiling test_queue--------
	g++ -ggdb    -std=c++11 $(CXXFLAGS) ArrayQueue.cpp LinkedQueue.cpp testQueue.cpp -o test_queue

isBalanced: ArrayStack.hpp ArrayStack.cpp isBalanced.cpp
	echo -----------compiling isBalanced--------
	g++ -ggdb    -std=c++11 $(CXXFLAGS) ArrayStack.cpp isBalanced.cpp -o isBalanced

clean:
	echo -----------------removing executable program-----------------
	rm test_stack
	rm test_queue
	rm isBalanced
