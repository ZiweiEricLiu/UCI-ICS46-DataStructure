#include "HeapSorter.hpp"

//O(NlogN)
void HeapSorter::heapSort(int N){
	heapify(N);
	for(int end = N-1; end > 0; --end){
		swap(0, end);
		siftSmallestDown(0, end-1);
	}
}

//O(NlogN)
void HeapSorter::heapify(int N){
	for(int start = N/2; start >= 0; --start){
		siftSmallestDown(start, N-1);
	}
}

//O(logN)
void HeapSorter::siftSmallestDown(int start, int end){
	int root = start;
	while(myLeftChild(root) <= end){
		int child = myLeftChild(root);
		int to_swap = root;
		if(data[to_swap] < data[child]){
			to_swap = child;
		}
		if(child+1 <= end && data[to_swap] < data[child+1]){
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
int HeapSorter::myLeftChild(int index){
	return 2*index + 1;
}

//O(NlogN)
void HeapSorter::sort(){
	heapSort(size);
}
