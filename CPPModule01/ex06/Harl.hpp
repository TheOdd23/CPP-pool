#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>


class Harl{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		std::string function[4];
	public:
		Harl();
		~Harl();
		void complain( std::string level );

};

typedef void (Harl::*function)(void);

#endif