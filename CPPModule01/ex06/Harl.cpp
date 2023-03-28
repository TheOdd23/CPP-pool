#include "Harl.hpp"

Harl::Harl(){
	this->function[0] = "DEBUG";
	this->function[1] = "INFO";
	this->function[2] = "WARNING";
	this->function[3] = "ERROR";
	return;
}

Harl::~Harl(){
	return;
}

void Harl::debug(){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger." << std::endl << "I really do!" << std::endl;
}

void Harl::info(){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger!" << std::endl 
	<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I've been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::error(){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}



void Harl::complain( std::string level ){
	int res;

	for(res = 0; res < 4; res++)
	{
		if (level == function[res])
			break ;
	}
	switch(res){
		case 0:
			this->debug();
			std::cout << std::endl;
		case 1:
			info();
			std::cout << std::endl;
		case 2:
			warning();
			std::cout << std::endl;
		case 3:
			error();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}