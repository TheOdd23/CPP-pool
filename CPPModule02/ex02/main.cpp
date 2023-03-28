#include <iostream>
#include "Fixed.hpp"

int	main( void ) {
	Fixed	a(10.5f);
	Fixed	b(2);
	const Fixed c(42);
	const Fixed d(8.75f);

	std::cout << a << " | " << b << std::endl;

	if (a < b)
		std::cout << "a is smaller then b" << std::endl;
	else
		std::cout << "a is not smaller then b" << std::endl;
	if (a <= b)
		std::cout << "a is smaller or equal then b" << std::endl;
	else
		std::cout << "a is not smaller or equal then b" << std::endl;
	if (a > b)
		std::cout << "a is bigger then b" << std::endl;
	else
		std::cout << "a is not bigger then b" << std::endl;
	if (a >= b)
		std::cout << "a is bigger or equal then b" << std::endl;
	else
		std::cout << "a is not bigger or equal then b" << std::endl;
	if (a >= (b + 8.5f))
		std::cout << "a is bigger or equal then b + 8.5" << std::endl;
	else
		std::cout << "a is not bigger or equal then b + 8.5" << std::endl;
	if (a == b)
		std::cout << "a is equal to b" << std::endl;
	else
		std::cout << "a is not equal to b" << std::endl;
	if (a != b)
		std::cout << "a is not equal to b" << std::endl;
	else
		std::cout << "a is equal to b" << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( c, d ) << std::endl;
	std::cout << Fixed::min( c, d ) << std::endl;
	/* Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;*/
return 0;
}