#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "An animal has been spotted" << std::endl;
}

AAnimal::AAnimal( std::string type ): type(type)
{
	std::cout << "An animal of type " << type << " has been spotted" << std::endl;
}

AAnimal::AAnimal( AAnimal const &src ): type(src.getType())
{
	std::cout << "The animal is dividing..." << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "*An animal left the chat*" << std::endl;
}

AAnimal & AAnimal::operator=( AAnimal const &src )
{
	std::cout << "The animals have become identical" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}

void	AAnimal::makeSound() const
{
	std::cout << "*Suspicious animal noise in the woods*" << std::endl;
}

const std::string &AAnimal::getType() const
{
	return this->type;
}
