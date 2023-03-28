/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:27:51 by anhebert          #+#    #+#             */
/*   Updated: 2022/11/08 12:08:11 by anhebert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#pragma once

class Animal
{
public:
    Animal();
    Animal( std::string Atype );
    Animal( Animal const &src );
    virtual ~Animal();
    Animal &operator=( Animal const &src );

    virtual void makeSound() const;
    const std::string &getType() const;
protected:
    std::string type;
};

#endif