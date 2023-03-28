#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	int		i;
	Zombie	*Horde;

	i = -1;
	Horde = new	Zombie[N];
	while (++i < N)
		Horde[i].Givename(name);
	return (Horde);
}
