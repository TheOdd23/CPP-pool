#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap_clap_name"){
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "A DiamondTrap has been borned" << std::endl;
}

DiamondTrap::DiamondTrap( std::string DT_name ): ClapTrap(DT_name + "_clap_name"){
	this->name = DT_name;
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDamage = FragTrap::AttackDamage;
	std::cout << "A Diamondtrap has been borned and it's name is " << this->name << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ){
	std::cout << "DiamondTrap copy constructor has been called" << std::endl;
	ClapTrap::set_name(src.get_name());
	*this = src;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "A Diamondtrap has been destroyed" << std::endl;
}


DiamondTrap & DiamondTrap::operator=( DiamondTrap const &src )
{
	std::cout << "DiamondTrap operator has been called" << std::endl;
	if ( this != &src )
	{
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
		this->name = src.name;
	}
	return *this;
}

void DiamondTrap::attack( const std::string& target ){
	ScavTrap::attack(target);
}

void	DiamondTrap::WhoAmI() const{
	std::cout << "I am " << name << ", built by " << ClapTrap::name << std::endl;
}