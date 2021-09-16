#include <iostream>
#include <fstream>
#include "UnorderedArrayList.hpp"
#include "UnorderedLinkedList.hpp"
#include "Timer.h"

using namespace std;

//O(N)
ostream& operator<<(ostream& out, UnorderedArrayList& L){
	L.print(out);
	return out;
}

//O(N)
ostream& operator<<(ostream& out, UnorderedLinkedList& L){
	L.print(out);
	return out;
}

//O(N)
void insert_all_words(string file_name, UnorderedArrayList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.insert(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//O(N)
void insert_all_words(string file_name, UnorderedLinkedList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.insert(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//O(N^2)
void find_all_words(string file_name, UnorderedArrayList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.find(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//O(N^2)
void find_all_words(string file_name, UnorderedLinkedList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.find(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime <<endl;
}

//O(N^2)
void remove_all_words(string file_name, UnorderedArrayList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.remove(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
}

//O(N^2)
void remove_all_words(string file_name, UnorderedLinkedList& L){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	t.start();
	string word;
	while(infile >> word){
		L.remove(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
}

//O(N^2)
void test_UnorderedArrayList_methods(string file_name, UnorderedArrayList& L){
	cout << "Testing UnorderedArrayList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

//O(N^2)
void test_UnorderedLinkedList_methods(string file_name, UnorderedLinkedList& L){
	cout << "Testing UnorderedLinkedList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

//O(N^2)
int main(int argc, char* argv[]){
	const char* input_file = argc == 2 ? argv[1] : "random.txt";
	UnorderedArrayList UAL(45500);
	UnorderedLinkedList ULL;
	try{
		test_UnorderedArrayList_methods(input_file, UAL);
		test_UnorderedLinkedList_methods(input_file, ULL);
	}
	catch(UnorderedListException e){
		cout << "Error: " << e.getError() << endl;
	}
	return 0;
}
