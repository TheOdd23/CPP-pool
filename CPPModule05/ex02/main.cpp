#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <thread>
#include <chrono>

int	main(void)
{
	try{
	std::cout << "BUREAUCRATS CREATION" << std::endl;
	Bureaucrat a("Jean-Guy", 2);
	Bureaucrat aa("Jean-Paul", 45);
	Bureaucrat b;
	Bureaucrat bb(b);
	Bureaucrat c("Gregory Jones", 150);
	std::cout << std::endl;
	
	std::cout << "FORMS CREATION" << std::endl;
	ShruberryCreationForm d("Forest");
	PresidentialPardonForm e("Jesus");
	RobotomyRequestForm f("Anthony");
	RobotomyRequestForm g("Bob");
	RobotomyRequestForm h("Trump");
	std::cout << std::endl;
	
	std::cout << "BUREAUCRATS INFORMATIONS" << std::endl;
	std::cout << a;
	std::cout << aa;
	std::cout << bb;
	std::cout << c;
	std::cout << std::endl;

	std::cout << "FORMS INFORMATIONS" << std::endl;
	std::cout << d;
	std::cout << e;
	std::cout << f;
	std::cout << std::endl;
	
	std::cout << "TRY FORM EXECUTION" << std::endl;
	a.executeForm(d);
	std::cout << std::endl;
	
	b.executeForm(f);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << std::endl;
	
	std::cout << "UPGRADES AND DOWNGRADES" << std::endl;
	a.upGrade();
	a.upGrade();
	a.upGrade();
	std::cout << std::endl;
	
	b.downGrade();
	b.upGrade();
	std::cout << std::endl;

	bb.upGrade();
	bb.upGrade();
	bb.upGrade();
	std::cout << std::endl;
	
	c.downGrade();
	std::cout << std::endl;
	
	std::cout << "BUREAUCRATS INFORMATIONS" << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << std::endl;

	std::cout << "FORMS INFORMATIONS" << std::endl;
	std::cout << d;
	std::cout << e;
	std::cout << f;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "TRY SIGN FORMS" << std::endl;
	b.signForm(d);
	std::cout << std::endl;
	a.signForm(d);
	std::cout << std::endl;
	c.signForm(d);
	c.signForm(e);
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "BUREAUCRATS INFORMATIONS" << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << std::endl;
	
	std::cout << "FORMS INFORMATIONS" << std::endl;
	std::cout << d;
	std::cout << e;
	std::cout << f;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "SIGN AND EXECUTE: A" << std::endl;
	a.signForm(f);
	a.executeForm(f);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	a.signForm(e);
	std::cout << std::endl;
	
	std::cout << "SIGN AND EXECUTE: B" << std::endl;
	b.executeForm(f);
	std::cout << std::endl;
	
	std::cout << "SIGN AND EXECUTE: C" << std::endl;
	c.executeForm(e);
	std::cout << std::endl;
	
	std::cout << "SIGN AND EXECUTE: A" << std::endl;
	a.executeForm(e);
	std::cout << std::endl;
	
	std::cout << "SIGN AND EXECUTE: AA" << std::endl;
	aa.signForm(g);
	aa.downGrade();
	aa.executeForm(g);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << std::endl;
	aa.signForm(h);
	aa.upGrade();
	aa.signForm(h);
	aa.executeForm(g);
	std::cout << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << std::endl;
	aa.executeForm(h);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << std::endl;
	std::cout << std::endl;
	aa.executeForm(d);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}