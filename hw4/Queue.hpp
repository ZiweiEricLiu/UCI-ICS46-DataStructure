#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>

using namespace std;

class Queue
{
public:
	virtual ~Queue() = default;
	virtual void enq(string word)=0;
	virtual string deq()=0;
	virtual string front()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
};

#endif
