/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhebert <anhebert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:23:07 by anhebert          #+#    #+#             */
/*   Updated: 2022/11/08 12:08:25 by anhebert         ###   ########.fr       */
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
    WrongAnimal( std::string WAtype );
    WrongAnimal( WrongAnimal const &src );
    virtual ~WrongAnimal();
    WrongAnimal &operator=( WrongAnimal const &src );
    void        makeSound() const;
    const std::string &getType() const;
protected:
    std::string type;
};

#endif