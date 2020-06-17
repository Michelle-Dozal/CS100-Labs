#ifndef HOMELOANACCOUNT_HPP
#define HOMELOANACCOUNT_HPP

#include "Account.hpp"
#include "visitor.hpp"

class HomeLoanAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
        HomeLoanAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_homeLoan(this, x);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
