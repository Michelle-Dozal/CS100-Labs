#include "user.hpp"

#include <iostream>
#include "Account.hpp"
#include "visitor.hpp"
#include "offerVisitor.hpp"
#include "depositVisitor.hpp"
#include "withdrawalVisitor.hpp"
#include "flightOffer.hpp"
#include "cashbackOffer.hpp"
#include <string>
#include <iomanip>

using namespace std;

void User::printMenu() {
	cout<<"Please choose an option: "<<endl;
	cout<<"(A) Open an account"<<endl;
	cout<<"(B) View Checking Account"<<endl;
	cout<<"(C) View Savings Account"<<endl;
	cout<<"(D) View Visa Account"<<endl;
	cout<<"(E) View Mastercard Account"<<endl;
	cout<<"(F) View Home Loan"<<endl;
	cout<<"(G) View Car Loan"<<endl;
	cout<<"(Q) Quit"<<endl;
}

void User::openAccount() {
	cout<<"Select which kind of account to open: "<<endl;
	cout<<"(A) Checking Account"<<endl;
	cout<<"(B) Savings Account"<<endl;
	cout<<"(C) Visa Account"<<endl;
	cout<<"(D) Mastercard Account"<<endl;
	cout<<"(E) Home Loan"<<endl;
	cout<<"(F) Car Loan"<<endl;
	cout<<"(Q) Quit"<<endl;
	char userIn;
	cin>>userIn;
	while (userIn != 'Q'){
		if (userIn == 'A'){
			if (checking != nullptr) {
				cout<<"You already have a checking account."<<endl;
				return;
			}
			checking = new CheckingAccount();
		}
		else if (userIn == 'B'){
        	        if (savings != nullptr) {
        	                cout<<"You already have a savings account."<<endl;
        	                return;
        	        }
        	        savings = new SavingsAccount();
        	}
		else if (userIn == 'C'){
        	        if (visa != nullptr) {
        	                cout<<"You already have a visa account."<<endl;
        	                return;
        	        }
        	        visa = new VisaAccount();
        	}
		else if (userIn == 'D'){
        	        if (mastercard != nullptr) {
        	                cout<<"You already have a mastercard account."<<endl;
        	                return;
        	        }
        	        mastercard = new MastercardAccount();
        	}
		else if (userIn == 'E'){
        	        if (homeLoan != nullptr) {
        	                cout<<"You already have a home loan."<<endl;
        	                return;
        	        }
        	        homeLoan = new HomeLoanAccount();
        	}
		else if (userIn == 'F'){
        	        if (carLoan != nullptr) {
        	                cout<<"You already have a car loan."<<endl;
        	                return;
        	        }
        	        carLoan = new CarLoanAccount();
        	}
		else {
			cout<<"Error: Invalid input."<<endl;
		}
		cout<<"Open another kind of account: "<<endl;
	        cout<<"(A) Checking Account"<<endl;
	        cout<<"(B) Savings Account"<<endl;
	        cout<<"(C) Visa Account"<<endl;
	        cout<<"(D) Mastercard Account"<<endl;
	        cout<<"(E) Home Loan"<<endl;
	        cout<<"(F) Car Loan"<<endl;
	        cout<<"(Q) Quit"<<endl;
		cin>>userIn;
	}
	return;
}

void User::checkSavings() {
	if (savings == nullptr){
		cout<<"Error: No savings account found."<<endl;
		return;
	}
	cout<<"Savings Account"<<endl;
	cout<<"Balance: $" << fixed<<setprecision(2)<<savings->getBalance()<<endl;
	cout<<"(A) Make a deposit"<<endl;
	cout<<"(B) Make a withdrawal"<<endl;
	cout<<"(Q) Quit"<<endl;
	char userIn;
	cin>>userIn;
	while (userIn != 'Q'){
		if (userIn == 'A'){
			cout<<"Deposit amount: $";
			double amnt;
			cin>>amnt;
			Visitor* d = new DepositVisitor();
			savings->accept(d, amnt);
		}
		else if (userIn == 'B'){
			if (savings->getBalance() == 0){
				cout<<"Cannot make withdrawal, balance is zero."<<endl;
			}
			else {
        	        	cout<<"Withdraw amount: $";
        	       		double amnt;
        	        	cin>>amnt;
				if (amnt > savings->getBalance()){
					cout<<"Not enough money in account."<<endl;
				}
				else{
	        	        	Visitor* w = new WithdrawalVisitor();
        		        	savings->accept(w, amnt);
				}
			}
        	}
		else {
			cout<<"Error: Invalid input."<<endl;
		}
		cout<<"Balance: $" <<fixed<<setprecision(2)<< savings->getBalance()<<endl;
	        cout<<"(A) Make a deposit"<<endl;
        	cout<<"(B) Make a withdrawal"<<endl;
       		cout<<"(Q) Quit"<<endl;
		cin>>userIn;
	}	
}

