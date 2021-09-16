#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include <iostream>
#include <string>
#include "Stack.hpp"

using namespace std;

class ArrayStack : public Stack
{
	string* buf;
	int capacity, tp;
public:
	ArrayStack(int max_len);
	~ArrayStack();
	virtual void push(string word) override;
	virtual string pop() override;
	virtual string top() override;
	virtual bool isEmpty() override;
	virtual bool isFull() override;
};

#endif
