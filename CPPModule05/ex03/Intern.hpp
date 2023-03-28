
#ifndef INTERN_H_
# define INTERN_H_

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern {
	public:
		Intern( void );
		Intern( const Intern &intern);
		~Intern();
		Intern & operator=(const Intern &intern);

		AForm *makeForm( std::string form, std::string target );
	private:
};


#endif // INTERN_H_