void User::checkChecking() {
	if (checking == nullptr){
		cout<<"Error: No checking account found."<<endl;
		return;
	}
	cout<<"Checking Account"<<endl;
        cout<<"Balance: $" <<fixed<<setprecision(2)<< checking->getBalance()<<endl;
        cout<<"(A) Make a deposit"<<endl;
        cout<<"(B) Make a withdrawal"<<endl;
        cout<<"(Q) Quit"<<endl;
        char userIn;
        cin>>userIn;
        while (userIn != 'Q'){
                if (userIn == 'A'){
                        cout<<"Deposit amount: $";
                        double amnt;
                        cin>>amnt;
                        Visitor* d = new DepositVisitor();
                        checking->accept(d, amnt);
                }
                else if (userIn == 'B'){
			if (checking->getBalance() == 0){
				cout<<"Cannot make withdrawal, balance is zero."<<endl;
                        }
			else {
                        	cout<<"Withdraw amount: $";
                        	double amnt;
                        	cin>>amnt;
				if (amnt > checking->getBalance()){
                                        cout<<"Not enough money in account."<<endl;
                                }
                                else{
        	                        Visitor* w = new WithdrawalVisitor();
 	                               checking->accept(w, amnt);
                                }
			}
                }	
                else {
                        cout<<"Error: Invalid input."<<endl;
                }
                cout<<"Balance: $" <<fixed<<setprecision(2)<< checking->getBalance()<<endl;
                cout<<"(A) Make a deposit"<<endl;
                cout<<"(B) Make a withdrawal"<<endl;
                cout<<"(Q) Quit"<<endl;
                cin>>userIn;
        }
}

void User::checkVisa() {
	if (visa == nullptr){
                cout<<"Error: No visa account found."<<endl;
                return;
        }
	cout<<"Visa Account"<<endl;
        cout<<"Balance: $" <<fixed<<setprecision(2)<< visa->getBalance()<<endl;
	cout<<"Offers"<<endl;
	OfferVisitor* f = new FlightOffer();
	cout<<"Flight miles: "<<visa->acceptOffer(f)<<endl;
	OfferVisitor* c	= new CashbackOffer();
	cout<<"Cashback: $"<< visa->acceptOffer(c)<<endl;
        cout<<"(A) Make a deposit"<<endl;
        cout<<"(B) Make a withdrawal"<<endl;
        cout<<"(Q) Quit"<<endl;
        char userIn;
        cin>>userIn;
        while (userIn != 'Q'){
                if (userIn == 'A'){
                        cout<<"Deposit amount: $";
                        double amnt;
                        cin>>amnt;
                        Visitor* d = new DepositVisitor();
                        visa->accept(d, amnt);
                }
                else if (userIn == 'B'){
			if (visa->getBalance() == 0){
				cout<<"Cannot make withdrawal, balance is zero."<<endl;
                        }
			else {
                        	cout<<"Withdraw amount: $";
                        	double amnt;
                        	cin>>amnt;
				if (amnt > visa->getBalance()){
                                        cout<<"Not enough money in account."<<endl;
                                }
                                else{
                                       Visitor* w = new WithdrawalVisitor();
                                       visa->accept(w, amnt);
                                }
			}
                }
                else {
                        cout<<"Error: Invalid input."<<endl;
                }
                cout<<"Balance: $" <<fixed<<setprecision(2)<< visa->getBalance()<<endl;
		cout<<"Offers"<<endl;
        	OfferVisitor* f = new FlightOffer();
        	cout<<"Flight miles: "<<visa->acceptOffer(f)<<endl;
       		OfferVisitor* c = new CashbackOffer();
  	     	cout<<"Cashback: $"<< visa->acceptOffer(c)<<endl;
                cout<<"(A) Make a deposit"<<endl;
                cout<<"(B) Make a withdrawal"<<endl;
                cout<<"(Q) Quit"<<endl;
                cin>>userIn;
        }
}

