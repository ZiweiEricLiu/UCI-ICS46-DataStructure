#ifndef UNORDERED_LIST_EXCEPTION_HPP
#define UNORDERED_LIST_EXCEPTION_HPP

#include <string>

using namespace std;

class UnorderedListException
{
	string errorMessage;
public:
	UnorderedListException(string e)
		:errorMessage{e}
	{
	}

	string getError(){
		return errorMessage;
	}
};

#endif
