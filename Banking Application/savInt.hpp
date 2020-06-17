#ifndef _SAVINT_
#define _SAVINT_

#include "decorator.hpp"
#include <iostream>

class SInterest : public Decorator{

        public:
        double input;
        SInterest(double value) : input(value) {};
        double interest { return (input * .02);}

};

#endif
