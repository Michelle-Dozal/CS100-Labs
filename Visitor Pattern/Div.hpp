#ifndef _DIV_HPP_
#define _DIV_HPP_

#include "base.hpp"
#include "op.hpp"

class Div : public Base{
private:
	Base* inputOne;
	Base* inputTwo;

public:

        
	Div(Base* first, Base* second) : inputOne(first), inputTwo(second) {}
        double evaluate() {return inputOne->evaluate() / inputTwo->evaluate();}
        std::string stringify() {return inputOne->stringify() + " / " + inputTwo->stringify();}
        Iterator* create_iterator() {return new BinaryIterator(this);}
        Base* get_left() {return inputOne;}
        Base* get_right() {return inputTwo;}
	void accept(CountVisitor* visit) {visit->visit_div();}
};

#endif //_DIV_HPP_

