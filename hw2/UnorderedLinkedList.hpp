#ifndef UNORDERED_LINKED_LIST_HPP
#define UNORDERED_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include "UnorderedListException.hpp"

using namespace std;

class UnorderedLinkedList
{
	struct ListNode{
		string info;
		ListNode* next;
		ListNode(string new_info, ListNode* new_next)
			:info{new_info}, next{new_next}{}
		static void print(ostream& out, ListNode* L){
			if(L){
				out << L->info << endl;
				print(out, L->next);
			}
		}
	};
	ListNode* head;

public:
	UnorderedLinkedList();
	void insert(string word);
	bool find(string word);
	void remove(string word);
	void print(ostream& out);
	~UnorderedLinkedList();
	bool isEmpty();
	bool isFull();
};

#endif
