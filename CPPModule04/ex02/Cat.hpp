#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#pragma once

class Cat: virtual public AAnimal
{
public:
    Cat();
    Cat( std::string type );
    Cat( Cat const &src );
    ~Cat();
    Cat &operator=( Cat const &src);

    void makeSound() const;
    Brain &get_brain() const;
private:
    Brain *brain;
};

#endif