
#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern( void ){
	std::cout << "Let's all welcome our new slave! ... hmm hmmm Intern" << std::endl;
	return;
}

Intern::Intern( Intern const &src){
	*this = src;
}


Intern::~Intern( void ) {
	std::cout << "Oh no, an intern died... Guess we'll have to get a new one" << std::endl; 
	return;
}

Intern &Intern::operator=(Intern const &src){
	(void)src;
	return *this;
}

AForm	*Intern::makeForm(std::string const form, std::string const target){
	std::string Form[3];
	AForm *a;
	int	i;

	Form[0] = "robotomy request";
	Form[1] = "shruberry creation";
	Form[2] = "presidential pardon";
	for(i = 0; i < 3; i++){
		if (Form[i].compare(form) == 0)
			break ;
	}
	switch(i){
		case 0:
			std::cout << "Juste made a new " << form << std::endl;
			a = new RobotomyRequestForm(target);
			break ;
		case 1:
			std::cout << "Juste made a new " << form << std::endl;
			a = new ShruberryCreationForm(target);
			break ;
		case 2:
			std::cout << "Juste made a new " << form << std::endl;
			a = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << "Sorry, I couldn't find the form you want me to create... 😭" << std::endl;
			a = NULL;
	}
	return (a);
}
