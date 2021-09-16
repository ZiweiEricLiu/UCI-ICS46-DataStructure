#include "ArrayStack.hpp"
#include "ContainerOverFlow.hpp"
#include "ContainerUnderFlow.hpp"

//O(1)
ArrayStack::ArrayStack(int max_len)
	:buf{new string[max_len]}, capacity{max_len}, tp{0}
{}

//O(N)
ArrayStack::~ArrayStack(){
	delete[] buf;
}

//O(1)
void ArrayStack::push(string word){
	if(tp == capacity){
		throw ContainerOverFlow("push on fullstack");
	}else{
		buf[tp++] = word;
	}
}

//O(1)
string ArrayStack::pop(){
	if(tp == 0){
		throw ContainerUnderFlow("pop on emptystack");
	}else{
		return buf[--tp];
	}
}

//O(1)
string ArrayStack::top(){
	if(tp == 0){
		throw ContainerUnderFlow("pop on emptystack");
	}else{
		return buf[tp];
	}
}

//O(1)
bool ArrayStack::isEmpty(){
	return tp == 0;
}

//O(1)
bool ArrayStack::isFull(){
	return tp == capacity;
}
