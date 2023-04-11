#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#pragma once

// For non const functions
template <typename T>void iter(T *tab, unsigned int size, void(*f)(T &))
{
	unsigned int	i;

	for(i = 0; i < size; i++)
    {
		f(tab[i]);
	}
}

// For const functions
template <typename T>void iter(const T *tab, unsigned int size, void(*f)(const T &))
{
	unsigned int	i;

	for(i = 0; i < size; i++)
    {
		f(tab[i]);
	}
}

template <typename T>void PlusOne(T a)
{
	a += 1;
}

template <typename T>void TimesTwo(T a)
{
	a *= 2;
}

template <typename T>void ToUpper(T a)
{
	a = toupper(a);
}

template <typename T>void Print(T const a)
{
	std::cout << a;
}

#endif
