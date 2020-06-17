#ifndef _TRUNC_HPP_
#define _TRUNC_HPP_

#include "decorator.hpp"
class Trunc : public Decorator
{

	public:
	Base* input;
	Trunc(Base* expres) : input(expres){ }
	/*Op* result()
	{
		Op* op = new Op(input->evaluate());	
		return op;
	}
	*/
	std::string stringify()
	{
		return "" + std::to_string(input->evaluate()); 
	}
};
#endif
