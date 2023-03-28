#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	a;
	std::cout << std::endl;
	Bureaucrat z("Henry", 1);
	std::cout << std::endl;
	AForm	*b;
	AForm	*c;
	AForm	*d;
	std::cout << std::endl;
	b = a.makeForm("berry creation", "Jardin");
	std::cout << std::endl;
	c = a.makeForm("resident pardon", "Satan");
	std::cout << std::endl;
	d = a.makeForm("robotisation request", "R2D2");
	std::cout << std::endl;
	b = a.makeForm("shruberry creation", "Jardin");
	std::cout << std::endl;
	c = a.makeForm("presidential pardon", "Satan");
	std::cout << std::endl;
	d = a.makeForm("robotomy request", "R2D2");
	std::cout << std::endl;
	std::cout << std::endl;
	
	z.signForm(*b);
	std::cout << std::endl;
	z.signForm(*c);
	std::cout << std::endl;
	z.signForm(*d);
	std::cout << std::endl;
	std::cout << std::endl;
	
	z.executeForm(*b);
	std::cout << std::endl;
	z.executeForm(*c);
	std::cout << std::endl;
	z.executeForm(*d);
	std::cout << std::endl;
	delete b;
	delete c;
	delete d;
	return (0);
}