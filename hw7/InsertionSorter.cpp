#include "InsertionSorter.hpp"

//O(N^2)
void InsertionSorter::sort(){
	for(int i=1; i<size-1; i++){
		if(data[i] > data[i+1]){
			int j;
			for(j=i-1; j>=0; j--){
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
