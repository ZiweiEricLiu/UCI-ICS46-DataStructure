CXXFLAGS=-std=c++11 -Wpedantic -Wall -Werror -Wextra -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

all: dijkstras genGraph

dijkstras: main.cpp Vertex.hpp Vertex.cpp Edge.hpp Edge.cpp Graph.hpp Graph.cpp PriorityQueue.hpp PriorityQueue.cpp
	echo ----------compiling dijkstras--------   
	g++  -ggdb   -std=c++11 $(CXXFLAGS) main.cpp Vertex.cpp Edge.cpp Graph.cpp PriorityQueue.cpp -o  dijkstras

genGraph: genGraph.cpp
	echo ----------compiling genGraph
	g++ -ggdb -std=c++11  genGraph.cpp -o genGraph

clean:
	echo -----------------removing executable program-----------------
	rm dijkstras
	rm genGraph
