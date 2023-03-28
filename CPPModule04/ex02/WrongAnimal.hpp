/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:23:07 by anhebert          #+#    #+#             */
/*   Updated: 2022/11/03 12:22:00 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#pragma once

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal( std::string type );
    WrongAnimal( WrongAnimal const &src );
    virtual ~WrongAnimal();
    WrongAnimal &operator=( WrongAnimal const &src );
    void makeSound() const;
    const std::string &getType() const;
protected:
    std::string type;
};

#endif