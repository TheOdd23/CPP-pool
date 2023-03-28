#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack: public std::stack<T>{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	
	MutantStack(){};
	MutantStack(const MutantStack& src){
		*this = src;
	};
	~MutantStack(){};
	MutantStack &operator=(const MutantStack& src){
		std::stack<T>::operator=(src);
		return *this;
	}
	iterator begin(){
		return iterator(this->c.begin());
	}
	iterator end(){
		return iterator(this->c.end());
	}
private:
};

#endif