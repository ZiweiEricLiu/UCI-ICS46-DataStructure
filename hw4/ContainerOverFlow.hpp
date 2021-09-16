#ifndef CONTAINER_OVER_FLOW_HPP
#define CONTAINER_OVER_FLOW_HPP

#include <string>

using namespace std;

class ContainerOverFlow
{
	string errorMessage;
public: 
	ContainerOverFlow(string e)
		:errorMessage(e)
	{}
	
	string getError(){
		return errorMessage;
	}
};

#endif
