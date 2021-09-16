#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>

using namespace std;

class Stack
{
public:
	virtual ~Stack() = default;
	virtual void push(string word)=0;
	virtual string pop()=0;
	virtual string top()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
};

#endif
