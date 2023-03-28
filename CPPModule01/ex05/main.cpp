#include "Harl.hpp"

int	main(){
	Harl h;
	h.complain("TABLE");
	std::cout << std::endl;
	h.complain("ERROR");
	std::cout << std::endl;
	h.complain("INFO");
	std::cout << std::endl;
	h.complain("CHAT");
	std::cout << std::endl;
	h.complain("WARNING");
	std::cout << std::endl;
	h.complain("DEBUG");
	return (0);
}