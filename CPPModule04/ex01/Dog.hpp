#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Dog: virtual public Animal
{
public:
    Dog();
    Dog( std::string Dtype );
    Dog( Dog const &src );
    virtual ~Dog();
    Dog &operator=( Dog const &src);

    virtual void    makeSound() const;
    Brain   &get_brain() const;
private:
    Brain   *brain;
};

#endif