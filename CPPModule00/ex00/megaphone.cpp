#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int		i, ii;
	char	c;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBERABLE NOISE *\n";
		return (0);
	}
	for (i = 1; i < ac; i++)
	{
		ii = 0;
		while (av[i][ii])
		{
			c = toupper(av[i][ii]);
			std::cout << c;
			ii++;
		}
	}
	std::cout << std::endl;
	return (0);
}
