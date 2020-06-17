#ifndef VISAACCOUNT_HPP
#define VISAACCOUNT_HPP_

#include "Account.hpp"
#include "visitor.hpp"
#include "offerVisitor.hpp"
class VisaAccount : public Account {
    private:
	double balance;	
    public:
        /* Constructors */
        VisaAccount() {balance = 0;}

        /* Pure Virtual Functions */
	void accept(Visitor* v, double x) {v->visit_visa(this, x);}
	double acceptOffer(OfferVisitor* o) {return o->visit_visa(this);}
	double getBalance(){ return balance; }
	void setBalance(double x) {balance = x;}
		  
};

#endif //__CREDIT_ACCOUNT_HPP__
