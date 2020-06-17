#ifndef _PAREN_HPP_
#define _PAREN_HPP_
#include "decorator.hpp"
class Paren : public Decorator
{
	public:
	Base* input;
	Paren(Base* expres) : input(expres){ }
	std::string stringify()
	{
		return "("+ input->stringify()  +")"; 
	}
	
	Base* get_left() {return input;}
	Base* get_right() {return nullptr;}
	Iterator* create_iterator() {return new UnaryIterator();}
	void accept(CountVisitor* visit) {visit->visit_paren();}
};
#endif
