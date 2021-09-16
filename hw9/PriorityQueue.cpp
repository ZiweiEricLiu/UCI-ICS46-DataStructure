#include "PriorityQueue.hpp"

//O(1)
void PriorityQueue::swap(int index1, int index2){
	int temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = temp;
}

//O(1)
int PriorityQueue::myLeftChild(int index){
	return index*2 + 1;
}

//O(1)
int PriorityQueue::myParent(int index){
	if(index == 0){
		return -1;
	}
	return index/2;
}

//O(logN)
void PriorityQueue::siftUp(int index, int* dist){
	int new_value = index;
	while(myParent(new_value) != -1){
		int parent = myParent(new_value);
		int to_swap = new_value;
		if(dist[heap[to_swap]] < dist[heap[parent]]){
			to_swap = parent;
		}
		if(to_swap == new_value){
			return;
		}else{
			swap(new_value, to_swap);
			new_value = to_swap;
		}
	}
}

//O(N)
void PriorityQueue::siftUpByID(int id, int* dist){
	for(int i=0; i<size; i++){
		if(heap[i] == id){
			siftUp(i, dist);
			return;
		}
	}
}

//O(logN)
void PriorityQueue::siftDown(int index, int* dist){
	int root = index;
	while(myLeftChild(root) < size){
		int child = myLeftChild(root);
		int to_swap = root;
		if(dist[heap[to_swap]] > dist[heap[child]]){
			to_swap = child;
		}
		if(child+1 < size && dist[heap[to_swap]] > dist[heap[child+1]]){
			to_swap = child+1;
		}
		if(to_swap == root){
			return;
		}else{
			swap(root, to_swap);
			root = to_swap;
		}
	}
}

//O(1)
PriorityQueue::PriorityQueue(int cap)
	:heap{new int[cap]}, capacity{cap}, size{0}
{}

//O(logN)
void PriorityQueue::enqueue(int vertexID, int* dist){
	heap[size] = vertexID;
	siftUp(size, dist);
	size++;
}

//O(logN)
int PriorityQueue::dequeue(int* dist){
	int to_return = heap[0];
	swap(0, size-1);
	size--;
	siftDown(0, dist);
	return to_return;
}

//O(1)
int PriorityQueue::peek(){
	return heap[0];
}

//O(N)
PriorityQueue::~PriorityQueue(){
	delete[] heap;
}

void PriorityQueue::print(ostream& out){
	for(int i=0; i<size; i++){
		out << heap[i] << " ";
	}
	out << endl;
}
