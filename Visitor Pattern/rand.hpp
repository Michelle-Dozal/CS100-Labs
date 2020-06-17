#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
	double number;
        Rand() : Base() {number = rand()%100; }
        virtual double evaluate() { return number; }
        virtual std::string stringify() { return std:: to_string(number); }
	
	Base* get_left(){return nullptr;}
	Base* get_right(){return nullptr;}
	Iterator* create_iterator(){return new NullIterator;}
	//void accept(CountVisitor* visit) {visit->visit_rand();}
};

#endif //__RAD_HPP__
