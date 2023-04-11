#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Soupe1;
	ClapTrap Soupe("Soupe");
    Soupe1.set_name("Jean-Guy");
	std::cout << std::endl;
	
    std::cout << Soupe1;
	std::cout << Soupe;
	std::cout << std::endl;
	
    Soupe1.set_attack(9000);
	Soupe1.attack("Beau Jack");
	std::cout << std::endl;
	
    Soupe.attack("Beau Jack");
	Soupe.takeDamage(9);
	Soupe.beRepaired(2);
	Soupe.beRepaired(12);
	Soupe.set_attack(23);
	Soupe.attack("Beau Jack");
	Soupe.attack("Beau Jack");
	Soupe.takeDamage(9);
	Soupe.beRepaired(12);
	Soupe.attack("Beau Jack");
	std::cout << std::endl;
	
    Soupe1.attack("Beau Jack");
	std::cout << std::endl;
	
    Soupe.attack("Beau Jack");
	Soupe.takeDamage(2);
	Soupe.takeDamage(1);
	Soupe.beRepaired(1);
	Soupe.beRepaired(1);
	Soupe.takeDamage(16);
	Soupe.attack("Beau Jack");
	std::cout << std::endl;
	
    Soupe1 = Soupe;
	Soupe1.beRepaired(42);
	Soupe1.attack("Antho");
	return (0);
}
