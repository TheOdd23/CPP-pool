#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed{
	private:
		int	fixed_nb; //valeur du nb en virgule fixe
		static const int frac = 8; //stock le nombre de bits de la partie fractionnaire, et dont la valeur sera toujours le littéral entier 8.
	public:
		// constructeur
		Fixed();
		// constructeur parametrique const int
		Fixed( const int ); 
		// constructeur parametrique const float
		Fixed( const float);
		// contructeur de recopie
		Fixed( Fixed const &src );
		// surcharge de l'operateur d'affectation
		Fixed &operator=( Fixed const &src );
		~Fixed();
		
		// Fonctions membres
		int	toInt( void ) const;
		float toFloat( void ) const;
		int getRawBits(void) const; //retourne valeur du nb a virgule
		void setRawBits(int const raw); // initialise la valeur du nombre à virgule fixe avec celle passée en parametre
};

std::ostream &operator << ( std::ostream &out, Fixed const &nb );

#endif