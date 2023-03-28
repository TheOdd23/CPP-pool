#include "MutantStack.hpp"
#include <iostream>
#include <list>

//Stack: Classe "container adaptor", qui contient un container (vector, list, deque(par défaut));
//Les éléments de la stack ne peuvent être qu'ajoutés et enlevés du dessus de la stack;
//La stack a son propre lot de fonctions membres

/* int main()
{
	MutantStack<int> mstack;
	MutantStack<int> vstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	vstack = mstack;
	std::cout << mstack.top() << std::endl;
	std::cout << mstack.size() << std::endl;
	return 0;
} */

/* int	main()
{
	std::list<int> mlist;
	std::list<int> vlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mlist);
	vlist = mlist;
	std::cout << mlist.back() << std::endl;
	std::cout << mlist.size() << std::endl;
	return 0;
} */

int main()
{
	MutantStack<char> mstack;
	std::stack<char> sstack;
	std::stack<char> vstack;
	MutantStack<char>::iterator it;;

	vstack.push('4');
	for(char c = 'a'; c <= 'z'; c++)
		mstack.push(c);
	for(it = mstack.begin(); it != mstack.end(); it++)
	{
		if (*it == 'g')
			std::cout << *it << " was found!" << std::endl;
	}
	for(it = mstack.begin(); it != mstack.end(); it++)
	{
		if (*it == '0')
			std::cout << *it << " was found!" << std::endl;
	}
	it = mstack.end() - 1;
	std::cout << *it << std::endl;
	std::cout << mstack.top() << std::endl;
	sstack = mstack;
	std::cout << sstack.size() << std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.swap(vstack);
	it = mstack.begin();
	std::cout << *it << std::endl;
}