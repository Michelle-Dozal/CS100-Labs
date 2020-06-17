#ifndef USER_HPP
#define USER_HPP

#include "Account.hpp"
#include "visitor.hpp"
#include "offerVisitor.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
#include "VisaAccount.hpp"
#include "MastercardAccount.hpp"
#include "HomeLoanAccount.hpp"
#include "CarLoanAccount.hpp"

class User {
public:
	User() : savings(nullptr), checking(nullptr), visa(nullptr), mastercard(nullptr), homeLoan(nullptr), carLoan(nullptr) {};
	void printMenu();
	void openAccount();
	void checkSavings();
	void checkChecking();
	void checkVisa();
	void checkMaster();
	void checkHome();
	void checkCar();

public:
	SavingsAccount* savings;
	CheckingAccount* checking;
	VisaAccount* visa;
	MastercardAccount* mastercard;
	HomeLoanAccount* homeLoan;
	CarLoanAccount* carLoan;
};

#endif