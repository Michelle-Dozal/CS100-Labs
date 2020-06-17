#ifndef _LISTCONTAINER_HPP_
#define _LISTCONTAINER_HPP_


#include "container.hpp"
#include "base.hpp"
//#include <iostream>

#include <list>
using namespace std;
class Sort;

class ListContainer : public Container {
private:
//Sort* sort_function;
list<Base*> baseList;

  public:

        ListContainer() : Container() {};
        //ListContainer(Sort* list) : sort_function(list) {};

        void add_element(Base* );
        void print();
        void sort();
        void swap(int, int);
        Base* at(int);
        int size();
};

#endif
