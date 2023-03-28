#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "An animal has been spotted" << std::endl;
}

Animal::Animal( std::string type ): type(type)
{
	std::cout << "An animal of type " << this->type << " has been spotted" << std::endl;
}

Animal::Animal( Animal const &src ): type(src.getType())
{
	std::cout << "The animal is dividing..." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "*An animal left the chat*" << std::endl;
}

Animal &Animal::operator=( Animal const &src )
{
	std::cout << "The animals have become identical" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}

void	Animal::makeSound() const
{
	std::cout << "*Suspicious animal noise in the woods*" << std::endl;
}

const std::string &Animal::getType() const
{
	return this->type;
}
