#ifndef MASTERCARDACCOUNT_HPP
#define MASTERCARDACCOUNT_HPP

#include "Account.hpp"
#include "visitor.hpp"
#include "offerVisitor.hpp"

class MastercardAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
        MastercardAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_mastercard(this, x);}
	double acceptOffer(OfferVisitor* o) {return o->visit_mastercard(this);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
