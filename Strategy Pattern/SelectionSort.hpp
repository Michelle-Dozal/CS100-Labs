#ifndef _SELECTIONSORT_HPP
#define _SELECTIONSORT_HPP

#include "container.hpp"
#include "sort.hpp"

#include <iostream>

class SelectionSort: public Sort{
        public:

        void sort(Container* container);
};

#endif //_SELECTIONSORT_HPP
