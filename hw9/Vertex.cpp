#include "Vertex.hpp"

//O(1)
Vertex::Vertex()
	:id{0}
{}

//O(1)
Vertex::Vertex(int i)
	:id{i}
{}

//O(1)
void Vertex::add_edge(const Edge& e){
	edges.push_back(e);
}

//O(N)
void Vertex::print(ostream& out){
	out << id << "{";
	for(auto e=edges.begin(); e!=edges.end()-1; e++){
		(*e).print(out);
		out << ",";
	}
	(*(edges.end()-1)).print(out);
	out << "}" << endl;
}
