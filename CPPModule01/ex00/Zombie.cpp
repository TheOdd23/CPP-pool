#include "Zombie.hpp"

Zombie::~Zombie(){
	std::cout << name << " has been destroyed" << std::endl;
}

Zombie::Zombie( std::string &Zombiename ): name(Zombiename){
	std::cout << name << " has been created" << std::endl;
}

void	Zombie::announce() const{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
