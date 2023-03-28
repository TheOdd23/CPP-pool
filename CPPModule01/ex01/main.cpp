#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main(){
	Zombie *Horde;
	Zombie *Horde2;
	int	i;

	Horde = zombieHorde(5, "Gaetan Barette");
	for(i = 0; i < 5; i++)
		Horde[i].announce();
	delete[] Horde;
	Horde2 = zombieHorde(12, "Pierre Fitzgibbon");
	for(i = 0; i < 12; i++)
		Horde2[i].announce();
	std::cout << "Oh no, he's become a superminister Zombie, destroy it with ethics" << std::endl;
	delete[] Horde2;
	return (0);
}