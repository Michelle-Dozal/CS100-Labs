#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

#include <string>
#include "visitor.hpp"
#include "offerVisitor.hpp"

class Account {
private: 
	double balance;
    public:
        /* Constructors */
        Account() {balance = 0;}
        /* Pure Virtual Functions */
	virtual void accept(Visitor*, double) = 0;
	virtual double getBalance() = 0;
	virtual void setBalance(double) = 0;
};

#endif //__ACCOUNT_HPP__
