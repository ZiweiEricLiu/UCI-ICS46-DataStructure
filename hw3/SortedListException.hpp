#ifndef SORTED_LIST_EXCEPTION_HPP
#define SORTED_LIST_EXCEPTION_HPP

#include <string>

using namespace std;

class SortedListException
{
	string errorMessage;
public:
	SortedListException(string e)
		:errorMessage{e}
	{
	}

	string getError(){
		return errorMessage;
	}
};

#endif
