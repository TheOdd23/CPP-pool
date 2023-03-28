#include "HumanA.hpp"

HumanA::HumanA( std::string a_name, Weapon &a_weapon ): name(a_name), type(a_weapon){
	std::cout << name << " has been created with his own " << this->type.getType() << std::endl;
}

HumanA::~HumanA(){
		std::cout << name << " has been killed" << std::endl;
}

void	HumanA::attack() const{
	std::cout << this->name << " attacks with their " << this->type.getType() << std::endl;
}

void	HumanA::setWeapon( Weapon &kind ){
	this->type = kind;
}