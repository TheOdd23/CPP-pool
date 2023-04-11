#include <iostream>
#include "Converter.hpp"

// Static cast: Fait une conversion implicite entre deux types de data (exemple transforme un int en char, float en int, etc);
// Conversion simple qui est fait au temps de compilation
int	main(int ac, char **av)
{
	Converter a;
	Converter b;
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments..." << std::endl;
		return (1);
	}
	std::string	var = av[1];
	a.setTypes(var);
	Converter c(a);
	b = a;
	
    std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c;
	return (0);
}
