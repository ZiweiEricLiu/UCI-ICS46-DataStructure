#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

using namespace std;

class Edge
{
	int src;
	int dst;
	int weight;
public:
	Edge(int s, int d, int w);
	Edge reverse();
	void print(ostream& out);
	int getSrc(){return src;}
	int getDst(){return dst;}
	int getWeight(){return weight;}
};


#endif
