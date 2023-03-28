#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal	bird("Bird");
	std::cout << std::endl;
	Animal	bird3;
	bird3 = bird;
	std::cout << "It also is a " << bird3.getType() << std::endl;
	std::cout << std::endl;
	
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* meta2 = new Animal("Chevreuil");
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* l = new Dog("Pug");
	std::cout << std::endl;
	const Animal* k = new Cat();
	std::cout << std::endl;
	const WrongAnimal* i = new WrongCat();
	std::cout << std::endl;
	const WrongCat m;
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
	meta->makeSound();
	std::cout << "Wait.. what was that?" << std::endl;
	meta2->makeSound();
	std::cout << "Oh, I think it is a " << meta2->getType() << std::endl;
	std::cout << std::endl;
	m.makeSound();
	std::cout << "Is that a dog or a cat? Maybe a " << m.getType() << std::endl;
	std::cout << std::endl;
	
	delete(meta);
	std::cout << std::endl;
	delete(meta2);
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