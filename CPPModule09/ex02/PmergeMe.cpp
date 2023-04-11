#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int ac, char **args)
{
	error = containers_init(ac, args);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
 	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
 	vec.clear();
	vec = other.vec;
	mp.clear();
	mp = other.mp;
	error = other.error;
	return *this;
}

int	PmergeMe::containers_init(int ac, char **args)
{
	clock_t	start = clock();
	if (ac == 1)
		return 4;
	for(int i = 0; i < (ac - 1); i++)
	{
		std::string temp(args[i]);
		if (temp.find("-") != temp.npos)
			return 2;
		for (size_t j = 0; j < temp.size(); j++)
		{
			if (!isdigit(temp[j]))
				return 1;
		}
		try
		{
			if (std::stol(temp) > INT_MAX)
			{
				return 2;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			exit(1);
		}
		start = clock();
		vec.push_back(std::stoi(temp));
		vec_time += static_cast<double> (clock() - start) / 1000;
		start = clock();
		mp.insert(std::make_pair(i, std::stoi(temp)));
		mp_time += static_cast<double> (clock() - start) / 1000;
	}
	if (vec.size() == 1)
		return 5;
	return 0;
}

bool	PmergeMe::is_in_order(std::vector<int> vec) const
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it + 1 == vec.end())
			return true;
		if (*it > *(it + 1))
			break ;
	}
	return false;
}

void	PmergeMe::print_sequence()
{
	std::cout << "        Vector:";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "        Map:";
	for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << " " << it->second;
	std::cout << std::endl;
}

void	PmergeMe::print_containers()
{
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << vec_time << " ms" << std::endl;
	std::cout << "Time to process a range of " << mp.size() << " elements with std::map : " << std::fixed << std::setprecision(5) << mp_time << " ms" << std::endl;
}

void	PmergeMe::start_sorting()
{
	switch(error)
	{
		case 1:
		{
			std::cerr << "Error, presence of undesirable character in arguments" << std::endl;
			return ;
		}
		case 2:
		{
			std::cerr << "Error, not all arguments are integers or positive integers" << std::endl;
			return ;
		}
		case 3:
		{
			std::cerr << "Error, presence of duplicates" << std::endl;
			return ;
		}
		case 4:
		{
			std::cerr << "Error, no arguments given" << std::endl;
			return ;
		}
		case 5:
		{
			std::cerr << "Error, takes two numbers to be sorted" << std::endl;
			return ;
		}
	}
	std::cout << "Before:" << std::endl;
	print_sequence();
	if (!is_in_order(vec))
	{
		clock_t	start = clock();
		merge_sort(vec, 0, vec.size() - 1);
		vec_time += static_cast<double> (clock() - start) / 1000;
		start = clock();
		merge_sort(mp, 0, mp.size() - 1);
		mp_time += static_cast<double> (clock() - start) / 1000;
	}
	else
	{
		vec_time = 0;
		mp_time = 0;
	}
	std::cout << std::endl << "After:" << std::endl;
	print_sequence();
	std::cout << std::endl;
	print_containers();
}

template <typename Cont>
void PmergeMe::insert_sort(Cont &cont, int start, int end)
{
	for (int i = start + 1; i <= end; i++)
	{
		int val = cont[i];
		int j = i - 1;
		while (j >= start && cont[j] > val)
		{
			cont[j + 1] = cont[j];
			j--;
		}
		cont[j + 1] = val;
	}
}

template <typename Cont>
void PmergeMe::merge_sort(Cont &cont, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort(cont, start, mid); //Sépare le contenu des containers en binômes
		merge_sort(cont, mid + 1, end);
		if (cont[start] > cont[end])
			std::swap(cont[start], cont[end]); //Remet les binômes en ordre (les binômes ne sont pas en ordre entre eux)
		insert_sort(cont, start, end); //Remet le tout en ordre
	}
}
