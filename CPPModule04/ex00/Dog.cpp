#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
	std::cout << "It is a dog!" << std::endl;
}

Dog::Dog( std::string Ctype ): Animal(Ctype){
	std::cout << "It is a dog and is of type " << this->type << std::endl;
}

Dog::Dog( Dog const &src ): Animal(src.getType()){
	std::cout << "The dog is creating a copy of itself 😨" << std::endl;
	*this = src;
}

Dog::~Dog(){
	std::cout << "Dog left to chew his bone" << std::endl;
}

Dog &Dog::operator=( Dog const &src){
	std::cout << "The Dogs have become identical" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}

void    Dog::makeSound() const{
	std::cout << "Woof... Woof..." << std::endl;
}