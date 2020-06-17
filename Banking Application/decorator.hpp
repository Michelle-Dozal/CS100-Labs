#ifndef _DECORATOR_HPP_
#define _DECORATOR_HPP_

#include <iostream>
#include "account.hpp"

class Decorator : public Account {

	public:
	Decorator() {};
	double interest(){};

};

#endif
