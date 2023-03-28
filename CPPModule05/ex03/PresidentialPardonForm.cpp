#include "PresidentialPardonForm.hpp"

 PresidentialPardonForm::PresidentialPardonForm( void ): AForm("presidential pardon", 25, 5), target("Default"){
	return;
}

 PresidentialPardonForm::PresidentialPardonForm( std::string const target): AForm("presidential pardon", 25, 5), target(target){
	return;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src): AForm(src.getName(), src.getSignGrade(), src.getExeGrade()), target(src.getTarget()){
	*this = src;
}


 PresidentialPardonForm::~ PresidentialPardonForm( void ) {
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const  PresidentialPardonForm &){
	return *this;
}

const std::string &PresidentialPardonForm::getTarget() const{
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->getIfSigned() == false)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getExeGrade())
		throw (GradeTooLowException());
	else
		std::cout << this->getTarget() << " was pardonned by Zaphod Beeblebrox" << std::endl;
}