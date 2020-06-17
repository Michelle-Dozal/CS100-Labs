#ifndef _ABS_HPP
#define _ABS_HPP

#include "decorator.hpp"


class Abs : public Decorator{
public:

Base* input;

   Abs(Base* value) : input(value) {};
   double evaluate() {return abs(input->evaluate());}

	Base* get_left() {return input;}
	Base* get_right() {return nullptr;}
	Iterator* create_iterator() {return new UnaryIterator(this);}
	void accept(CountVisitor* visit) {visit->visit_abs();}
};

#endif
