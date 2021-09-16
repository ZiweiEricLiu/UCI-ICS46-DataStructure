#include "InsertionSorter.hpp"
#include "QuickSorter.hpp"
#include "HeapSorter.hpp"
#include <iostream>
#include <fstream>


using namespace std;

//O(N^2) since InsertionSort is O(N^2)
void measureAll(string file_name){
	for(int i=1;i<=10;i++){
		InsertionSorter* IS = new InsertionSorter(i*4529+1);
		QuickSorter* QS = new QuickSorter(i*4529+1);
		HeapSorter* HS = new HeapSorter(i*4529+1);
		IS->insertAllFromFile(i, file_name, "InsertionSorter");
		QS->insertAllFromFile(i, file_name, "QuickSorter");
		HS->insertAllFromFile(i, file_name, "HeapSorter");
		delete IS;
		delete QS;
		delete HS;
	}
}

int main(){
	measureAll("random.txt");
	return 0;
}
