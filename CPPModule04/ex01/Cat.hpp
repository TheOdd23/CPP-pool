#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#pragma once

class Cat: virtual public Animal
{
public:
    Cat();
    Cat( std::string Ctype );
    Cat( Cat const &src );
    virtual ~Cat();
    Cat &operator=( Cat const &src);

    virtual void makeSound() const;
    Brain &get_brain() const;
private:
    Brain *brain;
};

#endif