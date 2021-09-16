#ifndef QUICK_SORTER_HPP
#define QUICK_SORTER_HPP

#include <string>
#include "Sorter.hpp"

using namespace std;

class QuickSorter : public Sorter
{
	static const int K = 16;
	void quicksort(int low, int high);
	void insertionsort(int low, int high);
	int partition(int low, int high, string pivot);
	string median_of_three(int low, int high);
public:
	QuickSorter(int max)
		: Sorter{max}
	{}
	void sort() override;
};

#endif
