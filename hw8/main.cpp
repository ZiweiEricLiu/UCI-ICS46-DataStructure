#include "Vertex.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include <iostream>
#include "Set.hpp"
#include <queue>
#include <vector>

using namespace std;

bool operator<(Edge le, Edge re){return le.getWeight() > re.getWeight();}

//O(|V|log|E|)
void kruskals(const Graph& g){
	int total_weights = 0;
	int num_vertex = g.getNumVertex();
	Vertex* vertices = g.getVertices();
	priority_queue<Edge> pqEdge;
	Set set(num_vertex);
	make_all_sets(set, num_vertex);
	for(int i=0; i<num_vertex; i++){
		vector<Edge> edges =  vertices[i].getEdges();
		for(auto e : edges){
			pqEdge.push(e);
		}
	}
	while(!pqEdge.empty()){
		Edge e = pqEdge.top();
		pqEdge.pop();
		int u = e.getSrc();
		int v = e.getDst();
		if(set.Find(u) != set.Find(v)){
			cout << "[ " << u << "-" << v << " ]" << "( " << e.getWeight() << " )" << endl;
			total_weights += e.getWeight();
			set.Union(u, v);
		}
	}
	cout << "Total Weights: " << total_weights << endl;
	delete[] set.elements;
}

int main(int argc, char* argv[]){
	const char* input_file = argc >= 2 ? argv[1] : "small.graph.txt";
	Graph g = Graph(input_file);
	kruskals(g);
	return 0;
}
