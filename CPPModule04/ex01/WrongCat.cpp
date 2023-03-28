#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Wrongcat"){
	std::cout << "It is somehow a wrong cat *pspsp pspsps*" << std::endl;
}

WrongCat::WrongCat( std::string WCtype ): WrongAnimal(WCtype){
	std::cout << "A Wrongcat has appeared and it is of type " << this->type << std::endl;
}

WrongCat::WrongCat( WrongCat const &src ): WrongAnimal(src.getType()){
	std::cout << "Seems like the Wrongcat is dividing 😨" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat saw a bird and decided to leave" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &src){
	std::cout << "The Wrongcats have become the same" << std::endl;
	if ( this != &src )
		this->type = src.getType();
	return *this;
}
