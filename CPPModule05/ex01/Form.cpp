#include "Form.hpp"

Form::Form(): name("A Form"), sign_grade(1), exe_grade(1), _signed(0){
	std::cout << this->name << " is ready to be signed!" << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int exe_grade): name(name), sign_grade(checkSignGrade(sign_grade)), exe_grade(checkExeGrade(exe_grade)), _signed(0){
	std::cout << this->name << " is ready to be signed!" << std::endl;
}

Form::Form(Form const &src): name(src.getName()), sign_grade(src.getSignGrade()), exe_grade(src.getExeGrade()), _signed(0){
	*this = src;
}

Form::~Form(){
}

Form &Form::operator=(Form const &src){
	if (this != &src)
		this->_signed = src.getIfSigned();
	return *this;
}

int Form::checkExeGrade(const int exe_grade){
	if (exe_grade < 1)
		throw (GradeTooHighException());
	else if (exe_grade > 150)
		throw (GradeTooLowException());
	return (exe_grade);
}

int Form::checkSignGrade(const int sign_grade){
	if (sign_grade < 1)
		throw (GradeTooHighException());
	else if (sign_grade > 150)
		throw (GradeTooLowException());
	return (sign_grade);
}

const std::string &Form::getName() const{
	return this->name;
}


const int &Form::getSignGrade() const{
	return this->sign_grade;
}

const int &Form::getExeGrade() const{
	return this->exe_grade;
}

const bool &Form::getIfSigned() const{
	return this->_signed;
}

bool Form::beSigned(Bureaucrat const &src){
	if (src.getGrade() > this->sign_grade)
		throw Form::GradeTooLowException();
	if (this->_signed == false)
		this->_signed = true;
	return this->_signed;
}

std::ostream &operator << ( std::ostream &out, Form const &instance ){
	std::string is_signed;
	if (instance.getIfSigned() == 0)
		is_signed = "is not signed,";
	else
		is_signed = "is signed,";
	out << "Form " << instance.getName() << ": " << is_signed << " grade to execute: "
	<< instance.getExeGrade() << " grade to sign: " << instance.getSignGrade() << std::endl;
	return out;
}