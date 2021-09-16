#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include "Edge.hpp"

using namespace std;

class Vertex
{
	int id;
	vector<Edge> edges;
public:
	Vertex();
	Vertex(int i);
	void add_edge(const Edge& e);
	void print(ostream& out);
	vector<Edge>& getEdges(){return edges;}
};

#endif
