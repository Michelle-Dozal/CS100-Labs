#ifndef __CREDIT_ACCOUNT_HPP__
#define __CREDIT_ACCOUNT_HPP__

#include "Account.hpp"
#include "visitor.hpp"

class CreditAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
        CreditAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_credit(this, x);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
