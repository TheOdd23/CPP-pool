#include "Fixed.hpp"

Fixed::Fixed(): fixed_nb(0){
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ){
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Tasse les bits de huit pour aller chercher les bits apres la virgule et transformer le tout en fixedpoint nb de 32 bits 'entier'
Fixed::Fixed(int const fixed_nbr){
	//std::cout << "Int constructor called" << std::endl;
	this->setRawBits(fixed_nbr << frac);
}

// Transforme le float en fixed number en multipliant sa valeur par 256 pour remettre le tout sur 32 bits 'entier'
Fixed::Fixed(float const flo){
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(flo * 256));
}

Fixed & Fixed::operator=( Fixed const &src ){
	//std::cout << "Copy assignement operator called" << std::endl;
	if ( this != &src )
		this->fixed_nb = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

// Retasse de huit bits pour enlever les huits bits apres la virgule 
int	Fixed::toInt( void ) const{
	return this->getRawBits() >> frac;
}

// Redivise le fixed number par 256 bits pour retrouver huit bits après la virgule
float Fixed::toFloat( void ) const{
	return (float)getRawBits() / 256;
}

int Fixed::getRawBits(void) const{
	return this->fixed_nb;
}

void Fixed::setRawBits(int const raw){
	this->fixed_nb = raw;
}

std::ostream &operator << ( std::ostream &out, Fixed const &fixed_nb ){
	out << fixed_nb.toFloat();
	return out;
}

// Opérateurs de comparaison
bool Fixed::Fixed::operator>(const Fixed &src) const{
	return this->fixed_nb > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const{
	return this->fixed_nb < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const{
	return this->fixed_nb >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const{
	return this->fixed_nb <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const{
	return this->fixed_nb == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const{
	return this->fixed_nb != src.getRawBits();
}

// Opérateurs Arithmetiques
Fixed Fixed::operator+(const Fixed &src) const{
	return this->toFloat() + src.toFloat();
}

Fixed Fixed::operator-(const Fixed &src) const{
	return this->toFloat() - src.toFloat();
}

Fixed Fixed::operator*(const Fixed &src) const{
	return this->toFloat() * src.toFloat();
}

Fixed Fixed::operator/(const Fixed &src) const{
	return this->toFloat() / src.toFloat();
}

// Opérateurs d'incrémentations et décrémentation
// Prefix
Fixed &Fixed::operator++(){
	this->fixed_nb++;
	return *this;
}

Fixed &Fixed::operator--(){
	this->fixed_nb--;
	return *this;
}

// Postfix
Fixed Fixed::operator++(int){
	Fixed fixed(*this);
	this->fixed_nb++;
	return fixed;
}

Fixed Fixed::operator--(int){
	Fixed fixed(*this);
	this->fixed_nb--;
	return fixed;
}

// Fonctions min/max
Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a > b)
		return b;
	else
		return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a < b)
		return b;
	else
		return a;
}
