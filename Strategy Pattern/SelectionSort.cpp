
#include "SelectionSort.hpp"

 void SelectionSort::sort(Container* container) {
        int i, j, min;
        int length = container->size();
        for(i = length - 1; i >= 0; i--){
        min = 0;
        for(j = 1; j<= i; j++)
        {
                if(container->at(j)->evaluate() > container->at(min)->evaluate())
                {min = j;}
        }
        container->swap(min, i);
}
}


