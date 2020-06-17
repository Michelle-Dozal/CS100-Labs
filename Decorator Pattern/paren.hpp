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
};
#endif
