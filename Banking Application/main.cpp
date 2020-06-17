#include "user.hpp"

#include <iostream>

using namespace std;

int main() {
	User* u = new User();
	u->printMenu();
	char userIn;
	cin>>userIn;
	while (userIn != 'Q'){
		if(userIn == 'A'){
			u->openAccount();
		}
		else if (userIn == 'B'){
			u->checkChecking();
		}
		else if (userIn == 'C') {
			u->checkSavings();
		}
		else if (userIn == 'D') {
			u->checkVisa();
		}
		else if (userIn == 'E') {
			u->checkMaster();
		}
		else if (userIn == 'F') {
			u->checkHome();
		}
		else if (userIn == 'G') {
			u->checkCar();
		}
		else {
			cout<<"Error: Invalid input."<<endl;
		}
		u->printMenu();
		cin>>userIn;
	}	
	cout<<"Lit :D, have a nice day!"<<endl;

	return 0;
}
