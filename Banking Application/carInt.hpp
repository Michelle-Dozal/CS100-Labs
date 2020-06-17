#ifndef _CARINT_
#define _CARINT_

#include "decorator.hpp"
#include <iostream>

class CInterest : public Decorator{

        public:
        double input;
        CInterest(double value) : input(value) {};
        double interest { return (input * .0375);}

};

#endif
