#include "Sorter.hpp"
#include "Timer.h"
#include <iomanip>
//O(1)
void Sorter::swap(int index1, int index2){
	string temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
	
}

//O(1)
Sorter::Sorter(int max)
	:data{new string[max]}, size{0}
{}

//O(N)
Sorter::~Sorter(){
	delete[] data;
}

//O(N^2) for InsertionSort
//O(NlogN) for QuickSort & HeapSort
void Sorter::insertAllFromFile(int partition, string fileName, string sorterName){
	ifstream infile(fileName);
	string word;
	for(int i=0; i<4529*partition; i++){
		infile >> word;
		data[i] = word;
		size++;
	}
	Timer t;
	double eTime;
	t.start();
	sort();
	t.elapsedUserTime(eTime);
	//print(cout);
	infile.close();
	cout<< "File: " << fileName << ". Partition: " << partition << "/10. Sorter: " << sorterName << ". " << "Time: " << eTime << "s" << endl;
}

//O(N)
void Sorter::print(ostream& out){
	for(int i=0; i<size-1; i++){
		out << data[i] << ", ";
	}
	out << data[size-1] << endl;
}
