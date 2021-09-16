#include "UnorderedLinkedList.hpp"

//O(1)
UnorderedLinkedList::UnorderedLinkedList()
	:head{nullptr}
{	
}

//O(1)
void UnorderedLinkedList::insert(string word){
	if(isEmpty()){
		head = new ListNode(word, nullptr);
	}else{
		head = new ListNode(word, head);
	}
}

//O(N)
bool UnorderedLinkedList::find(string word){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->info == word){
			return true;
		}
	}
	return false;	
}

//O(N)
void UnorderedLinkedList::remove(string word){
	if(head == nullptr){
		throw UnorderedListException("The UnorderedLinkedList is empty");
	}
	if(head->info == word){
		ListNode* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	for(ListNode* prev = head; prev->next != nullptr; prev = prev->next){
		if(prev->next->info == word){
			ListNode* current = prev->next;
			prev->next = current->next;
			delete current;
			return;
		}
	}
	throw UnorderedListException("The word is not in the UnorderedLinkedList");
}

//O(N)
void UnorderedLinkedList::print(ostream& out){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->next != nullptr){
			out << temp->info << "->";
		}else{
			out << temp->info << endl;
		}
	}
}

//O(N)
UnorderedLinkedList::~UnorderedLinkedList(){
	for(ListNode* temp = head; temp != nullptr; temp = head){
		head = temp->next;
		delete temp;
	}
}

//O(1)
bool UnorderedLinkedList::isEmpty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

//O(1)
bool UnorderedLinkedList::isFull(){
	return false;
}
