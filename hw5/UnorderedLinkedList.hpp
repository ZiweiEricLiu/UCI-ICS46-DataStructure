#ifndef UNORDERED_LINKED_LIST_HPP
#define UNORDERED_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include "UnorderedListException.hpp"

using namespace std;

class UnorderedLinkedList
{
	struct ListNode{
		string key;
		int count;
		ListNode* next;
		ListNode(string new_key, int new_count, ListNode* new_next)
			:key{new_key}, count{new_count}, next{new_next}{}
	};
	ListNode* head;

public:
	UnorderedLinkedList();
	UnorderedLinkedList(const UnorderedLinkedList& ll);
	UnorderedLinkedList& operator=(const UnorderedLinkedList& ll);
	void insert(string key, int count);
	int find(string word);
	int& findByRef(string word);
	void remove(string word);
	void print(ostream& out);
	~UnorderedLinkedList();
	bool isEmpty();
	bool isFull();
	int length();
};

#endif
