#include "ChainedHashTable.hpp"
#include <iostream>
#include <fstream>
#include "Timer.h"
#include <cmath>


using namespace std;

//Method Testing (insert, find, remove are tested in the insertAll...functions)
void testConstructor(Hasher& hasher){
	cout << "#####Testing Constructor#####" << endl;
	ChainedHashTable table = ChainedHashTable(20, hasher);
	cout << "#####Constructor Testing Pass#####" << endl;
}

ChainedHashTable test(ChainedHashTable t){return t;}
void testCopyConstructor(Hasher& hasher){
	cout << "#####Testing Copy Constructor#####" << endl;
	ChainedHashTable table = ChainedHashTable(20, hasher);
	test(table); 
	cout << "#####Copy Constructor Testing Pass#####" << endl;
}

void testBrackets(Hasher& hasher){
	cout << "#####Testing [] Operator#####" << endl;
	ChainedHashTable table = ChainedHashTable(20, hasher);
	table.insert("abc", 100);
	if(table["abc"] == 100){
		cout << "#####Brackets Testing Pass#####" << endl;
	}
}	

//Worst Case: O(N*L) N represents the file size and L represents the size of the linkedlist
//Typical Case: O(N) N represents the file size
void insertAll(string file_name, ChainedHashTable& h){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	while(infile>>word){
		h.insert(word, 1);
	}
	t.elapsedUserTime(eTime);
	infile.close();
}

//Worst Case: O(N*L) N represents the file size and L represents the size of the linkedlist
//Typical Case: O(N) N represents the file size
void findAll(string file_name, ChainedHashTable& h){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	while(infile>>word){
		h.find(word);
	}
	t.elapsedUserTime(eTime);
	infile.close();
}

//Worst Case: O(N*L) N represents the file size and L represents the size of the linkedlist
//Typical Case: O(N) N represents the file size
void removeAll(string file_name, ChainedHashTable& h){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	while(infile>>word){
		h.remove(word);
	}
	t.elapsedUserTime(eTime);
	infile.close();
}

int hash_min(int* chained_list_lengths){
	int minimum = chained_list_lengths[0];
	for(int i=1; i<5000; i++){
		if(chained_list_lengths[i] < minimum){
			minimum = chained_list_lengths[i];
		}
	}
	return minimum;
}

int hash_max(int* chained_list_lengths){
	int maximum = chained_list_lengths[0];
	for(int i=1; i<5000; i++){
		if(chained_list_lengths[i] > maximum){
			maximum = chained_list_lengths[i];
		}
	}
	return maximum;
}

int average(int* chained_list_lengths){
	int sum = 0;
	for(int i=0; i<5000; i++){
		sum += chained_list_lengths[i];
	}
	return sum/5000;
}

int stdDev(int* chained_list_lengths){
	int avg = average(chained_list_lengths);
	int variance_sum = 0;
	for(int i=0; i<5000; i++){
		variance_sum += (chained_list_lengths[i] - avg)*(chained_list_lengths[i] - avg);
	}
	return sqrt(variance_sum/5000);
}

void testHash(string inputFileName, Hasher& hasher){
	//Uncomment these three lines for method testing
	//testConstructor(hasher);
	//testCopyConstructor(hasher);
	//testBrackets(hasher);
	int min, max, avg, std_dev;
	double insertAllTime, findAllTime, removeAllTime;
	ChainedHashTable table = ChainedHashTable(5000, hasher);
	Timer t;

	t.start();
	insertAll(inputFileName, table);
	t.elapsedUserTime(insertAllTime);

	int* cll = table.chainedListLengths();
	min = hash_min(cll);
	max = hash_max(cll);
	avg = average(cll);
	std_dev = stdDev(cll);

	t.start();
	findAll(inputFileName, table);
	t.elapsedUserTime(findAllTime);

	t.start();
	removeAll(inputFileName, table);
	t.elapsedUserTime(removeAllTime);
	
	delete[] cll;
	cout << "	min = " << min << "; max = " << max << "; average = " << avg << "; std_dev = " << std_dev << endl;
	cout << "	insertAll = " << insertAllTime << "sec" << endl;
	cout << "	findAll = " << findAllTime << "sec" << endl;
	cout << "	removeAll = " << removeAllTime << "sec" << endl;
}

int main(){
	cout << "Hash function 1 (GeneralStringHasher) chain length statistics:" << endl;
	GeneralStringHasher h1;
	testHash("random.txt", h1);
	cout << endl;
	cout << "Hash function 2 (SumHasher) chain length statistics:" << endl;
	SumHasher h2;
	testHash("random.txt", h2);
	cout << endl;
	cout << "Hash function 3 (ProdHasher) chain length statistics:" << endl;
	ProdHasher h3;
	testHash("random.txt", h3);
	cout << endl;


	return 0;
}
