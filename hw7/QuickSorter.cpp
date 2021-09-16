#include "QuickSorter.hpp"

//O(NlogN)
void QuickSorter::quicksort(int low, int high){
	if(low>=high){
		return;		
	}else if(high-low+1 < K){
		insertionsort(low, high);
	}
	else{
		string pivot = median_of_three(low, high);
		int i = partition(low, high, pivot);
		quicksort(low, i-1);
		quicksort(i+1, high);
	}
}

//O(N)
int QuickSorter::partition(int low, int high, string pivot){
	int below = low, above = high-1;
	while(1){
		while(data[below] <= pivot){++below;}
		while(pivot <= data[above]){--above;}
		if(below < above){
			swap(below, above);
		}else{
			break;
		}
	}
	swap(below, high);
	return below;
}

//O(1)
string QuickSorter::median_of_three(int low, int high){
	int mid = low + (high - low)/2;
	if(data[mid] < data[low]){
		swap(low, mid);
	}
	if(data[high] < data[low]){
		swap(low, high);
	}
	if(data[mid] < data[high]){
		swap(mid, high);
	}
	return data[high];
}

//O(N^2)
void QuickSorter::insertionsort(int low, int high){
	for(int i=low+1; i<=high; i++){
		if(data[i] > data[i+1]){
			int j;
			for(j=i-1; j>=low; j--){
				if(data[i+1] > data[j]){
					break;
				}
			}
			string temp = data[i+1];
			for(int k=i+1; k>j+1; k--){
				data[k] = data[k-1];
			}
			data[j+1] = temp;	
		}
	}
}

//O(NlogN)
void QuickSorter::sort(){
	quicksort(0, size-1);
}
