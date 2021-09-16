#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

class LinkedQueue : public Queue
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
	ListNode* head, *tail;
public:
	LinkedQueue();
	~LinkedQueue();
	virtual void enq(string word) override;
	virtual string deq() override;
	virtual string front() override;
	virtual bool isEmpty() override;
	virtual bool isFull() override;	
};

#endif
