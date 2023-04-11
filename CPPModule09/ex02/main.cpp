#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe pm(ac, &av[1]);
	pm.start_sorting();
	return (0);
}