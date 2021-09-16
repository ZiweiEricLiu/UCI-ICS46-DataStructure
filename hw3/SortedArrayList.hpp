#ifndef SORTED_ARRAY_LIST_HPP
#define SORTED_ARRAY_LIST_HPP

#include <iostream>
#include <string>
#include "SortedListException.hpp"
#include "SortedList.hpp"

using namespace std;

class SortedArrayList : public SortedList
{
	string* buf;
	int capacity;
	int size;
	int get_index(string& word);
	void copy_up(int index);
	void copy_down(int index);
public:
	SortedArrayList(int max_len);
	virtual void insert(string word) override;
	virtual bool find(string word) override;
	virtual void remove(string word) override;
	virtual void print(ostream& out) override;
	~SortedArrayList();
	virtual bool isEmpty() override;
	virtual bool isFull() override;
};
	
#endif
