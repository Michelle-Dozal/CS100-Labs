#ifndef _HOMEINT_
#define _HOMEINT_

#include "decorator.hpp"
#include <iostream>

class HInterest : public Decorator{

	public:
	double input;
	HInterest(double value) : input(value) {};
	double interest { return (input * .04);}

};

#endif
