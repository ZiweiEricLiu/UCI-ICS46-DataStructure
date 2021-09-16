#include "SortedLinkedList.hpp"
#include <iostream>
//O(1)
SortedLinkedList::SortedLinkedList()
	:head{nullptr}
{	
}

//O(N)
void SortedLinkedList::insert(string word){
	if(isEmpty()){
		head = new ListNode(word, nullptr);
	}else{
		for(ListNode* temp = head; temp != nullptr; temp = temp->next){
			if(word < temp->info){
				head = new ListNode(word, head);
				break;
			}else if(temp->next == nullptr || word < temp->next->info){
				temp->next = new ListNode(word, temp->next);
				break;
			}
		}
	}
}

//O(N)
bool SortedLinkedList::find(string word){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->info == word){
			return true;
		}
	}
	return false;	
}

//O(N)
void SortedLinkedList::remove(string word){
	if(head == nullptr){
		throw SortedListException("The SortedLinkedList is empty");
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
	throw SortedListException("The word is not in the SortedLinkedList");
}

//O(N)
void SortedLinkedList::print(ostream& out){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->next != nullptr){
			out << temp->info << "->";
		}else{
			out << temp->info << endl;
		}
	}
}

//O(N)
SortedLinkedList::~SortedLinkedList(){
	for(ListNode* temp = head; temp != nullptr; temp = head){
		head = temp->next;
		delete temp;
	}
}

//O(1)
bool SortedLinkedList::isEmpty(){
	if(head == nullptr){
		return true;
	}
	return false;
}

//O(1)
bool SortedLinkedList::isFull(){
	return false;
}
