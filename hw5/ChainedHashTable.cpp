#include "ChainedHashTable.hpp"

//O(N) N represents the capacity here since the hashTable needs to be initialized
//O(1) if consider the capacity as a constant
ChainedHashTable::ChainedHashTable(int capacity, Hasher& myHasher)
	:hashTable{new UnorderedLinkedList[capacity]}, hasher{myHasher}, _capacity{capacity}
{}

//O(N)
ChainedHashTable::~ChainedHashTable(){
	delete[] hashTable;
}

//O(N)
ChainedHashTable::ChainedHashTable(const ChainedHashTable& table)
	:hashTable{new UnorderedLinkedList[table._capacity]}, hasher{table.hasher}, _capacity{table._capacity}
{
	for(int i=0; i<_capacity; i++){
		hashTable[i] = table.hashTable[i];
	}		
}

//Worst Case: O(L)
//Typical Case: O(1) when there is no collision
void ChainedHashTable::insert(string key, int count){
	int k = hash(key, _capacity);
	if(hashTable[k].find(key) != -1){
		hashTable[k].remove(key);
	}
	hashTable[k].insert(key, count);
}

//Worst Case: O(L)
//Typical Case: O(1) when there is no collision
int ChainedHashTable::find(string key){
	int k = hash(key, _capacity);
	return hashTable[k].find(key);
}

//Worst Case: O(L)
//Typical Case: O(1) when there is no collision
void ChainedHashTable::remove(string key){
	int k = hash(key, _capacity);
	try{
		hashTable[k].remove(key);
	}
	catch(...){
		throw ChainedHashTableException("Try to remove key that is not in the table");
	}
}

//Worst Case: O(L)
//Typical Case: O(1) there is no collision
int& ChainedHashTable::operator[](string key){
	int k = hash(key, _capacity);
	try{
		return hashTable[k].findByRef(key);
	}catch(...){
		throw ChainedHashTableException("Try to use [] operator with a key that is not in the table"); 
	}
}

//Worst Case: O(1)
//Typical Case: O(1)
int ChainedHashTable::hash(string s, int N){
	return hasher.hash(s, N);
}

//This is a helper method for statistics
//O(_capacity)
int* ChainedHashTable::chainedListLengths(){
	int* chained_list_lengths = new int[_capacity];
	for(int i=0; i<_capacity; i++){
		chained_list_lengths[i] = hashTable[i].length();
	}
	return chained_list_lengths;
}
