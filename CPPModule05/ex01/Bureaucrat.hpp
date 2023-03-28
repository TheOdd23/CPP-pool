#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#pragma once

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
		Bureaucrat();
		Bureaucrat( std::string const name, int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat();
		Bureaucrat &operator=( Bureaucrat const &src );

        const std::string &getName() const;
        const int &getGrade() const;

        int     checkGrade(int bgrade) const;
        void    upGrade();
        void    downGrade();

        void    signForm(Form &src) const;
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
        std::string const name;
        int grade;
};

std::ostream &operator << ( std::ostream &out, Bureaucrat const &instance );

#endif