#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	try{
	Bureaucrat a("Jean-guy", 2);
	Bureaucrat b;
	Bureaucrat a2(a);
	std::cout << std::endl;
	Form	d;
	Form	e("Groceries list", 6, 13);

	std::cout << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << a2;
	std::cout << std::endl;
	std::cout << d;
	std::cout << e;
	std::cout << std::endl;
	a.upGrade();
	a.upGrade();
	a.upGrade();
	std::cout << std::endl;
	b.downGrade();
	b.upGrade();
	std::cout << std::endl;
	b.signForm(d);
	a.signForm(d);
	b.signForm(d);
	std::cout << std::endl;
	std::cout << a;
	std::cout << b;
	std::cout << std::endl;
	std::cout << d;
	std::cout << e;
	std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try{
	Form	d;
	Form	e("Dark secret lore", 45, 73);
	Bureaucrat c("Gregory Jones", 230);
	std::cout << c;
	c.signForm(d);
	c.downGrade();
	std::cout << c;
	c.signForm(e);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try{
	Form	f("Fiscal evasion stuff", -78, 203);
	std::cout << f;
	std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}