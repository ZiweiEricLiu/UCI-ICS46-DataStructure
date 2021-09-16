#ifndef CHAINED_HASH_TABLE_EXCEPTION_HPP
#define CHAINED_HASH_TABLE_EXCEPTION_HPP

#include <string>

using namespace std;

class ChainedHashTableException
{
	string errorMessage;
public:
	ChainedHashTableException(string e)
		:errorMessage{e}
	{
	}

	string getError(){
		return errorMessage;
	}
};

#endif
