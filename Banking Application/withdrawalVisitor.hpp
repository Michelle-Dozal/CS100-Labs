#ifndef WITHDRAWALVISITOR_HPP
#define WITHDRAWALVISITOR_HPP

#include "Account.hpp"
#include "visitor.hpp"

class WithdrawalVisitor : public Visitor {
public:
	WithdrawalVisitor() {};
	void visit_savings(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
	void visit_checking(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
	void visit_visa(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
	void visit_mastercard(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
	void visit_homeLoan(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
	void visit_carLoan(Account* accnt, double x) {double y = accnt->getBalance(); y -= x; accnt->setBalance(y);}
};

#endif
