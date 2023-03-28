#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	//const AAnimal* aanimal = new AAnimal;
	const AAnimal* j = new Dog();
	std::cout << std::endl;
	const AAnimal* l = new Dog("Pug");
	std::cout << std::endl;
	const AAnimal* k = new Cat();
	std::cout << std::endl;
	const WrongAnimal* i = new WrongCat();
	std::cout << std::endl;
	std::cout << "It sure is a " << j->getType() << "." << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << "With it's friend the " << l->getType() << "." << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << "I also saw a " << k->getType() << std::endl;
	k->makeSound();
	std::cout << std::endl;
	std::cout << "What is that, is this really a " << i->getType() << "?" << std::endl;
	i->makeSound();
	std::cout << std::endl;
	delete(j);
	std::cout << std::endl;
	delete(l);
	std::cout << std::endl;
	delete(k);
	std::cout << std::endl;
	delete(i);
	std::cout << std::endl;
	return 0;
}