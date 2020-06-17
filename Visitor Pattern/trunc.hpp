#ifndef _TRUNC_HPP_
#define _TRUNC_HPP_

#include "decorator.hpp"
class Trunc : public Decorator
{

	public:
	Base* input;
	Trunc(Base* expres) : input(expres){ }
	std::string stringify()
	{
		return "" + std::to_string(input->evaluate()); 
	}
	
	Base* get_left() {return input;}
	Base* get_right() {return nullptr;}
	Iterator* create_iterator() {return new  UnaryIterator(this);}
	void accept(CountVisitor* visit) {visit->visit_trunc();}
};
#endif
