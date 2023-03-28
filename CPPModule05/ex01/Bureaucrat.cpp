#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Rrrrroberrrrt"), grade(150){
	std::cout << this->name << " is ready to be bored!" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ): name(name), grade(checkGrade(grade)){
	std::cout << this->name << " is ready to be bored!" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << this->name << " died of boredom... 🌹RIP🌹" << std::endl;
}


Bureaucrat::Bureaucrat( Bureaucrat const &src ): name(src.getName()), grade(src.getGrade()){
	*this = src;
	std::cout << "Clone of " << this->name << " is ready to be bored!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &src ){
	if (this != &src)
		this->grade = src.getGrade();
	return *this;
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

const std::string &Bureaucrat::getName() const{
	return this->name;
}

const int &Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::signForm(Form &src) const{
	if (src.getIfSigned() == true)
	{
		std::cout << this->getName() << " couldn't sign " << src.getName() << " because form already signed" << std::endl;
		return ;
	}
	try {
		src.beSigned(*this);
		if (src.getIfSigned() == true)
			std::cout << this->getName() << " signed " << src.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << this->getName() << " couldn't sign " << src.getName() << " because grade too low" << std::endl;
	}
}

void	Bureaucrat::upGrade(){
	try
	{
		this->grade = checkGrade(this->grade - 1);
		std::cout << this->name << " has upgraded to " << this->grade << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(){
	try
	{
		this->grade = checkGrade(this->grade + 1);
		std::cout << this->name << " has upgraded to " << this->grade << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream &operator << ( std::ostream &out, Bureaucrat const &instance ){
	out << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return out;
}
