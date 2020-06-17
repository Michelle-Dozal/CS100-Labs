#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "container.hpp"
#include "base.hpp"
#include <vector>
//#include "sort.hpp"
using namespace std;

class VectorContainer : public Container
{
	private:
	vector<Base*> tree;
	public:

	void add_element(Base* );
	void print();
	void sort();

	//soritn helper functions
	void swap(int , int );
	Base* at(int );
	int size();
};
#endif

