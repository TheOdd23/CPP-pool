#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{
	int		i, ii;
	std::string	str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBERABLE NOISE *\n";
		return (0);
	}
	for (i = 1; i < ac; i++)
	{
		ii = 0;
		str = av[i];
		while (str[ii] != *str.end())
		{
			str[ii] = toupper(str[ii]);
			std::cout << str[ii];
			ii++;
		}
	}
	std::cout << std::endl;
	return (0);
}
