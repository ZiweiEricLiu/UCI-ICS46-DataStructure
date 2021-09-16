#include <iostream>
#include <fstream>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"
#include "ContainerOverFlow.hpp"
#include "ContainerUnderFlow.hpp"

using namespace std;

//O(1) Only consider the size of the data structure
//O(N) consider the size of the input file
void fillAll(Stack& stk, string in_file){
	ifstream infile(in_file);
	string word;
	while(infile >> word){
		try{
			stk.push(word);
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
void emptyAll(Stack& stk, string out_file){
	ofstream outfile(out_file);
	while(true){
		try{
			outfile << stk.pop() << endl;
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
	const char* ASoutput_file = argc >= 3 ? argv[2] : nullptr;
	const char* LSoutput_file = argc == 4 ? argv[3] : nullptr;
	if(input_file == nullptr){
		cout << "input file needed to be specified" << endl;
		return 1;
	}
	if(ASoutput_file == nullptr){
		cout << "ArrayStack output file needed to be specified" << endl;
		return 2;
	}
	if(LSoutput_file == nullptr){
		cout << "LinkedStack output file needed to be specified" << endl;
		return 3;
	}
	ArrayStack AS = ArrayStack(45500);
	LinkedStack LS;
	cout << "--------Testing Array Stack--------" << endl;
	fillAll(AS, input_file);
	emptyAll(AS, ASoutput_file);
	cout << "--------Testing Linked Stack--------" << endl;
	fillAll(LS, input_file);
	emptyAll(LS, LSoutput_file);
	return 0;
}
