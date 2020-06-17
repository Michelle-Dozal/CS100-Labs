#ifndef CASHBACKOFFER_HPP
#define CASHBACKOFFER_HPP

#include "Account.hpp"
#include "offerVisitor.hpp"

class CashbackOffer : public OfferVisitor {
private:
	double cashback;
public:
	CashbackOffer() {cashback = 0;}
	double visit_visa(Account* accnt) {cashback = accnt->getBalance() * 0.01; return cashback;}
	double visit_mastercard(Account* accnt) {cashback = accnt->getBalance() * 0.01; return cashback;}
};

#endif
