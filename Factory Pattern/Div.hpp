#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"
#include "op.hpp"

class Div : public Base{

public:
	Base* inputOne;
	Base* inputTwo;

	Div() : inputOne(), inputTwo() {inputOne = new Op(0.0); inputTwo = new Op(0.0); }
	Div(Base* first, Base* second) : inputOne(first), inputTwo(second) {}
	double evaluate() {return inputOne->evaluate() / inputTwo->evaluate();}
	std::string stringify() {return inputOne->stringify() + " / " + inputTwo->stringify();}
};

#endif //_DIV_HPP_
