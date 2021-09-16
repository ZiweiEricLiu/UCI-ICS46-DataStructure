#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include <iostream>
#include <string>
#include "Queue.hpp"

using namespace std;

class ArrayQueue : public Queue
{
	string* buf;
	int capacity, start, end;
public:
	ArrayQueue(int max_len);
	~ArrayQueue();
	virtual void enq(string word) override;
	virtual string deq() override;
	virtual string front() override;
	virtual bool isEmpty() override;
	virtual bool isFull() override;
};

#endif
