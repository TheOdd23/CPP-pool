#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Rrrrroberrrrt"), grade(150){
	std::cout << this->name << " is ready to be bored!" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ): name(name), grade(grade){
	std::cout << this->name << " is ready to be bored!" << std::endl;
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
	}
	catch (std::exception& e)
	{
		this->grade = 150;
		std::cout << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){
	std::cout << this->name << " died of boredom... 🌹RIP🌹" << std::endl;
}


Bureaucrat::Bureaucrat( Bureaucrat const &src ){
	*this = src;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &src ){
	if (this != &src)
		this->grade = src.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName() const{
	return this->name;
}

const int &Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::signForm(AForm &src) const{
	if (src.getIfSigned() == false && src.beSigned(*this) == true)
		std::cout << this->getName() << " signed " << src.getName() << std::endl;
	else if (src.getIfSigned() == true)
		std::cout << this->getName() << " couldn't sign " << src.getName() << " because form already signed" << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << src.getName() << " because grade too low" << std::endl;
}

void Bureaucrat::executeForm(AForm const &form){
	try 
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << " Cannot execute! " << std::endl;
	}
}

int Bureaucrat::checkGrade(int bgrade) const{
		if (bgrade < 1)
		{
			bgrade = 1;
			throw (GradeTooHighException());
		}
		else if (bgrade > 150)
		{
			bgrade = 150;
			throw (GradeTooLowException());
		}
	return bgrade;
}

void	Bureaucrat::upGrade(){
	try
	{
		this->grade--;
		if (grade < 1)
			throw (GradeTooHighException());
		else
			std::cout << this->name << " has upgraded to " << this->grade << std::endl;
	}
	catch (std::exception& e)
	{
		this->grade++;
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(){
	try
	{
		this->grade++;
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->name << " has upgraded to " << this->grade << std::endl;
	}
	catch (std::exception &e)
	{
		this->grade--;
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << ( std::ostream &out, Bureaucrat const &instance ){
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return out;
}
