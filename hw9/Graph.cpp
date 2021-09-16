#include "Graph.hpp"

//O(N)
Graph::Graph(string file_name){
	ifstream infile(file_name);
	infile >> num_vertex;
	num_edge = 0;
	vertices =  new Vertex[num_vertex];
	for(int i=0; i<num_vertex; i++){
		vertices[i] = Vertex(i);
	}
	int s, d, w;
	while(infile >> s && infile >> d && infile >> w){
		vertices[s].add_edge(Edge(s, d, w));
		num_edge++;
	}
}

//O(1)
void Graph::add_edge(int src, int dst, int w){
	vertices[src].add_edge(Edge(src, dst, w));
	num_edge++;
}

//O(N)
void Graph::print(ostream& out){
	for(int i=0; i<num_vertex; i++){
		vertices[i].print(out);
	}	
}

//O(|V|)
Graph::~Graph(){
	delete[] vertices;
}
