#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#pragma once

class Dog: virtual public Animal
{
public:
    Dog();
    Dog( std::string type );
    Dog( Dog const &src );
    virtual ~Dog();
    Dog &operator=( Dog const &src);

    virtual void    makeSound() const;

private:

};

#endif