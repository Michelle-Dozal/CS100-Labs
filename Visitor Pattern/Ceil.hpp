#ifndef _CEIL_HPP_
#define _CEIL_HPP_

#include "decorator.hpp"

#include <iostream>

class Ceil : public Decorator {
   public:
   Base* input;

   Ceil(Base* value) : input(value) {};
   double evaluate() {return ceil(input->evaluate());}
	Base* get_left() {return input;}
	Base* get_right() {return nullptr;}
	Iterator* create_iterator() {return new UnaryIterator(this);}
	void accept(CountVisitor* visit) {visit->visit_ceil();}
};

#endif
