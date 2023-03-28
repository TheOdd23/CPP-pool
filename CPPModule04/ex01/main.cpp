#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	Animal	*anim[50];
	unsigned int	i, nb;
	Cat	chat;
	std::cout << std::endl;
	Cat	chat2("pouet");
	std::cout << std::endl;
	
	Dog basic;
	{
		std::cout << std::endl;
		basic.get_brain().set_ideas("Salut!", 1);
		Dog tmp = basic;
		std::cout << std::endl;
		std::cout << tmp.get_brain().get_ideas(1);
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << basic.getType() << " " << &basic.get_brain() << std::endl;;
	std::cout << std::endl;
	
	chat.get_brain().set_ideas("Miam, je mangerais bien un oiseau!", -4);
	chat.get_brain().set_ideas("Miam, je mangerais bien un oiseau!", 4);
	chat.get_brain().set_ideas("Miam, je mangerais bien un écureuil!", 0);
	chat.get_brain().set_ideas("Miam, je mangerais bien une jambe de mon maitre!", 7);
	chat.get_brain().set_ideas("Miam, je mangerais bien une deuxieme jambe de mon maitre!", 120);
	std::cout << std::endl;
	
	chat2 = chat;
	std::cout << std::endl;
	
	std::cout << chat2.get_brain().get_ideas(-1) << std::endl;
	std::cout << std::endl;
	std::cout << chat2.get_brain().get_ideas(1) << std::endl;
	std::cout << std::endl;
	std::cout << chat2.get_brain().get_ideas(100) << std::endl;
	std::cout << std::endl;
	std::cout << chat2.get_brain().get_ideas(0) << std::endl;
	std::cout << std::endl;
	std::cout << chat2.get_brain().get_ideas(7) << std::endl;
	std::cout << std::endl;

	nb = 10;
	//nb = 5;
	//nb = 34;
	//nb = -12;
	//nb = 100;
	if (nb > 50 || nb < 1)
	{
		std::cout << "Wrong number of animals..." << std::endl << std::endl;
		return (0);
	}
	std::cout << std::endl;
	std::cout << "Cats instanciation" << std::endl;
	for (i = 0; i < (nb / 2); i++)
	{
		anim[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << "Dogs instanciation" << std::endl;
	for (i = (nb / 2); i < nb; i++)
	{
		anim[i] = new Dog;
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Animals destructions" << std::endl;
	for (i = 0; i < nb; i++)
	{
		delete(anim[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
