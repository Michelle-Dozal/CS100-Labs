#ifndef _ABS_HPP
#define _ABS_HPP

#include "decorator.hpp"


class Abs : public Decorator{
public:

Base* input;

   Abs(Base* value) : input(value) {};
   double evaluate() {return abs(input->evaluate());}
  

};

#endif
