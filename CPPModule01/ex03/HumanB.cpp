#include "HumanB.hpp"

HumanB::HumanB( std::string b_name ): name(b_name){
	std::cout << name << " has been created" << std::endl;
}

HumanB::~HumanB(){
		std::cout << name << " has been killed" << std::endl;
}

void	HumanB::attack(){
	std::cout << this->name << " attacks with their " << this->type->getType() << std::endl;
}

void	HumanB::setWeapon( Weapon &kind ){
	this->type = &kind;
	std::cout << this->name << " takes " << this->type->getType() << std::endl;
}