#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
	double number;
        Rand() : Base() {number = rand()%100; }
        virtual double evaluate() { return number; }
        virtual std::string stringify() { return std:: to_string(number); }
};

#endif //__RAD_HPP__
