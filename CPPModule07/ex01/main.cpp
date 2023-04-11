#include "Iter.hpp"

int main(void)
{
	//Non const functions
	char	s[] = "Le chat de la voisine veut me tuer";
	int		i[] = {1, 4, 3, 9};
	float	f[] = {23.65f, 43.76f, 87654.56f, 2.0f};
	double	d[] = {45.65, 23.87, 234.87, 454.87};

	std::cout << "Non const variables" << std::endl;
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << std::endl;
	std::cout << "Print" << std::endl;
	std::cout << std::endl;
	std::cout << "string:" << std::endl;
	iter(s, 34,::Print);
	std::cout << std::endl;

	std::cout << "int:" << std::endl;
	iter(i, 4,::Print);
	std::cout << std::endl;

	std::cout << "float:" << std::endl;
	iter(f, 4, ::Print);
	std::cout << std::endl;

	std::cout << "double:" << std::endl;
	iter(d, 4, ::Print);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Plus one" << std::endl;
	iter(s, 34, ::PlusOne);
	iter(i, 4, ::PlusOne);
	iter(f, 4, ::PlusOne);
	iter(d, 4, ::PlusOne);
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;
	std::cout << std::endl;

	std::cout << "To Upper (string) / Times two (numbers)" << std::endl;
	iter(s, 34, ::ToUpper);
	iter(i, 4, ::TimesTwo);
	iter(f, 4, ::TimesTwo);
	iter(d, 4, ::TimesTwo);
	std::cout << std::endl;
	std::cout << "i: " << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << std::endl;
	std::cout << "f: " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << std::endl; 
	std::cout << "d: " << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << std::endl;
	std::cout << "s: " << s << std::endl;

	//const function
	std::cout << std::endl;
	std::cout << std::endl;
    std::cout << "Const variables" << std::endl;
	std::cout << std::endl;
    const char    cs[] = "La voisine veut tuer mon chat";
    const int        ci[] = {1, 4, 3, 9};
    const float    cf[] = {23.65f, 43.76f, 87654.56f, 2.0f};
    const double    cd[] = {45.65, 23.87, 234.87, 454.87};
	
	std::cout << "const_i: " << ci[0] << " " << ci[1] << " " << ci[2] << " " << ci[3] << std::endl;
	std::cout << "const_f: " << cf[0] << " " << cf[1] << " " << cf[2] << " " << cf[3] << std::endl; 
	std::cout << "const_d: " << cd[0] << " " << cd[1] << " " << cd[2] << " " << cd[3] << std::endl;
	std::cout << "const_s: " << cs << std::endl;

	std::cout << std::endl;
    std::cout << "Print:" << std::endl;
	std::cout << std::endl;
    std::cout << "string:" << std::endl;
    iter(cs, 29, ::Print);
	std::cout << std::endl;
    std::cout << "int:" << std::endl;
    iter(ci, 4, ::Print);
	std::cout << std::endl;
    std::cout << "float:" << std::endl;
    iter(cf, 4, ::Print);
	std::cout << std::endl;
    std::cout << "double:" << std::endl;
    iter(cd, 4, ::Print);
	return (0);
}
