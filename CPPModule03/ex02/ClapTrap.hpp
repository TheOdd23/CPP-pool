#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{
	
	protected:
		std::string		name;
		int	HitPoints;
		int	EnergyPoints;
		int	AttackDamage;
	
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const &src );
		~ClapTrap();
		ClapTrap &operator=( ClapTrap const &src );
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		int		get_attack() const;
		void	set_attack( int damage );
		std::string	get_name() const;
		void	set_name( std::string cp_name );
};



#endif