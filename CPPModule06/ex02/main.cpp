#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <exception>

// Dynamic cast est utilisé pour performer des conversions entre classe héritante et classe de base de façon sécuritaire
// Le cast se fait durant le runtime et non le temps de compilation.

Base	*generate(void){
	srand(time(NULL));
	int	res;
	Base	*base;

	reset:
	res = 1 + rand() % 3;
	std::cout << res << std::endl;
	switch (res)
	{
	case 1:
		base = new A;
		break;
	case 2:
		base = new B;
		break;
	case 3:
		base = new C;
		break;
	default:
		goto reset;
	}
	return base;
}

void	identify(Base *p){
	std::cout << "Identify ptr" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p){
	A a;
	B b;
	C c;
	std::cout << "Identify reference" << std::endl;
	try{
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e){}
	try{
		b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception &e){}
	try{
		 c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception &e){}
}

int main(void){
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);
	delete (base);
	return (0);
}