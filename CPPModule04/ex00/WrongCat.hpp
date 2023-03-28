#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#pragma once

class WrongCat: virtual public WrongAnimal
{
public:
    WrongCat();
    WrongCat( std::string type );
    WrongCat( WrongCat const &src );
    ~WrongCat();
    WrongCat &operator=( WrongCat const &src);

    void        makeSound() const;
};

#endif