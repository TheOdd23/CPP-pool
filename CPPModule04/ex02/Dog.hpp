#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#pragma once

class Dog: virtual public AAnimal
{
public:
    Dog();
    Dog( std::string type );
    Dog( Dog const &src );
    ~Dog();
    Dog &operator=( Dog const &src);
    void    makeSound() const;
    Brain   &get_brain() const;
private:
    Brain   *brain;
};

#endif