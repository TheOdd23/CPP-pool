#include "Contact.hpp"

	Contact::Contact(){
		return;
	}
	Contact::~Contact(){
		return;
	}
	void	Contact::firstname( std::string str ){
		this->first_name = str;
	}

	void	Contact::lastname( std::string str ){
		this->last_name = str;
	}

	void	Contact::nickname( std::string str ){
		this->nick_name = str;
	}

	void	Contact::phonenumber( std::string str ){
		this->phone_number = str;
	}

	void	Contact::secret( std::string str ){
		this->darkest_secret = str;
	}

	std::string	Contact::get_firstname( void ){
		return this->first_name;
	}
	
	std::string	Contact::get_name( void ){
		return this->last_name;
	}

	std::string	Contact::get_nickname( void ){
		return this->nick_name;
	}

	std::string	Contact::get_phonenumber( void ){
		return this->phone_number;
	}

	std::string	Contact::get_secret( void ){
		return this->darkest_secret;
	}
