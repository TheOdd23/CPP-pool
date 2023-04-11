#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap Soupe("Soupe");
	ScavTrap Johny("Grelot");
	std::cout << std::endl;
	
    Johny.attack("Beau Jack");
	Johny.takeDamage(9);
	Johny.beRepaired(256);
	Johny.beRepaired(12);
	Johny.attack("Beau Jack");
	Johny.attack("Beau Jack");
	Johny.takeDamage(9);
	Johny.beRepaired(12);
	Johny.guardGate();
	std::cout << std::endl;
	
    std::cout << "Back to ClapTrap" << std::endl;
	std::cout << std::endl;
	
    Soupe.attack("Brute sanguinaire");
	Soupe.takeDamage(9);
	Soupe.beRepaired(2);
	Soupe.beRepaired(12);
	Soupe.set_attack(23);
	Soupe.attack("Brute sanguinaire");
	Soupe.attack("Brute sanguinaire");
	Soupe.takeDamage(9);
	Soupe.beRepaired(12);
	Soupe.attack("Brute sanguinaire");
	Soupe.attack("Brute sanguinaire");
	Soupe.attack("Brute sanguinaire");
	Soupe.takeDamage(2);
	Soupe.takeDamage(1);
	Soupe.beRepaired(1);
	Soupe.beRepaired(1);
	Soupe.takeDamage(16);
	Soupe.attack("Brute sanguinaire");
	std::cout << std::endl;
	return (0);
}
