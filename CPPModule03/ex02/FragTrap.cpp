#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A FragTrap has been borned" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap(name){
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A FragTrap has been borned and it's name is " << this->name << std::endl;
}

FragTrap::FragTrap( FragTrap const &src ){
	std::cout << "FragTrap copy constructor has been called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "A FragTrap has been destroyed" << std::endl;
}


FragTrap & FragTrap::operator=( FragTrap const &src )
{
	std::cout << "FragTrap operator has been called" << std::endl;
	if ( this != &src )
	{
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
		this->name = src.name;
	}
	return *this;
}

void	FragTrap::highFivesGuys() const{
	std::cout << "FragTrap " << this->name << " wants to highfive you!" << std::endl;
	std::cout << "Do you want to highfive back? : y | n" << std::endl;
	std::string answer;
	while (std::cin >> answer){
		if (answer == "y")
		{
			std::cout << "Hell yeah! Mah man! 😎" << std::endl;
			break;
		}
		else if (answer == "n")
		{
			std::cout << "Why!!! You're tearing me appart... 😭" << std::endl;
			break;
		}
		else
			std::cout << "Why are you leaving me waiting? 😡" << std::endl;
	}
}