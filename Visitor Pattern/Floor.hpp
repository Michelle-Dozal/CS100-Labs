#ifndef _FLOOR_HPP
#define _FLOOR_HPP

#include "decorator.hpp"


class Floor : public Decorator{

public:

Base* input;

   Floor(Base* value) : input(value) {};
   double evaluate() {return floor(input->evaluate());}
	Base* get_left() {return input;}
	Base* get_right() {return nullptr;}
	Iterator* create_iterator() {return new UnaryIterator(this);}
	void accept(CountVisitor* visit) {visit->visit_floor();}
};


#endif
