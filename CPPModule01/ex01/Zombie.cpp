#include "Zombie.hpp"

Zombie::~Zombie(){
	std::cout << name << " has been destroyed" << std::endl;
}

Zombie::Zombie(){
	std::cout << "A zombie has been created" << std::endl;
}

void	Zombie::announce() const{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::Givename( std::string &Zombiename ){
	Zombie::name = Zombiename;
}