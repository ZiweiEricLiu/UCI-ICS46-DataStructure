#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include <iostream>
#include <string>

using namespace std;

class SortedList
{
public:
	virtual ~SortedList() = default;
	virtual void insert(string word)=0;
	virtual bool find(string word)=0;
	virtual void remove(string word)=0;
	virtual void print(ostream& out)=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
};

#endif
