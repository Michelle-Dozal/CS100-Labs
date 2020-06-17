#ifndef  _SUB_HPP_
#define _SUB_HPP

#include "base.hpp"
#include "op.hpp"

class Sub : public Base{

public:
       Base* inputOne;
	Base* inputTwo;
	Sub() : inputOne(), inputTwo() {inputOne = new Op(0.0); inputTwo = new Op(0.0);}
	Sub(Base* first, Base* second) : inputOne(first), inputTwo(second) {}
	double evaluate() {return inputOne->evaluate() - inputTwo->evaluate();}
	std::string stringify() {return inputOne->stringify() + " - " + inputTwo->stringify();}
};
#endif //_SUB_HPP
