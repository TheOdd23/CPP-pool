
#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShruberryCreationForm: public AForm {
	public:
		ShruberryCreationForm( void );
		ShruberryCreationForm( std::string const target );
		ShruberryCreationForm( const ShruberryCreationForm &shruberrycreationform);
		virtual ~ShruberryCreationForm();
		ShruberryCreationForm & operator = (const ShruberryCreationForm &);

		const std::string &getTarget() const;
		virtual void execute(Bureaucrat const & executor) const;
	private:
		const std::string target;
};


#endif // SHRUBERRYCREATIONFORM_H_
