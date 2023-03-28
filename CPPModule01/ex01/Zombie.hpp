#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void	Givename( std::string &Zombiename );
		void	announce() const;
};

#endif