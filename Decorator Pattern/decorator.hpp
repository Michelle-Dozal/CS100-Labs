#ifndef _DECORATOR_HPP_
#define _DECORATOR_HPP_

#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include <math.h>
class Decorator : public Base{
	public:
	Decorator() {};
 	double evaluate(){} ;
 	std::string stringify(){} ;


};

#endif
