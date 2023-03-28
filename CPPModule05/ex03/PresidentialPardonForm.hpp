
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const target );
		PresidentialPardonForm( const PresidentialPardonForm &presidentialpardonform);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm & operator = (const PresidentialPardonForm &);

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		const std::string target;
};


#endif // PRESIDENTIALPARDONFORM_H_
