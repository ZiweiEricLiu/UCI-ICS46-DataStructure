#include <iostream>
#include <fstream>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
#include "ContainerOverFlow.hpp"
#include "ContainerUnderFlow.hpp"

//O(1) Only consider the size of the data structure
//O(N) consider the size of the input file
void fillAll(Queue& que, string in_file){
	ifstream infile(in_file);
	string word;
	while(infile >> word){
		try{
			que.enq(word);
		}catch(ContainerOverFlow& e){
			cout << e.getError() << endl;
			infile.close();
			throw;
		}
	}
	infile.close();
}

//O(1) Only consider the size of the data structure
//O(N) consider the size of the input file
void emptyAll(Queue& que, string out_file){
	ofstream outfile(out_file);
	while(true){
		try{
			outfile << que.deq() << endl;
		}catch(ContainerUnderFlow& e){
			outfile.close();
			break;
		}
	}
}

//O(1) Only consider the size of the data structure
//O(N) consider the size of the input file
int main(int argc, char* argv[]){
	const char* input_file = argc >= 2 ? argv[1] : nullptr;
	const char* AQoutput_file = argc >= 3 ? argv[2] : nullptr;
	const char* LQoutput_file = argc == 4 ? argv[3] : nullptr;
	if(input_file == nullptr){
		cout << "input file needed to be specified" << endl;
		return 1;
	}
	if(AQoutput_file == nullptr){
		cout << "ArrayQueue output file needed to be specified" << endl;
		return 2;
	}
	if(LQoutput_file == nullptr){
		cout << "LinkedQueue output file needed to be specified" << endl;
		return 3;
	}
	ArrayQueue AQ = ArrayQueue(45500);
	LinkedQueue LQ;
	cout << "--------Testing Array Queue--------" << endl;
	fillAll(AQ, input_file);
	emptyAll(AQ, AQoutput_file);
	cout << "--------Testing Linked Queue--------" << endl;
	fillAll(LQ, input_file);
	emptyAll(LQ, LQoutput_file);
	return 0;
}
