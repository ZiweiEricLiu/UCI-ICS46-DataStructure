#ifndef CHAINED_HASH_TABLE_HPP
#define CHAINED_HASH_TABLE_HPP

#include <string>
#include <iostream>
#include "UnorderedLinkedList.hpp"
#include "Hasher.hpp"
#include "ChainedHashTableException.hpp"

using namespace std;

class ChainedHashTable{

private:
	UnorderedLinkedList* hashTable;
	Hasher& hasher;
	int _capacity;
public:
	ChainedHashTable(int capacity, Hasher& myHasher);
	~ChainedHashTable();
	ChainedHashTable(const ChainedHashTable& table);
	void insert(string key, int count);
	int find(string key);
	void remove(string key);
	int& operator[](string key);
	int hash(string s, int N);
	int* chainedListLengths();
};

#endif
