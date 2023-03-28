#include "AForm.hpp"

AForm::AForm(): name("A AForm"), sign_grade(150),exe_grade(150), _signed(0){
	std::cout << this->name << " is ready to be signed!" << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int exe_grade): name(name), sign_grade(checkSignGrade(sign_grade)), exe_grade(checkExeGrade(exe_grade)), _signed(0){
    std::cout << this->name << " is ready to be signed!" << std::endl;
}

AForm::AForm(AForm const &src): name(src.getName()), sign_grade(src.getSignGrade()), exe_grade(src.getExeGrade()), _signed(0){
	std::cout << "Copy of " << this->name << " is ready to be signed!" << std::endl;
	*this = src;
}

AForm::~AForm(){
}

AForm &AForm::operator=(AForm const &src){
	if (this != &src)
		this->_signed = src.getIfSigned();
	return *this;
}

int AForm::checkExeGrade(const int exe_grade){
    if (exe_grade < 1)
        throw (GradeTooHighException());
    else if (exe_grade > 150)
        throw (GradeTooLowException());
    return (exe_grade);
}

int AForm::checkSignGrade(const int sign_grade){
    if (sign_grade < 1)
        throw (GradeTooHighException());
    else if (sign_grade > 150)
        throw (GradeTooLowException());
    return (sign_grade);
}
    
const std::string &AForm::getName() const{
	return this->name;
}


const int &AForm::getSignGrade() const{
	return this->sign_grade;
}

const int &AForm::getExeGrade() const{
	return this->exe_grade;
}

const bool &AForm::getIfSigned() const{
	return this->_signed;
}

bool AForm::beSigned(Bureaucrat const &src){
	if (src.getGrade() > this->sign_grade)
		throw AForm::GradeTooLowException();
	if (this->_signed == false)
		this->_signed = true;
	return this->_signed;
}

std::ostream &operator << ( std::ostream &out, AForm const &instance ){
	std::string is_signed;
	if (instance.getIfSigned() == 0)
		is_signed = "is not signed,";
	else
		is_signed = "is signed,";
	out << "AForm " << instance.getName() << ": " << is_signed << " grade to execute: "
	<< instance.getExeGrade() << ", grade to sign: " << instance.getSignGrade() << std::endl;
	return out;
}
