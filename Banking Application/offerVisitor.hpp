#ifndef OFFERVISITOR_HPP
#define OFFERVISITOR_HPP

#include "Account.hpp"

class OfferVisitor {
public:
	OfferVisitor() {};
	virtual double visit_visa(Account* accnt) = 0;
	virtual double visit_mastercard(Account* accnt) = 0;
};

#endif
