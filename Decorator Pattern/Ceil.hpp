#ifndef _CEIL_HPP_
#define _CEIL_HPP_

#include "decorator.hpp"

#include <iostream>

class Ceil : public Decorator {
   public:
   Base* input;

  
   Ceil(Base* value) : input(value) {};
   double evaluate() {return ceil(input->evaluate());}
  

};

#endif
