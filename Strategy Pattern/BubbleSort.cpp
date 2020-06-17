#include "BubbleSort.hpp"
//#include "sort.hpp"
//#include "base.hpp"
//#include "container.hpp"
#include <iostream>

	void BubbleSort::sort(Container* container)
	{
		std::cout << "In bubble" << std::endl;
		
		while(1)
		{
			std::cout << "first loop" << std::endl;
			counter = 0;
			for(int i = 0; i < container->size() - 1; i++)
			{
			
				if(container->at(i+1)->evaluate() < container->at(i)->evaluate())
				{
					counter = 1;
					container->swap(i,i+1);
				}
				
			}
			if(counter == 0)
				break;
		}
	}
