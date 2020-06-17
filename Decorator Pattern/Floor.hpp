#ifndef _FLOOR_HPP
#define _FLOOR_HPP

#include "decorator.hpp"


class Floor : public Decorator{

public:

Base* input;

   Floor(Base* value) : input(value) {};
   double evaluate() {return floor(input->evaluate());}
  



};


#endif
