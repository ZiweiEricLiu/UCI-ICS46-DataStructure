#include <iostream>
#include <fstream>
#include "SortedArrayList.hpp"
#include "SortedLinkedList.hpp"
#include "SortedList.hpp"
#include "Timer.h"

using namespace std;

//O(N)
ostream& operator<<(ostream& out, SortedList* L){
	L->print(out);
	return out;
}

//SortedArrayList: O(N)
//SortedLinkedList: O(N)
//N represents only the elements in the list 
//(the size of the input file is considered constant)
void insert_all_words(string file_name, SortedList* L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L->insert(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//SortedArrayList: O(logN)
//SortedLinkedList: O(N)
//N represents only the elements in the list 
//(the size of the input file is considered constant)
void find_all_words(string file_name, SortedList* L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L->find(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//SortedArrayList: O(N*logN)
//SortedLinkedList: O(N)
//N represents only the elements in the list 
//(the size of the input file is considered constant)
void remove_all_words(string file_name, SortedList* L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L->remove(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
}

//SortedArrayList: O(N*logN)
//SortedLinkedList: O(N)
//N represents only the elements in the list 
//(the size of the input file is considered constant)
void test_SortedList_methods(string file_name, SortedList* L){
	cout << "Testing SortedList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

//O(N*logN)
int main(int argc, char* argv[]){
	const char* input_file = argc == 2 ? argv[1] : "random.txt";
	SortedList* UAL = new SortedArrayList{45500};
	SortedList* ULL = new SortedLinkedList();
	try{
		test_SortedList_methods(input_file, UAL);
		test_SortedList_methods(input_file, ULL);
	}
	catch(SortedListException e){
		cout << "Error: " << e.getError() << endl;
	}
	delete UAL;
	delete ULL;
	return 0;
}
