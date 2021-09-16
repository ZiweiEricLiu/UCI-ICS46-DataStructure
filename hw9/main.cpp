#include "Vertex.hpp"
#include "Edge.hpp"
#include "Graph.hpp"
#include <iostream>
#include "PriorityQueue.hpp"
#include <climits>
#include <vector>
#include <cstdlib>

using namespace std;

//O((|E|+|V|)log|V|)
void dijkstras(Graph& g, int src, int* dist, int* prev){
	int num_vertex = g.getNumVertex();
	Vertex* vertices = g.getVertices();
	PriorityQueue Q{num_vertex};
	for(int i=0; i<num_vertex; i++){
		int vertexID =  i;
		if(vertexID == src){
			dist[vertexID] = 0;
		}else{
			dist[vertexID] = INT_MAX;
		}
		prev[vertexID] = -1;
		Q.enqueue(vertexID, dist);
	}
	//Q.print(cout);
	while(!Q.isEmpty()){
		int u = Q.dequeue(dist);
		//Q.print(cout);
		//cout << u << endl;
		for(auto edge : vertices[u].getEdges()){
			int v = edge.getDst();
			//cout << v << endl;
			if(dist[u] != INT_MAX && dist[v] > dist[u]+edge.getWeight()){
				dist[v] = dist[u]+edge.getWeight();
				prev[v] = u;
				Q.siftUpByID(v, dist);
				//Q.print(cout);
			}
		}
	}
}

void printDijkstras(int* dist, int* prev, int size, int src){
	for(int i=0; i<size; i++){
		cout << i << " [ ";
		int j=i;
		if(j!= src && prev[j] == -1){
			cout << "NOT REACHABLE ]" << endl;
		}else{
			for(j=i; prev[j]!=-1; j=prev[j]){
				cout << j << "<-";
			}
			cout << j << " ] ( " << dist[i] << " )" << endl;
		}
	}
}

int main(int argc, char* argv[]){
	const int source = atoi(argv[1]);
	const char* input_file = argc >= 3 ? argv[2] : "small.graph.txt";
	Graph g = Graph(input_file);
	//g.print(cout);
	int size = g.getNumVertex();
	int* dist = new int[size];
	int* prev = new int[size];
	dijkstras(g, source, dist, prev);
	printDijkstras(dist, prev, size, source);
	delete[] dist;
	delete[] prev;
	return 0;
}
