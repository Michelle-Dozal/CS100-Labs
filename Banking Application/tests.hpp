#ifndef TESTS_HPP
#define TESTS_HPP

#include "gtest/gtest.h"

#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "MastercardAccount.hpp"
#include "HomeLoanAccount.hpp"
#include "CarLoanAccount.hpp"

#include "visitor.hpp"
#include "depositVisitor.hpp"
#include "withdrawalVisitor.hpp"

#include "offerVisitor.hpp"
#include "flightOffer.hpp"
#include "cashbackOffer.hpp"

#include "user.hpp"

TEST(BankTest, Test1) {
	User* u = new User();
	u->savings = new SavingsAccount();
	Visitor* d = new DepositVisitor();
	u->savings->accept(d, 1500);
	Visitor* w = new WithdrawalVisitor();
	u->savings->accept(w, 450);
	EXPECT_EQ(u->savings->getBalance(), 1050);
}

TEST(BankTest, Test2) {
        User* u = new User();
        u->checking = new CheckingAccount();
        Visitor* d = new DepositVisitor();
        u->checking->accept(d, 2000);
        Visitor* w = new WithdrawalVisitor();
        u->checking->accept(w, 450);
        EXPECT_EQ(u->checking->getBalance(), 1550);
}

TEST(BankTest, Test3) {
        User* u = new User();
        u->mastercard = new MastercardAccount();
        Visitor* d = new DepositVisitor();
        u->mastercard->accept(d, 2000);
        Visitor* w = new WithdrawalVisitor();
        u->mastercard->accept(w, 450);
	OfferVisitor* f = new FlightOffer();
        EXPECT_EQ(u->mastercard->acceptOffer(f), 1550);
}

TEST(BankTest, Test4) {
        User* u = new User();
        u->visa = new VisaAccount();
        Visitor* d = new DepositVisitor();
        u->visa->accept(d, 2000);
        Visitor* w = new WithdrawalVisitor();
        u->visa->accept(w, 450);
        OfferVisitor* c = new CashbackOffer();
        EXPECT_EQ(u->visa->acceptOffer(c), 15.5);
}

TEST(BankTest, Test5) {
        User* u = new User();
        u->homeLoan = new HomeLoanAccount();
        Visitor* d = new DepositVisitor();
        u->homeLoan->accept(d, 500);
        Visitor* w = new WithdrawalVisitor();
        u->homeLoan->accept(w, 450);
        EXPECT_EQ(u->homeLoan->getBalance(), 50);
}

TEST(BankTest, Test6) {
        User* u = new User();
        u->carLoan = new CarLoanAccount();
        Visitor* d = new DepositVisitor();
        u->carLoan->accept(d, 450);
        Visitor* w = new WithdrawalVisitor();
        u->carLoan->accept(w, 450);
        EXPECT_EQ(u->carLoan->getBalance(), 0);
}

#endif
