#ifndef FLIGHTOFFER_HPP
#define FLIGHTOFFER_HPP

#include "Account.hpp"
#include "offerVisitor.hpp"

class FlightOffer : public OfferVisitor {
private:
	double miles;
public:
	FlightOffer() {miles = 0;}
	double visit_visa(Account* accnt) {miles = accnt->getBalance(); return miles;}
	double visit_mastercard(Account* accnt) {miles = accnt->getBalance(); return miles;}
};

#endif
