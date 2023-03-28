#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		Contact();
		~Contact();
		
		std::string	get_firstname( void );
		std::string	get_name( void );
		std::string	get_nickname( void );
		std::string	get_phonenumber( void );
		std::string	get_secret( void );
		
		void	firstname( std::string first_name );
		void	lastname( std::string last_name );
		void	nickname( std::string nickname );
		void	phonenumber( std::string phone_number );
		void	secret( std::string darkest_secret );
};

#endif