#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "Vertex.hpp"
#include "Edge.hpp"

class Graph
{
	Vertex* vertices;
	int num_vertex;
	int num_edge;
public:
	Graph(string file_name);
	void add_edge(int src, int dst, int w);
	void print(ostream& out);
	~Graph();
	Vertex* getVertices() const {return vertices;}
	int getNumVertex() const {return num_vertex;}
};

#endif
