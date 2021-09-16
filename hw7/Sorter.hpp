#ifndef SORTER_HPP
#define SORTER_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Sorter
{
protected:
	string* data;
	int size;
	void swap(int index1, int index2);
public:
	Sorter(int max);
	virtual ~Sorter();
	void insertAllFromFile(int partition, string fileName, string sorterName);
	void print(ostream& out);
	virtual void sort() = 0;
};

#endif
