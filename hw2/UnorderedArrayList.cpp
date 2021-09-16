#include "UnorderedArrayList.hpp"

//private member functions

//O(N)
int UnorderedArrayList::get_index(string& word){
	for(int i=0; i<capacity; i++){
		if(buf[i] == word){
			return i;
		}
	}
	return -1;
}


//public member functions

//O(1)
UnorderedArrayList::UnorderedArrayList(int max_len)
	: buf{new string[max_len]}, capacity{max_len}, size{0}
{	
}

//O(1)
void UnorderedArrayList::insert(string word){
	if(size == capacity){
		throw UnorderedListException("The UnorderedArrayList is full");
	}else{
		buf[size] = word;
		size++;
	}
}

//O(N)
bool UnorderedArrayList::find(string word){
	int index = get_index(word);
	if(index != -1){return true;}
	else{return false;}
}

//O(N)
void UnorderedArrayList::remove(string word){
	if(size == 0){
		throw UnorderedListException("The UnorderArrayList is empty");
	}

	int index = get_index(word);
	if(index == -1){
		throw UnorderedListException("The word is not in the UnorderedArrayList"); 
	}else{
		buf[index] = buf[size-1];
		size--;
	}
}

//O(N)
void UnorderedArrayList::print(ostream& out){
	out << "[";
	for(int i=0; i<size-1; i++){
		out << buf[i] << ", ";
	}
	out << buf[size-1] << "]" << endl;
}

//O(N)
UnorderedArrayList::~UnorderedArrayList(){
	delete[] buf;
}

//O(1)
bool UnorderedArrayList::isEmpty(){
	if(size == 0){
		return true;
	}else{
		return false;
	}
}

//O(1)
bool UnorderedArrayList::isFull(){
	if(size == capacity){
		return true;
	}else{
		return false;
	}
}
