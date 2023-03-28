#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain){
	std::cout << "It is a cat *pspsp pspsps*" << std::endl;
}

Cat::Cat( std::string Ctype ): Animal(Ctype), brain(new Brain){
	std::cout << "It is a cat and is of type " << this->type << std::endl;
}

Cat::Cat( Cat const &src ): Animal(src.getType()), brain(new Brain){
	std::cout << "Seems like the cat is dividing 😨" << std::endl;
	*this = src;
}

Cat::~Cat(){
	std::cout << "Cat saw a bird and decided to leave" << std::endl;
	delete(this->brain);
}

Cat &Cat::operator=( Cat const &src){
	std::cout << "The cats have become identical" << std::endl;
	if ( this != &src )
    {
		this->type = src.getType();
        for (int i = 0; i < 100; i++){
			this->brain->set_ideas(src.get_brain().get_ideas(i), i);
		}
    }
	return *this;
}

void    Cat::makeSound() const{
	std::cout << "Meow... Meow..." << std::endl;
}

Brain	&Cat::get_brain() const{
	return *this->brain;
}

