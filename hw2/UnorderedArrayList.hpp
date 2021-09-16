#ifndef UNORDERED_ARRAY_LIST_HPP
#define UNORDERED_ARRAY_LIST_HPP

#include <iostream>
#include <string>
#include "UnorderedListException.hpp"

using namespace std;

class UnorderedArrayList
{
	string* buf;
	int capacity;
	int size;
	int get_index(string& word);
public:
	UnorderedArrayList(int max_len);
	void insert(string word);
	bool find(string word);
	void remove(string word);
	void print(ostream& out);
	~UnorderedArrayList();
	bool isEmpty();
	bool isFull();
};
	
#endif
