#include "UnorderedLinkedList.hpp"

//O(1)
UnorderedLinkedList::UnorderedLinkedList()
	:head{nullptr}
{	
}

//O(N)
UnorderedLinkedList::UnorderedLinkedList(const UnorderedLinkedList& ll)
	:head{nullptr}
{
	for(ListNode* temp = ll.head; temp != nullptr; temp = temp->next){
		insert(temp->key, temp->count);
	}
}

//O(N)
UnorderedLinkedList& UnorderedLinkedList::operator=(const UnorderedLinkedList& ll){
	if(this != &ll){
		for(ListNode* temp = head; temp != nullptr; temp = head){
			head = temp->next;
			delete temp;
		}
		head = nullptr;
		for(ListNode* temp = ll.head; temp != nullptr; temp = temp->next){
			insert(temp->key, temp->count);
		}
	}
	return *this;
}

//O(1)
void UnorderedLinkedList::insert(string key, int count){
	if(isEmpty()){
		head = new ListNode(key, count, nullptr);
	}else{
		head = new ListNode(key, count, head);
	}
}

//O(N)
int UnorderedLinkedList::find(string word){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->key == word){
			return temp->count;
		}
	}
	return -1;	
}

//O(N)
int& UnorderedLinkedList::findByRef(string word){
	for(ListNode* temp = head; temp != nullptr; temp = temp->next){
		if(temp->key == word){
			return temp->count;
		}
	}
	throw UnorderedListException("The Word is not in the List");
}

//O(N)
void UnorderedLinkedList::remove(string word){
	if(head == nullptr){
		throw UnorderedListException("The UnorderedLinkedList is empty");
	}
	if(head->key == word){
		ListNode* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	for(ListNode* prev = head; prev->next != nullptr; prev = prev->next){
		if(prev->next->key == word){
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
			out << temp->key << ": " << temp->count  << "->";
		}else{
			out << temp->key << ": " << temp->count  << endl;
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

//O(N)
int UnorderedLinkedList::length(){
	int len = 0;
	for(ListNode* temp = head; temp != nullptr; len++, temp = temp->next);
	return len;

}
