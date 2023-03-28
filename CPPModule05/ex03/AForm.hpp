#ifndef AFORM_HPP
#define AFORM_HPP

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
		AForm();
		AForm( const std::string name, const int sign_grade, const int exe_grade );
		AForm( AForm const &src );
		virtual ~AForm();
		AForm &operator=( AForm const &src );

        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExeGrade() const;
        const bool &getIfSigned() const;

        int checkExeGrade(const int exe_grade) const;
        int checkSignGrade(const int sign_grade) const;

        bool beSigned(Bureaucrat const &src);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Form not signed yet! ";
            }
        };
private:
        const std::string name;
        const int sign_grade;
        const int exe_grade;
        bool _signed;
};

std::ostream &operator << ( std::ostream &out, AForm const &instance );

#endif
