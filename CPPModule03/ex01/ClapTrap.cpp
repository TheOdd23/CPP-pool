#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "A ClapTrap has been borned" << std::endl;
}

ClapTrap::ClapTrap( std::string ct_name ): name(ct_name), HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "A Claptrap has been borned and it's name is " << this->name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src ){
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(){
	std::cout << "A Claptrap has been destroyed" << std::endl;
}


ClapTrap & ClapTrap::operator=( ClapTrap const &src )
{
	std::cout << "ClapTrap operator has been called" << std::endl;
	if ( this != &src )
	{
		this->HitPoints = src.HitPoints;
		this->EnergyPoints = src.EnergyPoints;
		this->AttackDamage = src.AttackDamage;
		this->name = src.name;
	}
	return *this;
}

void ClapTrap::attack( const std::string& target )
{
	if ( this->HitPoints <= 0 )
	{
		std::cout << "ClapTrap " << this->name << " can't attack 'cause he dead" << std::endl;
		return ;
	}
	else if ( this->EnergyPoints <= 0 )
	{
		std::cout << "ClapTrap " << this->name << " can't attack 'cause he's out of energy" << std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
	std::cout << "ClapTrap " << this->name << " has " << this->EnergyPoints << " energy points left" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
	if ( this->HitPoints <= 0 )
	{
		std::cout << "A ClapTrap " << " is already dead" << std::endl;
		return ;
	}
	this->HitPoints -= amount;
	if ( this->HitPoints < 0 )
		this->HitPoints = 0;
	std::cout << "A ClapTrap " << " receives " << amount << " points of damage and have "  << this->HitPoints << " life left" << std::endl;
	if ( this->HitPoints <= 0 )
	{
		std::cout << "A ClapTrap " << " won't clap anymore, 'cause he dead now" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired( unsigned int amount ){
	if ( this->EnergyPoints == 0 )
	{
		std::cout << "A ClapTrap " << " can't repair itself 'cause he's out of energypoints" << std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	this->HitPoints += amount;
	if ( this->HitPoints > 10 )
		this->HitPoints = 10;
	std::cout << "A ClapTrap " << " repairs itself of " << amount << " points of damage, have " << this->HitPoints << " life points left and " << this->EnergyPoints << " energy points left" << std::endl;
}

int		ClapTrap::get_attack() const{
	return this->AttackDamage;
}

void	ClapTrap::set_attack( int damage ){
	this->AttackDamage = damage;
}

void	ClapTrap::set_name(std::string cp_name){
	this->name = cp_name;
}

std::string	ClapTrap::get_name() const{
	return this->name;
}