
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <time.h>

 RobotomyRequestForm:: RobotomyRequestForm( void ): AForm("robotomy request", 72, 45), target("Default"){
	return;
}

 RobotomyRequestForm:: RobotomyRequestForm( std::string const target ): AForm("robotomy request", 72, 45), target(target){
	return;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ): AForm(src.getName(), src.getSignGrade(), src.getExeGrade()), target(src.getTarget()){
	*this = src;
}

 RobotomyRequestForm::~ RobotomyRequestForm( void ) {
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const  RobotomyRequestForm &){
	return *this;
}

const std::string &RobotomyRequestForm::getTarget() const{
	return this->target;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	srand(time(NULL));

	if (this->getIfSigned() == false)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getExeGrade())
		throw (GradeTooLowException());
	else
	{
		std::cout << "Brrrrrrrzwiiiiiiiiiiizzzzz!" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->getTarget() << " has successfully been Robotomized!" << std::endl;
		else
			std::cout << "Sadly, the experiment to robotomize " << this->getTarget() << " failed and the subject is dead" << std::endl;
	}
}