#include "Edge.hpp"

//O(1)
Edge::Edge(int s, int d, int w)
	:src{s}, dst{d}, weight{w}
{}

//O(1)
Edge Edge::reverse(){
	int temp = src;
	src = dst;
	dst = temp;
	return *this;
}

//O(1)
void Edge::print(ostream& out){
	out << src << "->" << dst << ":" << weight;
}
