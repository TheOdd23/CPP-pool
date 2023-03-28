#include "Weapon.hpp"

Weapon::Weapon( std::string w_type ): type(w_type){
	std::cout << type << " has been created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << type << " has been destroyed" << std::endl;
}

const std::string &Weapon::getType() const{
	return (type);
}
	
void Weapon::setType( const std::string &w_type ){
	Weapon::type = w_type;
}
