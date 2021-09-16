#ifndef SORTED_LINKED_LIST_HPP
#define SORTED_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include "SortedListException.hpp"
#include "SortedList.hpp"

using namespace std;

class SortedLinkedList : public SortedList
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
	SortedLinkedList();
	virtual void insert(string word) override;
	virtual bool find(string word) override;
	virtual void remove(string word) override;
	virtual void print(ostream& out) override;
	~SortedLinkedList();
	virtual bool isEmpty() override;
	virtual bool isFull() override;
};

#endif
