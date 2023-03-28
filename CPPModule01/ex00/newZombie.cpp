#include "Zombie.hpp"

/* Créé sur la heap */
Zombie* newZombie( std::string name ){
	Zombie	*new_zombie;
	new_zombie = new Zombie(name);
	return(new_zombie);
}