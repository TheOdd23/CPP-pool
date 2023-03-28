#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int	nb; //valeur du nb en virgule fixe
		static const int frac = 8; //stock le nombre de bits de la partie fractionnaire, et dont la valeur sera toujours le littéral entier 8.
	public:
		Fixed();
		// contructeur de recopie
		Fixed( Fixed const &src );
		// surcharge de l'operateur d'affectation
		Fixed &operator=( Fixed const &src );
		// Destructeur
		~Fixed();

		// Fonctions membres
		int getRawBits(void) const; //retourne valeur du nb a virgule
		void setRawBits(int const raw); // initialise la valeur du nombre à virgule fixe avec celle passée en parametre
};

#endif