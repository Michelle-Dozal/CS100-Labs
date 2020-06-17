#include "VectorContainer.hpp"
//#include "container.hpp"
//#include "base.hpp"
#include <vector>
#include <iostream>
using namespace std;

	void VectorContainer::add_element(Base* element)
	{
		tree.push_back(element);
	}
	void VectorContainer::print()
	{
		for(int i = 0; i <tree.size(); i++)
		{
			cout << tree.at(i)->stringify() << endl;			
		}
	}
	void VectorContainer::sort()
	{
		cout << "Before call of sort" << endl;
		sort_function->sort(this);
		cout <<"After call of sort" << endl;
	}
	//soritn helper functions
	void VectorContainer::swap(int i, int j)
	{
		
		Base* first = tree.at(i);
		Base* second = tree.at(j);
		
		tree.at(i) = second;
		tree.at(j) = first;						
	}
	Base* VectorContainer::at(int i)
	{
		return  tree.at(i);
	}
	int VectorContainer::size()
	{
		return tree.size();
	}

