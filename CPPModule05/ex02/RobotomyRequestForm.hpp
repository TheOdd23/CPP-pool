
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class  RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const target );
		RobotomyRequestForm( const  RobotomyRequestForm & robotomyrequestform);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm & operator=(const RobotomyRequestForm &);
		
		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		const std::string target;
};


#endif //  ROBOTOMYREQUESTFORM_H_
