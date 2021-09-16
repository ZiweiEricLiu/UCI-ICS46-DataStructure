#ifndef INSERTION_SORTER_HPP
#define INSERTION_SORTER_HPP

#include <string>
#include "Sorter.hpp"

using namespace std;

class InsertionSorter : public Sorter
{
	void copy_down(int i, int j);
public:
	InsertionSorter(int max)
		: Sorter{max}
	{}
	void sort() override;
};

#endif
