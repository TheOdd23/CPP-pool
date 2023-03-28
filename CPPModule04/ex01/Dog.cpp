#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain){
	std::cout << "It is a dog!" << std::endl;
}

Dog::Dog( std::string Dtype ): Animal(Dtype), brain(new Brain){
	std::cout << "It is a dog and is of type " << this->type << std::endl;
}

Dog::Dog( Dog const &src ): Animal(src.getType()), brain(new Brain){
	std::cout << "The dog is creating a copy of itself 😨" << std::endl;
	*this = src;
}

Dog::~Dog(){
	std::cout << "Dog left to chew his bone" << std::endl;
	delete(this->brain);
}

Dog &Dog::operator=( Dog const &src){
	std::cout << "The Dogs have become identical" << std::endl;
	if ( this != &src )
    {
		this->type = src.getType();
        for (int i = 0; i < 100; i++){
			this->brain->set_ideas(src.get_brain().get_ideas(i), i); 
		}
    }
	return *this;
}

void    Dog::makeSound() const{
	std::cout << "Woof... Woof..." << std::endl;
}

Brain	&Dog::get_brain() const{
	return *this->brain;
}
