#include "SortedArrayList.hpp"

using namespace std;
//private member functions

//O(logN)
int SortedArrayList::get_index(string& word){
	int mid;
	for(int start=0, end=size-1; start<=end;){
		mid = start+(end-start)/2;
		if(word < buf[mid]){
			start = mid + 1;
		}else if(buf[mid] < word){
			end = mid - 1;
		}else{
			return mid;
		}
	}
	return -1;
}

//O(N)
void SortedArrayList::copy_up(int index){
	for(int i=index; i<size-1; i++){
		buf[i] = buf[i+1];
	}
}

//O(N)
void SortedArrayList::copy_down(int index){
	for(int i=size-1; i>=index; i--){
		buf[i+1] = buf[i]; 
	}
}

//public member functions

//O(1)
SortedArrayList::SortedArrayList(int max_len)
	: buf{new string[max_len]}, capacity{max_len}, size{0}
{	
}

//O(N)
void SortedArrayList::insert(string word){
	if(size == capacity){
		throw SortedListException("The SortedArrayList is full");
	}else if(size == 0){
		buf[0] = word;
		size++;
	}else{
		int i;
		for(i=0; word<=buf[i]; i++);
		copy_down(i);
		buf[i] = word;
		size++;	
	}
}

//O(logN)
bool SortedArrayList::find(string word){
	int index = get_index(word);
	if(index != -1){return true;}
	else{return false;}
}

//O(N*logN)
void SortedArrayList::remove(string word){
	if(size == 0){
		throw SortedListException("The SortedArrayList is empty");
	}
	int index = get_index(word);
	if(index == -1){
		throw SortedListException("The word is not in the SortedArrayList"); 
	}else{
		copy_up(index);
		size--;
	}
}

//O(N)
void SortedArrayList::print(ostream& out){
	out << "[";
	for(int i=0; i<size-1; i++){
		out << buf[i] << ", ";
	}
	out << buf[size-1] << "]" << endl;
}

//O(N)
SortedArrayList::~SortedArrayList(){
	delete[] buf;
}

//O(1)
bool SortedArrayList::isEmpty(){
	if(size == 0){
		return true;
	}else{
		return false;
	}
}

//O(1)
bool SortedArrayList::isFull(){
	if(size == capacity){
		return true;
	}else{
		return false;
	}
}
