#ifndef HEAP_SORTER_HPP
#define	HEAP_SORTER_HPP

#include <string>
#include "Sorter.hpp"

class HeapSorter : public Sorter
{
	void heapSort(int N);
	void heapify(int N);
	void siftSmallestDown(int start, int end);
	int myLeftChild(int index);
public:
	HeapSorter(int max)
		: Sorter{max}
	{}
	void sort() override;
};

#endif
