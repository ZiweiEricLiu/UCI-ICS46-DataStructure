#include "ArrayQueue.hpp"
#include "ContainerOverFlow.hpp"
#include "ContainerUnderFlow.hpp"


//O(1)
ArrayQueue::ArrayQueue(int max_len)
	:buf{new string[max_len]}, capacity{max_len}, start{0}, end{0}
{}

//O(N)
ArrayQueue::~ArrayQueue(){
	delete[] buf;
}

//O(1)
void ArrayQueue::enq(string word){
	if(start == (end+1) % capacity){
		throw ContainerOverFlow("enque on fullqueue");
	}else{
		buf[end] = word;
		end = (end+1) % capacity;
	}
}

//O(1)
string ArrayQueue::deq(){
	if(start == end){
		throw ContainerUnderFlow("deque on emptyqueue");
	}else{
		string word = buf[start];
		start = (start+1) % capacity;
		return word;
	}
}

//O(1)
string ArrayQueue::front(){
	if(start == end){
		throw ContainerUnderFlow("front on emptyqueue");
	}else{
		return buf[start];
	}
}

//O(1)
bool ArrayQueue::isEmpty(){
	return start == end;
}

//O(1)
bool ArrayQueue::isFull(){
	return start == (end+1) % capacity;
}
