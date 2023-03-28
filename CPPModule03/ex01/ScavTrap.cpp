#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A ScavTrap has been borned" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name){
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "A Scavtrap has been borned and it's name is " << this->name << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src ){
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(){
	std::cout << "A Scavtrap has been destroyed" << std::endl;
}


ScavTrap & ScavTrap::operator=( ScavTrap const &src )
{
	std::cout << "Trap operator has been called" << std::endl;
	if ( this != &src )
	{
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
		this->name = src.name;
	}
	return *this;
}

void ScavTrap::attack( const std::string& target ){
	if ( this->HitPoints <= 0 )
	{
		std::cout << "ScavTrap " << this->name << " can't attack 'cause he dead" << std::endl;
		return ;
	}
	else if ( this->EnergyPoints <= 0 )
	{
		std::cout << "ScavTrap " << this->name << " can't attack 'cause he's out of energy" << std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
	std::cout << "ScavTrap " << this->name << " has " << this->EnergyPoints << " energy points left" << std::endl;
}

void	ScavTrap::guardGate() const{
	std::cout << "ScavTrap " << this->name << " entered Gate keeper mode" << std::endl;
}