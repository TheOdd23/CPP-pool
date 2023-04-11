#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <exception>
#include <algorithm>
#include <iterator>


template <typename T> typename T::iterator easyfind(T &cont, int val)
{
	typename T::iterator look;
	class UnFound: public std::exception
    {
		public:
			virtual const char *what() const throw()
            {
				return "Error: Not found";
			}
	};

	look = std::find(cont.begin(), cont.end(), val);
	if (look != cont.end())
		return look;
	else
		throw (UnFound());
}

#endif
