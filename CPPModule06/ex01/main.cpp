#include <iostream>
#include <string>

typedef struct s_Data{
	int			i;
	float		f;
	double		d;
	char		c;
	std::string	s;
} Data;

// Reinterpret cast: Prend un pointeur et peut le reconvertir en un autre type de Data,
// peut importe la nature de la data. Se converti au moment de la compilation

// uintptr_t est "an unsigned integer type with the property that any valid pointer to void can be converted to
// this type, then converted back to pointer to void, and the result will compare equal to the original pointer"

uintptr_t serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	uintptr_t	ptr;
	Data		a;
	Data		*aa = NULL;

	a.i = 42;
	a.f = 23.54f;
	a.d = 123.456;
	a.c = 'A';
	a.s = "Je suis awesome, deal with it";
	ptr = serialize(&a);
	aa = deserialize(ptr);
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "a: " << a.i << ", " << a.f << ", " << a.d << ", " << a.c << ", " << a.s << std::endl;
	std::cout << "aa: "<< aa->i << ", " << aa->f << ", " << aa->d << ", " << aa->c << ", " << aa->s << std::endl;
}
