#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "Account.hpp"
#include "visitor.hpp"

class SavingsAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
        SavingsAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_savings(this, x);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
