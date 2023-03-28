#include "Fixed.hpp"

Fixed::Fixed(): nb(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=( Fixed const &src ){
	std::cout << "Copy assignement operator called" << std::endl;
	if ( this != &src )
		this->nb = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return nb;
}

void Fixed::setRawBits(int const raw){
	this->nb = raw;
}