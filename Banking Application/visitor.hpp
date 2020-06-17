#ifndef VISITOR_HPP
#define VISITOR_HPP

#include "Account.hpp"

class Account;

class Visitor {
public:
	Visitor() {};
	virtual void visit_savings(Account* accnt, double x) = 0;
	virtual void visit_checking(Account* accnt, double x) = 0;
	virtual void visit_visa(Account*, double) = 0;
	virtual void visit_mastercard(Account*, double) = 0;
	virtual void visit_homeLoan(Account*, double) = 0;
	virtual void visit_carLoan(Account*, double) = 0;
};

#endif
