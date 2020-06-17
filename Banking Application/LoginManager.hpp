#ifndef __LOGIN_MANAGER_HPP__
#define __LOGIN_MANAGER_HPP__

#include <string>

class LoginManager {
    public:
	std::string usernameAttempt;
	std::string passwordAttempt;
	loginManager(){
	}
	void login(){
		std::cout << "Username: ";
		std::cin >> usernameAttempt;
		if(usernameAttempt == username){
			std::cout << "Password: ";
			std::cin >> passwordAttempt;
			if(passwordAttempt == password){
				std::cout << "Login Successful" << std::endl;
			}else{
				cout << "Invalid Password.
	}
};

#endif //__LOGIN_MANAGER_HPP__
