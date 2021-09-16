#ifndef LINKED_STACK_HPP
#define LINKED_STACK_HPP

#include <iostream>
#include <string>
#include "Stack.hpp"

using namespace std;

class LinkedStack : public Stack
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
	LinkedStack();
	~LinkedStack();
	virtual void push(string word) override;
	virtual string pop() override;
	virtual string top() override;
	virtual bool isEmpty() override;
	virtual bool isFull() override;	
};

#endif