void User::checkMaster() {
	if (mastercard == nullptr){
                cout<<"Error: No mastercard account found."<<endl;
                return;
        }
	cout<<"Mastercard Account"<<endl;
	cout<<"Balance: $" <<fixed<<setprecision(2)<< mastercard->getBalance()<<endl;
	cout<<"Offers"<<endl;
	OfferVisitor* f = new FlightOffer();
	cout<<"Flight miles: "<<mastercard->acceptOffer(f)<<endl;
        OfferVisitor* c = new CashbackOffer();
        cout<<"Cashback: $"<< mastercard->acceptOffer(c)<<endl;
        cout<<"(A) Make a deposit"<<endl;
        cout<<"(B) Make a withdrawal"<<endl;
        cout<<"(Q) Quit"<<endl;
        char userIn;
        cin>>userIn;
        while (userIn != 'Q'){
                if (userIn == 'A'){
                        cout<<"Deposit amount: $";
                        double amnt;
                        cin>>amnt;
                        Visitor* d = new DepositVisitor();
                        mastercard->accept(d, amnt);
                }
                else if (userIn == 'B'){
			if (mastercard->getBalance() == 0){
				cout<<"Cannot make withdrawal, balance is zero."<<endl;
                        }
			else {
                        	cout<<"Withdraw amount: $";
                        	double amnt;
                        	cin>>amnt;
				if (amnt > mastercard->getBalance()){
                                        cout<<"Not enough money in account."<<endl;
                                }
                                else{
                                       Visitor* w = new WithdrawalVisitor();
                                       mastercard->accept(w, amnt);
                                }
			}
                }
                else {
                        cout<<"Error: Invalid input."<<endl;
                }
                cout<<"Balance: $" <<fixed<<setprecision(2)<< mastercard->getBalance()<<endl;
		cout<<"Offers"<<endl;
        	OfferVisitor* f = new FlightOffer();
        	cout<<"Flight miles: "<<mastercard->acceptOffer(f)<<endl;
        	OfferVisitor* c = new CashbackOffer();
        	cout<<"Cashback: $"<< mastercard->acceptOffer(c)<<endl;
                cout<<"(A) Make a deposit"<<endl;
                cout<<"(B) Make a withdrawal"<<endl;
                cout<<"(Q) Quit"<<endl;
                cin>>userIn;
        }
}

void User::checkHome() {
	if (homeLoan == nullptr){
                cout<<"Error: No home loan found."<<endl;
                return;
        }
	cout<<"Home Loan"<<endl;
        cout<<"Balance: $" <<fixed<<setprecision(2)<< homeLoan->getBalance()<<endl;
        cout<<"(A) Make a deposit"<<endl;
        cout<<"(B) Make a withdrawal"<<endl;
        cout<<"(Q) Quit"<<endl;
        char userIn;
        cin>>userIn;
        while (userIn != 'Q'){
                if (userIn == 'A'){
                        cout<<"Deposit amount: $";
                        double amnt;
                        cin>>amnt;
                        Visitor* d = new DepositVisitor();
                        homeLoan->accept(d, amnt);
                }
                else if (userIn == 'B'){
			if (homeLoan->getBalance() == 0){
				cout<<"Cannot make withdrawal, balance is zero."<<endl;
                        }
			else {
                        	cout<<"Withdraw amount: $";
                        	double amnt;
                        	cin>>amnt;
				if (amnt > homeLoan->getBalance()){
                                        cout<<"Not enough money in account."<<endl;
                                }
                                else{
                                       Visitor* w = new WithdrawalVisitor();
                                       homeLoan->accept(w, amnt);
                                }
			}
                }
                else {
                        cout<<"Error: Invalid input."<<endl;
                }
                cout<<"Balance: $" <<fixed<<setprecision(2)<< homeLoan->getBalance()<<endl;
                cout<<"(A) Make a deposit"<<endl;
                cout<<"(B) Make a withdrawal"<<endl;
                cout<<"(Q) Quit"<<endl;
                cin>>userIn;
        }
}

void User::checkCar() {
	if (carLoan == nullptr){
                cout<<"Error: No car loan found."<<endl;
                return;
        }
	cout<<"Car Loan"<<endl;
        cout<<"Balance: $" << fixed<<setprecision(2)<<carLoan->getBalance()<<endl;
        cout<<"(A) Make a deposit"<<endl;
        cout<<"(B) Make a withdrawal"<<endl;
        cout<<"(Q) Quit"<<endl;
        char userIn;
        cin>>userIn;
        while (userIn != 'Q'){
                if (userIn == 'A'){
                        cout<<"Deposit amount: $";
                        double amnt;
                        cin>>amnt;
                        Visitor* d = new DepositVisitor();
                        carLoan->accept(d, amnt);
                }
                else if (userIn == 'B'){
			if (carLoan->getBalance() == 0) {
				cout<<"Cannot make withdrawal, balance is zero. oof"<<endl;
                        }
			else {
                        	cout<<"Withdraw amount: $";
                        	double amnt;
                        	cin>>amnt;
				if (amnt > carLoan->getBalance()){
                                        cout<<"Not enough money in account. :( rip"<<endl;
                                }
                                else{
                                       Visitor* w = new WithdrawalVisitor();
                                       carLoan->accept(w, amnt);
                                }
			}
                }
                else {
                        cout<<"Error: Invalid input."<<endl;
                }
                cout<<"Balance: $" <<fixed<<setprecision(2)<< carLoan->getBalance()<<endl;
                cout<<"(A) Make a deposit"<<endl;
                cout<<"(B) Make a withdrawal"<<endl;
                cout<<"(Q) Quit"<<endl;
                cin>>userIn;
        }
}
