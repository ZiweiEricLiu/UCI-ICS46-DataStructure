#include "ArrayStack.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//O(N)
bool isBalanced(string brackets){
	ArrayStack stk = ArrayStack(100);
	string bracket;
	for(char c : brackets){
		string b{c};
		if(b=="("||b=="{"||b=="<"||b=="["){
			stk.push(b);
		}else if(b==")"||b=="}"||b==">"||b=="]"){
			try{
				bracket = stk.pop();
				if((b==")"&&bracket=="(") || (b=="}"&&bracket=="{") || (b==">"&&bracket=="<") || (b=="]"&&bracket=="[")){
					continue;
				}else{
					return false;
				}
			}catch(...){
				return false;
			}		
		}
	}
	try{
		bracket = stk.pop();
	}catch(...){
		return true;
	}
	return false;
}

int main(int argc, char* argv[]){
	const char* input_file = argc == 2 ? argv[1] : nullptr;
	if(input_file == nullptr){
		cout << "Please specify an arguement for the testing input file name" << endl;
		return 1;
	}
	ifstream infile(input_file);
	string brackets;
	while(infile >> brackets){
		cout << boolalpha << isBalanced(brackets) << endl;
	}
	return 0;
}
