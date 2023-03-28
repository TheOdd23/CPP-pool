
#include "Converter.hpp"

Converter::Converter( void ): c('\0'), i(0), f(0.0f), d(0.0) {
	return;
}

Converter::Converter( const Converter &src): c(src.getChar()), i(src.getInt()), f(src.getFloat()), d(src.getDouble()){
	*this = src;
}

Converter::~Converter( void ) {
	return;
}

Converter &Converter::operator = (const Converter &src){
	if (this != &src)
	{
		this->c = src.getChar();
		this->i = src.getInt();
		this->f = src.getFloat();
		this->d = src.getDouble();
	}
	return *this;
}

char	Converter::getChar() const{
	return this->c;
}

int	Converter::getInt() const{
	return this->i;
}

float	Converter::getFloat() const{
	return this->f;
}

double	Converter::getDouble() const{
	return this->d;
}

void	Converter::convertFromChar(){
	this->i = static_cast<int>(this->c);
	this->f = static_cast<float>(this->c);
	this->d = static_cast<double>(this->c);
}

void	Converter::convertFromInt(){
	this->c = static_cast<char>(this->i);
	this->f = static_cast<float>(this->i);
	this->d = static_cast<double>(this->i);
}

void	Converter::convertFromFLoat(){
	this->c = static_cast<char>(this->f);
	this->i = static_cast<int>(this->f);
	this->d = static_cast<double>(this->f);
}

void	Converter::convertFromDouble(){
	this->c = static_cast<char>(this->d);
	this->i = static_cast<int>(this->d);
	this->f = static_cast<float>(this->d);
}

void	Converter::setTypes(std::string var){
	int res;

	res = checkType(var);
	switch (res)
	{
		case 0:
			convertFromChar();
			break ;
		case 1:
			convertFromInt();
			break ;
		case 2:
			convertFromFLoat();
			break ;
		case 3:
			convertFromDouble();
			break ;
		default:
			std::cout << "Wrong type, cannot execute..." << std::endl;
	}
}

int	Converter::checkType(std::string var){
	int			index = 0;
	size_t		found = var.find('.');

	if (var[i] == '+' || var[i] == '-')
		index++;
	if (isdigit(var[index]) && found == std::string::npos)
	{
		try{
			this->i = std::stoi(var);
			return 1;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	if (var == "inff" || var == "+inff" || var == "-inff" || var == "nanf"
		|| (var[var.length() - 1] == 'f' && found != std::string::npos))
	{
		try{
			this->f = std::stof(var);
			return 2;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	if (var == "inf" || var == "+inf" || var == "-inf" || var == "nan"
		|| found != std::string::npos)
	{
		try{
			this->d = std::stod(var);
			return 3;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	if (isprint(var[0]) && var.length() == 1)
	{
		try{
		this->c = var[0];
		return 0;
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return (-1);
}

std::ostream &operator << ( std::ostream &out, Converter const &instance ){
	if (instance.getDouble() < 32 && instance.getDouble() >= 0)
		out << "char: " << "Non displayable" << std::endl;
	else if (instance.getDouble() > 127 || instance.getDouble() < 0 || instance.getChar() == 0)
		out << "char: " << "Impossible" << std::endl;
	else
		out << "char: '" << instance.getChar() << "'" << std::endl;
	if (instance.getInt() <= INT_MIN || instance.getInt() > INT_MAX )
		out << "int: " << "Impossible" << std::endl;
	else
		out << "int: " << instance.getInt() << std::endl;
	out << "float: " << std::fixed << std::setprecision(1) << instance.getFloat() << 'f' << std::endl;
	out << "double: " << std::fixed << std::setprecision(1) << instance.getDouble() << std::endl;
	return out;
}
