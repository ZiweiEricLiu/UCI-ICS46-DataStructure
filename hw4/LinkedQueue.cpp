#include "LinkedQueue.hpp"
#include "ContainerUnderFlow.hpp"

//O(1)
LinkedQueue::LinkedQueue()
	:head{nullptr}, tail{nullptr}
{}

//O(N)
LinkedQueue::~LinkedQueue(){
	for(ListNode* temp = head; temp != nullptr; temp = head){
		head = temp->next;
		delete temp;
	}
	tail = nullptr;
}

//O(1)
void LinkedQueue::enq(string word){
	ListNode* newNode = new ListNode(word, nullptr);
	if(!tail){
		head = newNode;
	}else{
		tail->next = newNode;
	}
	tail = newNode;
}

//O(1)
string LinkedQueue::deq(){
	if(head == nullptr){
		throw ContainerUnderFlow("deque on emptyqueue");
	}else{
		ListNode* temp = head;
		string word = head->info;
		head = head->next;
		delete temp;
		if(!head){
			tail = nullptr;
		}
		return word;
	}
}

//O(1)
string LinkedQueue::front(){
	if(head == nullptr){
		throw ContainerUnderFlow("front on emptyqueue");
	}else{
		return head->info;
	}
}

//O(1)
bool LinkedQueue::isEmpty(){
	return head == nullptr;
}

//O(1)
bool LinkedQueue::isFull(){
	return false;
}
