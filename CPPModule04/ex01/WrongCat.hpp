#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#pragma once

class WrongCat: virtual public WrongAnimal
{
public:
    WrongCat();
    WrongCat( std::string WCtype );
    WrongCat( WrongCat const &src );
    ~WrongCat();
    WrongCat &operator=( WrongCat const &src);
};

#endif