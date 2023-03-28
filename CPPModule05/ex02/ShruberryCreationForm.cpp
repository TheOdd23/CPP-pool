#include "ShruberryCreationForm.hpp"

 ShruberryCreationForm::ShruberryCreationForm( void ): AForm("shruberry creation", 145, 137), target("Default"){
	return;
}

 ShruberryCreationForm::ShruberryCreationForm( std::string const target ): AForm("shruberry creation", 145, 137), target(target){
	return;
}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm &src): AForm(src.getName(), src.getSignGrade(), src.getExeGrade()), target(src.getTarget()){
	*this = src;
}


 ShruberryCreationForm::~ ShruberryCreationForm( void ) {
	return;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const  ShruberryCreationForm &){
	return *this;
}

const std::string &ShruberryCreationForm::getTarget() const{
	return this->target;
}

void ShruberryCreationForm::execute(Bureaucrat const &executor) const{

	if (this->getIfSigned() == false)
	{
		throw (FormNotSignedException());
		return ;
	}
	else if (executor.getGrade() > this->getExeGrade())
	{
		throw (GradeTooLowException());
		return ;
	}
	else
	{
		std::ofstream outfile(this->getTarget() + "_shruberry");
		outfile << " \
          &&& &&  & && \n\
      && &\\/&\\|& ()|/ @, && \n\
      &\\/(/&/&||/& /_/)_&/_& \n\
   &() &\\/&|()|/&\\/ '%  & () \n\
  &_\\_&&_\\ |& |&&/&__%_/_& && \n\
&&   && & &| &| /& & % ()& /&& \n\
 ()&_---()&\\&\\|&&-&&--%---()~ \n\
     &&     \\||| \n\
             ||| \n\
             ||| \n\
             ||| \n\
       , -=-~  .-^- _ \n\
              `";
		outfile.close();
	}
}
