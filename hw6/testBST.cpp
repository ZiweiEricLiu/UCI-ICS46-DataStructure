#include "BinarySearchTree.hpp"
#include <iostream>
#include <fstream>
#include "Timer.h"


using namespace std;

//O(M*logN) M represents the file size N represents the data structure size
void insertAll(string file_name, BinarySearchTree<string, int>& h, int partition){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	for(int i=0;i<4529*partition;i++){
		infile>>word;
		h.insert(word, 1);
	}
	t.elapsedUserTime(eTime);
	infile.close();
	cout << "File: " << file_name << ". Partition: " << partition << "/10. Function: insertAllWords. 	Time: " << eTime << "s" << endl;
}

//O(M*logN) M represents the file size N represents the data structure size
void findAll(string file_name, BinarySearchTree<string, int>& h, int partition){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	for(int i=0;i<4529*partition;i++){
		infile>>word;
		h.find(word);
	}
	t.elapsedUserTime(eTime);
	infile.close();
	cout << "File: " << file_name << ". Partition: " << partition << "/10. Function: findAllWords.  	Time: " << eTime << "s" << endl; 
}

//Worst Case: O(N*L) N represents the file size and L represents the size of the linkedlist
//Typical Case: O(N) N represents the file size
void removeAll(string file_name, BinarySearchTree<string, int>& h, int partition){
	Timer t;
	double eTime;
	ifstream infile(file_name);
	string word;
	t.start();
	for(int i=0;i<4529*partition;i++){
		infile>>word;
		h.remove(word);
	}
	t.elapsedUserTime(eTime);
	infile.close();
	cout << "File: " << file_name << ". Partition: " << partition << "/10. Function: removeAllWords.  	Time: " << eTime << "s" << endl; 
}

void insertAllWithoutPartition(string file_name, BinarySearchTree<string, int>& h){
	ifstream infile(file_name);
	string word;
	while(infile>>word){
		h.insert(word, 1);
	}
	infile.close();
}

void testBST(string inputFileName){
	cout << "---------------------Part1--------------------" << endl;
	for(int i=1; i<=10; i++){
		BinarySearchTree<string, int> tree;
		insertAll(inputFileName, tree, i);
		findAll(inputFileName, tree, i);
		removeAll(inputFileName, tree, i);
	}
	cout << "---------------------Part2--------------------" << endl;
	BinarySearchTree<string, int> tree;
	int* cl = new int[30];
	for(int i=0; i<30; i++){
		cl[i] = 0;
	}
	insertAllWithoutPartition(inputFileName, tree);
	cl = tree.countLengths(cl, 30);
	cout << "Words in " << inputFileName << " of:" << endl;
	for(int i=0; i<30; i++){
		if(cl[i] != 0){
			cout << "	length " << i+1 << ": " << cl[i] << " words" << endl;
		}
	}
	delete[] cl;
}

int main(){
	testBST("random.txt");
	return 0;
}
