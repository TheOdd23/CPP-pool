#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "It is a cat *pspsp pspsps*" << std::endl;
}

Cat::Cat( std::string Ctype ): Animal(Ctype){
	std::cout << "It is a cat and is of type " << this->type << std::endl;
}

Cat::Cat( Cat const &src ): Animal(src.getType()){
	std::cout << "Seems like the cat is dividing 😨" << std::endl;
	*this = src;
}

Cat::~Cat(){
	std::cout << "Cat saw a bird and decided to leave" << std::endl;
}

Cat &Cat::operator=( Cat const &src){
	std::cout << "The cats have become identical" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}

void    Cat::makeSound() const{
	std::cout << "Meow... Meow..." << std::endl;
}