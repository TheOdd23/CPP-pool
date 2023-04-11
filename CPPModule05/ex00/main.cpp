#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	try
    {
		Bureaucrat a("Jean-guy", 2);
		Bureaucrat b;
		try
        {
            Bureaucrat c("Gregory Jones", 230);
            std::cout << c << std::endl;
		}
		catch (std::exception &e)
        {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		
        std::cout << a << std::endl;
		std::cout << b << std::endl;
		a.upGrade();
		a.upGrade();
		a.upGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
    {
			std::cout << e.what() << std::endl;
	}
	return (0);
}
