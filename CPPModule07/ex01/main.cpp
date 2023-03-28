#include "Iter.hpp"

int main(void){
	//Non const functions
	char	s[] = "Le chat de la voisine veut me tuer";
	int		i[] = {1, 4, 3, 9};
	float	f[] = {23.65f, 43.76f, 87654.56f, 2.0f};
	double	d[] = {45.65, 23.87, 234.87, 454.87};

	std::cout << "Originals" << std::endl;
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << std::endl;
	std::cout << "Print" << std::endl;
	std::cout << std::endl;
	std::cout << "string:" << std::endl;
	iter(s, 34, ::Print);
	std::cout << std::endl;

	std::cout << "int:" << std::endl;
	iter(i, 4, ::Print);
	std::cout << std::endl;

	std::cout << "float:" << std::endl;
	iter(f, 3, ::Print);
	std::cout << std::endl;

	std::cout << "double:" << std::endl;
	iter(d, 4, ::Print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Plus one" << std::endl;
	iter(s, 34, ::PlusOne);
	iter(i, 4, ::PlusOne);
	iter(f, 3, ::PlusOne);
	iter(d, 4, ::PlusOne);
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << std::endl;

	std::cout << "To Upper (string) / Times two (numbers)" << std::endl;
	iter(s, 34, ::ToUpper);
	iter(i, 4, ::TimesTwo);
	iter(f, 3, ::TimesTwo);
	iter(d, 4, ::TimesTwo);
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;

	//const function

	return (0);
}