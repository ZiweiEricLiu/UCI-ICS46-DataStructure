#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>
#include "Vertex.hpp"

using namespace std;

class PriorityQueue
{
	int* heap;
	int capacity;
	int size;
	void swap(int index1, int index2);
	int myLeftChild(int index);
	int myParent(int index);
	void siftUp(int index, int* dist);
	void siftDown(int index, int* dist);
public:
	PriorityQueue(int cap);
	void enqueue(int vertexID, int* dist);
	int dequeue(int* dist);
	int peek();
	bool isEmpty(){return size==0;}
	void siftUpByID(int id, int* dist);
	~PriorityQueue();
	void print(ostream& out);
};

#endif
