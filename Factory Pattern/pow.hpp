#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <math.h>
class Pow : public Base {
    public:
	Base* base;
	Base* expo;
	double result;
        Pow() : base(), expo() {base = new Op(0.0); expo = new Op(0.0); }
	Pow(Base* inputOne, Base* inputTwo) : base(inputOne), expo(inputTwo){}
        virtual double evaluate() {
	    return pow(base->evaluate(),expo->evaluate());
	}
        virtual std::string stringify() { return base->stringify() + " ** " +  expo->stringify(); }
};

#endif //__POW_HPP__
