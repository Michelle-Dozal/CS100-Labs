#ifndef _BUBBLE_SORT_HPP_
#define _BUBBLE_SORT_HPP_
#include "sort.hpp"
//#include "base.hpp"
//#include "container.hpp"

class BubbleSort : public Sort
{
	private:
	int counter;
	public:
//	BubbleSort : Sort(){};

	void sort(Container* container);
};
#endif
