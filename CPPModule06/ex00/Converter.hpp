
#ifndef CONVERTER_HPP_
# define CONVERTER_HPP_

# include <iostream>
# include <string>
# include <cstdlib>
# include <climits>
# include <iomanip>

class Converter {
	public:
		Converter( void );
		Converter(const Converter &converter);
		~Converter();
		Converter & operator = (const Converter &converter);
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
		void	convertFromChar();
		void	convertFromInt();
		void	convertFromFLoat();
		void	convertFromDouble();
		void	setTypes(std::string var);
		int		checkType(std::string var);
	private:
		char	c;
		int		i;
		float	f;
		double	d;
};

std::ostream &operator << ( std::ostream &out, Converter const &instance );

#endif // CONVERTER_HPP_
