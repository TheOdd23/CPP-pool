#ifndef FORM_HPP
#define FORM_HPP

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
		Form();
		Form( const std::string name, const int sign_grade, const int exe_grade );
		Form( Form const &src );
		~Form();
		Form &operator=( Form const &src );

        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExeGrade() const;
        const bool &getIfSigned() const;

        bool beSigned(Bureaucrat const &src);

        int checkExeGrade(const int exe_grade);
        int checkSignGrade(const int sign_grade);

        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Grade is too high!";
            }
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Grade is too low!";
            }
        };
private:
        const std::string name;
        const int sign_grade;
        const int exe_grade;
        bool _signed;
};

std::ostream &operator << ( std::ostream &out, Form const &instance );

#endif