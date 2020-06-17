#ifndef CARLOANACCOUNT_HPP
#define CARLOANACCOUNT_HPP

#include "Account.hpp"
#include "visitor.hpp"

class CarLoanAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
       	CarLoanAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_carLoan(this, x);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
