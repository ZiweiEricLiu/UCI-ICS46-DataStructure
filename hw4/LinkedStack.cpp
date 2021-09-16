#include "LinkedStack.hpp"
#include "ContainerUnderFlow.hpp"

//O(1)
LinkedStack::LinkedStack()
	:head{nullptr}
{}

//O(N)
LinkedStack::~LinkedStack(){
	for(ListNode* temp = head; temp != nullptr; temp = head){
		head = temp->next;
		delete temp;
	}
}

//O(1)
void LinkedStack::push(string word){
	head = new ListNode(word, head);
}

//O(1)
string LinkedStack::pop(){
	if(head == nullptr){
		throw ContainerUnderFlow("pop on emptystack");
	}else{
		ListNode* temp =  head;
		string word = head->info;
		head = head->next;
		delete temp;
		return word;
	}
}

//O(1)
string LinkedStack::top(){
	if(head == nullptr){
		throw ContainerUnderFlow("top on emptystack");
	}else{
		return head->info;
	}
}

//O(1)
bool LinkedStack::isEmpty(){
	return head == nullptr;
}

//O(1)
bool LinkedStack::isFull(){
	return false;
}
