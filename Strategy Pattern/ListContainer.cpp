#include <iostream>
#include "ListContainer.hpp"


using namespace std;


void ListContainer::sort() { sort_function->sort(this);}
void ListContainer::add_element(Base* element) {baseList.push_back(element);}
void ListContainer::print()
{
        list<Base*>::iterator i;
        for(i = baseList.begin(); i != baseList.end(); i++){
        cout << (*i)->evaluate() << endl; }

}

void ListContainer::swap (int i, int j)
{
        list<Base*>::iterator it = baseList.begin();
        advance(it,i);
        list<Base*>::iterator it2 = baseList.begin();
        advance(it2, j);
        std::swap(*it, *it2);

}

Base* ListContainer::at (int i)
{
        list<Base*>::iterator it = baseList.begin();
        advance(it, i);
        return *it;
}

int ListContainer::size() {return baseList.size();}

