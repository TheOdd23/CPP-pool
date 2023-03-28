#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Animal can now think, because brain" << std::endl;
}

Brain::Brain( Brain const &src ){
	std::cout << "The animal decided to share it's ideas" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Animal is now brain dead" << std::endl;
}

Brain	&Brain::operator=( Brain const &src ){
	int	i;

	std::cout << "The animals now share the same ideas" << std::endl;
	if (this != &src)
	{
		for (i = 0; i < 100; i++)
			this->ideas[i] = src.get_ideas(i);
	}
	return *this;
}

void	Brain::set_ideas(std::string idea, int i){
	if (i > 99)
	{
		std::cout << "Wooooo my brain's not that big!" << std::endl;
		return ;
	}
	else if (i < 0)
	{
		std::cout << "Where do you think you're putting this idea?" << std::endl;
		return ;
	}
	this->ideas[i] = idea;
}

const std::string Brain::get_ideas(int i) const{
	if (i > 99 || i < 0)
		return ("Brain segfault...");
	return this->ideas[i];
}
