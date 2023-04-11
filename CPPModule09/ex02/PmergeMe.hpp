#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <ctime>
#include <algorithm>
#include <exception>

class PmergeMe
{
	public:
		PmergeMe(int ac, char **args);
		~PmergeMe();

		void	start_sorting();
	private:
		std::vector<int>	vec;
		std::map<int, int>	mp;
		int		error;
		double	vec_time;
		double	mp_time;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		
		template<typename Cont>
		void	merge_sort(Cont &cont, int low, int high);
		template<typename Cont>
		void	insert_sort(Cont &cont, int low, int high);
		void	print_sequence();
		void	print_containers();
		int		containers_init(int ac, char **args);
		bool	is_in_order(std::vector<int> vec) const;
};

#endif