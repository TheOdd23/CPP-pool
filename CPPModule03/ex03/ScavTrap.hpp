#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:

		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const &src );
		~ScavTrap();
		ScavTrap &operator=( ScavTrap const &src );

		void	attack( const std::string& target );
		void	guardGate() const;
};

#endif