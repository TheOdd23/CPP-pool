#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "A WrongAnimal has been spotted" << std::endl;
}

WrongAnimal::WrongAnimal( std::string WAtype ): type(WAtype)
{
	std::cout << "A WrongAnimal of type " << type << " has been spotted" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ): type(src.getType())
{
	std::cout << "WrongAnimal copy constructor has been called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "A WrongAnimal has been destroyed" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const &src )
{
	std::cout << "WrongAnimal operator has been called" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Suspicious wrong animal noise in the woods*" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
	return this->type;
}