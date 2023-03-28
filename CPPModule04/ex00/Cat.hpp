#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#pragma once

class Cat: virtual public Animal
{
public:
    Cat();
    Cat( std::string type );
    Cat( Cat const &src );
    virtual ~Cat();
    Cat &operator=( Cat const &src);

    virtual void    makeSound() const;

};

#endif