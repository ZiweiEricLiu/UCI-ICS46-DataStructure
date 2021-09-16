#ifndef CONTAINER_UNDER_FLOW_HPP
#define CONTAINER_UNDER_FLOW_HPP

#include <string>

using namespace std;

class ContainerUnderFlow
{
	string errorMessage;
public: 
	ContainerUnderFlow(string e)
		:errorMessage(e)
	{}
	
	string getError(){
		return errorMessage;
	}
};

#endif
